#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <circles.h>
#include <MoveItem.h>

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
    //QList<MoveItem*> moveItems;

signals:
    void invertion();
    void coordination(int *xcoords, int *coords);

public slots:
    void update(int adx,int ady,int id
                );

};

#endif // WIDGET_H
