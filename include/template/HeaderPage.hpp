#ifndef TEMPLATE_HEADERPAGE_HPP
#define TEMPLATE_HEADERPAGE_HPP

#include <QFont>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

#include "interface/template/IHeaderPage.hpp"

namespace Template {
    // Template for a page with a heading in the top-left.
    class HeaderPage : public QWidget, public IHeaderPage {
        Q_OBJECT
        Q_INTERFACES(Template::IHeaderPage)

        private:
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

        public:
            // Constructs a new HeaderPage.
            HeaderPage(QWidget * parent = nullptr);

            // Implement IHeaderPage.
            QWidget * widget() override;

        public slots:
            // Implement IHeaderPage.
            void setHeadingText(const std::string & text) override;
            void setIcon(QWidget * icon) override;
            void setMainWidget(QWidget * widget) override;
    };
};

#endif