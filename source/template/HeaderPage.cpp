#include <QGraphicsColorizeEffect>

#include "factory/ConfigFactory.hpp"
#include "template/HeaderPage.hpp"

#define HEADING_FONT_OFFSET 2

namespace Template {
    long HeaderPage::nextID = 0;

    HeaderPage::HeaderPage(QWidget * parent) : QWidget(parent) {
        this->icon = nullptr;
        this->ID = "templateHeaderPage" + std::to_string(HeaderPage::nextID++);
        this->mainWidget = nullptr;

        // Set up header layout
        QWidget * headerWidget = new QWidget(this);
        this->heading = new QLabel("HeaderPage", headerWidget);
        this->headerLayout = new QHBoxLayout(headerWidget);
        this->headerLayout->addWidget(this->heading, 0, Qt::AlignVCenter);
        this->headerLayout->addStretch();
        this->headerLayout->setContentsMargins(10, 0, 0, 0);
        this->headerLayout->setSpacing(20);

        // Set up the layout
        this->mainLayout = new QVBoxLayout(this);
        this->mainLayout->setMargin(30);
        this->mainLayout->addWidget(headerWidget);
        this->mainLayout->addSpacing(20);

        QWidget * separator = new QWidget(this);
        separator->setFixedHeight(1);
        separator->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        separator->setStyleSheet("background-color: gray");
        this->mainLayout->addWidget(separator);

        // Read in config and attach event handlers
        ConfigFactory configFactory;
        IConfig * config = configFactory.getConfig();

        this->onFontFamilyChanged(config->fontFamily());
        config->onFontFamilyChanged(this->ID, [this](const std::string fontFamily) {
            this->onFontFamilyChanged(fontFamily);
        }, []() { return true; });

        this->onFontSizeChanged(config->fontSize());
        config->onFontSizeChanged(this->ID, [this](const int fontSize) {
            this->onFontSizeChanged(fontSize);
        }, []() { return true; });

        this->onMainTextColourChanged(config->mainTextColour());
        config->onMainTextColourChanged(this->ID, [this](const IConfig::Colour mainTextColour) {
            this->onMainTextColourChanged(mainTextColour);
        }, []() { return true; });
    }

    void HeaderPage::onFontFamilyChanged(const std::string & fontFamily) {
        QFont font = this->heading->font();
        font.setBold(true);
        font.setFamily(QString::fromStdString(fontFamily));
        this->heading->setFont(font);
    }

    void HeaderPage::onFontSizeChanged(const int fontSize) {
        QFont font = this->heading->font();
        font.setPointSize(fontSize + HEADING_FONT_OFFSET);
        this->heading->setFont(font);
    }

    void HeaderPage::onMainTextColourChanged(const IConfig::Colour & mainTextColour) {
        IConfig::Colour c = mainTextColour;
        QGraphicsColorizeEffect * headingEffect = new QGraphicsColorizeEffect();
        headingEffect->setColor(QColor(c.r, c.g, c.b, c.a));
        this->heading->setGraphicsEffect(headingEffect);
    }

    void HeaderPage::setHeadingText(const std::string & text) {
        this->heading->setText(QString::fromStdString(text));
    }

    void HeaderPage::setIcon(QWidget * icon) {
        if (this->icon != nullptr) {
            this->headerLayout->removeWidget(this->icon);
            this->icon->setParent(nullptr);
            delete this->icon;
        }

        this->icon = icon;
        this->icon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->icon->setParent(this);
        this->headerLayout->insertWidget(0, this->icon, 0, Qt::AlignVCenter);
    }

    void HeaderPage::setMainWidget(QWidget * widget) {
        widget->setParent(this);
        this->mainLayout->addWidget(widget, 1);
        this->mainWidget = widget;
    }

    QWidget * HeaderPage::widget() {
        return this;
    }

    HeaderPage::~HeaderPage() {
        ConfigFactory configFactory;
        IConfig * config = configFactory.getConfig();

        // Remove event handlers
        config->onFontFamilyChanged(this->ID, nullptr, nullptr);
        config->onFontSizeChanged(this->ID, nullptr, nullptr);
        config->onMainTextColourChanged(this->ID, nullptr, nullptr);
    }
};