#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QBuffer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_connectBT_clicked()
{
    this->socket.connectToHost(QHostAddress::LocalHost, ui->port->text().toInt());
    if(this->socket.waitForConnected(-1))
            qDebug() << "connected";
        else {
            qDebug() << "cannot connect";
            return;
        }
    QImage image;
    image.load("/home/jakub/Downloads/orig.jpg");
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    image.save(&buffer, "JPG");
    this->socket.write(ba);
}
