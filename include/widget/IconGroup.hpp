#ifndef WIDGET_ICONGROUP_HPP
#define WIDGET_ICONGROUP_HPP

#include <QHBoxLayout>
#include <QString>
#include <QSvgWidget>
#include <QWidget>
#include <vector>

namespace Widget {
    // Widget consisting of zero or more icons aligned in a row.
    class IconGroup : public QWidget {
        Q_OBJECT

        private:
            // Collection of an icon and it's identfier.
            struct Icon {
                QString identifier;     // (Unique) identifier
                QSvgWidget * widget;    // Icon widget
            };

            // Array of added icons.
            std::vector<Icon> icons;

            // Icon layout object.
            QHBoxLayout * layout;

        protected:
            // Overload to adjust svg size.
            void resizeEvent(QResizeEvent * event);

        public:
            // Creates a new IconGroup.
            explicit IconGroup(QWidget * parent = nullptr);

            // Sets the spacing between each icon.
            void setIconSpacing(int spacing);

            // Adds an icon to the icon group in the rightmost position.
            // Returns whether successful or not (fails if another icon with the same ID exists).
            bool addIcon(QString identifier, QString icon);

            // Returns the widget with the given identifier.
            // Returns nullptr if not found.
            QSvgWidget * getIcon(QString identifier);
    };
};

#endif