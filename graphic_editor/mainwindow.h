#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include "form.h"
#include "cut.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void resizeEvent(QResizeEvent* event);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionMonochrome_triggered();

    void on_actionChange_color_triggered();

    void on_actionCut_image_triggered();

    void slot(int value,int type);

    void slot2(int x1, int y1, int x2, int y2);


    void on_actionColor_palette_triggered();

private:
    Ui::MainWindow *ui;
    QImage* image;
    Form *form;
    Cut *cut;

protected:
    //void pointEvent(QPaintEvent*) override;
    //Image *image;
};

#endif // MAINWINDOW_H
