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
 
 draw_Rectangles(&painter);
 draw_Files(&painter);
 
 painter.setPen(Constants::TEXT_COLOR_WHITE_PURE);
 
}


void FileBar::draw_Files(QPainter *painter) {
  uint32_t text_position_x = 3; 
  const int char_width = QWidget::fontMetrics().averageCharWidth();
  
  std::vector<std::shared_ptr<File>> files = file_manager->Files();
  uint32_t msg_end_x = 0;

  for(const std::shared_ptr<File> file : files){
    // In order to calculate distance between vertical lines that separate file names i need width of the text and also i add some space between;
    //Todo: add icons
    uint32_t msg_size = char_width * file->FIle_Name_Length();
    
    painter->setPen(Constants::TEXT_COLOR_WHITE_PURE);


    if(file == file_manager->Active_File()){
      // File that is open in current window
      painter->fillRect(text_position_x, 0, text_position_x + msg_size + Constants::FILE_BAR_TAB_WIDTH, Constants::FILE_BAR_HEIGHT, QColor(50, 50, 50));
      painter->drawText(text_position_x, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->File_Name()));
      painter->setPen(Constants::LINES_PEN);
      painter->drawLine(msg_end_x, 0, msg_end_x, Constants::FILE_BAR_HEIGHT);
      draw_Lines(painter);
     }else if(file == nullptr){
       
    } else {
      //Other file Names
      painter->fillRect(text_position_x, 0, msg_end_x, Constants::FILE_BAR_HEIGHT, QColor(36, 36, 36));
      painter->drawText(text_position_x, Constants::FILE_BAR_TEXT_HEIGHT, QString::fromStdString(file->File_Name()));
      painter->setPen(Constants::LINES_PEN);
      painter->drawLine(msg_end_x, 0, msg_end_x, Constants::FILE_BAR_HEIGHT);
      draw_Lines(painter);
    }
    text_position_x += msg_size + Constants::FILE_BAR_TAB_WIDTH;
     msg_end_x =+ text_position_x +  msg_size + Constants::FILE_BAR_TAB_WIDTH;
  }
  
  
}


void FileBar::draw_Rectangles(QPainter *painter){
  painter->fillRect(0, 0, width(), Constants::FILE_BAR_HEIGHT, Constants::FILE_BAR_BACKGROUND_BRUSH);
}

void FileBar::draw_Lines(QPainter *painter){
  painter->setPen(Constants::LINES_PEN);
  painter->drawLine(0, Constants::FILE_BAR_HEIGHT, 0, 0);
  painter->drawLine(width(), 0, 0, 0);
  
  // -- Text font setup --
  QFont text_files_font("Lucida Sans Typewriter", 15);
  text_files_font.setStyleStrategy(QFont::PreferAntialias);
  text_files_font.setHintingPreference(QFont::HintingPreference::PreferFullHinting);
  painter->setRenderHint(QPainter::Antialiasing, true);
  painter->setPen(Constants::TEXT_COLOR_WHITE_PURE);
  
  // I get vector of available  files from file manager 
  std::vector<std::shared_ptr<File>> files = file_manager->Files();
}