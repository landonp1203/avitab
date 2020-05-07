//
// Created by landon on 5/6/20.
//

#include <cmath>
#include "Calculations.h"

namespace avitab {
    Calculations::Calculations() = default;

    double Calculations::calculateCrowDistance(Location userPosition, Location otherPosition) {
        const auto earthRadius = 6371;
        const auto dLat = toRadians(otherPosition.latitude - userPosition.latitude);
        const auto dLon = toRadians(otherPosition.longitude - userPosition.longitude);
        const auto lat1 = toRadians(userPosition.latitude);
        const auto lat2 = toRadians(otherPosition.latitude);

        const auto a = std::sin(dLat / 2) * std::sin(dLat / 2) +
                       std::sin(dLon / 2) * std::sin(dLon / 2) * std::cos(lat1) * std::cos(lat2);
        const auto c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

        return earthRadius * c;
    }

    double Calculations::toRadians(double value) {
        return value * M_PI / 180;
    }
}