#include "principal.h"
//#include "calculosalario.h"

//#include <QtDebug>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Principal w;
    w.show();

    //Prueba de calculo del salario

    /*CalculoSalario s1("Juan",40,'M');
    s1.calcular();
    qDebug() << s1.salarioBruto();
    qDebug() << s1.descuento();
    qDebug() << s1.salarioNeto();
    */

    return a.exec();
}
