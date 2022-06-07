#ifndef DRAWING_A_SECTION_H
#define DRAWING_A_SECTION_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QColorDialog>
#include <QCheckBox>
#include "image.h"

class drawing_a_section : public QDialog
{
    Q_OBJECT
public:
    drawing_a_section(QDialog* parent = nullptr);
    ~drawing_a_section();

private:
    QPushButton* ok;
    QPushButton* cancel;
    QPushButton* acolor;
    QLabel* x1;
    QLabel* y1;
    QLabel* x2;
    QLabel* y2;
    QLabel* r;
    QSpinBox* fir_x_spin;
    QSpinBox* fir_y_spin;
    QSpinBox* sec_x_spin;
    QSpinBox* sec_y_spin;
    QSpinBox* r_spin;
    QColor* c_color;
    QHBoxLayout* fir_layout;
    QHBoxLayout* sec_layout;
    QHBoxLayout* r_layout;
    QHBoxLayout* ok_layout;
    QVBoxLayout* windows;

public slots:
    void change_color();
    void line();

signals:
    void d_a_s(int, int, int, int, int, QColor*);
};

#endif // DRAWING_A_SECTION_H
