#ifndef KOMORKA_H
#define KOMORKA_H

#include <QLineEdit>
#include <QObject>




class Komorka: public QObject

{
Q_OBJECT
public:
    Komorka();
    ~Komorka();
    QLineEdit *pole;
    int wartoscGra;
    int wartoscZnana;
    void format(bool write);

private slots:
    void ustaw();

};

#endif // KOMORKA_H
