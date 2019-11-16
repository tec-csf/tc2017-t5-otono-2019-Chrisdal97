#include "Arco.h"
#include "Ui_Arco.h"
#include <QMessageBox>
#include <math.h>

#define PI 3.14159265

Arco::Arco(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Arco)
{
    this->setFixedSize(900,600);

    ui->setupUi(this);

    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Arco::~Arco()
{
    delete ui;
}

void CirclePoint(int & x, int & y, int & angulo, QPaint & Paint) {

    int Circle = (angulo - (angulo % 45)) / 45;

    double Limite1 = tan((90.0 - (angulo % 90)) * PI / 180.0) * x;

    double Limite2 = tan((45.0 + (angulo % 45)) * PI / 180.0) * x;

    if (Circle > 0 || (Circle == 0 && y > Limite1))
        Paint.drawPoint(x,-y);
    if (Circle > 1 || (Circle == 1 && y <= Limite2))
        Paint.drawPoint(y,-x);
    if (Circle > 2 || (Circle == 2 && y > Limite1))
        Paint.drawPoint(y,x);
    if (Circle > 3 || (Circle == 3 && y <= Limite2))
        Paint.drawPoint(x,y);
    if (Circle > 4 || (Circle == 4 && y > Limite1))
        Paint.drawPoint(-x,y);
    if (Circle > 5 || (Circle == 5 && y <= Limite2))
        Paint.drawPoint(-y,x);
    if (Circle > 6 || (Circle == 6 && y > Limite1))
        Paint.drawPoint(-y,-x);
    if (Circle > 7 || (Circle == 7 && y <= Limite2))
        Paint.drawPoint(-x,-y);

}

void ArcoDraw(int angulo, int Rad, QPaint & Paint) {

    //---Dibuja por simetría en todos los octantes---
    int x = 0;
    int y = Rad;
    double p = 5.0/4.0-y;

    CirclePoint(x, y, angulo, Paint);

    do{
        if(p < 0) {
            p += 2.0 * x + 3.0;
        }
        else {
            p += 2.0 * (x - y) + 5.0;
            y--;
        }

        x++;

        CirclePoint(x, y, angulo, Paint);

    }while(y > x);

}

void Arco::PaintNow(QPaintNow *e)
{
    QPaint Paint(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    Paint.setPen(pointPen);

    if (Draw) {

        QString radioStr = ui->boxRadio->toPlainText();
        QString anguloStr = ui->boxAngulo->toPlainText();

        int angulo = anguloStr.toInt();
        int Rad = radioStr.toInt();

        if (!radioStr.isEmpty() && !anguloStr.isEmpty()) {

            for(int i=0; i<vecTrans.size(); ++i) {
                Paint.setTransform(vecTrans[i],true);
                ArcoDraw(angulo, Rad,  Paint);

            }
        }
    }
}

void Arco::on_pushButton_clicked()
{
    trans.dibujar(Draw,vecTrans,xCentro,yCentro);

    update();

}

void Arco::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void Arco::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void Arco::on_pushButton_4_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void Arco::on_pushButton_5_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void Arco::on_pushButton_6_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}

void Arco::on_pushButton_7_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}
