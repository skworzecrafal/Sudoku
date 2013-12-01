#include "opcje.h"

Opcje::Opcje()
{
    poziomC = 1;
    oknoOpcje = new QWidget;
    oknoOpcje->setFixedSize(470,500);
    easy = new QPushButton(oknoOpcje);
    easy->setGeometry(5,55,150,50);
    easy->setText("Łatwy");
    medium = new QPushButton(oknoOpcje);
    medium->setGeometry(160,55,150,50);
    medium->setText("Średni");
    hard = new QPushButton(oknoOpcje);
    hard->setGeometry(315,55,150,50);
    hard->setText("Trudny");
    back = new QPushButton(oknoOpcje);
    back->setGeometry(390,465,75,30);
    back->setText("Wstecz");
    connect(back,SIGNAL(clicked()),oknoOpcje,SLOT(close()));
    oknoOpcje->close();
    oknoOpcje->setWindowTitle("Opcje");
    opcje1 = new QLabel(oknoOpcje);
    opcje1->setText("Wybierz poziom trudności:");
    opcje1->setGeometry(5,5,350,45);
    opcje1->setStyleSheet("font: 20pt MS Shell Dlg 2;");
    poziom = new QLabel(oknoOpcje);
    poziom->setGeometry(355,5,115,45);
    poziom->setText("Łatwy");
    poziom->setStyleSheet("font: 20pt MS Shell Dlg 2;");
    connect(easy,SIGNAL(clicked()),SLOT(on_easy_clicked()));
    connect(medium,SIGNAL(clicked()),SLOT(on_medium_clicked()));
    connect(hard,SIGNAL(clicked()),SLOT(on_hard_clicked()));
    reset = new QPushButton(oknoOpcje);
    reset->setGeometry(390,430,75,30);
    reset->setText("Reset");
}

void Opcje::on_easy_clicked()
{
    poziomC = 1;
    poziom->setText("Łatwy");
}

void Opcje::on_medium_clicked()
{
    poziomC = 2;
    poziom->setText("Średni");
}

void Opcje::on_hard_clicked()
{
    poziomC = 3;
    poziom->setText("Trudny");
}
