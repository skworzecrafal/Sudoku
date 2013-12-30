#ifndef OPCJE_H
#define OPCJE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "styltekstu.h"

class Opcje:
        public QMainWindow,
        public StylTekstu
{
    Q_OBJECT
public:
    Opcje();
    QPushButton* easy;
    QPushButton* medium;
    QPushButton* hard;
    QPushButton* back;
    QPushButton* reset;
    QLabel* etykietaTyp;
    QLabel* poziom;

    int poziomC;
    int typ;

private:

    QPushButton* klasyczny;
    QPushButton* samurajskie;
    QLabel* opcje1;


private slots:
    void easy_clicked();

    void medium_clicked();

    void hard_clicked();

    void klasyk_clicked();

    void samuraj_clicked();
};

#endif // OPCJE_H
