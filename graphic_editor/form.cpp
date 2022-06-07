#include "form.h"
#include "ui_form.h"
#include <QDebug>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

//R
void Form::on_RverticalSlider_valueChanged(int value)
{
    int type = 1;
    emit(signal(value,type));
}
//G
void Form::on_GverticalSlider_valueChanged(int value)
{
    int type = 2;
    emit(signal(value,type));
}
//B
void Form::on_BverticalSlider_valueChanged(int value)
{
    int type = 3;
    emit(signal(value,type));
}

void Form::on_SverticalSlider_valueChanged(int value)
{
    int type = 4;
    emit(signal(value,type));
}
