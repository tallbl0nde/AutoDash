#ifndef TEMPLATEPROVIDER_HPP
#define TEMPLATEPROVIDER_HPP

#include "interface/ITemplateProvider.hpp"

// Provides a number of widget templates.
class TemplateProvider : public ITemplateProvider {
    public:
        // Constructs a new template provider.
        TemplateProvider();

        // Implement ITemplateProvider.
        Template::IHeaderPage * createHeaderPage() override;
};

#endif