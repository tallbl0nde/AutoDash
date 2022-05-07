#include "template/Button.hpp"
#include "template/HeaderPage.hpp"
#include "template/slider/HorizontalDoubleSlider.hpp"
#include "template/slider/HorizontalIntSlider.hpp"
#include "TemplateProvider.hpp"

TemplateProvider::TemplateProvider() {

}

Template::IButton * TemplateProvider::createButton() {
    return new Template::Button();
}

Template::IHeaderPage * TemplateProvider::createHeaderPage() {
    return new Template::HeaderPage();
}

Template::IHorizontalDoubleSlider * TemplateProvider::createHorizontalDoubleSlider() {
    return new Template::HorizontalDoubleSlider();
}

Template::IHorizontalIntSlider * TemplateProvider::createHorizontalIntSlider() {
    return new Template::HorizontalIntSlider();
}
