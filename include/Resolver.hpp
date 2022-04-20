#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include "interface/ITemplateProvider.hpp"
#include "interface/IResolver.hpp"

// Resolve optional dependencies for modules.
class Resolver : public IResolver {
    private:
        // TemplateProvieder instance.
        ITemplateProvider * templateProvider_;

    public:
        // Constructs a new Resolver.
        Resolver();

        // Methods to set object instances.
        void setTemplateProvider(ITemplateProvider * templateProvider);

        // Implement IResolver.
        ITemplateProvider * templateProvider() override;
};

#endif