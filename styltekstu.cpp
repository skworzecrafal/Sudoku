#include "styltekstu.h"

StylTekstu::StylTekstu()
{
}

void StylTekstu::setStyl(const QString &czcionka, QPalette::ColorRole role, const QColor &kolor, int rozmiar)
{
    this->czcionka.setFamily(czcionka);
    this->czcionka.setPixelSize(rozmiar);
    paleta.setColor(role,kolor);
}
