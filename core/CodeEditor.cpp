//
// Created by vovab on 12.03.2025.
//

#include "CodeEditor.h"






CodeEditor::CodeEditor(QWidget *parent, const Qt::WindowFlags &f) : QWidget(parent, f) {



}

CodeEditor::~CodeEditor() {

}

void CodeEditor::paintEvent(QPaintEvent *event) {
  QWidget::paintEvent(event);
  QPainter painter(this);
  painter.setFont(font());
  int lineheight = fontMetrics().height();
  int line_spacing = fontMetrics().lineSpacing();
  int y = 75;
  QString temp_text = "temp \n text \n penis";
  QTextLayout layout(temp_text, painter.font());
  layout.beginLayout();
  const QString& text = layout.text();
  while(true)
  {

    QTextLine line = layout.createLine();

    qDebug() << "Lines count: " << layout.lineCount();

    if (!line.isValid())
      break;

    line.setLineWidth(width());

    // check for line breaks
    QStringView line_text = text.mid(line.textStart(), line.textLength());
    if (line_text.contains('\n')) {
      line.setNumColumns(line_text.indexOf('\n') + 1);
    }

    const int nextLineY = y + line_spacing;


    if (height() >= nextLineY + line_spacing) {
      line.draw(&painter, QPoint(175, y));
      y = nextLineY;
    } else {
      const QString lastLine = temp_text.mid(line.textStart());
      const QString elidedLastLine = fontMetrics().elidedText(lastLine, Qt::ElideRight, width());
      painter.drawText(QPoint(0, y + fontMetrics().ascent()), elidedLastLine);
      line = layout.createLine();
      break;
    }
  }
    layout.endLayout();
  }





