// 
// SPDX-License-Identifier: MIT
// /file  : FileManager.cpp
// Last modified: 2025-08-12 17:39
// 

#include "FileManager.h"

// void FileManager::add_File(File &&file) noexcept{
//   files.push_back(std::move(file));
// }

void FileManager::add_File(std::shared_ptr<File> file){
    files.push_back(file);
    active_file = file;
}

void FileManager::set_Active_File_Index(uint32_t index){
    assert(files[index]);
    active_file = files[index];
}
std::shared_ptr<File> FileManager::get_File_By_Index(uint32_t index){
    assert(files[index]);
    return files[index];
}
std::shared_ptr<File> FileManager::get_Active_File(){
    assert(active_file);
    return active_file;
}