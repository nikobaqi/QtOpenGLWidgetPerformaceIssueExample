#include "MainWindow.h"
#include "./ui_MainWindow.h"
#include <QOpenGLWindow>
#include <QMouseEvent>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  // auto aaa = new QOpenGLWindow(QOpenGLWindow::PartialUpdateBlit,this->window())


  ui->setupUi(this);


  QTimer *timer = new QTimer(this);

  timer->setInterval(0);

  connect(timer, &QTimer::timeout, this, [this]()
  {
    static int counter = 0;
    ui->timerLabel->setText(QString::number(counter++));
  });

  connect(ui->startPushButton, &QPushButton::pressed, this, [ =, this]()
  {
    if (timer->isActive())
    {
      timer->stop();
      ui->startPushButton->setText("Start");
    }
    else
    {
      timer->start();
      ui->startPushButton->setText("Stop");
    }
  });
}

MainWindow::~MainWindow()
{
  delete ui;
}

void  MainWindow::mouseMoveEvent(QMouseEvent *event)
{
  ui->mouseCoordsLabel->setText(QString("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA%1,"
                                        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB%2")
                                .arg(event->x() * event->x() * event->x() * 2450).arg(event->y() * event->x() * event->x() * event->x() * 5567));// make some
                                                                                                                                                 // random text
  QMainWindow::mouseMoveEvent(event);
}
