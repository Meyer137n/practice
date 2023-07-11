#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <Customer.h>
#include <Staff.h>
#include <Store.h>

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
    int count=0;
    int xcor[2];
    int ycor[2];
    QList<Store*>* stores =new QList<Store*>();

signals:
    void invertion();
    void coordination(QList<Store*>* stores);

public slots:
    void update(int adx,int ady,int id);

};

#endif // WIDGET_H
