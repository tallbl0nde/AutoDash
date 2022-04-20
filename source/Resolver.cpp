#include "Resolver.hpp"

Resolver::Resolver() {
    this->templateProvider_ = nullptr;
}

ITemplateProvider * Resolver::templateProvider() {
    return this->templateProvider_;
}

void Resolver::setTemplateProvider(ITemplateProvider * templateProvider) {
    this->templateProvider_ = templateProvider;
}