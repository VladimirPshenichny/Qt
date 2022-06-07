#ifndef CUT_IMAGE_H
#define CUT_IMAGE_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QColorDialog>
#include <QCheckBox>
#include "image.h"

class Cut_image : public QDialog
{
    Q_OBJECT
public:
    Cut_image(QDialog* parent = nullptr);
    ~Cut_image();

private:
    QPushButton* ok;
    QPushButton* cancel;
    QLabel* x1;
    QLabel* y1;
    QLabel* x2;
    QLabel* y2;
    QSpinBox* fir_x_spin;
    QSpinBox* fir_y_spin;
    QSpinBox* sec_x_spin;
    QSpinBox* sec_y_spin;
    QHBoxLayout* fir_layout;
    QHBoxLayout* sec_layout;
    QHBoxLayout* ok_layout;
    QVBoxLayout* windows;

public slots:
    void cut();

signals:
    void make_cut(int, int, int, int);
};

#endif // CUT_IMAGE_H
