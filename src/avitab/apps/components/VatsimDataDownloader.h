//
// Created by landon on 5/2/20.
//

#ifndef AVITAB_VATSIMDATADOWNLOADER_H
#define AVITAB_VATSIMDATADOWNLOADER_H

#include "src/maps/Downloader.h"
#include <nlohmann/json_fwd.hpp>
#include "src/avitab/apps/models/VatsimAtcModel.h"
#include "src/avitab/apps/models/VatsimPilotModel.h"

namespace avitab {
    class VatsimDataDownloader {
    public:
        // constructor / destructor
        VatsimDataDownloader();

        ~VatsimDataDownloader();

        // functions
        std::vector<VatsimAtcModel> getVatsimAtcList();

        std::vector<VatsimPilotModel> getVatsimPilotList();

    private:
        // variables
        constexpr static const auto ATC = "ATC";
        constexpr static const auto PILOT = "PILOT";
        constexpr static const auto VATSIM_DATA_URL = "http://cluster.data.vatsim.net/vatsim-data.json";
        maps::Downloader downloader;

        // functions
        nlohmann::json getVatsimData();
    };

} /* namespace avitab */


#endif //AVITAB_VATSIMDATADOWNLOADER_H
