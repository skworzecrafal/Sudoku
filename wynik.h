#ifndef WYNIK_H
#define WYNIK_H
#include <QString>

class Wynik
{
private:
    QString imie;
    int minuty;
    int sekundy;
public:
    Wynik();
    ~Wynik();
    void setImie(QString imie);
    void setMinuty(int min);
    void setSekundy(int sek);
    QString getImie();
    int getMinuty();
    int getSekundy();
    Wynik* nastepny;


};

#endif // WYNIK_H
