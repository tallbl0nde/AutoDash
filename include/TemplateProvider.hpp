#ifndef TEMPLATEPROVIDER_HPP
#define TEMPLATEPROVIDER_HPP

#include "interface/ITemplateProvider.hpp"

// Provides a number of widget templates.
class TemplateProvider : public ITemplateProvider {
    public:
        // Constructs a new template provider.
        TemplateProvider();

        // Implement ITemplateProvider.
        Template::IButton * createButton() override;
        Template::IHeaderPage * createHeaderPage() override;
        Template::IHorizontalDoubleSlider * createHorizontalDoubleSlider() override;
        Template::IHorizontalIntSlider * createHorizontalIntSlider() override;
        Template::IList * createList() override;
        Template::IListButton * createListButton() override;
        Template::IListSeparator * createListSeparator() override;
        Template::IListSpacer * createListSpacer() override;
        IListOptionFactory * listOptionFactory() override;
        QMetaObject::Connection connect(Template::ITemplate * source, const char * signal, QObject * sink, const char * slot) override;
        QMetaObject::Connection connect(Template::ITemplate * source, const char * signal, Template::ITemplate * sink, const char * slot) override;
        QMetaObject::Connection connect(QObject * source, const char * signal, Template::ITemplate * sink, const char * slot) override;
};

#endif