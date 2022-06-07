#ifndef INVERSIONN_H
#define INVERSIONN_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLayout>
#include <QSpinBox>
#include <QPushButton>

class inversion: public QDialog {
    Q_OBJECT
public:
    inversion(QDialog* parent = nullptr);
    ~inversion();
private:
    QPushButton* ok;
    QLabel* label;
    QLabel* label_1x;
    QLabel* label_1y;
    QLabel* label_2x;
    QLabel* label_2y;

    QSpinBox* coord_1x;
    QSpinBox* coord_1y;
    QSpinBox* coord_2x;
    QSpinBox* coord_2y;

    QHBoxLayout* box_1x;
    QHBoxLayout* box_1y;
    QHBoxLayout* box_2x;
    QHBoxLayout* box_2y;
    QVBoxLayout* lay;
signals:
    void change_inversation(int, int, int, int);
public slots:
    void do_inverse();
};

#endif // INVERSIONN_H
