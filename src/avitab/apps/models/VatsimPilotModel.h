//
// Created by landon on 5/3/20.
//

#ifndef AVITAB_VATSIMPILOTMODEL_H
#define AVITAB_VATSIMPILOTMODEL_H

#include "VatsimBaseModel.h"

namespace avitab {
    struct VatsimPilotModel : VatsimBaseModel {
        std::string callSign;
        // since the airport where the pilot is flying may be below MSL
        int altitude;
        unsigned int groundSpeed;
        std::string aircraft;
        unsigned int heading;
    };
}

#endif //AVITAB_VATSIMPILOTMODEL_H
