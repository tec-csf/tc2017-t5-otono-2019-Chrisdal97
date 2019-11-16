#include <QMessageBox>
#include <math.h>
#include "Poligonos.h"
#include "ui_Poligonos.h"


Poligonos::Poligonos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poligonos)
{
    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);

}

Poligonos::~Poligonos()
{
    delete ui;
}

void DrawPoligono(int Side, QPaint & Paint) {

    double radio = 100;
    double angulo = (double)360.0/(double)Side;

    int xi,yi,xf,yf;
    double val = M_PI / 180;
    angulo *= val;
    int a = 0;

    for(a = 1; a <= Side; a++) {
        xi = (radio * cos(angulo*a));
        yi = (radio * sin(angulo*a));

        xf = (radio * cos(angulo*(a+1)));
        yf = (radio * sin(angulo*(a+1)));

        Paint.drawLine(xi, yi, xf, yf);
    }
}

void Poligonos::PaintNow(QPaintNow *e)
{
    QPaint Paint(this);
    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    Paint.setPen(pointPen);

    if (dibuja) {

        QString ladosStr = ui->boxXfin->toPlainText();

        if (!ladosStr.isEmpty()) {

            int Side = ladosStr.toInt();

            for(int i=0; i<vecTrans.size(); ++i) {
                Paint.setTransform(vecTrans[i],true);
                DrawPoligono(Side, Paint);
            }
        }
    }
}

void Poligonos::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}

void Poligonos::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void Poligonos::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void Poligonos::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void Poligonos::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void Poligonos::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

void Poligonos::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}