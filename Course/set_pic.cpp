#include "set_pic.h"

Set_Pic::Set_Pic(QPixmap pixmap, QGraphicsView *parent) : QGraphicsView(parent) {
    start_point = new QPoint;
    end_point = new QPoint;
    pos = new QPoint;
    pixmap_ = new QPixmap;
    *pixmap_ = pixmap;
    group = new QGraphicsItemGroup;

    line_color = new QColor;
    fill_color = new QColor;

    this->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, pixmap_->width(), pixmap_->height());
    scene->addPixmap(pixmap);
    setScene(scene);
    scene->addItem(group);
}

Set_Pic::~Set_Pic() {
    delete group;
    delete pos;
    delete start_point;
    delete end_point;
    delete pixmap_;
    delete scene;
    delete line_color;
    delete fill_color;
}

int Set_Pic::updateImage(QPixmap pixmap) {
    scene->removeItem(group);
    scene->clear();
    *pixmap_ = pixmap;
    scene->setSceneRect(0, 0, pixmap.width(), pixmap.height());
    scene->addPixmap(pixmap);
    scene->addItem(group);
    return 0;
}
