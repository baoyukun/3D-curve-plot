#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
       ui->setupUi(this);

       QFont myFont("Times",20);
       QFile file("data.txt");
       QVector<double> x(0),y(0),z(0),t(0);
       char buf[1000];
       double x1,x2,x3,x4;

       file.open(QIODevice::ReadOnly);
       sscanf(buf,"%lf %lf %lf %lf",&x1,&x2,&x3,&x4);
       x.fill(x1); y.fill(x2); z.fill(x3); t.fill(x4);

       while (!file.atEnd())
       {
           file.readLine(buf,sizeof(buf));
           sscanf(buf,"%lf %lf %lf %lf",&x1,&x2,&x3,&x4);
           x.append(x1); y.append(x2); z.append(x3); t.append(x4);
       }
       file.close();

       ui->touying1->addGraph();
       ui->touying1->graph(0)->setData(t,x);
       ui->touying1->xAxis->setLabel("t");
       ui->touying1->yAxis->setLabel("X");
       ui->touying1->xAxis->setLabelFont(myFont);
       ui->touying1->yAxis->setLabelFont(myFont);
       ui->touying1->rescaleAxes();

       ui->touying2->addGraph();
       ui->touying2->graph(0)->setData(t,y);
       ui->touying2->xAxis->setLabel("t");
       ui->touying2->yAxis->setLabel("Y");
       ui->touying2->xAxis->setLabelFont(myFont);
       ui->touying2->yAxis->setLabelFont(myFont);
       ui->touying2->rescaleAxes();

       ui->touying3->addGraph();
       ui->touying3->graph(0)->setData(t,z);
       ui->touying3->xAxis->setLabel("t");
       ui->touying3->yAxis->setLabel("Z");
       ui->touying3->xAxis->setLabelFont(myFont);
       ui->touying3->yAxis->setLabelFont(myFont);
       ui->touying3->rescaleAxes();

       ui->widget->setData(x,y,z);
       ui->widget->show();
}

Widget::~Widget()
{
    delete ui;
}
