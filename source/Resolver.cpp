#include "Resolver.hpp"

Resolver::Resolver() {
    this->templateProvider_ = nullptr;
    this->window_ = nullptr;
}

ITemplateProvider * Resolver::templateProvider() {
    return this->templateProvider_;
}

QWidget * Resolver::window() {
    return this->window_;
}

void Resolver::setTemplateProvider(ITemplateProvider * templateProvider) {
    this->templateProvider_ = templateProvider;
}

void Resolver::setWindow(QWidget * window) {
    this->window_ = window;
}