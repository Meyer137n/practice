#include "widget.h"
#include "ui_widget.h"
#include "iostream"


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

    int cord=30;
    for(int count=0;count<2;count++)
    {
        MoveItem *item = new MoveItem();        // Создаём графический элемент
        connect(this,&Widget::invertion,item,&MoveItem::slot);
        ycor[count] = 150;
        xcor[count] = cord;
        item->setPos(xcor[count],ycor[count]);// Устанавливаем случайную позицию элемента
        scene->addItem(item);   // Добавляем элемент на графическую сцену
        // //moveItems->append(item);
        cord+=650;
        //connect(item,&MoveItem::update,this,&Widget::update);
    }

    animationTimer = new QTimer(this);
    connect(animationTimer,SIGNAL(timeout()),scene,SLOT(advance()));
    animationTimer->start(1000/60);

    /*generatorTimer = new QTimer(this);
    connect(generatorTimer,SIGNAL(timeout()),this,SLOT(onGenerate()));
    generatorTimer->start(1000);

    scene->addItem(new Circles(scene->sceneRect().width()));*/

}

Widget::~Widget()
{
    emit coordination(xcor, ycor);
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    emit invertion();
    emit coordination(xcor, ycor);
}

void Widget::on_pushButton_2_clicked()
{


    Circles *c = new Circles(scene->sceneRect().width());
    scene->addItem(c);   // Добавляем элемент на графическую сцену

    connect(this,&Widget::coordination,c,&Circles::look);
    connect(this,&Widget::invertion,c,&Circles::reverse);
    emit coordination(xcor, ycor);


}

void Widget::update(int adx, int ady,int id)
{
    xcor[id]=adx;
    ycor[id]=ady;
    for (int i = 0; i<2 ; i++)
    {
        cout<<"\n";
            cout << " " << xcor[id] << " " << ycor[id];
    }
    cout<<"\n";
}

void Widget::onGenerate()
{
    scene->addItem(new Circles(scene->sceneRect().width()));
}
