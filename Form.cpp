#include "Form.h"

Form::Form()
{

}

void Form::dibujar(bool & dibuja, QVector<QTransform> & vecTrans, double & xCentro, double & yCentro)
{
    dibuja=!dibuja;
    vecTrans.clear();
    QTransform centro;
    centro.translate(xCentro,yCentro);
    vecTrans.push_back(centro);
}

void Form::trasladar(QString & xStr, QString & yStr, QVector<QTransform> & vecTrans)
{
    if(!xStr.isEmpty() && !yStr.isEmpty()) {
        double x = xStr.toDouble();
        double y = yStr.toDouble();
        QTransform translate;
        translate.translate(x, y);
        vecTrans.push_back(translate);
    }
}

void Form::rotar(QString & gradosStr, QVector<QTransform> & vecTrans)
{
    if(!gradosStr.isEmpty()) {
        double grados = gradosStr.toDouble();
        QTransform rotate;
        rotate.rotate(grados);
        vecTrans.push_back(rotate);
    }
}

void Form::zoomOut(QVector<QTransform> & vecTrans)
{
    QTransform zoomOut;
    zoomOut.scale(0.5,0.5);
    vecTrans.push_back(zoomOut);
}

void Form::zoomIn(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(1.5,1.5);
    vecTrans.push_back(zoomIn);
}

void Form::reflexHorizontal(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(-1,1);
    vecTrans.push_back(zoomIn);
}

void Form::reflexVertical(QVector<QTransform> & vecTrans)
{
    QTransform zoomIn;
    zoomIn.scale(1,-1);
    vecTrans.push_back(zoomIn);
}
