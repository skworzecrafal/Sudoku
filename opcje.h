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

public slots:
    void on_easy_clicked();

    void on_medium_clicked();

    void on_hard_clicked();
};

#endif // OPCJE_H
