//
// Created by vovab on 12.03.2025.
//

#include <QLayout>
#include "Editor.h"






Editor::Editor(QWidget *parent, const Qt::WindowFlags &f) : QWidget(parent, f), numerator(this){
  window()->setMinimumSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
  QGridLayout grid_layout;
  //this.setLayout(grid_layout);


}

void Editor::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);

  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);

  // Font setup
  QFont text_font("Lucida Sans Typewriter", 8);
  text_font.setStyle(QFont::StyleNormal);
  text_font.setStyleStrategy(QFont::PreferAntialias);
  text_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);
  painter.setFont(text_font);
  painter.setPen(Constants::TEXT_COLOR_WHITE_SOFT);

  // Backgrounds
  painter.fillRect(0, 0, width(), Constants::CODE_LINES_Y_OFFSET, Constants::MENU_BACKGROUND_BRUSH);
  painter.fillRect(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET,
                   width() - Constants::CODE_LINES_X_OFFSET,
                   height() - Constants::CODE_LINES_Y_OFFSET,
                   Constants::CODE_BACKGROUND_BRUSH);
  painter.fillRect(0, 0, Constants::CODE_LINES_X_OFFSET, height(), Constants::MENU_BACKGROUND_BRUSH);

  // Rulers
  QPen ruler_pen(Constants::LINE_NUMBER_BRUSH, 1, Qt::SolidLine);
  painter.setPen(ruler_pen);
  painter.drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(Constants::CODE_LINES_X_OFFSET, height()));
  painter.drawLine(QPoint(width() * 0.75, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(width() * 0.75, height()));
  painter.drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
                   QPoint(width(), Constants::CODE_LINES_Y_OFFSET));

  // Text rendering
  const QStringList lines = QString("temp \ntext\npenis123123131").split('\n');
  const int line_spacing = fontMetrics().lineSpacing();
  int y = Constants::CODE_LINES_Y_OFFSET;

  for (const QString& lineText : lines) {
    QTextLayout layout(lineText, text_font);
    layout.beginLayout();
    QTextLine line = layout.createLine();
    if (line.isValid()) {
      line.setLineWidth(width() - Constants::CODE_LINES_X_OFFSET);
      line.draw(&painter, QPoint(Constants::CODE_LINES_X_OFFSET, y));
    }
    layout.endLayout();
    y += line_spacing;
    if (y >= height()) break;
  }
}



Editor::~Editor() {

}

