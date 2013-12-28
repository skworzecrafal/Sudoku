#ifndef STYLTEKSTU_H
#define STYLTEKSTU_H
#include <QLineEdit>

class StylTekstu
{
public:
    StylTekstu();
    QPalette paleta;
    QFont czcionka;
    void setStyl(const QString &czcionka, QPalette::ColorRole role,const QColor & kolor, int rozmiar);
};

#endif // STYLTEKSTU_H
