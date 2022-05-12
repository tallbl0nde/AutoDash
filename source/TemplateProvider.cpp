#include "template/Button.hpp"
#include "template/HeaderPage.hpp"
#include "template/list/List.hpp"
#include "template/list/ListButton.hpp"
#include "template/list/ListSeparator.hpp"
#include "template/list/ListSpacer.hpp"
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

Template::IList * TemplateProvider::createList() {
    return new Template::List();
}

Template::IListButton * TemplateProvider::createListButton() {
    return new Template::ListButton();
}

Template::IListSeparator * TemplateProvider::createListSeparator() {
    return new Template::ListSeparator();
}

Template::IListSpacer * TemplateProvider::createListSpacer() {
    return new Template::ListSpacer();
}