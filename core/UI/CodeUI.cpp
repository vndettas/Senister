//
// Created by vovab on 12.03.2025.
//

#include <QLayout>
#include "CodeUI.h"






CodeUI::CodeUI(std::shared_ptr<TextEngine> text_engine, std::shared_ptr<PieceOfTable> text_data_structure, QWidget* parent, const Qt::WindowFlags &f): QWidget(parent, f), text_engine(text_engine)
  {
  window()->setMinimumSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
  timer = new QTimer(this);
  line_numerator = new LineNumerator(this, text_engine);
  line_numerator->setGeometry(Constants::NUMERATION_X_OFFSET, Constants::CODE_LINES_Y_OFFSET, Constants::NUMERATION_WIDTH, this->height());
  connect(timer, &QTimer::timeout, this, &CodeUI::on_Scroll_Tick);
}

void CodeUI::resizeEvent(QResizeEvent *event) {
  QWidget::resizeEvent(event);

  line_numerator->setGeometry(Constants::NUMERATION_X_OFFSET, Constants::CODE_LINES_Y_OFFSET, Constants::NUMERATION_WIDTH, this->height());

}

void CodeUI::paintEvent(QPaintEvent* event)
  {
  QWidget::paintEvent(event);
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  QFont text_font("Lucida Sans Typewriter", 10);
  text_font.setStyleStrategy(QFont::PreferAntialias);
  text_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);

  draw_Background(&painter);

  // Text rendering
  int y=Constants::CODE_LINES_Y_OFFSET;
  float first_visible_line=scroll_offset_y / line_height;
  text_engine->setFirstVisibleLine(first_visible_line);
  float y_offset_first_line=std::fmod(scroll_offset_y, line_height);
  size_t line_counter=first_visible_line;
  painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);

  while(line_counter <= visible_line_count) {


    std::optional<QString> line=(text_engine->get_Line(line_counter));
    if(line)
    {
      QTextLayout text_layout(line.value(), text_font);
      text_layout.beginLayout();

      QTextLine text_line=text_layout.createLine();
        if(text_line.isValid())
        {
          painter.setFont(text_font);
          text_line.setLineWidth(width() - Constants::CODE_LINES_X_OFFSET);
          text_line.draw(&painter, QPoint(Constants::CODE_LINES_X_OFFSET, y));
      }
      ++line_counter;
      text_layout.endLayout();
      y+=line_spacing + 2;
    }
    else{
      ++line_counter;
    }
  }
  painter.end();
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

void CodeUI::draw_Background(QPainter *painter)
  {
  painter->fillRect(0, 0, width(), Constants::CODE_LINES_Y_OFFSET, Constants::MENU_BACKGROUND_BRUSH);
  painter->fillRect(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET,
                   width() - Constants::CODE_LINES_X_OFFSET, height() - Constants::CODE_LINES_Y_OFFSET,
                   Constants::CODE_BACKGROUND_BRUSH);
  painter->fillRect(0, 0, Constants::CODE_LINES_X_OFFSET, height(), Constants::MENU_BACKGROUND_BRUSH);


  QPen ruler_pen(Constants::LINE_NUMBER_BRUSH, 1, Qt::SolidLine);
  painter->setPen(ruler_pen);
  painter->drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(Constants::CODE_LINES_X_OFFSET, height()));
  painter->drawLine(QPoint(width() * 0.75, Constants::CODE_LINES_Y_OFFSET), QPoint(width() * 0.75, height()));
  painter->drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(width(), Constants::CODE_LINES_Y_OFFSET));
}

const uint32_t CodeUI::getLineSpacing() const {
  return line_spacing;
}


