#include "cut.h"
#include "ui_cut.h"

Cut::Cut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cut)
{
    ui->setupUi(this);
}

Cut::~Cut()
{
    delete ui;
}

void Cut::on_buttonBox_accepted()
{
    emit(signal(x1, y1, x2, y2));
}

void Cut::on_spinBox_valueChanged(int arg1)
{
    x1 = arg1;
}

void Cut::on_spinBox_2_valueChanged(int arg1)
{
    y1 = arg1;
}

void Cut::on_spinBox_3_valueChanged(int arg1)
{
    x2 = arg1;
}

void Cut::on_spinBox_4_valueChanged(int arg1)
{
    y2 = arg1;
}
