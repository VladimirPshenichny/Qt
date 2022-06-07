#include "MainWindow.h"
//"Clear", "Run qmake"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    img = new MyImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete img;
}

void MainWindow::on_inversion_triggered()
{
    ui->statusBar->showMessage("Вы выбрали функцию №1 - инверсия цвета");

    inversion* inverse = new inversion;
    connect(inverse, SIGNAL(change_inversation(int, int, int, int)), img, SLOT(inversion(int, int, int, int)));
    inverse->exec();
    delete inverse;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_monochrome_triggered() {
    ui->statusBar->showMessage("Вы выбрали функцию №2 - черно-белый фильтр");

    monochrome* blackWhite = new monochrome;
    connect(blackWhite, SIGNAL(change_monochrome(int, int, int, int)), img, SLOT(monochrome(int, int, int, int)));
    blackWhite->exec();
    delete blackWhite;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_open_my_file_triggered() {
    filename = QFileDialog::getOpenFileName(this,
                tr("Inversion"), "C:\\programming\\2019-1 course, 2 sem\\CourseWork\\city.bmp"
                );
    QPixmap pix(filename);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    int error;
    error = img->loadimage(filename.toUtf8());
    if (error != 1) {
        QMessageBox::critical(this, "ERROR", "Not available format");
    }
}

void MainWindow::on_actionReset_triggered() {
    QPixmap pix(filename);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
    img->resetimage(filename.toUtf8());
}

void MainWindow::on_increase_triggered() {
    increase *color = new increase();
    connect(color, SIGNAL(do_increase(QColor*, int)), img, SLOT(increase(QColor*, int)));
    color->exec();
    delete color;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_decrease_triggered() {
    decrease* reduct = new decrease();
    connect(reduct, SIGNAL(do_decrease(int)), img, SLOT(decrease(int)));
    reduct->exec();
    delete reduct;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}

void MainWindow::on_line_triggered() {
    line *l = new line;
    connect(l, SIGNAL(make_line(int, int, int, int, QColor*)), img, SLOT(line(int, int, int, int, int, QColor*)));
    l->exec();
    delete l;

    QString f = "D://out.bmp";
    QPixmap pix(f);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}
