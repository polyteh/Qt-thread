#include "mainwindow.h"
#include "ui_mainwindow.h"

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
void MainWindow::update (int i){
    ui->label->setText(QString::number(i));
}

void MainWindow::on_pushButton_clicked()
{
    QThread *thread= new QThread;
    MyClass *my = new MyClass("B");

    my->moveToThread(thread);

    connect(my, SIGNAL(send(int)), this, SLOT(update(int)));
    connect(thread, SIGNAL(started()), my, SLOT(doWork()));

    thread->start();
}
