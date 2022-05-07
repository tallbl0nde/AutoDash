#ifndef SETTINGS_SETTINGSFRAME_HPP
#define SETTINGS_SETTINGSFRAME_HPP

#include "interface/IResolver.hpp"
#include "interface/ISettingEntry.hpp"
#include "interface/template/IHeaderPage.hpp"

class SettingsFrame : public QWidget {
    public:
        // Constructs a new SettingsFrame.
        SettingsFrame(Template::IHeaderPage * parent, std::vector<std::vector<ISettingEntry *>> moduleSettingEntries, IResolver * resolver);
};

#endif