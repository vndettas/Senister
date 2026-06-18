#include "FileBar.h"
#include "../HELPER/CONSTANTS.h"

FileBar::FileBar(QWidget *parent, FileManager* _file_manager,const Qt::WindowFlags &f)
{

  setParent(parent);
  file_manager = _file_manager;


}

void
FileBar::paintEvent(QPaintEvent *event)
{

 QWidget::paintEvent(event);
 QPainter painter(this);


 assert(file_manager);

 draw_Files(&painter);

 painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);


}

void FileBar::draw_Files(QPainter *painter)
{
    painter->save();
    painter->translate(x_scroll_offset, 0);
    
    QFont text_files_font = QFont(active_profile.font, active_profile.font_size - 1);
    text_files_font.setWeight(QFont::Normal);
    painter->setFont(text_files_font);
    
    uint32_t current_x = 0; 
    QFontMetrics fm = painter->fontMetrics();
    
    QString cross_symbol = "×"; 
    uint32_t cross_width = fm.horizontalAdvance(cross_symbol);
    
    uint32_t pad_left = 15;
    uint32_t pad_middle = 15;
    uint32_t pad_right = 18;
    uint32_t pad_top = 6;
    
    std::vector<std::shared_ptr<File>> files = file_manager->files();

    for(const std::shared_ptr<File>& file : files) {
        QString file_name = QString::fromStdString(file->file_Name());

        uint32_t text_width = fm.horizontalAdvance(file_name); 
        
        uint32_t tab_width = pad_left + text_width + pad_middle + cross_width + pad_right; 
        QRect tab_rect(current_x, 0, tab_width, Constants::FILE_BAR_HEIGHT);

        QColor bg_color, text_color, cross_color;

        if(file == file_manager->active_File()) {
            bg_color = QColor(30, 30, 30);
            text_color = QColor(210, 210, 210); 
            cross_color = QColor(251, 73, 52);
        } else {
            bg_color = QColor(33, 33, 33);
            text_color = QColor(88, 83, 85);
            cross_color = QColor(88, 83, 85);
        }

        painter->fillRect(tab_rect, bg_color);

        int text_y = pad_top + fm.ascent();

        painter->setPen(text_color);
        int text_x = current_x + pad_left;
        painter->drawText(text_x, text_y, file_name);

        painter->setPen(cross_color);
        int cross_x = text_x + text_width + pad_middle;
        painter->drawText(cross_x, text_y, cross_symbol);

        current_x += tab_width;
    }
    
    painter->restore();
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
void
FileBar::set_Active_Profile(Profile profile)
{

  active_profile = profile;


}
