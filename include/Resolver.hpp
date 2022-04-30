#ifndef RESOLVER_HPP
#define RESOLVER_HPP

#include "interface/IResolver.hpp"

// Resolve optional dependencies for modules.
class Resolver : public IResolver {
    private:
        // TemplateProvieder instance.
        ITemplateProvider * templateProvider_;

        // Window instance.
        QWidget * window_;

    public:
        // Constructs a new Resolver.
        Resolver();

        // Methods to set object instances.
        void setTemplateProvider(ITemplateProvider * templateProvider);
        void setWindow(QWidget * window);

        // Implement IResolver.
        ITemplateProvider * templateProvider() override;
        QWidget * window() override;
};

#endif