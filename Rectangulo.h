#ifndef PRISMAREC_H
#define PRISMAREC_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include "Form.h"

namespace Ui {
class Rectangulo;
}

class Rectangulo : public QDialog
{
    Q_OBJECT

public:
    explicit Rectangulo(QWidget *parent = 0);
    ~Rectangulo();

protected:

    void PaintNow(QPaintNow *e);

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::Rectangulo *ui;
    bool dibuja = false;

    double xCentro;
    double yCentro;

    QVector<QTransform> vecTrans;
    Transformaciones trans;

};

#endif 