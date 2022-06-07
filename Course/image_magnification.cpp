#include "image_magnification.h"

image_magnification::image_magnification(QDialog* parent) : QDialog (parent)
{
    ok = new QPushButton();
    cancel = new QPushButton();
    n = new QLabel();
    n_spin = new QSpinBox();
    n_layout = new QHBoxLayout();
    ok_layout = new QHBoxLayout();
    windows = new QVBoxLayout();
    ok->setText("Ok");
    cancel->setText("Cancel");
    n-> setText("insert the number");
    n_spin->setRange(1,10);
    ok_layout->addWidget(ok);
    ok_layout->addWidget(cancel);
    n_layout->addWidget(n);
    n_layout->addWidget(n_spin);
    windows->addLayout(n_layout);
    windows->addLayout(ok_layout);
    setLayout(windows);

    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(increase()));
}

image_magnification::~image_magnification(){
    delete ok;
    delete cancel;
    delete n;
    delete n_spin;
    delete n_layout;
    delete ok_layout;
    delete windows;
}

void image_magnification::increase(){
    emit zoom(n_spin->value());
}
