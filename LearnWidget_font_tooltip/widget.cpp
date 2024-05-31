#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    button = new QPushButton(this);
    button->setText("this is a click button");

    // 设置按钮字体的各类格式
    QFont font;
    font.setFamily("宋体");
    font.setPixelSize(20);
    font.setBold(true);
    font.setItalic(true);
    font.setUnderline(true);
    font.setStrikeOut(true);

    // 把font类型设置进入按钮的字体格式
    this->button->setFont(font);

    // 设置按钮的tooltip提示信息
    this->button->setToolTip("click me to change the text of mine");
    this->button->setToolTipDuration(3000);

    connect(button, &QPushButton::clicked, this, &Widget::clicked_event);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clicked_event()
{
    if(button->text() == "text changed!")
    {
        exit(0);
    }
    this->button->setToolTip("click me again to exit progamme");
    this->button->setText("text changed!");
}
