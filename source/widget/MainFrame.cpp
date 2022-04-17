#include "widget/MainFrame.hpp"

namespace Widget {
    MainFrame::MainFrame(QWidget * home, QWidget * parent) : QStackedWidget(parent) {
        this->onChange = nullptr;
        this->stack.push(Frame{"Root Launcher", home});
        this->addFrame("Root Launcher", home);
        this->currentID = "Root Launcher";
    }

    void MainFrame::onFrameChanged(const std::function<void(std::string, int)> & callback) {
        this->onChange = callback;
    }

    void MainFrame::goBack() {
        Frame frame = this->stack.top();
        this->setCurrentWidget(frame.frame);

        if (this->stack.size() > 1) {
            this->stack.pop();
            frame = this->stack.top();
            this->currentID = frame.id;
            if (this->onChange != nullptr)
            {
                this->onChange(frame.id, this->stack.size());
            }
        }
    }

    void MainFrame::goHome() {
        while (this->stack.size() > 1) {
            this->stack.pop();
        }

        Frame frame = this->stack.top();
        this->currentID = frame.id;
        this->setCurrentWidget(frame.frame);
        if (this->onChange != nullptr)
        {
            this->onChange(frame.id, this->stack.size());
        }
    }

    void MainFrame::addFrame(const std::string & id, QWidget * widget) {
        this->availableFrames.push_back(Frame{id, widget});
        this->addWidget(widget);
    }

    void MainFrame::openFrame(const std::string & id) {
        // Find frame
        auto it = std::find_if(this->availableFrames.begin(), this->availableFrames.end(), [id](const Frame & frame) {
            return (frame.id == id);
        });

        if (it == this->availableFrames.end() || (*it).id == this->currentID) {
            return;
        }

        // Store current frame
        this->stack.push(Frame{this->currentID, this->currentWidget()});

        // Set new and emit event
        this->currentID = (*it).id;
        this->setCurrentWidget((*it).frame);
        if (this->onChange != nullptr)
        {
            this->onChange(this->currentID, this->stack.size());
        }
    }
};
