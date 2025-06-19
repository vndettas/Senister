//
// Created by vovab on 12.03.2025.
//

#include <QLayout>
#include "CodeUI.h"






CodeUI::CodeUI(std::shared_ptr<TextEngine> text_engine, std::shared_ptr<PieceOfTable> text_data_structure, QWidget* parent, const Qt::WindowFlags &f): QWidget(parent, f), text_engine(text_engine)
  {
  window()->setMinimumSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
  timer = new QTimer(this);
  cursor = std::make_unique<Cursor>();
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
  size_t current_line_index = cursor->get_Current_Line();

  draw_Background(&painter);

  uint32_t y=Constants::CODE_LINES_Y_OFFSET;
  float first_visible_line=scroll_offset_y / line_height;
  text_engine->setFirstVisibleLine(first_visible_line);
  float y_offset_first_line=std::fmod(scroll_offset_y, line_height);
  uint32_t line_counter=first_visible_line;
  painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);

    while (line_counter <= visible_line_count) {
      std::optional<QString> line = text_engine->get_Line(line_counter);
      if (!line) {
        ++line_counter;
        continue;
      }

      QTextLayout text_layout(line.value(), text_font);
      text_layout.beginLayout();
      QTextLine text_line = text_layout.createLine();
      text_line.setLineWidth(width() - Constants::CODE_LINES_X_OFFSET);
      text_layout.endLayout();

      if (line_counter == current_line_index) {
        QTextCharFormat selected_char_format;
        selected_char_format.setFontPointSize(text_font.pointSizeF() + 1);
        selected_char_format.setFontWeight(QFont::Bold);

        QTextLayout::FormatRange highlight;
        highlight.start = cursor->get_Current_Symbol_Index();
        highlight.length = 1;
        highlight.format = selected_char_format;

        QVector<QTextLayout::FormatRange> formats;
        formats.append(highlight);
        text_layout.setFormats(formats);
      }

      if (text_line.isValid()) {
        text_line.draw(&painter, QPoint(Constants::CODE_LINES_X_OFFSET, y));
      }

      ++line_counter;
      y += line_spacing + 2;
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

void CodeUI::Keypressed(QKeyEvent *event) {
  emit keyPressEvent(event);
}


