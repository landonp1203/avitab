//
// Created by landon on 5/2/20.
//

#ifndef AVITAB_VATSIMAPP_H
#define AVITAB_VATSIMAPP_H

#include <memory>
#include <src/gui_toolkit/widgets/List.h>
#include "App.h"
#include "src/gui_toolkit/widgets/Window.h"
#include "src/gui_toolkit/widgets/Label.h"
#include "src/avitab/apps/components/VatsimDataDownloader.h"
#include "src/environment/Environment.h"

namespace avitab {
    class VatsimApp : public App {
    public:
        explicit VatsimApp(FuncsPtr appFuncs);

        std::vector<VatsimAtcModel> getAtcWithinDistance(bool isKm, int distance);

        std::vector<VatsimPilotModel> getPilotsWithinDistance(bool isKm, int distance);

    private:
        std::shared_ptr<Window> window;
        std::shared_ptr<Label> label;
        std::shared_ptr<List> list;
        VatsimDataDownloader vatsimDataDownloader;

        std::vector<VatsimBaseModel> getClosestEntitiesList(std::vector<VatsimBaseModel> listToFilter, int distanceInKm, Location currentLocation);
        void getClosestEntitiesList(VatsimBaseModel listToFilter, int distanceInKm, Location currentLocation);
//        SelectCallback selectCallback;

//        void onDown();
//        void onUp();
//        void onSelect(int data);
    };

} /* namespace avitab */


#endif //AVITAB_VATSIMAPP_H
