#ifndef INTERFACE_TEMPLATE_IHEADERPAGE_HPP
#define INTERFACE_TEMPLATE_IHEADERPAGE_HPP

#include "interface/template/ITemplate.hpp"

namespace Template {
    // Template for a page with a heading in the top-left.
    class IHeaderPage : public ITemplate {
        public:
            // Sets the heading text.
            virtual void setHeadingText(const std::string & text) = 0;

            // Sets the icon.
            virtual void setIcon(QWidget * icon) = 0;

            // Sets the main widget shown under the heading.
            virtual void setMainWidget(QWidget * widget) = 0;

            virtual ~IHeaderPage() {};
    };
};

#endif