#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    label = new QLabel(tr("Find &what:"));
    lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);

    caseCheckBox = new QCheckBox(tr("Match &case"), this);
    backwardChechBox = new QCheckBox(tr("Search backward"), this);

    findButton = new QPushButton(tr("&Find"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    closeButton = new QPushButton(tr("&Close"));
    // closeButton->setEnabled(true); // 这行代码可有可无，因为closeButton是要一直生效的，QPushbutton 的成员函数setEnable可能缺省值就是true

    QObject::connect(lineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(enableFindButton(const QString&)));
    QObject::connect(findButton, SIGNAL(clicked()), this, SLOT(findClicled()()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout* topLeftlayout = new QHBoxLayout;
    topLeftlayout->addWidget(label);
    topLeftlayout->addWidget(lineEdit);

    QVBoxLayout* leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftlayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwardChechBox);

    QVBoxLayout* rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    this->setLayout(mainLayout);

    this->setWindowTitle(tr("Find"));
    this->setFixedHeight(sizeHint().height());
}

void Dialog::findClicled()
{
    QString text = lineEdit->text();
    Qt::CaseSensitivity cs =
            caseCheckBox->isChecked() ? Qt::CaseSensitive
                                      : Qt::CaseInsensitive;
    if(backwardChechBox->isChecked())
            emit findPrevious(text, cs);
    else emit findNext(text, cs);
}

void Dialog::enableFindButton(const QString& text)
{
    // findButton->setEnabled(!text.IsEmpty());
    findButton->setEnabled(text.size());
}

Dialog::~Dialog()
{
    delete ui;
}

