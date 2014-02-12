#ifndef OPCJE_H
#define OPCJE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <fstream>
#include "styltekstu.h"

class Opcje:
        public QMainWindow,
        public StylTekstu
{
    Q_OBJECT
public:
    Opcje();
    ~Opcje();

    QPushButton* reset;

    void wczytajConf();
    int getPoziomC() {return poziomC;}
    int getTyp() {return typ;}


private:

    QPushButton* easy;
    QPushButton* medium;
    QPushButton* hard;
    QPushButton* back;
    QPushButton* klasyczny;
    QPushButton* samurajskie;
    QLabel* opcje1;
    QLabel* etykietaTyp;
    QLabel* poziom;
    QLabel* resetW;

    int poziomC;
    int typ;


private slots:
    void easy_clicked();

    void medium_clicked();

    void hard_clicked();

    void klasyk_clicked();

    void samuraj_clicked();
};

#endif // OPCJE_H
