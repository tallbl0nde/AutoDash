#ifndef SETTINGS_SETTINGSFRAME_HPP
#define SETTINGS_SETTINGSFRAME_HPP

#include "interface/template/IHeaderPage.hpp"

class SettingsFrame : public QWidget {
    public:
        // Constructs a new SettingsFrame.
        SettingsFrame(Template::IHeaderPage * parent = nullptr);
};

#endif