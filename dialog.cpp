#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    thread = new TimerThread(this);

    connect(thread, SIGNAL(updateSec(QString)), this, SLOT(updateJam(QString)));

    thread->setSecs(125);
    thread->start();
    thread->run();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateJam(QString jam){
    ui->label->setText(jam);
}
