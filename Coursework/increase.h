#ifndef INCREASE_H
#define INCREASE_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>
#include <QRadioButton>

class increase: public QDialog {
    Q_OBJECT
public:
    increase(QDialog* parent = nullptr);
    ~increase();
private:
    QLabel* text;
    QPushButton* choose_color;
    QPushButton* button_ok;
    QRadioButton* button_centre;
    QRadioButton* button_leftup;
    QRadioButton* button_rightup;
    QRadioButton* button_leftdown;
    QRadioButton* button_rightdown;
    QColor* chosen_color;
    QHBoxLayout* horizontal_lay;
    QVBoxLayout* vertical_lay;
    int point;
public slots:
    void set_color();
    void make_increase();
    void centre();
    void leftup();
    void leftdown();
    void rightup();
    void rightdown();
signals:
    void do_increase(QColor*, int);
};

#endif // INCREASE_BMP_H
