#ifndef KOMORKAS_H
#define KOMORKAS_H
#include "komorka.h"
class Komorkas :public Komorka
{
public:
    Komorkas();
    ~Komorkas();
    int *backupWart;
    Komorkas & operator=(Komorkas & K);
    void zeruj();
};

#endif // KOMORKAS_H
