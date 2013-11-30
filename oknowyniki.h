#ifndef OKNOWYNIKI_H
#define OKNOWYNIKI_H
#include <QTabWidget>
#include <QMainWindow>
#include <QWidget>

class OknoWyniki: public QMainWindow
{
public:
    OknoWyniki();
    QTabWidget* oknoWyniki;
    QWidget* easy;
    QWidget* medium;
    QWidget* hard;
};

#endif // OKNOWYNIKI_H
