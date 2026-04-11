#include <QInternal>
#include "LineNumerator.h"

LineNumerator::LineNumerator(QWidget *parent, ProfileEngine* _profile_engine, const Qt::WindowFlags &f): text_engine(engine)
{

  line_height = fontMetrics().height();
  setParent(parent);
  parent_widget_ui = dynamic_cast<CodeUI *>(parent);
  line_spacing = parent_widget_ui->getLineSpacing();
  setup_Font();


}

void
LineNumerator::set_Active_Profile(Profile profile)
{

  active_profile = profile;



}

void
LineNumerator::paintEvent(QPaintEvent *event)
{

  assert(text_engine);
  QWidget::paintEvent(event);
  QPainter painter(this);
  QPen numerator_pen(Constants::TEXT_GRAY_MID);
  QPen numerator_highlighter_pen(QColor(235, 219, 178));

  painter.setPen(numerator_pen);
  painter.setFont(numerator_font);

  //Widget background
  painter.fillRect(0, 0, width(), parent_widget_ui->height(), Constants::CODE_BACKGROUND_BRUSH);

  bool isRelative = false;
  if(isRelative){


   } else {
  uint32_t y = 0; // y coordinate where line index placed
  uint32_t numeration_line = text_engine->getFirstVisibleLine();
  uint32_t line_numerator_counter = 1;
  uint32_t all_lines_count = text_engine->get_Lines_Count();
  uint32_t selected_line = parent_widget_ui->get_Cursor()->get_Current_Line_Index();


  while (numeration_line < all_lines_count)
  {
    QString line_str = QString::number(numeration_line);
    QTextLayout layout(line_str, numerator_font);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    layout.endLayout();
    line.draw(&painter, QPoint( 19, y));
    if(numeration_line == selected_line)
    {
      layout.setFont(numerator_highlighter_font);
      painter.setPen(numerator_highlighter_pen);
      line.draw(&painter, QPoint( 19, y));
      painter.setPen(numerator_pen);

    }
    y += line_spacing + 2; //diffrence between line size and numerator size
    ++numeration_line;
    ++line_numerator_counter;
   }
  }


}

void
LineNumerator::set_Current_Text_Engine(TextEngine* _text_engine)
{

  text_engine = _text_engine;
  update();


}

void
LineNumerator::setup_Font()
{

  numerator_font = QFont(profile_engine->get_Current_Profile().font, 9);
  numerator_highlighter_font = QFont(profile_engine->get_Current_Profile().font, 10);

}
