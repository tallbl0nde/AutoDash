#include <QAbstractItemView>
#include <QComboBox>
#include <QStyledItemDelegate>

#include "template/list/ListOptionComboBox.hpp"

namespace Template {
    ListOptionComboBox::ListOptionComboBox(const std::string & name, const std::string & description, const std::string value, const std::vector<std::string> permittedValues, const StringHandler & onChange) : ListOption(name, description) {
        QComboBox * comboBox = new QComboBox();
        comboBox->setItemDelegate(new QStyledItemDelegate(comboBox));

        for (std::string value : permittedValues) {
            QString tmp = QString::fromStdString(value);
            comboBox->addItem(tmp, QVariant(tmp));
        }

        int idx = comboBox->findText(QString::fromStdString(value));
        comboBox->setCurrentIndex(idx);
        comboBox->setStyleSheet(

// TODO: Finish styling and use config values
"QComboBox { "
    "border: 1px solid rgb(69, 69, 69);"
    "border-radius: 20px;"
    "height: 50px;"
    "background-color: rgb(69, 69, 69);"
    "color: white;"
    "font-family: Rubik;"
    "font-size: 20px;"
    "padding: 0px 30px 0px 20px;"
"}"
""
"QComboBox::drop-down {"
    "border: 0;"
    "padding-right: 30px;"
"}"
""
"QComboBox::down-arrow {"
    "image: url(:/icons/drop-down.svg);"
    "width: 40px;"
    "height: 40px;"
"}"
""
"QComboBox QAbstractItemView {"
    "border: 1px solid rgb(80, 80, 80);"
    "border-radius: 20px;"
    "background-color: rgb(69, 69, 69);"
    "color: white;"
    "font-family: Rubik;"
    "font-size: 20px;"
    "padding: 5px;"
    "text-align: center;"
"}"
""
"QComboBox QAbstractItemView::item {"
    "background-color: transparent;"
    "border: none;"
    "padding: 10px;"
    "text-align: center;"
"}"
""
"QComboBox QAbstractItemView::item:selected {"
    "border: none;"
"}"

        );
        comboBox->view()->window()->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
        comboBox->view()->window()->setAttribute(Qt::WA_TranslucentBackground);

        this->setRightWidget(comboBox);
    }
};