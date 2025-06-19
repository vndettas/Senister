//
// Created by vovab on 19.06.2025.
//

#ifndef VEDITOR_FILEMANAGER_H
#define VEDITOR_FILEMANAGER_H

#include "File.h"
#include <vector>
class FileManager {

public:

    void add_File(File&& file) noexcept;



private:

    std::vector<File> files;


};


#endif //VEDITOR_FILEMANAGER_H
