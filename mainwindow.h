#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "styltekstu.h"
#include "gra.h"


class MainWindow :
        public QMainWindow,
        public StylTekstu,
        public Gra
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void stworzUi();

private:
    /*
     * 0-nowa gra
     * 1-opcje
     * 2-tablica wynikow
     * 3-instrukcja
     * 4-wyjscie
     * 5-sprawdzenie rozwiazania
     * 6-pojedyncza podpowiedz
     * 7-szybkie rozwiazanie
     */
    QPushButton* przycisk[8];
    QLabel* naglowek;
    QLabel* zegarWyswietlacz;
    QLabel* wynikGry;

private slots:

    void nowaGra_clicked();

    void zegarek();

    void opcje_clicked();

    void Check_clicked();

//    void on_pomoc_clicked();

//    void on_pomoc_2_clicked();

    void wyjscie_clicked();

//    void easy_clicked();

//    void medium_clicked();

//    void hard_clicked();

    void wyniki_clicked();

//    void resetWynikow();

    void nowyWynik();

};

#endif // MAINWINDOW_H
