#ifndef IMAGE_MAGNIFICATION_H
#define IMAGE_MAGNIFICATION_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QColorDialog>
#include <QCheckBox>
#include "image.h"

class image_magnification : public QDialog
{
    Q_OBJECT
public:
    image_magnification(QDialog* parent = nullptr);
    ~image_magnification();

private:
    QPushButton* ok;
    QPushButton* cancel;
    QLabel* n;
    QSpinBox* n_spin;
    QHBoxLayout* n_layout;
    QHBoxLayout* ok_layout;
    QVBoxLayout* windows;

public slots:
    void increase();

signals:
    void zoom(int);
};

#endif // IMAGE_MAGNIFICATION_H
