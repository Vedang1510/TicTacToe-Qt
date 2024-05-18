#ifndef GAMEMODEDIALOG_H
#define GAMEMODEDIALOG_H

#include <QDialog>

namespace Ui {
class GameModeDialog;
}

class GameModeDialog : public QDialog {
    Q_OBJECT

public:
    explicit GameModeDialog(QWidget *parent = nullptr);
    ~GameModeDialog();

    bool isPlayWithComputer() const;

private slots:
    void onPlayWithFriendButtonClicked();
    void onPlayWithComputerButtonClicked();

private:
    Ui::GameModeDialog *ui;
    bool playWithComputer;
};

#endif // GAMEMODEDIALOG_H
