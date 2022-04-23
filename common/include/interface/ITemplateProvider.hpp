#ifndef INTERFACE_ITEMPLATEPROVIDER_HPP
#define INTERFACE_ITEMPLATEPROVIDER_HPP

#include "interface/template/IButton.hpp"
#include "interface/template/IHeaderPage.hpp"

// Interface for a TemplateProvider, which provides widget templates.
class ITemplateProvider {
    public:
        // Returns a new button template.
        virtual Template::IButton * createButton() = 0;

        // Returns a new HeaderPage template.
        virtual Template::IHeaderPage * createHeaderPage() = 0;

        virtual ~ITemplateProvider() {};
};

#endif