//
// Created by landon on 5/2/20.
//

#ifndef AVITAB_VATSIMAPP_H
#define AVITAB_VATSIMAPP_H

#include <memory>
#include "App.h"
#include "src/gui_toolkit/widgets/Window.h"
#include "src/gui_toolkit/widgets/Label.h"
#include "src/avitab/apps/components/VatsimDataDownloader.h"

namespace avitab {

    class VatsimApp: public App {
    public:
        explicit VatsimApp(FuncsPtr appFuncs);
    private:
        std::shared_ptr<Window> window;
        std::shared_ptr<Label> label;
        VatsimDataDownloader vatsimDataDownloader;
    };

} /* namespace avitab */


#endif //AVITAB_VATSIMAPP_H
