#include "opcje.h"

Opcje::Opcje():QMainWindow()
{
    typ = 1;
    poziomC = 1;
    setFixedSize(470,500);
    close();
    setWindowTitle("Opcje");

    easy = new QPushButton(this);
    easy->setGeometry(5,55,150,50);
    easy->setText("Łatwy");

    medium = new QPushButton(this);
    medium->setGeometry(160,55,150,50);
    medium->setText("Średni");

    hard = new QPushButton(this);
    hard->setGeometry(315,55,150,50);
    hard->setText("Trudny");

    back = new QPushButton(this);
    back->setGeometry(390,465,75,30);
    back->setText("Wstecz");
    connect(back,SIGNAL(clicked()),this,SLOT(close()));

    setStyl("MS Shell",QPalette::Text,Qt::black,20);

    opcje1 = new QLabel(this);
    opcje1->setText("Wybierz poziom trudności:");
    opcje1->setGeometry(5,5,350,45);
    opcje1->setPalette(paleta);
    opcje1->setFont(czcionka);

    poziom = new QLabel(this);
    poziom->setGeometry(355,5,115,45);
    poziom->setText("Łatwy");
    poziom->setPalette(paleta);
    poziom->setFont(czcionka);

    etykietaTyp = new QLabel(this);
    etykietaTyp->setGeometry(5,155,460,45);
    etykietaTyp->setPalette(paleta);
    etykietaTyp->setFont(czcionka);

    klasyczny = new QPushButton(this);
    klasyczny->setGeometry(5,205,225,50);
    klasyczny->setText("Klasyczne");

    samurajskie = new QPushButton(this);
    samurajskie->setGeometry(235,205,225,50);
    samurajskie->setText("Samurajskie");

    connect(back,SIGNAL(clicked()),this,SLOT(close()));
    connect(easy,SIGNAL(clicked()),this,SLOT(easy_clicked()));
    connect(medium,SIGNAL(clicked()),this,SLOT(medium_clicked()));
    connect(hard,SIGNAL(clicked()),this,SLOT(hard_clicked()));
    connect(klasyczny,SIGNAL(clicked()),this,SLOT(klasyk_clicked()));
    connect(samurajskie,SIGNAL(clicked()),this,SLOT(samuraj_clicked()));

    reset = new QPushButton(this);
    reset->setGeometry(390,430,75,30);
    reset->setText("Reset");
}

void Opcje::easy_clicked()
{
    poziomC = 1;
    poziom->setText("Łatwy");
}

void Opcje::medium_clicked()
{
    poziomC = 2;
    poziom->setText("Średni");
}

void Opcje::hard_clicked()
{
    poziomC = 3;
    poziom->setText("Trudny");
}

void Opcje::klasyk_clicked()
{
    typ = 1;
    easy->setEnabled(true);
    medium->setEnabled(true);
    hard->setEnabled(true);
    etykietaTyp->setText("Wybierz typ gry: \t Klasyczne");
}

void Opcje::samuraj_clicked()
{
    typ = 2;
    easy->setEnabled(false);
    medium->setEnabled(false);
    hard->setEnabled(false);
    etykietaTyp->setText("Wybierz typ gry: \t Samurajskie");
}
