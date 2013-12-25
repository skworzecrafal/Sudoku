#ifndef OPCJE_H
#define OPCJE_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class Opcje: public QMainWindow
{
    Q_OBJECT
public:
    Opcje();
    QWidget* oknoOpcje;
    QPushButton* easy;
    QPushButton* medium;
    QPushButton* hard;
    QPushButton* back;
    QPushButton* reset;
    QLabel* opcje1;
    QLabel* poziom;
    int poziomC;

private slots:
    void easy_clicked();

    void medium_clicked();

    void hard_clicked();
};

#endif // OPCJE_H
