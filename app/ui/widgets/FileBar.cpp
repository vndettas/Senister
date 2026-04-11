#include "FileBar.h"
#include "../HELPER/CONSTANTS.h"

FileBar::FileBar(QWidget *parent, FileManager* _file_manager, ProfileEngine* _profile_engine, const Qt::WindowFlags &f)
{

  setParent(parent);
  file_manager = _file_manager;
  profile_engine = _profile_engine; 



}

void
FileBar::paintEvent(QPaintEvent *event)
{

 QWidget::paintEvent(event);
 QPainter painter(this);


 assert(file_manager);

 draw_Files(&painter);
 draw_Lines(&painter);

 painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);


}


void FileBar::draw_Files(QPainter *painter)
{

  painter->save();
  painter->translate(x_scroll_offset, 0);
  
    uint32_t current_x = 0; 
    const int char_width = QWidget::fontMetrics().averageCharWidth();
    
    std::vector<std::shared_ptr<File>> files = file_manager->files();

    for(const std::shared_ptr<File>& file : files) {

    uint32_t msg_size = char_width * file->file_Name_Length();
    uint32_t tab_width = msg_size + Constants::FILE_BAR_TAB_WIDTH; 

        if(file == file_manager->active_File()) {
            painter->fillRect(current_x, 0, tab_width - 1, Constants::FILE_BAR_HEIGHT, QColor(50, 50, 50));
            painter->drawText(current_x + 10, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->file_Name()));
        } else {
            painter->fillRect(current_x, 0, tab_width - 1, Constants::FILE_BAR_HEIGHT, QColor(36, 36, 36));
            painter->drawText(current_x + 10, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->file_Name()));
        }

        painter->setPen(Constants::TEXT_COLOR_WHITE_PURE);

       painter->setPen(QPen(QColor(80, 80, 80), 1)); 
        painter->drawLine(current_x + tab_width - 1, 0, current_x + tab_width - 1, Constants::FILE_BAR_HEIGHT);

        current_x += tab_width;
    }
  painter->restore();


}

void
FileBar::draw_Lines(QPainter *painter)
{

  painter->setPen(Constants::LINES_PEN);
 // painter->drawLine(0, Constants::FILE_BAR_HEIGHT, 0, 0);
  painter->drawLine(width(), 0, 0, 0);

  QFont text_files_font = QFont(profile_engine->get_Current_Profile().font, profile_engine->get_Current_Profile().font_size);
  painter->setPen(Constants::TEXT_COLOR_WHITE_PURE);


}

void
FileBar::wheelEvent(QWheelEvent *event)
{

   uint32_t delta = event->angleDelta().y();

    uint32_t scroll_speed = 30;

    if (delta > 0) {
        x_scroll_offset += scroll_speed;
    } else if (delta < 0) {
        x_scroll_offset -= scroll_speed;
    }

    if (x_scroll_offset > 0) {
        x_scroll_offset = 0;
    }

    update(); 


}
