#include "uzamig.h"
#include "./ui_uzamig.h"
#include <QInputDialog>



uzamig::uzamig(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::uzamig)
{
    ui->setupUi(this);
    ui->display->setText("Welcome to Uzamig: The Game\n Press the button to start");
    connect(&fsm, &FSM::stateChanged,this,&uzamig::updateState);
    ui->crt_charButton->setVisible(false);
}

uzamig::~uzamig()
{
    delete ui;
}

void uzamig::updateState(FSM::State state){
    switch(state){
    case FSM::State::INIT:
        break;
    case FSM::State::HOME:
        ui->display->setText("This is an RPG\n press the button to create your character");
        ui->crt_charButton->setVisible(true);
        ui->startButton->setVisible(false);
        break;
    case FSM::State::CREATE_CHARACTER:
        ui->crt_charButton->setVisible(false);
        break;
}
}

void uzamig::on_startButton_clicked()
{
    fsm.start();
}


void uzamig::on_crt_charButton_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, tr("Character creation"),
                                         tr("What is your character's name"), QLineEdit::Normal,
                                         QString(), &ok);
    if (ok && !name.isEmpty()) {
        player1.name = name.toStdString();
        ui->display->setText("Character " + QString::fromStdString(player1.name) + " created!");
        fsm.create();
    } else {
        ui->display->setText("Character creation cancelled.");
    }
}

