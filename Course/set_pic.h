#ifndef SET_PIC_H
#define SET_PIC_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItemGroup>
#include <QPixmap>
#include <QPen>

class Set_Pic : public QGraphicsView {
    Q_OBJECT
public:
    explicit Set_Pic(QPixmap pixmap, QGraphicsView *parent = nullptr);
    ~Set_Pic();

private:
    QGraphicsScene *scene;
    QPoint* start_point;
    QPoint* end_point;
    QPoint* pos;
    QGraphicsItemGroup* group;
    QPixmap* pixmap_;
    QColor* line_color;
    QColor* fill_color;
    int width_line;

    int angle;

public slots:
    int updateImage(QPixmap pixmap);
};

#endif // MYGRAPHICSVIEW_H
