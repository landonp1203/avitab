//
// Created by landon on 5/2/20.
//

#include <iostream>
#include "VatsimApp.h"
#include "src/avitab/apps/utils/Calculations.h"
#include <algorithm>

namespace avitab {

    VatsimApp::VatsimApp(FuncsPtr appFuncs) :
            App(appFuncs),
            window(std::make_shared<Window>(getUIContainer(), "Vatsim App")),
            list(std::make_shared<List>(window)) {
        window->setOnClose([this]() { exit(); });

        window->addSymbol(Widget::Symbol::DOWN, [this]() {});
        window->addSymbol(Widget::Symbol::UP, [this]() {});

        list->setDimensions(window->getContentWidth(), window->getContentHeight());
        list->centerInParent();
        list->setCallback([this](int data) {
            api().executeLater([this, data] {
//                onSelect(data);
            });
        });

        auto q = getAtcWithinDistance(false, 50);
        std::cout << "AMOUNT: " << q.size() << std::endl;
    }

    std::vector<VatsimAtcModel> VatsimApp::getAtcWithinDistance(bool isKm, int distance) {
        const auto currentLocation = (Location) {.longitude = 33.748997, .latitude = -84.387985};
        // want this in km since the crow distance is calculated in km
        const auto distanceInKm = isKm ? distance : distance * 1.60934;
        const auto atcList = vatsimDataDownloader.getVatsimAtcList(); // TODO: get the saved list
        std::vector<VatsimAtcModel> closestAtc;
        std::copy_if(atcList.begin(), atcList.end(), std::back_inserter(closestAtc),
                     [currentPosition, distanceInKm](const VatsimAtcModel &toCheck) {
                         const auto atcPosition = (Location) {.longitude = toCheck.lat, .latitude = toCheck.lon};
                         const auto calculatedDistance = Calculations::calculateCrowDistance(currentPosition,
                                                                                             atcPosition);
                         return calculatedDistance <= distanceInKm;
                     });

        return closestAtc;
    }

    std::vector<VatsimPilotModel> VatsimApp::getPilotsWithinDistance(bool isKm, int distance) {
        const auto currentLocation = (Location) {.longitude = 33.748997, .latitude = -84.387985};
        const auto pilotList = vatsimDataDownloader.getVatsimPilotList(); // TODO: get the saved list
        const auto distanceInKm = isKm ? distance : distance * 1.60934;

        getClosestEntitiesList(pilotList[0], 600, currentLocation)
//        const auto q = getClosestEntitiesList(pilotList, distanceInKm, currentLocation);
        return pilotList;
    }

    std::vector<VatsimBaseModel>
    VatsimApp::getClosestEntitiesList(std::vector<VatsimBaseModel> listToFilter, int distanceInKm,
                                      Location currentLocation) {
        std::vector<VatsimBaseModel> closestEntities;
        std::copy_if(listToFilter.begin(), listToFilter.end(), std::back_inserter(closestEntities),
                     [&currentLocation, &distanceInKm](const VatsimBaseModel &toCheck) {
                         const auto entityPosition = (Location) {.longitude = toCheck.location.longitude,
                                 .latitude = toCheck.location.latitude};
                         const auto calculatedDistance = Calculations::calculateCrowDistance(currentLocation,
                                                                                             entityPosition);
                         return calculatedDistance <= distanceInKm;
                     });
    }

    void VatsimApp::getClosestEntitiesList(VatsimBaseModel listToFilter, int distanceInKm, Location currentLocation) {

    }

//    void FileSelect::setSelectCallback(SelectCallback cb) {
//        selectCallback = cb;
//    }

//    void VatsimApp::onDown() {
//        list->scrollDown();
//    }
//
//    void VatsimApp::onUp() {
//        list->scrollUp();
//    }
//
//    void VatsimApp::onSelect(int data) {
//    }

} /* namespace avitab */
