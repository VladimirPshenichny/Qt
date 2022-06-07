#include "inversion.h"
#include <iostream>

inversion::inversion(QDialog* parent): QDialog(parent)
{
    setWindowTitle("Inversion");
    ok = new QPushButton;
    ok->setText("OK");
    label = new QLabel;
    label->setText("Введите координаты левой верхней точки и нижней правой");
    label_1x = new QLabel;
    label_1x->setText("Координаты левого верхнего по x");
    label_1y = new QLabel;
    label_1y->setText("Координаты левого верхнего по y");
    label_2x = new QLabel;
    label_2x->setText("Координаты правого нижнего по x");
    label_2y = new QLabel;
    label_2y->setText("Координаты правого нижнего по y");

    coord_1x = new QSpinBox;
    coord_1x->setRange(0, 10000);
    coord_1x->setSingleStep(5);
    coord_1y = new QSpinBox;
    coord_1y->setRange(0, 10000);
    coord_1y->setSingleStep(5);
    coord_2x = new QSpinBox;
    coord_2x->setRange(0, 10000);
    coord_2x->setSingleStep(5);
    coord_2y = new QSpinBox;
    coord_2y->setRange(0, 10000);
    coord_2y->setSingleStep(5);

    box_1x = new QHBoxLayout;
    box_1x->addWidget(label_1x);
    box_1x->addWidget(coord_1x);
    box_1y = new QHBoxLayout;
    box_1y->addWidget(label_1y);
    box_1y->addWidget(coord_1y);
    box_2x = new QHBoxLayout;
    box_2x->addWidget(label_2x);
    box_2x->addWidget(coord_2x);
    box_2y = new QHBoxLayout;
    box_2y->addWidget(label_2y);
    box_2y->addWidget(coord_2y);
    lay = new QVBoxLayout;
    lay->addWidget(label);
    lay->addLayout(box_1x);
    lay->addLayout(box_1y);
    lay->addLayout(box_2x);
    lay->addLayout(box_2y);
    lay->addWidget(ok);
    setLayout(lay);

    connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(do_inverse()));
}

inversion::~inversion()
{
    delete label;
    delete label_1x;
    delete label_1y;
    delete label_2x;
    delete label_2y;
    delete coord_1x;
    delete coord_1y;
    delete coord_2x;
    delete coord_2y;
    delete box_1x;
    delete box_1y;
    delete box_2x;
    delete box_2y;
    delete lay;
    delete ok;
}

void inversion::do_inverse()
{
    emit change_inversation(coord_1x->value(), coord_1y->value(), coord_2x->value(), coord_2y->value());
}

