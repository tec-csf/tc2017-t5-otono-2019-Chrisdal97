#include "math.h"
#include "cono.h"
#include "ui_cono.h"


Cono::Cono(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cono)
{

    this->setFixedSize(900,600);
    ui->setupUi(this);
    xCentro = 450.0;
    yCentro = 300.0;
    QTransform center;
    center.translate(xCentro,yCentro);
    vecTrans.push_back(center);
}

Cono::~Cono()
{
    delete ui;
}


void PuntoElipse(double & centroX, double & centroY, int & x, int & y, int & i, QPaint & Paint) {

    Paint.drawPoint(centroX+x,centroY+y);

    i+=2;

    Paint.drawPoint(centroX-x,centroY+y);
    Paint.drawPoint(centroX+x,centroY-y);
    Paint.drawPoint(centroX-x,centroY-y);

}

void MedioPuntoElipse(int & a, int & b, double & centroX, double & centroY, QPaint & Paint) {

    int i = 0;
    double d2;
    int x=0;
    int y=b;

    double dl=b*b-(a*a*b)+(0.25*a*a);

    Paint.drawPoint(x,y);

    do{

        if(dl<0) {
            dl+=b*b*(2*x+3);
        }
        else {
            dl+=b*b*(2*x+3)+a*a*(-2*y+2);
            y--;
        }
        x++;

        PuntoElipse(centroX, centroY, x, y, i, Paint);

    }hile((a*a*(y-0.5))>(b*b*(x+1)));

    d2=b*b*(x+0.5)*(x+0.5)+a*a*(y-1)*(y-1)-a*a*b*b;

   do{

        if(d2<0) {
            d2+=b*b*(2*x+2)+a*a*(-2*y+3);
            x++;
        }
        else{
            d2+=a*a*(-2*y+3);
        }
        y--;

        PuntoElipse(centroX, centroY, x, y, i, Paint);

    } while(y>0);

}

void Draw(QPaint & Paint) {

    double centroX = 0.0;
    double centroY = 0.0;

    int a = 50;
    int b = 20;

    MedioPuntoElipse(a, b, centroX, centroY, Paint);

    int incX = 50;
    int incY = 100;

    int x0 = centroX - incX;
    int y0 = centroY;
    int x1 = centroX + incX;
    int y1 = y0;
    int x2 = centroX;
    int y2 = y0 + incY;

    Paint.drawLine(x0,y0,x2,y2);
    Paint.drawLine(x2,y2,x1,y1);

}

void Cono::PaintNow(QPaintNow *e)
{
    QPaint Paint(this);

    QPen pointPen(Qt::black);
    pointPen.setWidth(2);
    Paint.setPen(pointPen);

    if (dibuja) {
        for(int i=0; i<vecTrans.size(); ++i) {
            Paint.setTransform(vecTrans[i],true);
            Draw(Paint);
        }
    }
}

void Cono::on_pushButton_clicked()
{
    trans.dibujar(dibuja,vecTrans,xCentro,yCentro);

    update();

}/

void Cono::on_pushButton_2_clicked()
{
    QString xStr = ui->boxXinicio->toPlainText();
    QString yStr = ui->boxYinicio->toPlainText();

    trans.trasladar(xStr, yStr, vecTrans);

    update();

}

void Cono::on_pushButton_3_clicked()
{
    QString gradosStr = ui->boxGrados->toPlainText();

    trans.rotar(gradosStr, vecTrans);

    update();

}

void Cono::on_pushButton_4_clicked()
{
    trans.zoomOut(vecTrans);

    update();

}

void Cono::on_pushButton_5_clicked()
{
    trans.zoomIn(vecTrans);

    update();

}

void Cono::on_pushButton_6_clicked()
{
    trans.reflexHorizontal(vecTrans);

    update();

}

void Cono::on_pushButton_7_clicked()
{
    trans.reflexVertical(vecTrans);

    update();

}