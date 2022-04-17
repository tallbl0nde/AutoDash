#ifndef WIDGET_FAVOURITES_HPP
#define WIDGET_FAVOURITES_HPP

#include <functional>
#include <QBoxLayout>
#include <QWidget>

#include "widget/SvgButton.hpp"

namespace Widget {
    class Favourites : public QWidget {
        Q_OBJECT

        public:
            // Orientation of favourites bar.
            enum class Orientation {
                Horizontal,
                Vertical
            };

            // Set of data for each entry.
            struct Entry {
                std::string id;         // ID of icon/module
                SvgButton * button;     // Actual button
            };

        private:
            // Callback to invoke when an entry is clicked.
            std::function<void(std::string)> onEntryClickedCallback;

            // List of all entries in the layout.
            std::vector<Entry> entries;

            // Midpoint of highlight.
            QPoint highlightMidpoint;

            // Main layout.
            QBoxLayout * layout;

        protected:
            // Override to draw highlight
            virtual void paintEvent(QPaintEvent * event) override;

        public:
            // Constructs a new favourites widget with the given orientation.
            Favourites(Orientation orientation, QWidget * parent = nullptr);

            // Adds an entry to the bar (bottom-most or right-most).
            void addEntry(const std::string & id, const std::string & svgPath);

            // Removes an entry from the bar.
            void removeEntry(const std::string & id);

            // Removes all entries from the bar.
            void removeAllEntries();

            // Sets the given entry as 'active'.
            void setActiveEntry(const std::string & id);

            // Assigns a handler for the 'onEntryClicked' event.
            void onEntryClicked(const std::function<void(std::string)> callback);

    };
};

#endif