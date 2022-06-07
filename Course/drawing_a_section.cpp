#include "drawing_a_section.h"
#include <QMessageBox>

drawing_a_section::drawing_a_section(QDialog*parent) : QDialog(parent)
{
    ok = new QPushButton();
    cancel = new QPushButton();
    acolor = new QPushButton();
    x1 = new QLabel();
    y1 = new QLabel();
    x2 = new QLabel();
    y2 = new QLabel();
    r = new QLabel();
    fir_x_spin = new QSpinBox();
    fir_y_spin = new QSpinBox();
    sec_x_spin = new QSpinBox();
    sec_y_spin = new QSpinBox();
    r_spin = new QSpinBox();
    c_color = new QColor;
    fir_layout = new QHBoxLayout();
    sec_layout = new QHBoxLayout();
    r_layout = new QHBoxLayout();
    ok_layout = new QHBoxLayout();
    windows = new QVBoxLayout();
    ok->setText("Ok");
    cancel->setText("Cancel");
    acolor->setText("Choose color");
    c_color->setRgb(0, 0, 0);
    x1->setText("left x");
    y1->setText("left y");
    x2->setText("right x");
    y2->setText("right y");
    r->setText("width");
    fir_x_spin->setRange(0,10000);
    fir_y_spin->setRange(0,10000);
    sec_x_spin->setRange(0,10000);
    sec_y_spin->setRange(0,10000);
    r_spin->setRange(0,1000);
    fir_layout->addWidget(x1);
    fir_layout->addWidget(fir_x_spin);
    fir_layout->addWidget(y1);
    fir_layout->addWidget(fir_y_spin);
    sec_layout->addWidget(x2);
    sec_layout->addWidget(sec_x_spin);
    sec_layout->addWidget(y2);
    sec_layout->addWidget(sec_y_spin);
    r_layout->addWidget(r);
    r_layout->addWidget(r_spin);
    ok_layout->addWidget(ok);
    ok_layout->addWidget(cancel);
    windows->addLayout(fir_layout);
    windows->addLayout(sec_layout);
    windows->addLayout(r_layout);
    windows->addWidget(acolor);
    windows->addLayout(ok_layout);
    setLayout(windows);

    connect(cancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(close()));
    connect(ok, SIGNAL(clicked()), this, SLOT(line()));
    connect(acolor, SIGNAL(clicked()), this, SLOT(change_color()));
}
drawing_a_section::~drawing_a_section(){
    delete ok;
    delete cancel;
    delete acolor;
    delete x1;
    delete y1;
    delete x2;
    delete y2;
    delete r;
    delete fir_x_spin;
    delete fir_y_spin;
    delete sec_x_spin;
    delete sec_y_spin;
    delete r_spin;
    delete fir_layout;
    delete sec_layout;
    delete r_layout;
    delete ok_layout;
    delete windows;
}

void drawing_a_section::change_color(){
    *c_color = QColorDialog::getColor();
}

void drawing_a_section::line(){
    emit d_a_s(fir_x_spin->value(), fir_y_spin->value(), sec_x_spin->value(), sec_y_spin->value(), r_spin->value(), c_color);
}
