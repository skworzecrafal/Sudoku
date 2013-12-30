#ifndef KOMORKA_H
#define KOMORKA_H

#include <QObject>
#include "styltekstu.h"




class Komorka:
        public QObject,
        public StylTekstu

{
Q_OBJECT
public:
    Komorka();
    virtual ~Komorka();
    QLineEdit *pole;
    int *wartoscGra;
    int *wartoscZnana;
    void format(bool write,int rozm);
    Komorka & operator=(Komorka & K);

private slots:
    void ustaw();

};

#endif // KOMORKA_H
