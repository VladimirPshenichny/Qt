#ifndef D_I_C_H
#define D_I_C_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QColorDialog>
#include <QCheckBox>
#include "image.h"

class d_i_c : public QDialog
{
    Q_OBJECT
public:
    d_i_c(QDialog* parent = nullptr);
    ~d_i_c();

private:
    QPushButton* ok;
    QPushButton* cancel;
    QLabel* x;
    QLabel* y;
    QLabel* r;
    QSpinBox* x_spin;
    QSpinBox* y_spin;
    QSpinBox* r_spin;
    QHBoxLayout* x_layout;
    QHBoxLayout* y_layout;
    QHBoxLayout* r_layout;
    QHBoxLayout* ok_layout;
    QVBoxLayout* windows;

public slots:
    void invertCircle();

signals:
    void invertCircle(int, int, int);
};

#endif // D_I_C_H
