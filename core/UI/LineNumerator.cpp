#include <QInternal>
#include "LineNumerator.h"

void LineNumerator::paintEvent(QPaintEvent *event)
{
  assert(text_engine);
  QWidget::paintEvent(event);
  QPainter painter(this);
  QPen numerator_pen(Constants::TEXT_COLOR_WHITE_PURE);
  QFont numeration_font("Lucida Sans Typewriter", 8);
  QFont numeration_font_highlighter("Lucida Sans Typewriter", 9);

  painter.setPen(numerator_pen);
  painter.setFont(numeration_font);

  //Widget background
  painter.fillRect(0, 0, width(), parent_widget_ui->height(), Constants::CODE_BACKGROUND_BRUSH);

  uint32_t y = 0;
  uint32_t numeration_line = text_engine->getFirstVisibleLine();
  uint32_t line_numerator_counter = 0;
  uint32_t all_lines_count = text_engine->get_Lines_Count();
  uint32_t selected_line = parent_widget_ui->get_Cursor_Current_Line();


  while (line_numerator_counter <= visible_line_count && numeration_line < all_lines_count)
  {
    QString line_str = QString::number(numeration_line);
    QTextLayout layout(line_str, numeration_font);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    layout.endLayout();
    line.draw(&painter, QPoint( 5, y));
    if(numeration_line == selected_line)
    {
      layout.setFont(numeration_font_highlighter);
      line.draw(&painter, QPoint( 5, y));
    }
    y += line_spacing + 2; //diffrence between line size and numerator size
    ++numeration_line;
    ++line_numerator_counter;
  }
}

LineNumerator::LineNumerator(QWidget *parent, TextEngine* engine, const Qt::WindowFlags &f): text_engine(engine)
{
  setParent(parent);
  parent_widget_ui = dynamic_cast<CodeUI *>(parent);
  line_spacing = parent_widget_ui->getLineSpacing();

}


void LineNumerator::set_Current_Text_Engine(TextEngine* _text_engine){
  text_engine = _text_engine;
  update();
}