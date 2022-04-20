#include "template/HeaderPage.hpp"
#include "TemplateProvider.hpp"

TemplateProvider::TemplateProvider() {

}

Template::IHeaderPage * TemplateProvider::createHeaderPage() {
    return new Template::HeaderPage();
}