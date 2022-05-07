#ifndef TEMPLATE_HEADERPAGE_HPP
#define TEMPLATE_HEADERPAGE_HPP

#include <QFont>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "interface/template/IHeaderPage.hpp"

namespace Template {
    // Template for a page with a heading in the top-left.
    class HeaderPage : public IHeaderPage, public QWidget {
        private:
            // Unique identifier
            static long nextID;
            std::string ID;

            // Heading layout
            QHBoxLayout * headerLayout;

            // Main layout
            QVBoxLayout * mainLayout;

            // Heading widget.
            QLabel * heading;

            // Icon widget.
            QWidget * icon;

            // Main (user-set) widget.
            QWidget * mainWidget;

            // Handle FontFamilyChanged event.
            void onFontFamilyChanged(const std::string & fontFamily);

            // Handle FontSizeChanged event.
            void onFontSizeChanged(const int fontSize);

            // Handle MainTextColourChanged event.
            void onMainTextColourChanged(const IConfig::Colour & mainTextColour);

        public:
            // Constructs a new HeaderPage.
            HeaderPage(QWidget * parent = nullptr);

            ~HeaderPage();

            // Implement IHeaderPage.
            void setHeadingText(const std::string & text) override;
            void setIcon(QWidget * icon) override;
            void setMainWidget(QWidget * widget) override;
            QWidget * widget() override;
    };
};

#endif