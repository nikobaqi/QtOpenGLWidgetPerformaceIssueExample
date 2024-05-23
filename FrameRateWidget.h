#ifndef FRAMERATEWIDGET_H
#define FRAMERATEWIDGET_H

#include <QWidget>

namespace Ui
{
class FrameRateWidget;
}

class FrameRateWidget: public QWidget
{
  Q_OBJECT

public:
  explicit FrameRateWidget(QWidget *parent = nullptr);

  ~FrameRateWidget();

  void  setFrameRate(int frameRate);

private:
  Ui::FrameRateWidget *ui;
  bool                 pause = false;
};

#endif // FRAMERATEWIDGET_H
