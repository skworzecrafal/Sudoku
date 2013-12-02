#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <stdlib.h>
#include "generacja.h"
#include <QFrame>
#include "komorka.h"
#include <QTimer>
#include "opcje.h"
#include "listawynikow.h"
#include "oknowyniki.h"
#include "dodajwynik.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Generacja g;
    Komorka plansza[9][9];
    QFrame* linie[8];
    QTimer* zegar;
    ListaWynikow lista[4];
    Opcje oknoOpcje;
    OknoWyniki okno;
    DodajWynik dodajWynik;
    int i,j,wpisane,sek,min;
    void wypisz(bool w);
    bool isClickedNG;
    bool isClickedOpcje;
    bool isClickedTW;
    bool isClickedCheck;
    void close99();
    void show99();

private slots:

    void on_nowaGra_clicked();

    void doTablicy99();

    void zegarek();

    void on_opcje_clicked();

    void on_Check_clicked();

    void on_pomoc_clicked();

    void on_pomoc_2_clicked();

    void on_wyjscie_clicked();

    void on_easy_clicked();

    void on_medium_clicked();

    void on_hard_clicked();

    void on_tabWyn_clicked();

    void resetWynikow();

    void nowyWynik();

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
