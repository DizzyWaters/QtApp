#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    connect(ui->login_button, &QDialogButtonBox::accepted, this, &LoginDialog::onLoginClicked);
    connect(ui->login_button, &QDialogButtonBox::rejected, this, &LoginDialog::reject);
}

void LoginDialog::onLoginClicked()
{
    QString username =  ui->login_enter_line->text();
    QString password = ui->Password_enter_line->text();
    if(username == "admin" && password == "1234")
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,"eror", "Invalid username/passowrd!");
    }
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
