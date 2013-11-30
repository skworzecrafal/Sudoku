#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <stdlib.h>
#include "plansza.h"
#include "generacja.h"
#include <QFrame>
#include "komorka.h"
#include <QTimer>
#include "opcje.h"
#include "listawynikow.h"
#include "oknowyniki.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Plansza tab;
    Generacja g;
    Komorka plansza[9][9];
    QFrame* linie[8];
    QTimer* zegar;
    ListaWynikow listaEasy;
    ListaWynikow listaMedium;
    ListaWynikow listaHard;
    Opcje oknoOpcje;
    int i,j,wpisane,sek,min;
    void wypisz(bool w);
    bool isClickedNG;    
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

private:
    Ui::MainWindow *ui;



};

#endif // MAINWINDOW_H
