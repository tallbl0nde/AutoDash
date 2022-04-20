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
            // Main layout
            QVBoxLayout * layout;

            // Heading widget.
            QLabel * heading;

            // Main (user-set) widget.
            QWidget * mainWidget;

        public:
            // Constructs a new HeaderPage.
            HeaderPage(QWidget * parent = nullptr);

            // Implement IHeaderPage.
            void setHeadingText(const std::string & text) override;
            void setMainWidget(QWidget * widget) override;
            QWidget * widget() override;
    };
};

#endif