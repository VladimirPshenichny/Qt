#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    image = new Image();

    vertical_layout = new QVBoxLayout;
    horizontal_layout = new QHBoxLayout;
    central_widget = new QWidget;

    picture = new Set_Pic(image->getPixMap());
    vertical_layout->addLayout(horizontal_layout);
    vertical_layout->addWidget(picture);
    central_widget->setLayout(vertical_layout);
    draw_i_c = new d_i_c();
    cut_i = new Cut_image();
    draw_a_s = new drawing_a_section();
    zoom = new image_magnification();
    setCentralWidget(central_widget);
    connect(image, SIGNAL(changed(QPixmap)), picture, SLOT(updateImage(QPixmap)));
    connect(image, SIGNAL(size_error()), this, SLOT(size_error_dialog()));
    connect(draw_i_c, SIGNAL(invertCircle(int, int, int)), image, SLOT(invertCircle(int, int, int)));
    connect(cut_i, SIGNAL(make_cut(int, int, int, int)), image, SLOT(cutter(int, int, int, int)));
    connect(draw_a_s, SIGNAL(d_a_s(int, int, int, int, int, QColor*)), image, SLOT(draw(int, int, int, int, int, QColor*)));
    connect(zoom, SIGNAL(zoom(int)),image, SLOT(gain(int)));
}

MainWindow::~MainWindow() {
    delete ui;
    delete image;
    delete picture;
    delete horizontal_layout;
    delete vertical_layout;
    delete central_widget;
}


void MainWindow::on_actionOpen_triggered() {
    int error;
    QString name = QFileDialog::getOpenFileName(nullptr, "Open file", "", "*.bmp");
    if (!name.isNull()) {
        error = image->open_file(name.toUtf8());
        if (error == 0) {
            picture->updateImage(image->getPixMap());
        }
        else {
            QMessageBox::critical(this, "ERROR", "Not available format");
        }
    }
}

void MainWindow::on_actionSave_triggered()
{
    int error;
    QString name = QFileDialog::getSaveFileName();
    if (!name.isNull()) {
        error = image->save_file(name.toUtf8() + ".bmp");
        if (error != 0) {
            QMessageBox::critical(this, "ERROR", "Failed to save file");
        }
    }
}

void MainWindow::on_actionCreate_triggered()
{
    image->createImage();
    picture->updateImage(image->getPixMap());
}


void MainWindow::size_error_dialog() {
    QMessageBox::critical(this, "ERROR", "Inconsistency in size and width");
}

void MainWindow::on_actionDraw_invert_circle_triggered(){
    draw_i_c->exec();
}

void MainWindow::on_actionCut_image_triggered(){
    cut_i->exec();
}

void MainWindow::on_actionDraw_a_section_triggered(){
    draw_a_s->exec();
}

void MainWindow::on_actionImage_magnification_triggered(){
    zoom->exec();
}

void MainWindow::on_actionaAuthor_triggered(){
    QMessageBox::information(this, "Author", "Author : Pshenichny Vladimir");
}

void MainWindow::on_actionAbout_file_triggered(){
    int ver = 0;
    switch (static_cast<int>(image->b_h.bfOffBits)) {
    case 58:
        ver = 3;
        break;
    case 126:
        ver = 4;
        break;
    case 142:
        ver = 5;
        break;
    }

    QMessageBox::information(this,"File Info", QString("Rezolution : %1 x %2 \nSize : %3 byte \nVersion : %4 \nBit depth : 24")
                             .arg(static_cast<int>(image->b_i.biWidth))
                             .arg(static_cast<int>(image->b_i.biHeight))
                             .arg(static_cast<int>(image->b_h.bfSize))
                             .arg(ver));
}

void MainWindow::on_actionHelp_triggered(){
    QDesktopServices::openUrl(QUrl("info.html"));
}




