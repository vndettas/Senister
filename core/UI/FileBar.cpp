#include "FileBar.h"
#include "../HELPER/CONSTANTS.h"

FileBar::FileBar(QWidget *parent, FileManager* _file_manager, const Qt::WindowFlags &f) {
    setParent(parent);
    file_manager = _file_manager;
}

void FileBar::paintEvent(QPaintEvent *event) {
 QWidget::paintEvent(event);
 QPainter painter(this);
 

 assert(file_manager);
 QFont text_font("Lucida Sans Typewriter", 10);
 text_font.setStyleStrategy(QFont::PreferAntialias);
 painter.setRenderHint(QPainter::Antialiasing, true);
 text_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);


 draw_Rectangles(&painter);
 draw_Lines(&painter);         
 draw_Files(&painter);
 painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);
 
}

void FileBar::draw_Rectangles(QPainter *painter){
  painter->fillRect(0, 0, width(), Constants::FILE_BAR_HEIGHT, Constants::FILE_BAR_BACKGROUND_BRUSH);
}

void FileBar::draw_Lines(QPainter *painter){
QPen ruler_pen(Constants::LINE_NUMBER_BRUSH, 2, Qt::SolidLine);
painter->setPen(ruler_pen);
painter->drawLine(0, Constants::FILE_BAR_HEIGHT, 0, 0);
painter->drawLine(width(), 0, 0, 0);

}
void FileBar::draw_Files(QPainter *painter) {
  

 QFont text_files_font("Lucida Sans Typewriter", 15);
 text_files_font.setStyleStrategy(QFont::PreferAntialias);
 text_files_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);
 painter->setRenderHint(QPainter::Antialiasing, true);
 painter->setPen(Constants::TEXT_COLOR_WHITE_PURE);
 
 std::vector<std::shared_ptr<File>> files = file_manager->get_Files();

 uint32_t x = 3; 
 const int c_width = QWidget::fontMetrics().averageCharWidth();
 for(const std::shared_ptr<File> file : files){
  uint32_t msg_size = c_width * file->get_File_Name_Length();
  uint32_t msg_end_x = x + msg_size + Constants::FILE_BAR_TAB_WIDTH;

 if(file == file_manager->get_Active_File()){
  painter->drawText(x, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->get_File_Name()));
  QPen ruler_pen(Constants::LINE_NUMBER_BRUSH, 2, Qt::SolidLine);
  painter->setPen(ruler_pen);
  painter->drawLine(msg_end_x, 0, msg_end_x, Constants::FILE_BAR_HEIGHT);
  painter->setPen(ruler_pen);

 } else {
  painter->drawText(x, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->get_File_Name()));
  painter->drawLine(msg_end_x, 0, msg_end_x, Constants::FILE_BAR_HEIGHT);
  painter->setPen(ruler_pen);
 }
 x += msg_end_x;
}


}