#ifndef LINE_H
#define LINE_H

#include <QDialog>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QColor>
#include <QLayout>
#include <QColorDialog>
#include <QRadioButton>

class line: public QDialog{
    Q_OBJECT
public:
    line(QDialog *parent = nullptr);
    ~line();
private:
    QPushButton *ok;
    QPushButton* choose_color;
    QColor* chosen_color;
    QLabel *label;
    QLabel *label_1x;
    QLabel *label_1y;
    QLabel *label_2x;
    QLabel *label_2y;
    QLabel *label_width;

    QSpinBox *coord_1x;
    QSpinBox *coord_1y;
    QSpinBox *coord_2x;
    QSpinBox *coord_2y;
    QSpinBox *width;

    QHBoxLayout *box_1x;
    QHBoxLayout *box_1y;
    QHBoxLayout *box_2x;
    QHBoxLayout *box_2y;
    QHBoxLayout *box_width;
    QVBoxLayout *lay;

signals:
    void make_line(int, int, int, int, int, QColor*);

public slots:
    void set_color();
    void do_line();
};
#endif // LINE_H
