#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(button()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button()
{
    QString name[] = {"abc", "def", "ghi"};
    QString code[] = {"abc12", "def34", "ghi56"};

    QString uName = ui->lineEdit->text();
    QString uCode = ui->lineEdit_2->text();

    bool found= false;

    for(int i = 0;i < name->length();i++){
        if(uName == name[i] && uCode == code[i]){
            QMessageBox::information(this, "Welcome", "User " + name[i] + "\n"
                                                          + "succesfully logged in");
            found = true;
            break;
        }
    }

    if(!found){
        QMessageBox::information(this, "Error", "Invalid username or password");
    }
}

