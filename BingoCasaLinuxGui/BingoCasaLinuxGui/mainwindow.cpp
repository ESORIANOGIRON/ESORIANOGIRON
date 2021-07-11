#include <time.h>
#include "mainwindow.h"
#include "ui_BingoCasaLinuxGui.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Hide Groups and buttons not to be seen initially
    ui->groupBoxGameSelected->hide();
    ui->groupBoxPrintCards->hide();
    ui->groupBoxNoThanks->hide();
    ui->groupBoxBingoGame_75->hide();
    ui->groupBoxBingoGame_90->hide();
    ui->groupBoxPrintedCards_75->hide();
    ui->groupBoxPrintedCards_90->hide();
    ui->groupBoxCongrats->hide();
    ui->pushButtonPickBall_Finished90->hide();
    ui->pushButtonPickBall_Finished75->hide();

    //Connect buttons signals to appropriate slots
    connect(ui->pushButton75Balls, SIGNAL (pressed()),this, SLOT (handle75BallsButton()));
    connect(ui->pushButton90Balls, SIGNAL (pressed()),this, SLOT (handle90BallsButton()));
    connect(ui->pushButtonGenerateCards, SIGNAL (pressed()),this, SLOT (handleGenerateCardsButton()));
    connect(ui->pushButtonNoThanks, SIGNAL (pressed()),this, SLOT (handleNoThanksButton()));
    connect(ui->pushButtonNoThanksStartBingo, SIGNAL (pressed()),this, SLOT (handleNoThanksStartBingoButton()));
    connect(ui->pushButtonPickBall_75, SIGNAL (pressed()),this, SLOT (handlePickBallButton_75()));
    connect(ui->pushButtonPickBall_90, SIGNAL (pressed()),this, SLOT (handlePickBallButton_90()));
    connect(ui->pushButtonEnterPlayers, SIGNAL (pressed()),this, SLOT (handleEnterPlayersButton()));
    connect(ui->pushButton75BallsGoOn, SIGNAL (pressed()),this, SLOT (handleEnter75BallsGoOn()));
    connect(ui->pushButton90BallsGoOn, SIGNAL (pressed()),this, SLOT (handleEnter90BallsGoOn()));
    connect(ui->pushButtonSeeYou, SIGNAL (pressed()),this, SLOT (handleSeeYou()));
    connect(ui->pushButtonPickBall_Finished75,SIGNAL (pressed()),this, SLOT (handleFinished75()));
    connect(ui->pushButtonPickBall_Finished90,SIGNAL (pressed()),this, SLOT (handleFinished90()));


    //Initialize random seed
    srand(time(NULL));
    BingoGame = new Bingo();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete BingoGame;
}

void MainWindow::SetWelcomeText(QString Message)
{
    ui->textEditWelcome->setText(Message);
}

void MainWindow::handle75BallsButton()
{
    ui->groupBoxWelcome->hide();
    ui->groupBoxGameSelected->show();
    ui->textEdit90BallsChosen->hide();
    BingoGame->SetGameMaxBallNumber(MAX75);
    GameMaxBallNumber = 75;
}

void MainWindow::handle90BallsButton()
{
    ui->groupBoxWelcome->hide();
    ui->groupBoxGameSelected->show();
    ui->textEdit75BallsChosen->hide();
    BingoGame->SetGameMaxBallNumber(MAX90);
    GameMaxBallNumber = 90;
}

void MainWindow::handleGenerateCardsButton()
{
    ui->groupBoxGameSelected->hide();
    ui->groupBoxPrintCards->show();

}

void MainWindow::handleNoThanksButton()
{
    ui->groupBoxGameSelected->hide();
    ui->groupBoxNoThanks->show();
}

void MainWindow::handleNoThanksStartBingoButton()
{
    ui->groupBoxNoThanks->hide();
    //Start the Game
    BingoGame->SetGameStatus(NORMALRUN);
    GamePic = 0;
    CurrentRow = 0;
    CurrentColumn = 0;

    if(GameMaxBallNumber == 75)
    {
        BingoTableRows = ui->tableWidget_Bingo75->rowCount();
        BingoTableColumns = ui->tableWidget_Bingo75->columnCount();
        ui->groupBoxBingoGame_75->show();
        ui->tableWidget_Bingo75->show();
        ui->tableWidget_Bingo90->hide();

        for(int i=3;i<8;i++)
        {
            ui->tableWidget_Bingo75->setItem(9,i, new QTableWidgetItem);
            ui->tableWidget_Bingo75->item(9,i)->setBackground(Qt::lightGray);
        }
    }
    else if(GameMaxBallNumber == 90)
    {
        BingoTableRows = ui->tableWidget_Bingo90->rowCount();
        BingoTableColumns = ui->tableWidget_Bingo90->columnCount();
        ui->groupBoxBingoGame_90->show();
        ui->tableWidget_Bingo75->hide();
        ui->tableWidget_Bingo90->show();
    }
    else
    {
        cout << "Game Max Ball not set" << endl;
        exit(0);
    }
}

void MainWindow::handleEnterPlayersButton()
{
    //Get Number of Players (up to 100)
    NumberOfPlayers = ui->spinBoxPlayers->value();
    if(NumberOfPlayers>100) NumberOfPlayers = 100;
    CurrentPlayer =1;
    ui->groupBoxPrintCards->hide();
    if(BingoGame->GetGameMaxBalls()==MAX75)
    {
        ui->groupBoxPrintedCards_75->show();
        QString DisplayNumberOfPlayers = "PERFECT! " + QString::number(NumberOfPlayers)+ " PLAYER(S) WILL ENJOY THIS GAME";
        ui->textEditDisplayNumberOfPlayers_75->setText(DisplayNumberOfPlayers);
        ui->textEditDisplayNumberOfPlayers_75->setStyleSheet("font-family: SansSerif; font-size: 20pt; color: rgba(255,255,255,255); background-color: rgba(0,0,0,0%); border-color: rgba(0,0,0,0%)");
        //Set Card Header cells
        ui->tableWidget_Card75->setItem(0, 0, new QTableWidgetItem("  B"));
        ui->tableWidget_Card75->setItem(0, 1, new QTableWidgetItem("   I"));
        ui->tableWidget_Card75->setItem(0, 2, new QTableWidgetItem("  N"));
        ui->tableWidget_Card75->setItem(0, 3, new QTableWidgetItem("  G"));
        ui->tableWidget_Card75->setItem(0, 4, new QTableWidgetItem("  O"));
        //Set Card No-Number cells
        ui->tableWidget_Card75->setItem(3,2, new QTableWidgetItem);
        ui->tableWidget_Card75->item(3,2)->setBackground(Qt::white);
        ui->tableWidget_Card75->setItem(2,0, new QTableWidgetItem);
        ui->tableWidget_Card75->item(2,0)->setBackground(Qt::lightGray);
        ui->tableWidget_Card75->setItem(4,1, new QTableWidgetItem);
        ui->tableWidget_Card75->item(4,1)->setBackground(Qt::lightGray);
        ui->tableWidget_Card75->setItem(5,2, new QTableWidgetItem);
        ui->tableWidget_Card75->item(5,2)->setBackground(Qt::lightGray);
        ui->tableWidget_Card75->setItem(3,3, new QTableWidgetItem);
        ui->tableWidget_Card75->item(3,3)->setBackground(Qt::lightGray);
        ui->tableWidget_Card75->setItem(1,4, new QTableWidgetItem);
        ui->tableWidget_Card75->item(1,4)->setBackground(Qt::lightGray);
        FillUp75Card(CurrentPlayer);
    }
    else if (BingoGame->GetGameMaxBalls()==MAX90)
    {
        ui->groupBoxPrintedCards_90->show();
        QString DisplayNumberOfPlayers = "PERFECT! " + QString::number(NumberOfPlayers)+ " PLAYER(S) WILL ENJOY THIS GAME";
        ui->textEditDisplayNumberOfPlayers_90->setText(DisplayNumberOfPlayers);
        ui->textEditDisplayNumberOfPlayers_90->setStyleSheet("font-family: SansSerif; font-size: 20pt; color: rgba(255,255,255,255); background-color: rgba(0,0,0,0%); border-color: rgba(0,0,0,0%)");
        //Set Card Header cells
        ui->tableWidget_Card90->setItem(0, 0, new QTableWidgetItem("  G"));
        ui->tableWidget_Card90->setItem(0, 1, new QTableWidgetItem("   O"));
        ui->tableWidget_Card90->setItem(0, 2, new QTableWidgetItem("  O"));
        ui->tableWidget_Card90->setItem(0, 3, new QTableWidgetItem("  D"));
        ui->tableWidget_Card90->setItem(0, 4, new QTableWidgetItem("   "));
        ui->tableWidget_Card90->setItem(0, 5, new QTableWidgetItem("  L"));
        ui->tableWidget_Card90->setItem(0, 6, new QTableWidgetItem("   U"));
        ui->tableWidget_Card90->setItem(0, 7, new QTableWidgetItem("  C"));
        ui->tableWidget_Card90->setItem(0, 8, new QTableWidgetItem("  K"));
        //Set Card No-Number cells
        ui->tableWidget_Card90->setItem(1,0, new QTableWidgetItem);
        ui->tableWidget_Card90->item(1,0)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(1,2, new QTableWidgetItem);
        ui->tableWidget_Card90->item(1,2)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(1,5, new QTableWidgetItem);
        ui->tableWidget_Card90->item(1,5)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(1,7, new QTableWidgetItem);
        ui->tableWidget_Card90->item(1,7)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(2,1, new QTableWidgetItem);
        ui->tableWidget_Card90->item(2,1)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(2,3, new QTableWidgetItem);
        ui->tableWidget_Card90->item(2,3)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(2,4, new QTableWidgetItem);
        ui->tableWidget_Card90->item(2,4)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(2,7, new QTableWidgetItem);
        ui->tableWidget_Card90->item(2,7)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(3,2, new QTableWidgetItem);
        ui->tableWidget_Card90->item(3,2)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(3,4, new QTableWidgetItem);
        ui->tableWidget_Card90->item(3,4)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(3,6, new QTableWidgetItem);
        ui->tableWidget_Card90->item(3,6)->setBackground(Qt::lightGray);
        ui->tableWidget_Card90->setItem(3,8, new QTableWidgetItem);
        ui->tableWidget_Card90->item(3,8)->setBackground(Qt::lightGray);
        FillUp90Card(CurrentPlayer);
    }
    else
    {
         ui->groupBoxWelcome->show();
    }
}

void MainWindow::handleSeeYou()
{
    close();
}

void MainWindow::FillUp75Card(int CurrentPlayer)
{
    QString CurrentPlayerTakeDown = "PLAYER " + QString::number(CurrentPlayer)+ ": TAKE DOWN YOUR NUMBERS!";
    ui->textEditTakeDownNumbers_75->setText(CurrentPlayerTakeDown);
    ui->textEditTakeDownNumbers_75->setStyleSheet("font-family: SansSerif; font-size: 20pt; color: rgba(255,255,255,255); background-color: rgba(0,0,0,0%); border-color: rgba(0,0,0,0%)");

    //Set Card Number cells
    CardNumbers = BingoGame->FillUpCard();
    ui->tableWidget_Card75->setItem(1, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][0])));
    ui->tableWidget_Card75->setItem(3, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][1])));
    ui->tableWidget_Card75->setItem(4, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][2])));
    ui->tableWidget_Card75->setItem(5, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][3])));
    ui->tableWidget_Card75->setItem(1, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][0])));
    ui->tableWidget_Card75->setItem(2, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][1])));
    ui->tableWidget_Card75->setItem(3, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][2])));
    ui->tableWidget_Card75->setItem(5, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][3])));
    ui->tableWidget_Card75->setItem(1, 2, new QTableWidgetItem("  " +QString::number(CardNumbers[2][0])));
    ui->tableWidget_Card75->setItem(2, 2, new QTableWidgetItem("  " +QString::number(CardNumbers[2][1])));
    ui->tableWidget_Card75->setItem(4, 2, new QTableWidgetItem("  " +QString::number(CardNumbers[2][3])));
    ui->tableWidget_Card75->setItem(1, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][0])));
    ui->tableWidget_Card75->setItem(2, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][1])));
    ui->tableWidget_Card75->setItem(4, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][2])));
    ui->tableWidget_Card75->setItem(5, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][3])));
    ui->tableWidget_Card75->setItem(2, 4, new QTableWidgetItem("  " +QString::number(CardNumbers[4][0])));
    ui->tableWidget_Card75->setItem(3, 4, new QTableWidgetItem("  " +QString::number(CardNumbers[4][1])));
    ui->tableWidget_Card75->setItem(4, 4, new QTableWidgetItem("  " +QString::number(CardNumbers[4][2])));
    ui->tableWidget_Card75->setItem(5, 4, new QTableWidgetItem("  " +QString::number(CardNumbers[4][3])));
    //Clear Card Numbers once the card is filled up
    BingoGame->ClearCard();

}

void MainWindow::FillUp90Card(int CurrentPlayer)
{
    QString CurrentPlayerTakeDown = "PLAYER " + QString::number(CurrentPlayer)+ ": TAKE DOWN YOUR NUMBERS!";
    ui->textEditTakeDownNumbers_90->setText(CurrentPlayerTakeDown);
    ui->textEditTakeDownNumbers_90->setStyleSheet("font-family: SansSerif; font-size: 20pt; color: rgba(255,255,255,255); background-color: rgba(0,0,0,0%); border-color: rgba(0,0,0,0%)");

    //Set Card Number cells
    CardNumbers = BingoGame->FillUpCard();
    ui->tableWidget_Card90->setItem(2, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][0])));
    ui->tableWidget_Card90->setItem(3, 0, new QTableWidgetItem("  " +QString::number(CardNumbers[0][1])));
    ui->tableWidget_Card90->setItem(1, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][0])));
    ui->tableWidget_Card90->setItem(3, 1, new QTableWidgetItem("  " +QString::number(CardNumbers[1][1])));
    ui->tableWidget_Card90->setItem(2, 2, new QTableWidgetItem("  " +QString::number(CardNumbers[2][0])));
    ui->tableWidget_Card90->setItem(1, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][0])));
    ui->tableWidget_Card90->setItem(3, 3, new QTableWidgetItem("  " +QString::number(CardNumbers[3][1])));
    ui->tableWidget_Card90->setItem(1, 4, new QTableWidgetItem("  " +QString::number(CardNumbers[4][0])));
    ui->tableWidget_Card90->setItem(2, 5, new QTableWidgetItem("  " +QString::number(CardNumbers[5][0])));
    ui->tableWidget_Card90->setItem(3, 5, new QTableWidgetItem("  " +QString::number(CardNumbers[5][1])));
    ui->tableWidget_Card90->setItem(1, 6, new QTableWidgetItem("  " +QString::number(CardNumbers[6][0])));
    ui->tableWidget_Card90->setItem(2, 6, new QTableWidgetItem("  " +QString::number(CardNumbers[6][1])));
    ui->tableWidget_Card90->setItem(3, 7, new QTableWidgetItem("  " +QString::number(CardNumbers[7][0])));
    ui->tableWidget_Card90->setItem(1, 8, new QTableWidgetItem("  " +QString::number(CardNumbers[8][0])));
    ui->tableWidget_Card90->setItem(2, 8, new QTableWidgetItem("  " +QString::number(CardNumbers[8][1])));
    //Clear Card Numbers once the card is filled up
    BingoGame->ClearCard();
}

void MainWindow::handleEnter75BallsGoOn()
{
    CurrentPlayer ++;
    if(CurrentPlayer<NumberOfPlayers+1)
    {
        FillUp75Card(CurrentPlayer);
    }
    else
    {
        ui->groupBoxPrintedCards_75->hide();
        //Start the Game
        BingoGame->SetGameStatus(NORMALRUN);
        GamePic = 0;
        CurrentRow = 0;
        CurrentColumn = 0;
        BingoTableRows = ui->tableWidget_Bingo75->rowCount();
        BingoTableColumns = ui->tableWidget_Bingo75->columnCount();
        ui->groupBoxBingoGame_75->show();
        for(int i=3;i<8;i++)
        {
            ui->tableWidget_Bingo75->setItem(9,i, new QTableWidgetItem);
            ui->tableWidget_Bingo75->item(9,i)->setBackground(Qt::lightGray);
        }
    }
}

void MainWindow::handleEnter90BallsGoOn()
{
    CurrentPlayer ++;
    if(CurrentPlayer<NumberOfPlayers+1)
    {
        FillUp90Card(CurrentPlayer);
    }
    else
    {
        ui->groupBoxPrintedCards_90->hide();
        //Start the Game
        BingoGame->SetGameStatus(NORMALRUN);
        GamePic = 0;
        CurrentRow = 0;
        CurrentColumn = 0;
        BingoTableRows = ui->tableWidget_Bingo90->rowCount();
        BingoTableColumns = ui->tableWidget_Bingo90->columnCount();
        ui->groupBoxBingoGame_90->show();
    }
}

void MainWindow::handlePickBallButton_75()
{
  BingoGame->SetLuckyBallNumber(BingoGame->GetLuckyNumber(GamePic));

  if(CurrentColumn==BingoTableColumns)
  {
      CurrentColumn = 0;
      CurrentRow++;
  }
  if(BingoGame->GetLuckyNumber(GamePic)<10)
  {
      ui->tableWidget_Bingo75->setItem(CurrentRow,CurrentColumn,new QTableWidgetItem(" "+QString::number(BingoGame->GetLuckyNumber(GamePic))));
  }
  else
  {
      ui->tableWidget_Bingo75->setItem(CurrentRow,CurrentColumn,new QTableWidgetItem(QString::number(BingoGame->GetLuckyNumber(GamePic))));
  }
  CurrentColumn++;
  GamePic++;
  if(GamePic == 75)
  {
       ui->pushButtonPickBall_Finished75->show();
  }
}

void MainWindow::handlePickBallButton_90()
{
    BingoGame->SetLuckyBallNumber(BingoGame->GetLuckyNumber(GamePic));

    if(CurrentColumn==BingoTableColumns)
    {
        CurrentColumn = 0;
        CurrentRow++;
    }
    if(BingoGame->GetLuckyNumber(GamePic)<10)
    {
        ui->tableWidget_Bingo90->setItem(CurrentRow,CurrentColumn,new QTableWidgetItem(" "+QString::number(BingoGame->GetLuckyNumber(GamePic))));
    }
    else
    {
        ui->tableWidget_Bingo90->setItem(CurrentRow,CurrentColumn,new QTableWidgetItem(QString::number(BingoGame->GetLuckyNumber(GamePic))));
    }

    CurrentColumn++;
    GamePic++;
    if(GamePic == 90)
    {
        ui->pushButtonPickBall_Finished90->show();
    }


}

void MainWindow::handleFinished75()
{
    ui->groupBoxBingoGame_75->hide();
    ui->groupBoxCongrats->show();
}

void MainWindow::handleFinished90()
{
    ui->groupBoxBingoGame_90->hide();
    ui->groupBoxCongrats->show();
}


