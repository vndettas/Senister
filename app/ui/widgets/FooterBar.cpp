#include "FooterBar.h"
#include "../HELPER/CONSTANTS.h"

FooterBar::FooterBar(QWidget *parent, const Qt::WindowFlags &f): QWidget(parent, f)
{

  setParent(parent);


}

void
FooterBar::paintEvent(QPaintEvent *event)
{

  QWidget::paintEvent(event);
  QPainter painter(this);

  painter.fillRect(0, 0, width(), height(), QColor(33, 33, 33));

}
