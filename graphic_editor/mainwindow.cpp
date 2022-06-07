#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include <QRgb>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    image = new QImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete image;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open file", QDir::currentPath(), "Images (*.png);; Image (*.jpeg);;  Image (*.jpg)");
    if (filePath.isEmpty()) {
        QMessageBox::critical(this, "Error", "Image not found.");
    } else {
        image->load(filePath);
        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*image));
        this->resize(image->size());
    }
}

void MainWindow::resizeEvent(QResizeEvent* event)
{
   QMainWindow::resizeEvent(event);
   QSize size = this->size();
   ui->graphicsView->resize(size);
}

void MainWindow::on_actionSave_triggered()
{
    bool res;
    QString savePath = QFileDialog::getSaveFileName(this, "Save file", ".", "Images (*.png);; Image (*.jpeg);;  Image (*.jpg)");
    res = image->save(savePath);
    if (res) {
        qDebug() << "Success";
    } else {
        qDebug() << "Fail";
    }
}

void MainWindow::on_actionMonochrome_triggered()
{
    ui->graphicsView->scene()->clear();
    *image = image->convertToFormat(QImage::Format_Grayscale8);
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*image));
}

void MainWindow::on_actionChange_color_triggered()
{
    form = new Form;
    form->show();
    connect(form,&Form::signal,this,&MainWindow::slot);
}

void MainWindow::slot(int Value,int type)
{

    ui->graphicsView->scene()->clear();
    for (int i = 0; i < static_cast<int>(image->height()); i++) {
        for (int j = 0; j < static_cast<int>(image->width()); j++) {
            int R = QColor(image->pixel(j,i)).red();
            int G = QColor(image->pixel(j,i)).green();
            int B = QColor(image->pixel(j,i)).blue();
            int S = QColor(image->pixel(j,i)).saturation();
            switch (type)
            {
            case 1:
                R = Value;
                break;
            case 2:
                G = Value;
                break;
            case 3:
                B = Value;
                break;
            case 4:
                S = Value;
                break;
            default:
                break;
            }
            image->setPixelColor(j,i,QColor(R,G,B,S));
        }
    }
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*image));
}

void MainWindow::on_actionCut_image_triggered()
{
    cut = new Cut;
    cut->show();
    connect(cut, &Cut::signal, this, &MainWindow::slot2);
}

void MainWindow::slot2(int x1, int y1, int x2, int y2)
{
    if((y1<y2) || (x2<x1)){
        QMessageBox err;
        err.setWindowTitle("ERROR");
        err.setText("wrong boundaries");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        return;
    }
    else{
        if((y2 <= static_cast<int>(image->height())) && (x2 <= static_cast<int>(image->width()))){
            for(int i=0; i<=x2-x1; i++){
                int k = 0;
                for(int j=0;j <= y1-y2; j++){
                    QColor(image->pixel(j,i)) = QColor(image->pixel(y1-k, x1+i));
                    k++;
                }
            }
            QImage rez = image->copy(0, 0, x2-x1, y1-y2);
            image = &rez;
            ui->graphicsView->scene()->clear();
            ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*image));
        }
        else{
           QMessageBox err;
           err.setWindowTitle("ERROR");
           err.setText("values ​​are outside the picture");
           err.setIcon(QMessageBox::Critical);
           err.exec();
           return;
        }
    }
}

void MainWindow::on_actionColor_palette_triggered()
{
    int x, y;
    int contains;
    int counter = 0;
    int monochrome = 0;
    int size = image->width() *image->height();
    QColor color[6];
    while (counter !=5 && monochrome < size) {
        contains = 0;
        monochrome +=1;
        x = rand() % image->width();
        y = rand() % image->height();
        for (int i = 0; i < counter; i++) {
            if (image->pixelColor(x, y) == color[i])
                contains = 1;
        }
        if (contains == 0) {
            color[counter] = image->pixelColor(x, y);
            counter++;
        }
    }
    if(monochrome < size){
        QStringList name_color = color->colorNames();
        QMessageBox msgBox;
        msgBox.setWindowTitle("Color palette consists of the following colors:");
        msgBox.setText(name_color[1] + ", " + name_color[2] + ", " + name_color[3] + ", " + name_color[4] + ", " + name_color[5] + ", " + name_color[0] + " .");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.exec();
    }
    else{
        QMessageBox err;
        err.setWindowTitle("ERROR");
        err.setText("Image is monochrome");
        err.setIcon(QMessageBox::Critical);
        err.exec();
        return;
    }
}
