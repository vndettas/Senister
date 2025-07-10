//
// Created by vovab on 19.06.2025.
//

#include "FileManager.h"

// void FileManager::add_File(File &&file) noexcept{
//   files.push_back(std::move(file));
// }

void FileManager::add_File(std::shared_ptr<File> file){
    files.push_back(file);
    active_file = file;
}