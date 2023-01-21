#ifndef INTERFACE_ITEMPLATEPROVIDER_HPP
#define INTERFACE_ITEMPLATEPROVIDER_HPP

#include "interface/factory/IListOptionFactory.hpp"
#include "interface/template/IButton.hpp"
#include "interface/template/IHeaderPage.hpp"
#include "interface/template/list/IList.hpp"
#include "interface/template/list/IListButton.hpp"
#include "interface/template/list/IListSeparator.hpp"
#include "interface/template/list/IListSpacer.hpp"
#include "interface/template/slider/IHorizontalDoubleSlider.hpp"
#include "interface/template/slider/IHorizontalIntSlider.hpp"

// Interface for a TemplateProvider, which provides widget templates.
class ITemplateProvider {
    public:
        // Returns a new button template.
        virtual Template::IButton * createButton() = 0;

        // Returns a new HeaderPage template.
        virtual Template::IHeaderPage * createHeaderPage() = 0;

        // Returns a new HorizontalDoubleSlider template.
        virtual Template::IHorizontalDoubleSlider * createHorizontalDoubleSlider() = 0;

        // Returns a new HorizontalIntSlider template.
        virtual Template::IHorizontalIntSlider * createHorizontalIntSlider() = 0;

        // Returns a new List template.
        virtual Template::IList * createList() = 0;

        // Returns a new ListButton template.
        virtual Template::IListButton * createListButton() = 0;

        // Returns a new ListSeparator template.
        virtual Template::IListSeparator * createListSeparator() = 0;

        // Returns a new ListSpacer template.
        virtual Template::IListSpacer * createListSpacer() = 0;


        // Returns a new IListOptionFactory.
        // Must be deleted when finished with.
        virtual IListOptionFactory * listOptionFactory() = 0;


        // Connects the requested ITemplate signal to the QObject slot.
        virtual QMetaObject::Connection connect(Template::ITemplate * source, const char * signal, QObject * sink, const char * slot) = 0;

        // Connects the requested ITemplate signal to the ITemplate slot.
        virtual QMetaObject::Connection connect(Template::ITemplate * source, const char * signal, Template::ITemplate * sink, const char * slot) = 0;

        // Connects the requested QObject signal to the ITemplate slot.
        virtual QMetaObject::Connection connect(QObject * source, const char * signal, Template::ITemplate * sink, const char * slot) = 0;

        virtual ~ITemplateProvider() {};
};

#endif