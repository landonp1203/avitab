//
// Created by landon on 5/2/20.
//

#include <iostream>
#include "VatsimApp.h"

namespace avitab {

    VatsimApp::VatsimApp(FuncsPtr appFuncs):
            App(appFuncs),
            window(std::make_shared<Window>(getUIContainer(), "Vatsim App")),
            label(std::make_shared<Label>(window, ""))
    {
        const auto q = vatsimDataDownloader.getVatsimPilotList();
        std::stringstream ss;
        for(const auto& i : q) {
            ss << i.callSign + " " << i.heading << std::endl;
        }
        window->setOnClose([this] () { exit(); });

        label->setText(ss.str());
    }

} /* namespace avitab */
