#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_parse_clicked()
{

    QFileDialog dialog;
    QString adress = dialog.getOpenFileName();

    ui->file_adress->setText(adress);
    qDebug() << adress;

    QFile file(adress);

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Service::Error";
        return;
    }

    QByteArray fullData = file.readAll();
    file.close();

    QString filename = "/Users/Mac/Data.txt";
    QFile file_out(filename);

    if (!file_out.open(QIODevice::WriteOnly))
    {
        qDebug() << "Service::Error";
        return;
    }

    file_out.write(fullData);
}


