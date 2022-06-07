#include "decrease.h"

decrease::decrease(QDialog* parent) : QDialog(parent)
{
    point = 0;
    text = new QLabel;
    text->setText("Выберите точку, относительно которой будет будет производиться действие");
    button_ok = new QPushButton;
    button_ok->setText("OK");

    button_centre = new QRadioButton;
    button_centre->setText("Центр");
    button_centre->setChecked(true);
    button_leftup = new QRadioButton;
    button_leftup->setText("Левая верхняя");
    button_rightup = new QRadioButton;
    button_rightup->setText("Правая верхняя");
    button_leftdown = new QRadioButton;
    button_leftdown->setText("Левая нижняя");
    button_rightdown = new QRadioButton;
    button_rightdown->setText("Правая нижняя");

    vertical_lay = new QVBoxLayout;
    vertical_lay->addWidget(text);
    vertical_lay->addWidget(button_centre);
    vertical_lay->addWidget(button_rightup);
    vertical_lay->addWidget(button_rightdown);
    vertical_lay->addWidget(button_leftup);
    vertical_lay->addWidget(button_leftdown);
    vertical_lay->addWidget(button_ok);
    setLayout(vertical_lay);

    connect(button_ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(button_centre, SIGNAL(pressed()), this, SLOT(centre()));
    connect(button_leftup, SIGNAL(pressed()), this, SLOT(leftup()));
    connect(button_leftdown, SIGNAL(pressed()), this, SLOT(leftdown()));
    connect(button_rightup, SIGNAL(pressed()), this, SLOT(rightup()));
    connect(button_rightdown, SIGNAL(pressed()), this, SLOT(rightdown()));
    connect(button_ok, SIGNAL(clicked()), this, SLOT(make_decrease()));
}

decrease::~decrease(){
    delete text;
    delete button_ok;
    delete vertical_lay;
    delete button_centre;
    delete button_leftup;
    delete button_rightup;
    delete button_leftdown;
    delete button_rightdown;
}

void decrease::centre()
{
    point = 0;
}

void decrease::leftup()
{
    point = 1;
}

void decrease::leftdown()
{
    point = 2;
}

void decrease::rightup()
{
    point = 3;
}

void decrease::rightdown()
{
    point = 4;
}

void decrease::make_decrease()
{
    emit do_decrease(point);
}
