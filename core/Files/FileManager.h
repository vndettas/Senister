// 
// SPDX-License-Identifier: MIT
// /file  : FileManager.h
// Last modified: 2025-08-20 17:54
// 

#pragma once
#include "File.h"
#include <vector>
#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class File;


class FileManager {

public:

    const std::vector<std::shared_ptr<File>>& Files() const { return files; };

    void add_File(std::shared_ptr<File> file);

    std::shared_ptr<File> Active_File();

    void set_Active_File_Index(uint32_t index);

    std::shared_ptr<File> File_By_Index(uint32_t index);

private:

    std::vector<std::shared_ptr<File>> files;

    std::shared_ptr<File> active_file;


};

