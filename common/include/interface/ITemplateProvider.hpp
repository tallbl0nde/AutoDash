#ifndef INTERFACE_ITEMPLATEPROVIDER_HPP
#define INTERFACE_ITEMPLATEPROVIDER_HPP

#include "template/IHeaderPage.hpp"

// Interface for a TemplateProvider, which provides widget templates.
class ITemplateProvider {
    public:
        // Returns a new HeaderPage template.
        virtual Template::IHeaderPage * createHeaderPage() = 0;

        virtual ~ITemplateProvider() {};
};

#endif