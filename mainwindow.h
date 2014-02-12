#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "gra.h"
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QUrl>


class MainWindow :
        public QMainWindow,
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
     */
    QPushButton* przycisk[7];
    QPushButton* play;
    QPushButton* stop;
    QLabel* radio;
    QLabel* naglowek;
    QLabel* zegarWyswietlacz;
    QLabel* wynikGry;
    QTimer* czekaj;
    QUrl url;
    QWebView* webview;
    QTimer* czekanie;


private slots:

    void nowaGra_clicked();

    void zegarek();

    void opcje_clicked();

    void Check_clicked();

    void wskazowka();

    void wyjscie_clicked();

    void wyniki_clicked();

    void reset_clicked();

    void nowyWynik();

    void pomoc_clicked();

    void czysc_wynik();

    void wlacz();

    void wylacz();

    void poczekaniu();

};

#endif // MAINWINDOW_H
