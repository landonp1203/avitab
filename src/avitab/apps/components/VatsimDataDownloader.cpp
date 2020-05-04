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
                // push it onto the vector
                atcList.push_back(atc);
            }
        }

        return atcList;
    }

    VatsimDataDownloader::~VatsimDataDownloader() = default;
} /* namespace avitab */