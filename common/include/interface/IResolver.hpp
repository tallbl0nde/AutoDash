#ifndef INTERFACE_IRESOLVER_HPP
#define INTERFACE_IRESOLVER_HPP

#include "ITemplateProvider.hpp"

// Interface for the 'resolver', which provides optional shared dependencies
// to modules (e.g. templates, config, etc).
class IResolver {
    public:
        // Returns the TemplateProvider.
        virtual ITemplateProvider * templateProvider() = 0;

        virtual ~IResolver() {};
};

#endif