#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <stdlib.h>
#include "generacja.h"
#include <QTimer>
#include "opcje.h"
#include "listawynikow.h"
#include "oknowyniki.h"
#include "dodajwynik.h"
#include "plansza99.h"
#include "planszasamuraj.h"




namespace Ui {
class MainWindow;
}

class MainWindow :
        public QMainWindow,
        public Generacja
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer* zegar;
    ListaWynikow lista[4];
    Opcje oknoOpcje;
    OknoWyniki okno;
    DodajWynik dodajWynik;
    Plansza99* plansza99;
    PlanszaSamuraj* samuraj;
    int i,j,wpisane,sek,min;
    void wypisz(bool w);
    void wypiszSam(bool w, Komorkas plansza[5][9][9]);
    void generuj(int typ);
    bool isClickedNG;
    bool isClickedOpcje;
    bool isClickedTW;
    bool isClickedCheck;
    bool plansza99Open;
    bool samurajOpen;

private slots:

    void on_nowaGra_clicked();

    void zegarek();

    void on_opcje_clicked();

    void on_Check_clicked();

    void on_pomoc_clicked();

    void on_pomoc_2_clicked();

    void on_wyjscie_clicked();

    void easy_clicked();

    void medium_clicked();

    void hard_clicked();

    void on_tabWyn_clicked();

    void resetWynikow();

    void nowyWynik();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
