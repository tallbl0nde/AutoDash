#ifndef TEMPLATE_LIST_LISTOPTION_HPP
#define TEMPLATE_LIST_LISTOPTION_HPP

#include <QHBoxLayout>
#include <QLabel>

#include "interface/template/list/IListOption.hpp"

namespace Template {
    // Base class for a ListOption.
    class ListOption : public QWidget, public IListOption {
        Q_OBJECT
        Q_INTERFACES(Template::IListOption)

        private:
            // Main layout.
            QHBoxLayout * layout;

            // Icon widget.
            QWidget * icon;

            // Label widget.
            QLabel * label;

            // Description widget.
            QLabel * description;

            // Right-hand side widget.
            QWidget * rightWidget;

        public:
            // Constructs a new ListOption.
            ListOption(const std::string & name, const std::string & description, QWidget * parent = nullptr);

            // Implement IListOption.
            void setRightWidget(QWidget * widget) override;
            QWidget * widget() override;

        public slots:
            // Implement IListOption.
            void setIcon(QWidget * icon) override;
            void setLabel(const std::string label) override;
            void setDescription(const std::string description) override;
    };
};

#endif