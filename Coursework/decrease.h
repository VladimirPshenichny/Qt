#ifndef DECREASE_H
#define DECREASE_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QLayout>
#include <QColorDialog>
#include <QRadioButton>

class decrease: public QDialog {
    Q_OBJECT
public:
    decrease(QDialog* parent = nullptr);
    ~decrease();
private:
    QLabel* text;
    QPushButton* button_ok;
    QRadioButton* button_centre;
    QRadioButton* button_leftup;
    QRadioButton* button_rightup;
    QRadioButton* button_leftdown;
    QRadioButton* button_rightdown;
    QVBoxLayout* vertical_lay;
    int point;
public slots:
    void make_decrease();
    void centre();
    void leftup();
    void leftdown();
    void rightup();
    void rightdown();
signals:
    void do_decrease(int);
};

#endif // REDUCTION_BMP_H
