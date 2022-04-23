#include "template/Button.hpp"
#include "template/HeaderPage.hpp"
#include "TemplateProvider.hpp"

TemplateProvider::TemplateProvider() {

}

Template::IButton * TemplateProvider::createButton() {
    return new Template::Button();
}

Template::IHeaderPage * TemplateProvider::createHeaderPage() {
    return new Template::HeaderPage();
}