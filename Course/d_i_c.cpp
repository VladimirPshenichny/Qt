#include "d_i_c.h"

d_i_c::d_i_c(QDialog*parent) : QDialog(parent)
{
    ok = new QPushButton();
    cancel = new QPushButton();
    x = new QLabel();
    y = new QLabel();
    r = new QLabel();
    x_spin = new QSpinBox();
    y_spin = new QSpinBox();
    r_spin = new QSpinBox();
    x_layout = new QHBoxLayout();
    y_layout = new QHBoxLayout();
    r_layout = new QHBoxLayout();
    ok_layout = new QHBoxLayout();
    windows = new QVBoxLayout();
    ok->setText("Ok");
    cancel->setText("Cancel");
    x->setText("Centre on x");
    y->setText("Centre on y");
    r->setText("Radius");
    x_spin->setRange(0,1000);
    y_spin->setRange(0,1000);
    r_spin->setRange(0,500);
    x_layout->addWidget(x);
    x_layout->addWidget(x_spin);
    y_layout->addWidget(y);
    y_layout->addWidget(y_spin);
    r_layout->addWidget(r);
    r_layout->addWidget(r_spin);
    ok_layout->addWidget(ok);
    ok_layout->addWidget(cancel);
    windows->addLayout(x_layout);
    windows->addLayout(y_layout);
    windows->addLayout(r_layout);
    windows->addLayout(ok_layout);
    setLayout(windows);

    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(invertCircle()));
}
d_i_c::~d_i_c(){
    delete ok;
    delete cancel;
    delete x;
    delete y;
    delete r;
    delete x_spin;
    delete y_spin;
    delete r_spin;
    delete x_layout;
    delete y_layout;
    delete r_layout;
    delete ok_layout;
    delete windows;
}

void d_i_c::invertCircle(){
    emit invertCircle(x_spin->value(), y_spin->value(), r_spin->value());
}
