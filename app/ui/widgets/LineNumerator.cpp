#include <QInternal>
#include <QFontInfo>
#include "LineNumerator.h"

LineNumerator::LineNumerator(QWidget *parent, TextEngine* text_engine, const Qt::WindowFlags &f): text_engine{text_engine} 
{

  line_height = fontMetrics().height();
  setParent(parent);
  parent_widget_ui = dynamic_cast<CodeUI *>(parent);


}

void
LineNumerator::set_Active_Profile(Profile profile)
{

  active_profile = profile;
  setup_Font();


}

void
LineNumerator::paintEvent(QPaintEvent *event)
{

  assert(text_engine);
  QWidget::paintEvent(event);
  QPainter painter(this);
  QPen numerator_pen(Constants::TEXT_GRAY_MID);
  QPen numerator_highlighter_pen(QColor(236, 219, 178));

  painter.setPen(numerator_pen);
  painter.setFont(numerator_font);

  //Widget background
  painter.fillRect(0, 0, width(), parent_widget_ui->height(), Constants::CODE_BACKGROUND_BRUSH);

  bool isRelative = true;
  
  line_spacing = parent_widget_ui->get_Line_Spacing();

  if(isRelative){
  long numeration_line = text_engine->getFirstVisibleLine();
  uint32_t all_lines_count = text_engine->get_Lines_Count();
  long selected_line = parent_widget_ui->get_Cursor()->get_Current_Line_Index();

  float exact_scroll = static_cast<float>(parent_widget_ui->get_Current_File()->get_scroll_offset()) / line_spacing;
  float int_part = 0.0f;
  float rem = std::modf(exact_scroll, &int_part);
  float y = -(line_spacing * rem); 

  while (numeration_line < all_lines_count)
  {
      QString line_str = "";
      if(numeration_line != selected_line) {
        line_str = QString::number(std::abs(numeration_line - selected_line));
      } else {
        line_str = QString::number(selected_line);
      }
      QTextLayout text_layout(line_str, numerator_font);
      text_layout.beginLayout();
      QTextLine line = text_layout.createLine();
      text_layout.endLayout();

      if(numeration_line == selected_line) {
          text_layout.setFont(numerator_highlighter_font);
          painter.setPen(numerator_highlighter_pen);
          line.draw(&painter, QPointF(10, y));
          painter.setPen(numerator_pen);
      } else {
          line.draw(&painter, QPointF(19, y));
      }
      
      y += line_spacing;
      ++numeration_line;
      if (y > height()) break;
    }


  } else {

  uint32_t numeration_line = text_engine->getFirstVisibleLine();
  uint32_t all_lines_count = text_engine->get_Lines_Count();
  uint32_t selected_line = parent_widget_ui->get_Cursor()->get_Current_Line_Index();

  float exact_scroll = static_cast<float>(parent_widget_ui->get_Current_File()->get_scroll_offset()) / line_spacing;
  float int_part = 0.0f;
  float rem = std::modf(exact_scroll, &int_part);
  float y = (line_spacing * rem); 

  while (numeration_line < all_lines_count)
  {
      QString line_str = QString::number(numeration_line);
      QTextLayout text_layout(line_str, numerator_font);
      text_layout.beginLayout();
      QTextLine line = text_layout.createLine();
      text_layout.endLayout();

      if(numeration_line == selected_line) {
          text_layout.setFont(numerator_highlighter_font);
          painter.setPen(numerator_highlighter_pen);
          line.draw(&painter, QPointF(19, y));
          painter.setPen(numerator_pen);
      } else {
          line.draw(&painter, QPointF(19, y));
      }
      
      y += line_spacing;
      ++numeration_line;
      if (y > height()) break;
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

  numerator_font = QFont(active_profile.font, active_profile.font_size - 1);
  numerator_highlighter_font = QFont(active_profile.font, active_profile.font_size - 1);
  QFontInfo info(numerator_font);
  qDebug() << "LineNumerator font setup";
  qDebug() << "Requested font:" << numerator_font.family();
  qDebug() << "Actual used font:" << info.family(); 

}
