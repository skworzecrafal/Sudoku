#include "opcje.h"

Opcje::Opcje():QMainWindow()
{
    typ = 1;
    poziomC = 1;
    setFixedSize(470,500);
    close();
    setWindowTitle("Opcje");
    wczytajConf();

    setStyl("Comic Sans MS",QPalette::ButtonText,Qt::black,20);

    easy = new QPushButton(this);
    easy->setGeometry(5,55,150,50);
    easy->setText("Łatwy");
    easy->setPalette(paleta);
    easy->setFont(czcionka);

    medium = new QPushButton(this);
    medium->setGeometry(160,55,150,50);
    medium->setText("Średni");
    medium->setPalette(paleta);
    medium->setFont(czcionka);

    hard = new QPushButton(this);
    hard->setGeometry(315,55,150,50);
    hard->setText("Trudny");
    hard->setPalette(paleta);
    hard->setFont(czcionka);

    klasyczny = new QPushButton(this);
    klasyczny->setGeometry(5,205,225,50);
    klasyczny->setText("Klasyczne");
    klasyczny->setPalette(paleta);
    klasyczny->setFont(czcionka);

    samurajskie = new QPushButton(this);
    samurajskie->setGeometry(235,205,225,50);
    samurajskie->setText("Samurajskie");
    samurajskie->setPalette(paleta);
    samurajskie->setFont(czcionka);

    reset = new QPushButton(this);
    reset->setGeometry(135,355,200,50);
    reset->setText("Reset");
    reset->setPalette(paleta);
    reset->setFont(czcionka);

    setStyl("Comic Sans MS",QPalette::ButtonText,Qt::black,15);
    back = new QPushButton(this);
    back->setGeometry(390,465,75,30);
    back->setText("Wstecz");
    back->setPalette(paleta);
    back->setFont(czcionka);
    connect(back,SIGNAL(clicked()),this,SLOT(close()));

    setStyl("Comic Sans MS",QPalette::Text,Qt::black,20);

    opcje1 = new QLabel(this);
    opcje1->setText("Wybierz poziom trudności:");
    opcje1->setGeometry(5,5,350,45);
    opcje1->setPalette(paleta);
    opcje1->setFont(czcionka);

    poziom = new QLabel(this);
    poziom->setGeometry(355,5,115,45);
    poziom->setPalette(paleta);
    poziom->setFont(czcionka);

    etykietaTyp = new QLabel(this);
    etykietaTyp->setGeometry(5,155,460,45);
    etykietaTyp->setPalette(paleta);
    etykietaTyp->setFont(czcionka);

    resetW = new QLabel(this);
    resetW->setGeometry(5,305,460,45);
    resetW->setPalette(paleta);
    resetW->setFont(czcionka);
    resetW->setText("Aby zresetować listę wyników wciśnij:");


    connect(back,SIGNAL(clicked()),this,SLOT(close()));
    connect(easy,SIGNAL(clicked()),this,SLOT(easy_clicked()));
    connect(medium,SIGNAL(clicked()),this,SLOT(medium_clicked()));
    connect(hard,SIGNAL(clicked()),this,SLOT(hard_clicked()));
    connect(klasyczny,SIGNAL(clicked()),this,SLOT(klasyk_clicked()));
    connect(samurajskie,SIGNAL(clicked()),this,SLOT(samuraj_clicked()));

    if(poziomC == 1)
        poziom->setText("Łatwy");
    if(poziomC == 2)
        poziom->setText("Średni");
    if(poziomC == 3)
        poziom->setText("Trudny");
    if(typ == 1)
    {
        easy->setEnabled(true);
        medium->setEnabled(true);
        hard->setEnabled(true);
        etykietaTyp->setText("Wybierz typ gry: \t Klasyczne");
    }
    if(typ == 2)
    {
        easy->setEnabled(false);
        medium->setEnabled(false);
        hard->setEnabled(false);
        etykietaTyp->setText("Wybierz typ gry: \t Samurajskie");
    }
}

Opcje::~Opcje()
{
    delete easy;
    delete medium;
    delete hard;
    delete back;
    delete klasyczny;
    delete samurajskie;
    delete opcje1;
    delete etykietaTyp;
    delete poziom;
    delete reset;
    delete resetW;
}

void Opcje::wczytajConf()
{
    std::fstream dane;
    dane.open("conf.txt",std::ios::in);
    if(dane.is_open())
    {
        dane>>poziomC>>typ;
        dane.close();
    }
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
