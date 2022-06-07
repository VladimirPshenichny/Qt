#include "change_color.h"

Change_color::Change_color(QDialog *parent) : QDialog(parent) {
    setFixedSize(250, 150);
    setWindowTitle("RGB component");

    ok = new QPushButton;
    ok->setText("Ok");
    cancel = new QPushButton;
    cancel->setText("Cancel");

    red = new QRadioButton;
    red->setText("Red");
    red->setChecked(true);
    green = new QRadioButton;
    green->setText("Green");
    blue = new QRadioButton;
    blue->setText("Blue");
    color = 1;

    slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 255);
    slider->setValue(0);
    value = new QLCDNumber(3);

    horizontal_layout = new QHBoxLayout;
    vertical_layout = new QVBoxLayout;
    horizontal_layout2 = new QHBoxLayout;
    horizontal_layout->addWidget(ok);
    horizontal_layout->addWidget(cancel);
    horizontal_layout2->addWidget(red);
    horizontal_layout2->addWidget(green);
    horizontal_layout2->addWidget(blue);
    vertical_layout->addLayout(horizontal_layout2);
    vertical_layout->addWidget(value);
    vertical_layout->addWidget(slider);
    vertical_layout->addLayout(horizontal_layout);
    setLayout(vertical_layout);

    connect(slider, SIGNAL(valueChanged(int)), value, SLOT(display(int)));
    connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(rgb_mod()));
    connect(red, SIGNAL(pressed()), this, SLOT(red_c()));
    connect(green, SIGNAL(pressed()), this, SLOT(green_c()));
    connect(blue, SIGNAL(pressed()), this, SLOT(blue_c()));
}


Change_color::~Change_color() {
    delete ok;
    delete cancel;
    delete red;
    delete green;
    delete blue;
    delete slider;
    delete value;
    delete horizontal_layout;
    delete horizontal_layout2;
    delete vertical_layout;
}


void Change_color::rgb_mod() {
    emit change_rgb(color, value->intValue());
}

void Change_color::red_c() {
    this->color = 1;
}


void Change_color::green_c() {
    this->color = 2;
}


void Change_color::blue_c() {
    this->color = 3;
}
