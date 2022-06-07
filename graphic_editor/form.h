#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private slots:

    void on_RverticalSlider_valueChanged(int value);

    void on_GverticalSlider_valueChanged(int value);

    void on_BverticalSlider_valueChanged(int value);

    void on_SverticalSlider_valueChanged(int value);

private:
    Ui::Form *ui;
signals:
    void signal(int value,int type);
};

#endif // FORM_H
