#include <QHBoxLayout>
#include <QPainter>

#include "widget/LauncherEntry.hpp"

#include "Log.hpp"

namespace Widget {
    LauncherEntry::LauncherEntry(QWidget * parent) : IClickable(parent) {
        this->backgroundColour = QColor(255, 255, 255, 0);
        this->onClickedCallback = nullptr;

        // Create layout
        // TODO: Update
        this->layout = new QHBoxLayout(this);
        this->layout->setMargin(0);
        this->layout->setSpacing(0);

        // Insert widgets into layout
        this->label = new QLabel();
        this->label->setFont(this->labelFont());
        this->label->setStyleSheet(this->labelStylesheet());
        this->svg = new QSvgWidget();

        this->layout->addWidget(this->svg);
        this->layout->addWidget(this->label);
    }

    QFont LauncherEntry::labelFont() {
        QFont font = QFont("Rubik");
        font.setBold(true);
        font.setPointSize(24);
        return font;
    }

    QString LauncherEntry::labelStylesheet() {
        return QString("QLabel { color: white; }");
    }

    void LauncherEntry::paintEvent(QPaintEvent * event) {
        // TODO: Global colour?
        Q_UNUSED(event);
        QColor colour = QColor(50, 50, 50, 80);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        QPainterPath path;
        path.addRoundedRect(this->rect(), 20, 20);

        painter.fillPath(path, colour);
        painter.fillPath(path, backgroundColour);
    }

    void LauncherEntry::resizeEvent(QResizeEvent * event) {
        event->accept();

        // Set the minimum size of the svg to the height of the label (making it 1:1)
        // TODO: Update
        int size = this->size().height();
        int svgSize = size * 0.6;
        this->svg->setFixedSize(svgSize, svgSize);

        int padding = size * 0.2;
        this->layout->setMargin(padding);
        this->layout->setSpacing(padding * 1.25);
    }

    void LauncherEntry::onClick() {
        this->backgroundColour.setAlpha(50);
        this->update();
    }

    void LauncherEntry::onRegainedFocus() {
        this->backgroundColour.setAlpha(50);
        this->update();
    }

    void LauncherEntry::onLostFocus() {
        this->backgroundColour.setAlpha(20);
        this->update();
    }

    void LauncherEntry::onRelease() {
        this->backgroundColour.setAlpha(0);
        this->update();

        if (this->onClickedCallback != nullptr) {
            this->onClickedCallback();
        }
    }

    void LauncherEntry::onClicked(const std::function<void ()> & func) {
        this->onClickedCallback = func;
    }

    void LauncherEntry::setLabel(QString label) {
        this->label->setText(label);
    }

    void LauncherEntry::setLabelStyle(QFont & font, QString & stylesheet) {
        this->label->setFont(font);
        this->label->setStyleSheet(stylesheet);
    }

    void LauncherEntry::setSVG(QString svg) {
        this->svg->load(svg);
    }
};
