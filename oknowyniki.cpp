#include "oknowyniki.h"

OknoWyniki::OknoWyniki()
{
    oknoWyniki = new QTabWidget();
    oknoWyniki->setWindowTitle("Tablica wyników");
    oknoWyniki->setFixedSize(250,250);
    oknoWyniki->addTab(easy = new QWidget(),"Łatwy");
    oknoWyniki->addTab(medium = new QWidget(),"Średni");
    oknoWyniki->addTab(hard = new QWidget(),"Trudny");
}
