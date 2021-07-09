#include "principal.h"
#include "ui_principal.h"
#include <QtDebug>
#include <QMessageBox>


Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}

void Principal::on_cmdCalcular_clicked()
{
    this->calcular();
}

void Principal::on_actionCalcular_triggered()
{
    this->calcular();
}

void Principal::calcular()
{
    // Obtener el nombre
    QString nombre = ui->intNom->text();
    // Valida que el nombre no esté vacío
    if (nombre.isEmpty()){
        QMessageBox::warning(this, "Salarios","No has proporcionado el nombre del obrero");
        return;
    }
    // Obtiene horas
    int horas = ui->intHora->value();
    // Obtiene la jornada
    char jornada ='\0';
    if (ui->inMatutina->isChecked()) {
        jornada = 'M';
    }else if (ui->inNocturna->isChecked()){
        jornada = 'N';
    }else if (ui->inVespertina->isChecked()){
        jornada = 'V';
    }
    // Instancia el objeto y se calcula
    CalculoSalario *s1 = new CalculoSalario(nombre, horas, jornada);
    s1->calcular();
    // Muestra los resultados
    ui->outResultado->appendPlainText(s1->resultado());
    // Encerar los widgets
    this->borrar();
}

void Principal::borrar()
{
    ui->intNom->setText("");
    ui->intHora->setValue(0);
    ui->inMatutina->setChecked(true);
    ui->intNom->setFocus();
}

void Principal::nuevo()
{
    ui->outResultado->clear();
}

void Principal::on_actionNuevo_triggered()
{
    this->nuevo();
}

void Principal::on_actionAcerca_de_triggered()
{
    Acerca *acercaDe = new Acerca(this);
    acercaDe->setVersion(VERSION);
    acercaDe->show();
}

void Principal::on_actionGuardar_2_triggered()
{
    QDir directorio=QDir::home();
        QString pathArchivo=directorio.absolutePath()+"  sin_nombre.txt";
        QString fileName = QFileDialog::getSaveFileName(this,"Guardar Archivo",
                    pathArchivo,
             "Archivo de texto(*.txt)");

        QFile f(fileName);
        QTextStream out(&f);
        if(!f.open(QIODevice::WriteOnly | QIODevice::Append)){
            QMessageBox::warning(this,"Salarios","No se puede abrir el archivo"+fileName);
            return;
        }
        out<<ui->outResultado->toPlainText()<<endl;
        f.close();
}


void Principal::on_actionAbrir_triggered()
{

    QDir directorio = QDir::home();
        QString pathArchivo = directorio.absolutePath();
        QString fileName = QFileDialog::getOpenFileName(this,
                                                        "Abriendo archivo",
                                                        pathArchivo,
                                                        "Archivo de texto (*.txt)");
        QFile f(fileName);
        QTextStream in(&f);
        QString impresion;
        if(!f.open(QIODevice::ReadOnly))
            QMessageBox::warning(this,"Salarios","No se puede abrir el archivo");
        while(!in.atEnd())
        {
            impresion = impresion + in.readLine() + "\n";
        }
        f.close();
        ui->outResultado->appendPlainText(impresion);
 }

