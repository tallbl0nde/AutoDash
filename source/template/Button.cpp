#include <QGraphicsColorizeEffect>
#include <QPainter>

#include "factory/ConfigFactory.hpp"
#include "template/Button.hpp"

namespace Template {
    long Button::nextID = 0;

    Button::Button(QWidget * parent) : IClickable(parent) {
        this->action = nullptr;
        this->customColours = false;
        this->clickedColour = QColor(255, 255, 255, 0);
        this->icon = nullptr;
        this->label = new QLabel(this);
        this->ID = "templateButton" + std::to_string(Button::nextID++);

        this->mainLayout = new QHBoxLayout(this);
        this->mainLayout->setContentsMargins(20, 15, 20, 15);
        this->mainLayout->setSpacing(15);

        // Read in config and attach event handlers
        ConfigFactory configFactory;
        IConfig * config = configFactory.getConfig();

        this->onBackgroundColourChanged(config->backgroundColour());
        config->onBackgroundColourChanged(this->ID, [this](const IConfig::Colour backgroundColour) {
            this->onBackgroundColourChanged(backgroundColour);
        }, []() { return true; });

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

        this->mainLayout->addStretch();
        this->mainLayout->addWidget(this->label, 0, Qt::AlignVCenter);
        this->mainLayout->addStretch();
    }

    void Button::onBackgroundColourChanged(const IConfig::Colour & backgroundColour) {
        if (this->customColours) {
            return;
        }

        this->resetButtonColour();
    }

    void Button::onFontFamilyChanged(const std::string & fontFamily) {
        QFont font = this->label->font();
        font.setFamily(QString::fromStdString(fontFamily));
        this->label->setFont(font);
    }

    void Button::onFontSizeChanged(const int fontSize) {
        QFont font = this->label->font();
        font.setPointSize(fontSize);
        this->label->setFont(font);
    }

    void Button::onMainTextColourChanged(const IConfig::Colour & mainTextColour) {
        if (this->customColours) {
            return;
        }

        this->resetButtonColour();
    }

    void Button::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), 20, 20);
        painter.fillPath(path, this->backgroundColour);
        painter.fillPath(path, this->clickedColour);
    }

    void Button::onClick() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void Button::onRegainedFocus() {
        this->clickedColour.setAlpha(40);
        this->update();
    }

    void Button::onLostFocus() {
        this->clickedColour.setAlpha(0);
        this->update();
    }

    void Button::onRelease() {
        this->clickedColour.setAlpha(0);
        this->update();
        if (this->action != nullptr) {
            this->action();
        }
    }

    void Button::resetButtonColour() {
        ConfigFactory configFactory;
        IConfig * config = configFactory.getConfig();
        IConfig::Colour c;

        if (this->icon != nullptr) {
            c = config->mainTextColour();
            QGraphicsColorizeEffect * iconEffect = new QGraphicsColorizeEffect();
            iconEffect->setColor(QColor(c.r, c.g, c.b, c.a));
            this->label->setGraphicsEffect(iconEffect);
        }

        c = config->backgroundColour();
        this->backgroundColour = QColor(c.r, c.g, c.b, c.a);

        c = config->mainTextColour();
        QGraphicsColorizeEffect * labelEffect = new QGraphicsColorizeEffect();
        labelEffect->setColor(QColor(c.r, c.g, c.b, c.a));
        this->label->setGraphicsEffect(labelEffect);

        this->customColours = false;
    }

    void Button::setButtonAction(const std::function<void()> & action) {
        this->action = action;
    }

    void Button::setButtonColour(QColor background, QColor foreground) {
        this->backgroundColour = background;

        if (this->icon != nullptr) {
            QGraphicsColorizeEffect * iconEffect = new QGraphicsColorizeEffect();
            iconEffect->setColor(foreground);
            this->label->setGraphicsEffect(iconEffect);
        }

        QGraphicsColorizeEffect * labelEffect = new QGraphicsColorizeEffect();
        labelEffect->setColor(foreground);
        this->label->setGraphicsEffect(labelEffect);

        this->customColours = true;
    }

    void Button::setButtonIcon(QWidget * icon) {
        if (this->icon != nullptr) {
            this->mainLayout->removeWidget(this->icon);
            this->icon->setParent(nullptr);
            delete this->icon;
        }

        QGraphicsColorizeEffect * iconEffect = new QGraphicsColorizeEffect();
        iconEffect->setColor(static_cast<QGraphicsColorizeEffect *>(this->label->graphicsEffect())->color());

        this->icon = icon;
        this->icon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        this->icon->setGraphicsEffect(iconEffect);
        this->icon->setParent(this);
        this->mainLayout->insertWidget(1, this->icon, 0, Qt::AlignVCenter);
    }

    void Button::setButtonText(const std::string & text) {
        this->label->setText(QString::fromStdString(text));
    }

    QWidget * Button::widget() {
        return this;
    }

    Button::~Button() {
        ConfigFactory configFactory;
        IConfig * config = configFactory.getConfig();

        // Remove event handlers
        config->onBackgroundColourChanged(this->ID, nullptr, nullptr);
        config->onFontFamilyChanged(this->ID, nullptr, nullptr);
        config->onFontSizeChanged(this->ID, nullptr, nullptr);
        config->onMainTextColourChanged(this->ID, nullptr, nullptr);
    }
};