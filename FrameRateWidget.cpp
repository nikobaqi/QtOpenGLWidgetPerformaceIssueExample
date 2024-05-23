#include "FrameRateWidget.h"
#include "ui_FrameRateWidget.h"

FrameRateWidget::FrameRateWidget(QWidget *parent):
  QWidget(parent),
  ui(new Ui::FrameRateWidget)
{
  ui->setupUi(this);

  connect(ui->pauseButton, &QPushButton::pressed, this, [this]()
  {
    pause = !pause;

    if (pause)
    {
      ui->pauseButton->setText("Count");
    }
    else
    {
      ui->pauseButton->setText("Pause");
    }
  });


  // setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
}

FrameRateWidget::~FrameRateWidget()
{
  delete ui;
}

void  FrameRateWidget::setFrameRate(int frameRate)
{
  if (!pause)
  {
    ui->frameRateLabel->setText(QString::number(frameRate));
    ui->timeOfEachFrame->setText(QString::number(1000 / frameRate));
  }
}
