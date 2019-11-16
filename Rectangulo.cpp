#include <math.h>
#include "prismarec.h"
#include "ui_prismarec.h"


Rectangulo::Rectangulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Rectangulo)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Rectangulo::~Rectangulo()
{
    delete ui;
}

void Draw(QPaint & Paint){

    int medida = 45;
    int medida2 = 90;
    int medida3 = 27;

    int x0 = 0;
    int y0 = medida;
    int x1 = medida;
    int y1 = medida;
    int x2 = 0;
    int y2 = -medida2;
    int x3 = medida;
    int y3 = -medida2;

    //Cuadrado 3
    int x4 = x0 + medida3;
    int y4 = y0 - medida;
    int x5 = x1 + medida3;
    int y5 = y1 - medida;
    int x6 = x2 + medida3;
    int y6 = y2 - medida;
    int x7 = x3 + medida3;
    int y7 = y3 - medida;

    Paint.drawLine(x0,y0,x1,y1);
    Paint.drawLine(x2,y2,x3,y3);
    Paint.drawLine(x2,y2,x0,y0);
    Paint.drawLine(x3,y3,x1,y1);

    Paint.drawLine(x4,y4,x5,y5);
    Paint.drawLine(x6,y6,x7,y7);
    Paint.drawLine(x6,y6,x4,y4);
    Paint.drawLine(x7,y7,x5,y5);

    Paint.drawLine(x0,y0,x4,y4);
    Paint.drawLine(x1,y1,x5,y5);
    Paint.drawLine(x2,y2,x6,y6);
    Paint.drawLine(x3,y3,x7,y7);

}

void Rectangulo::PaintNow(QPaintEvent *e)
{
    QPaint Paint(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    Paint.setPen(pointPen);

    if(dibuja) {

        for(int i=0; i<vecTrans.size(); ++i) {
            Paint.setTransform(vecTrans[i],true);
            Draw(Paint);
        }
    }
}

void Rectangulo::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

void Rectangulo::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void Rectangulo::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void Rectangulo::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void Rectangulo::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void Rectangulo::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

void Rectangulo::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}