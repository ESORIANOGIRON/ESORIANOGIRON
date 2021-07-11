#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <vector>
#include <QMainWindow>
#include <QPushButton>

#include "BingoGame/Bingo.h"
#include "BingoGame/Card.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void SetWelcomeText(QString message);

private slots:
    //GUI Methods:
    void handle90BallsButton();
    void handle75BallsButton();
    void handleGenerateCardsButton();
    void handleNoThanksButton();
    void handleNoThanksStartBingoButton();
    void handlePickBallButton_75();
    void handlePickBallButton_90();
    void handleEnterPlayersButton();
    void handleEnter75BallsGoOn();
    void handleEnter90BallsGoOn();
    void handleSeeYou();
    void handleFinished75();
    void handleFinished90();

    void FillUp75Card(int NumberOfPlayers);
    void FillUp90Card(int NumberOfPlayers);

private:
    Ui::MainWindow *ui;
    //Bingo Game
    Bingo *BingoGame;

    int CurrentPlayer, NumberOfPlayers, GameMaxBallNumber,GamePic,CurrentRow,CurrentColumn, BingoTableRows, BingoTableColumns;
    vector <vector <int>> CardNumbers;


};

#endif // MAINWINDOW_H
