#ifndef UZAMIG_H
#define UZAMIG_H

#include <QMainWindow>
#include "fsm.h"
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class uzamig;
}
QT_END_NAMESPACE

class uzamig : public QMainWindow
{
    Q_OBJECT

public:
    uzamig(QWidget *parent = nullptr);
    ~uzamig();
    void updateState(FSM::State state);

private slots:
    void on_startButton_clicked();

    void on_crt_charButton_clicked();


    void on_attributesButton_clicked();

private:
    Ui::uzamig *ui;
    FSM fsm;
    struct player {
        std::string name;
        int health;
        int strength;
        int dexterity;
        int magic;
    }player1;
};
#endif // UZAMIG_H
