#include "widget.h"
#include "ui_widget.h"
#include "iostream"
#include <QString>
#include <QByteArray>
#include <QTextStream>
#include <QDebug>


/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high)
{
    return (rand() % ((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Косметическая подготовка приложения
    this->resize(700,700);          // Устанавливаем размеры окна приложения
    this->setFixedSize(1440,920);

    scene = new QGraphicsScene(this);   // Инициализируем графическую сцену
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); // настраиваем индексацию элементов

    ui->graphicsView->resize(800,800);  // Устанавливаем размер graphicsView
    ui->graphicsView->setScene(scene);  // Устанавливаем графическую сцену в graphicsView
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    scene->setSceneRect(0,0,700,700); // Устанавливаем размер сцены

    scene->addRect(-50,-50,800,7,QPen(Qt::NoPen),QBrush(Qt::darkGray));
    scene->addRect(-50,-50,7,800,QPen(Qt::NoPen),QBrush(Qt::darkGray));
    scene->addRect(-50,743,800,7,QPen(Qt::NoPen),QBrush(Qt::darkGray));
    scene->addRect(743,-50,7,800,QPen(Qt::NoPen),QBrush(Qt::darkGray));

    scene->addRect(260,-50,200,50,QPen(Qt::NoPen),QBrush(Qt::darkGray));

    info->filereader();

    int cord=30;
    int numbers[2][4]
    {
        {1,3,5,7},
        {2,4,6,8},
    };
    for(int count=0;count<2;count++)
    {
        Store *item = new Store(info);        // Создаём графический элемент
        for (int g=0;g<4;g++)
        {
            item->putGoods(numbers[count][g],10);
        }
        connect(this,&Widget::invertion,item,&Store::slot);
        item->setPos(cord,150);// Устанавливаем случайную позицию элемента
        scene->addItem(item);   // Добавляем элемент на графическую сцену
        places->append(item);
        cord+=650;
        connect(item,&Store::click,this,&Widget::click);
    }

    Paybox* paybox= new Paybox;
    paybox->setPos(480,650);
    scene->addItem(paybox);
    places->append(paybox);

    Door* exit= new Door;
    exit->setPos(700,600);
    scene->addItem(exit);
    places->append(exit);


    animationTimer = new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    animationTimer->start(1000/60);

    generatorTimer = new QTimer(this);
    connect(generatorTimer,SIGNAL(timeout()),this,SLOT(onGenerate()));
    generatorTimer->start(6000);

    Staff *v = new Staff();
    v->setPos(0,650);
    scene->addItem(v);
    connect(this,&Widget::coordination,v,&Staff::look);
    emit coordination(this->places);
}

Widget::~Widget()
{
    emit coordination(this->places);
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    emit invertion();
    emit coordination(this->places);
}

void Widget::on_pushButton_2_clicked()
{

}

void Widget::update()
{

}

void Widget::click(QAbstractListModel *model)
{
    ui->listView->setModel(model);
}

void Widget::onGenerate()
{
    //scene->addItem(new Customer());
    Customer *c = new Customer(this->info);
    c->setPos(350,0);
    scene->addItem(c);   // Добавляем элемент на графическую сцену
    connect(this,&Widget::coordination,c,&Customer::look);
    connect(this,&Widget::invertion,c,&Customer::reverse);
    connect(c,&Customer::click,this,&Widget::click);

    emit coordination(this->places);
}

