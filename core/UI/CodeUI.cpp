//
// Created by vovab on 12.03.2025.
//

#include <QLayout>
#include "CodeUI.h"






CodeUI::CodeUI(std::shared_ptr<TextEngine> text_engine, std::shared_ptr<PieceOfTable> text_data_structure, QWidget* parent, const Qt::WindowFlags &f): QWidget(parent, f), text_engine(text_engine)
{
  window()->setMinimumSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
  timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &CodeUI::on_Scroll_Tick);
}

void CodeUI::paintEvent(QPaintEvent* event)
{
  QWidget::paintEvent(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  // Font setup
  QFont text_font("Lucida Sans Typewriter", 9);
  text_font.setStyleStrategy(QFont::PreferAntialias);
  text_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);
  painter.setFont(text_font);

  // Backgrounds
  painter.fillRect(0, 0, width(), Constants::CODE_LINES_Y_OFFSET, Constants::MENU_BACKGROUND_BRUSH);
  painter.fillRect(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET,
                   width() - Constants::CODE_LINES_X_OFFSET, height() - Constants::CODE_LINES_Y_OFFSET,
                   Constants::CODE_BACKGROUND_BRUSH);
  painter.fillRect(0, 0, Constants::CODE_LINES_X_OFFSET, height(), Constants::MENU_BACKGROUND_BRUSH);

  //Lines
  QPen ruler_pen(Constants::LINE_NUMBER_BRUSH, 1, Qt::SolidLine);
  painter.setPen(ruler_pen);
  painter.drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(Constants::CODE_LINES_X_OFFSET, height()));
  painter.drawLine(QPoint(width() * 0.75, Constants::CODE_LINES_Y_OFFSET), QPoint(width() * 0.75, height()));
  painter.drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(width(), Constants::CODE_LINES_Y_OFFSET));

  // Text rendering
  const int line_spacing=fontMetrics().lineSpacing();
  int y=Constants::CODE_LINES_Y_OFFSET;
  int line_height=fontMetrics().height();
  float first_visible_line=scroll_offset_y / line_height;
  float y_offset_first_line=std::fmod(scroll_offset_y, line_height);
  size_t visible_line_count=(Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;
  size_t line_counter=first_visible_line;
  painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);

  while(line_counter <= visible_line_count) {

    std::optional<QString> line=(text_engine->get_Line(line_counter));
    if(line) {
      QTextLayout layout(line.value(), text_font);
      layout.beginLayout();
      QTextLine l=layout.createLine();
      if(l.isValid()) {
        l.setLineWidth(width() - Constants::CODE_LINES_X_OFFSET);
        l.draw(&painter, QPoint(Constants::CODE_LINES_X_OFFSET, y));
      }
      ++line_counter;
      layout.endLayout();
      y+=line_spacing + 2;
    }
    else{

    }
  }
}


void CodeUI::wheelEvent(QWheelEvent *event)
{
  QWidget::wheelEvent(event);
  scroll_velocity -= event->angleDelta().y()/11;
  if(!timer->isActive()) timer->start(1000/120);
  update();
}

void CodeUI::on_Scroll_Tick()
{
  if((scroll_offset_y + scroll_velocity) > 0) scroll_offset_y += scroll_velocity;
  scroll_velocity = scroll_velocity * 0.92;
  if (std::abs(scroll_velocity) < 0.01f) {
    timer->stop();
    scroll_velocity = 0.0f;
  }
  update();

}

