#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "set_pic.h"
#include <QBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QTextBrowser>
#include <QMessageBox>
#include "d_i_c.h"
#include <QDesktopServices>
#include <QInputDialog>
#include <cut_image.h>
#include <drawing_a_section.h>
#include <image_magnification.h>

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
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCreate_triggered();

    void size_error_dialog();

    void on_actionDraw_invert_circle_triggered();

    void on_actionaAuthor_triggered();

    void on_actionAbout_file_triggered();

    void on_actionHelp_triggered();

    void on_actionCut_image_triggered();

    void on_actionDraw_a_section_triggered();

    void on_actionImage_magnification_triggered();

private:
    Ui::MainWindow *ui;
    Set_Pic* picture;
    Image *image;
    QHBoxLayout *horizontal_layout;
    QVBoxLayout *vertical_layout;
    QWidget *central_widget;
    QPixmap stdPixmap;
    d_i_c* draw_i_c;
    Cut_image* cut_i;
    drawing_a_section* draw_a_s;
    image_magnification* zoom;
};

#endif // MAINWINDOW_H
