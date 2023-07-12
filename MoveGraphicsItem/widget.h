#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <Customer.h>
#include <Staff.h>
#include <Store.h>
#include "productinfo.h"
#include "paybox.h"
#include "door.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void onGenerate();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QTimer* animationTimer;
    QTimer* generatorTimer;
    QList<Place*>* places =new QList<Place*>();
    ProductInfo* info = new ProductInfo();



signals:
    void invertion();
    void coordination(QList<Place*>*);

public slots:
    void update();
    void click(QAbstractListModel* model);
};

#endif // WIDGET_H
