#include "calculosalario.h"

float CalculoSalario::salarioBruto() const
{
    return m_salarioBruto;
}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}

QString CalculoSalario::getJornada()
{
    switch(m_jornada){
    case 'V':
        return "Vespertina";
        break;
    case 'M':
        return "Matutina";
        break;
    case 'N':
        return "Nocturna";
        break;
    }
    return "N/D";
}

CalculoSalario::CalculoSalario(QObject *parent) : QObject(parent)
{

}

CalculoSalario::CalculoSalario(QString nombre, int horas, char jornada)
{
    m_nombre = nombre;
    m_horas = horas;
    m_jornada = jornada;
}

void CalculoSalario::calcular()
{
    float valorHora = 0;
    switch(m_jornada){
    case 'V':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'M':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'N':
        valorHora = VALOR_HORA_NOCTURNO;
        break;
    }

    m_salarioBruto = m_horas * valorHora;
    m_descuento = m_salarioBruto * PORCENTAJE_DESCUENTO / 100;
    m_salarioNeto = m_salarioBruto - m_descuento;
}

QString CalculoSalario::resultado()
{
    QString str;
    str += "Obrero: " + m_nombre + "\n";
    str += "Horas: " + QString::number(m_horas) + "\n";
    str += "Jornada: " + getJornada() + "\n";
    str += "Salario Bruto: $" + QString::number(m_salarioBruto) + "\n";
    str += "Descuento: $" + QString::number(m_descuento) + "\n";
    str += "Salario Neto: $" + QString::number(m_salarioNeto) +"\n\n";
    return str;
}
