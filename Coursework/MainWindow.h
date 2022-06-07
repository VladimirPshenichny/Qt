#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "increase.h"
#include "decrease.h"
#include "inversion.h"
#include "line.h"
#include "monochrome.h"
#include "myBMP.h"
#include <QBoxLayout>
#include <QPixmap>
#include <QFileDialog>
#include <QFile>
#include <QTextBrowser>
#include <QMessageBox>
#include <QDebug>
#include <QSize>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_open_my_file_triggered();

    void on_inversion_triggered();

    void on_monochrome_triggered();

    void on_actionReset_triggered();

    void on_increase_triggered();

    void on_decrease_triggered();

    void on_line_triggered();

private:
    Ui::MainWindow *ui;
    MyImage* img;
    QString filename;
};

#endif // MAINWINDOW_H
