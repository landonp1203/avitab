//
// Created by landon on 5/3/20.
//

#ifndef AVITAB_VATSIMATCMODEL_H
#define AVITAB_VATSIMATCMODEL_H

struct VatsimAtcModel {
    std::string atcName;
    std::string name;
    std::string frequency;
    float lat;
    float lon;
    unsigned int visualRange;
    std::string loggedOnTime;
    std::string atis;
};

#endif //AVITAB_VATSIMATCMODEL_H
