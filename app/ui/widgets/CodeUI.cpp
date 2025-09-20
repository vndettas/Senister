#include "CodeUI.h"
#include <cstdint>


CodeUI::CodeUI(std::shared_ptr<FileManager> file_manager, QWidget* parent, const Qt::WindowFlags &f): QWidget(parent, f), file_manager(file_manager)
{


  // --Widgets and window initialization
  window()->setMinimumSize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);
  timer = new QTimer(this);
  cursor = std::make_unique<Cursor>();
  line_numerator = new LineNumerator(this, text_engine);
  input_engine = std::make_unique<InputEngine>(cursor.get(),this);
  file_bar = new FileBar(this, file_manager.get());
  // Todo : the editor should open with no active file and draw something like menu
  set_Current_File(file_manager->active_File());
  // --Children widgets geometry setup--
  line_numerator->setGeometry(Constants::NUMERATION_X_OFFSET, Constants::CODE_LINES_Y_OFFSET, Constants::NUMERATION_WIDTH, this->height());
  file_bar->setGeometry(Constants::FILE_BAR_X_OFFSET, Constants::FILE_BAR_Y_OFFSET, this->width(), Constants::FILE_BAR_Y_OFFSET + Constants::FILE_BAR_HEIGHT);
  // --Signals--
  connect(timer, &QTimer::timeout, this, &CodeUI::on_Scroll_Tick);
  visible_line_count = (Constants::CODE_VIEWPORT_HEIGHT / line_height) + 1;

}



void
CodeUI::paintEvent(QPaintEvent* event)
{


  QWidget::paintEvent(event);

  QPainter painter(this);

  QFont text_font("Lucida Sans Typewriter", 10);
  text_font.setStyleStrategy(QFont::PreferAntialias);
  painter.setRenderHint(QPainter::Antialiasing, true);
  text_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);

  draw_Rectangles(&painter);
  draw_Lines(&painter);
  //-- Text pen --
  painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);

  // -- Current line one on which cursor currently located --
  size_t current_line_index = cursor->get_Current_Line_Index();
  // --Position where code area starts--
  uint32_t y_offset=Constants::CODE_LINES_Y_OFFSET;

  // -- First visible line one which is first in code area --
  float first_visible_line=scroll_offset_y / line_height;
  std::cout << first_visible_line << '\n';
  float y_offset_first_line=std::fmod(scroll_offset_y, line_height);
  std::cout << y_offset_first_line << '\n';
  uint32_t line_counter=first_visible_line;

  // -- First visible line used also in LineNumerator --
  text_engine->setFirstVisibleLine(first_visible_line);

  while (line_counter <= visible_line_count) {
    // -- Here we check if line exists, if not we dont have to print it --
    // -- So our file contains 10 lines of code but on the screen can be shown 42 we will print only 10 and wont print empty lines --
    std::optional<QString> line = text_engine->get_Line(line_counter);
    if (!line) {
      ++line_counter;
      continue;
    }

    QTextLayout text_layout(line.value(), text_font);
    text_layout.beginLayout();
    QTextLine text_line = text_layout.createLine();
    // -- Area where line can be --
    // -- If line bigger than this area it will be transfered to the next and basically will break all next lines :/ --
    text_line.setLineWidth(width() - Constants::CODE_LINES_X_OFFSET);
    text_layout.endLayout();

    if (line_counter == current_line_index) {
      draw_Cursor(&painter, &text_layout, &text_font);
    }

    if (text_line.isValid()) {
      text_line.draw(&painter, QPoint(Constants::CODE_LINES_X_OFFSET, y_offset));
    }
    ++line_counter;
    y_offset += line_spacing + 2;
  }
  painter.end();


}


void
CodeUI::resizeEvent(QResizeEvent *event)
{

  QWidget::resizeEvent(event);
  line_numerator->setGeometry(Constants::NUMERATION_X_OFFSET, Constants::CODE_LINES_Y_OFFSET, Constants::NUMERATION_WIDTH, this->height());
  file_bar->setGeometry(Constants::FILE_BAR_X_OFFSET, Constants::FILE_BAR_Y_OFFSET-Constants::FILE_BAR_HEIGHT, this->width(), Constants::FILE_BAR_Y_OFFSET);

}

void
CodeUI::wheelEvent(QWheelEvent *event)
{

  QWidget::wheelEvent(event);
  scroll_velocity -= event->angleDelta().y()/13;
  if(!timer->isActive()) timer->start(1000/120);
  update();

}

void
CodeUI::on_Scroll_Tick()
{
    // Basic inertia algorithm
  if((scroll_offset_y + scroll_velocity) > 0) scroll_offset_y += scroll_velocity;
    // Every frame makes velocity smaller till very small
  scroll_velocity = scroll_velocity * 0.96;
  if (std::abs(scroll_velocity) < 0.01f) {
    timer->stop();
    scroll_velocity = 0.0f;
  }
  update();

}

void
CodeUI::draw_Rectangles(QPainter *painter)
{

  painter->fillRect(0, 0, width(), Constants::CODE_LINES_Y_OFFSET, Constants::MENU_BACKGROUND_BRUSH);
  painter->fillRect(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET,
  width() - Constants::CODE_LINES_X_OFFSET, height() - Constants::CODE_LINES_Y_OFFSET,
  Constants::CODE_BACKGROUND_BRUSH);
  painter->fillRect(0, 0, Constants::CODE_LINES_X_OFFSET, height(), Constants::MENU_BACKGROUND_BRUSH);

  }

  void CodeUI::draw_Cursor(QPainter *painter, QTextLayout *text_layout, QFont *text_font){
    QTextCharFormat selected_char_format;
    selected_char_format.setFontPointSize(text_font->pointSizeF() + 1);
    selected_char_format.setFontWeight(QFont::Bold);

    //Symbol highlighting
    QTextLayout::FormatRange highlight;
    highlight.start = cursor->get_Current_Symbol_Index();
    highlight.length = 1;
    highlight.format = selected_char_format;

    QVector<QTextLayout::FormatRange> formats;
    formats.append(highlight);
    text_layout->setFormats(formats);

  }
  void CodeUI::draw_Lines(QPainter *painter) {
    painter->setPen(Constants::LINES_PEN);

    painter->drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
    QPoint(Constants::CODE_LINES_X_OFFSET, height()));
    painter->drawLine(QPoint(width() * 0.75, Constants::CODE_LINES_Y_OFFSET), QPoint(width() * 0.75, height()));
    painter->drawLine(QPoint(Constants::CODE_LINES_X_OFFSET, Constants::CODE_LINES_Y_OFFSET),
    QPoint(width(), Constants::CODE_LINES_Y_OFFSET));


  }

const uint32_t
CodeUI::getLineSpacing() const
{

    return line_spacing;

}

void
CodeUI::keyPressEvent(QKeyEvent *event)
{

    input_engine->handle_Key(event);

}

void
Cursor::move_Right()
{

    current_symbol_index += 1;

}

void
Cursor::move_Left()
{

    current_symbol_index -= 1;

}

void
Cursor::move_Up()
{

    current_line_index -= 1;

}

void
Cursor::move_Down()
{

    current_line_index += 1;

}

void
CodeUI::set_Current_File_Index(uint32_t index)
{


    file_manager->set_Active_File_Index(index);
    set_Current_File(file_manager->active_File());
    assert(line_numerator);
    update();


}

void
CodeUI::set_Current_File(std::shared_ptr<File> file)
{


    current_file = file;
    text_engine = file_manager->active_File()->text_Engine();
    assert(line_numerator);
    assert(text_engine);
    text_data_structure = file_manager->active_File()->text_Data_Structure();
    assert(line_numerator);
    line_numerator->set_Current_Text_Engine(text_engine);


}

Cursor*
CodeUI::get_Cursor()
{

  return cursor.get();

}

TextEngine*
CodeUI::Text_Engine()
{

  return text_engine;

}
