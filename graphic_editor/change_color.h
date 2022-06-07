#ifndef CHANGE_COLOR_H
#define CHANGE_COLOR_H

#include <QDialog>
#include <QBoxLayout>
#include <QPushButton>
#include <QRadioButton>
#include <QSlider>
#include <QLabel>
#include <QLCDNumber>


class Change_color : public QDialog {
    Q_OBJECT
public:
    Change_color(QDialog *parent = nullptr);
    ~Change_color();

private:
    QPushButton* cancel;
    QHBoxLayout *horizontal_layout;
    QVBoxLayout *vertical_layout;
    QHBoxLayout *horizontal_layout2;
    QRadioButton* red;
    QRadioButton* green;
    QRadioButton* blue;
    QSlider* slider;
    QPushButton* ok;
    QLCDNumber* value;
    int color;

public slots:
    void rgb_mod();
    void red_c();
    void green_c();
    void blue_c();

signals:
    void change_rgb(int, int);
};


#endif // CHANGE_COLOR_H
