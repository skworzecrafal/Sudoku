#ifndef KOMORKA_H
#define KOMORKA_H

#include <QLineEdit>



class Komorka

{

public:
    Komorka();
    QLineEdit *pole;
    int wartoscGra;
    int wartoscZnana;
    void format(bool write);

};

#endif // KOMORKA_H
