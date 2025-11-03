#include "mainwindow.h"
#include "./ui_mainwindow.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->chatSendButton, &QPushButton::clicked, this, &MainWindow::sendText);
    connect(ui->chatInputLine, &QLineEdit::returnPressed, this, &MainWindow::sendText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_chatSendButton_clicked()
{


}

void MainWindow::test()
{
    qDebug() << "Slot test is running\n";
}

void MainWindow::sendText()
{
    QString text = ui->chatInputLine->text();
    if(!text.isEmpty())
    {
        ui->chatWindow->append(text);
        ui->chatInputLine->clear();
    }
}
