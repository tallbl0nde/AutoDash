#include "widget/MainFrame.hpp"

namespace Widget {
    MainFrame::MainFrame(QWidget * home, QWidget * parent) : QStackedWidget(parent) {
        this->onChange = nullptr;
        this->stack.push(home);
        this->addWidget(home);
    }

    void MainFrame::onWidgetChanged(const std::function<void(int)> & func) {
        this->onChange = func;
    }

    void MainFrame::goBack() {
        this->setCurrentWidget(this->stack.top());

        if (this->stack.size() > 1) {
            this->stack.pop();
            if (this->onChange != nullptr)
            {
                this->onChange(this->stack.size());
            }
        }
    }

    void MainFrame::goHome() {
        while (this->stack.size() > 1) {
            this->stack.pop();
        }

        this->setCurrentWidget(this->stack.top());
        if (this->onChange != nullptr)
        {
            this->onChange(this->stack.size());
        }
    }

    void MainFrame::addWidget(QWidget * widget) {
        QStackedWidget::addWidget(widget);
    }

    void MainFrame::goToWidget(QWidget * widget) {
        this->stack.push(this->currentWidget());
        this->setCurrentWidget(widget);
        if (this->onChange != nullptr)
        {
            this->onChange(this->stack.size());
        }
    }
};
