//
// Created by vovab on 18.06.2025.
//



#include <QInternal>
#include "LineNumerator.h"

void LineNumerator::paintEvent(QPaintEvent *event)
{
  QWidget::paintEvent(event);
  QPainter painter(this);


  QFont numeration_font("Lucida Sans Typewriter", 8);
  QFontMetrics metrics(numeration_font);
  painter.setFont(numeration_font);
  painter.fillRect(0, 0, width(), parent_widget_ui->height(), Constants::CODE_BACKGROUND_BRUSH);


  QPen numerator_pen(Constants::TEXT_COLOR_WHITE_PURE);
  painter.setPen(numerator_pen);

  int y = 0;

  uint32_t numeration_line = text_engine->getFirstVisibleLine();
  size_t line_numerator_counter = 0;
  uint32_t all_lines_count = text_engine->get_Lines_Count();
  qDebug() << all_lines_count << ": all lines";

  while (line_numerator_counter <= visible_line_count && numeration_line < all_lines_count - 1) // -1 because '\n' treats like line(the last empty) line will be indexed
  {
    QString line_str = QString::number(numeration_line);

    QTextLayout layout(line_str, numeration_font);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    layout.endLayout();


    line.draw(&painter, QPoint( 5, y));
    qDebug() << "Drawing " << line_numerator_counter << " At:" <<  y;

    y += line_spacing + 2; //diffrence between line size and numerator size
    ++numeration_line;
    ++line_numerator_counter;
  }
}

LineNumerator::LineNumerator(QWidget *parent, std::shared_ptr<TextEngine> engine, const Qt::WindowFlags &f): text_engine(engine) {
  setParent(parent);
  parent_widget_ui = qobject_cast<CodeUI*>(parent);
  line_spacing = parent_widget_ui->getLineSpacing();
  raise();


}


