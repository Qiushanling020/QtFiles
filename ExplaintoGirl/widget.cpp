#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("我是一个表白小程序!");
    srand(time(nullptr));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_accept_clicked()
{
    ui->label->setText("我很高兴!\n接受了就不能反悔了嗷!");
    this->ui->pushButton_reject->setEnabled(false);
}

void Widget::on_pushButton_reject_pressed()
{
    QRect rect = this->geometry();
    int max_width = rect.width(), max_height = rect.height();
    ui->pushButton_reject->move(rand() % max_width, rand() % max_height);
}
