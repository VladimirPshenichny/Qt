#ifndef CUT_H
#define CUT_H

#include <QDialog>

namespace Ui {
class Cut;
}

class Cut : public QDialog
{
    Q_OBJECT

public:
    explicit Cut(QWidget *parent = nullptr);
    ~Cut();

private slots:
    void on_buttonBox_accepted();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_4_valueChanged(int arg1);

private:
    Ui::Cut *ui;
    int x1; int y1; int x2; int y2;
signals:
    void signal(int x1, int y1, int x2, int y2);
};

#endif // CUT_H
