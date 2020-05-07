//
// Created by landon on 5/6/20.
//

#ifndef AVITAB_CALCULATIONS_H
#define AVITAB_CALCULATIONS_H

#include "src/environment/Environment.h"

namespace avitab {
    class Calculations {
    public:
        Calculations();
        static double calculateCrowDistance(Location userPosition, Location otherPosition);
    private:
        static double toRadians(double value);
    };
}

#endif //AVITAB_CALCULATIONS_H
