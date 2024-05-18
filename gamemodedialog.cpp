#include "gamemodedialog.h"
#include "ui_gamemodedialog.h"

GameModeDialog::GameModeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameModeDialog),
    playWithComputer(false) {
    ui->setupUi(this);

    connect(ui->playWithFriendButton, &QPushButton::clicked, this, &GameModeDialog::onPlayWithFriendButtonClicked);
    connect(ui->playWithComputerButton, &QPushButton::clicked, this, &GameModeDialog::onPlayWithComputerButtonClicked);
}

GameModeDialog::~GameModeDialog() {
    delete ui;
}

bool GameModeDialog::isPlayWithComputer() const {
    return playWithComputer;
}

void GameModeDialog::onPlayWithFriendButtonClicked() {
    playWithComputer = false;
    accept();
}

void GameModeDialog::onPlayWithComputerButtonClicked() {
    playWithComputer = true;
    accept();
}
