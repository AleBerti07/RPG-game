#include "uzamig.h"
#include "./ui_uzamig.h"
#include <QInputDialog>
#include <random>
#include <QMessageBox>

int global;
int c_health = 100;


void dice(){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist8(1,8);
    global = dist8(rng);
}


uzamig::uzamig(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::uzamig)
{
    ui->setupUi(this);
    ui->display->setText("Welcome to Uzamig: The Game\n Press the button to start");
    connect(&fsm, &FSM::stateChanged,this,&uzamig::updateState);

    ui->crt_charButton->setVisible(false);
    ui->attributesButton->setVisible(false);
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
        ui->attributesButton->setVisible(true);
        ui->display->setText("Character " + QString::fromStdString(player1.name) + " created!");
        break;
    case FSM::State::GENERATE_ATTRIBUTES:
        ui->display->setText(QString::fromStdString(player1.name+" is ready for their journey"));
        ui->attributesButton->setVisible(false);
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
        fsm.create_character();
    } else {
        ui->display->setText("Character creation cancelled.");
    }
}



void uzamig::on_attributesButton_clicked() {
    dice();
    int dice1 = global;
    dice();
    int dice2 = global;
    int points = dice1 + dice2;

    QMessageBox::information(this, tr("Attributes points"), tr("You have: %1 points").arg(points));

    bool ok;
    int atk_points = QInputDialog::getInt(this, tr("Strength"),
                                          tr("How many points will you invest in attack?"), 0, 0, points, 1, &ok);
    if (ok) {
        points -= atk_points;
        player1.strength = atk_points;

        if (points > 0) {
            int mgc_points = QInputDialog::getInt(this, tr("Magic"),
                                                  tr("How many points will you invest in magic?"), 0, 0, points, 1, &ok);
            if (ok) {
                points -= mgc_points;
                player1.magic = mgc_points;

                if (points > 0) {
                    int dex_points = QInputDialog::getInt(this, tr("Dexterity"),
                                                          tr("How many points will you invest in dexterity?"), 0, 0, points, 1, &ok);
                    if (ok) {
                        points -= dex_points;
                        player1.dexterity = dex_points;

                        if (points>0){
                            int HP_points = QInputDialog::getInt(this, tr("Health points"),
                                                               tr("How many points will you invest in HP?"), 0, 0, points, 1, &ok);
                            if(ok){
                                points -= HP_points;
                                player1.health = HP_points + c_health;
                            }
                        }
                    }
                }
            }
        }
    }

    if (points == 0) {
        ui->display->setText("Your points have been distributed.");
        QMessageBox::information(this, tr("Attribute Points"),
                                 tr("These are your attribute points\nStrength: %1\nMagic: %2\nDexterity: %3\nHealth Points: %4")
                                        .arg(player1.strength)
                                        .arg(player1.magic)
                                        .arg(player1.dexterity)
                                        .arg(player1.health));
        fsm.generate_attributes();
    } else {
        ui->display->setText(tr("Attribute distribution incomplete. You have %1 points left.").arg(points));
    }
}
