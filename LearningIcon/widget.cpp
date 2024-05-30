#include "widget.h"
#include "ui_widget.h"

#include <QIcon>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIcon icon(":/images/title.jpg");
    this->setWindowIcon(icon);

//    QPalette palette;
//    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/background.jpg")));
//    (*this).setPalette(palette);
//    (*this).setAutoFillBackground(true);


    QPixmap image(":/images/yamato.jpg"); // 设置鼠标的光标
    this->setCursor(image);

    QPixmap m1(":/images/title.jpg");
    this->ui->pushButton_add->setCursor(m1);

//    QPixmap m2(":/images/title.jpg");
    QCursor m2 = this->ui->pushButton_add->cursor();
    this->ui->pushButton_sub->setCursor(m2);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_add_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity >= 1.0)
        return;
    qDebug() << opacity;
    opacity += 0.1;
    this->setWindowOpacity(opacity);
}

void Widget::on_pushButton_sub_clicked()
{
    float opacity = this->windowOpacity();
    if(opacity <= 0)
        return;
    qDebug() << opacity;
    opacity -= 0.1;
    this->setWindowOpacity(opacity);
}
