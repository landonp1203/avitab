//
// Created by landon on 5/2/20.
//

#include <nlohmann/json.hpp>
#include <iostream>
#include "VatsimDataDownloader.h"

namespace avitab {
    VatsimDataDownloader::VatsimDataDownloader() = default;

    nlohmann::json VatsimDataDownloader::getVatsimData() {
        bool cancelToken = false;
        auto data = downloader.download(VATSIM_DATA_URL, cancelToken);
        auto test = std::string(data.begin(), data.end());
        return nlohmann::json::parse(test);
    }

    std::vector<VatsimAtcModel> VatsimDataDownloader::getVatsimAtcList() {
        std::vector<VatsimAtcModel> atcList;
        auto data = getVatsimData();

        auto clients = data.at("clients");
        for (auto it : clients) {
            if (it.at("clienttype") == ATC) {
                // create the model
                VatsimAtcModel atc;
                atc.atcName = it.at("callsign");
                atc.name = it.at("realname");
                atc.frequency = it.at("frequency");
                atc.lat = it.at("latitude").get<float>();
                atc.lon = it.at("longitude").get<float>();
                atc.visualRange = it.at("visualrange").get<int>();
                atc.loggedOnTime = it["time_logon"];

                auto atisMessage = it.at("atis_message");
                atc.atis = atisMessage.is_null() ? "" : atisMessage;

                // push it onto the vector
                atcList.push_back(atc);
            }
        }
        return atcList;
    }

    std::vector<VatsimPilotModel> VatsimDataDownloader::getVatsimPilotList() {
        std::vector<VatsimPilotModel> pilotList;
        auto data = getVatsimData();

        auto clients = data.at("clients");
        for (auto it : clients) {
            if (it.at("clienttype") == PILOT) {
                // create the model
                VatsimPilotModel pilot;
                pilot.callSign = it.at("callsign");
                pilot.lat = it.at("latitude").get<float>();
                pilot.lon = it.at("longitude").get<float>();
                pilot.altitude = it.at("altitude").get<int>();
                pilot.groundSpeed = it.at("groundspeed").get<unsigned int>();
                pilot.heading = it.at("heading").get<unsigned int>();

                auto aircraft = it.at("planned_aircraft");
                pilot.aircraft = aircraft.is_null() ? "" : aircraft;

                // push it onto the vector
                pilotList.push_back(pilot);
            }
        }
        return pilotList;
    }

    VatsimDataDownloader::~VatsimDataDownloader() = default;
} /* namespace avitab */