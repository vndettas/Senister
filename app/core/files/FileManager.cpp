// 
// SPDX-License-Identifier: MIT
// /file  : FileManager.cpp
// Last modified: 2025-08-28 15:06
// 

#include "FileManager.h"

void
FileManager::add_File(std::shared_ptr<File> file)
{

    current_files.push_back(file);
    active_file = file;

}

const std::vector<std::shared_ptr<File>>&
FileManager::files() const
{

    return current_files;

}

void
FileManager::set_Active_File_Index(uint32_t index)
{
                                                                                                        //ToDo: make it range checking
    assert(current_files[index]);
    active_file = current_files[index];

}

std::shared_ptr<File>
FileManager::file_By_Index(uint32_t index) const
{
    
    assert(current_files[index]);
    return current_files[index];

}

std::shared_ptr<File>
FileManager::active_File() const
{

    assert(active_file);
    return active_file;

}