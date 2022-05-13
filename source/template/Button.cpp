#include <QGraphicsColorizeEffect>
#include <QPainter>

#include "factory/ConfigFactory.hpp"
#include "template/Button.hpp"

namespace Template {
    int Button::BackgroundCornerRadius = 20;

    Button::Button(QWidget * parent) : BaseClickable(parent) {
        this->customColours = false;
        this->icon = nullptr;
        this->label = new QLabel(this);

        this->mainLayout = new QHBoxLayout(this);
        this->mainLayout->setContentsMargins(20, 15, 20, 15);
        this->mainLayout->setSpacing(15);
        this->mainLayout->addStretch();
        this->mainLayout->addWidget(this->label, 0, Qt::AlignVCenter);
        this->mainLayout->addStretch();
    }

    void Button::paintEvent(QPaintEvent * event) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), this->BackgroundCornerRadius, this->BackgroundCornerRadius);
        painter.fillPath(path, this->backgroundColour);

        // Draw highlight if needed
        BaseClickable::paintEvent(event);
    }

    QWidget * Button::widget() {
        return this;
    }

    void Button::resetButtonColour() {
        // TODO: Improve
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
};