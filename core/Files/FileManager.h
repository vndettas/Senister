// 
// SPDX-License-Identifier: MIT
// /file  : FileManager.h
// Last modified: 2025-08-28 15:06
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

    const std::vector<std::shared_ptr<File>>&                   files() const;

    [[nodiscard]] std::shared_ptr<File>                         file_By_Index(uint32_t index) const;
    
    [[nodiscard]] std::shared_ptr<File>                         active_File() const;
    
    void                                                        set_Active_File_Index(uint32_t index);
    
    void                                                        add_File(std::shared_ptr<File> file);

private:

    std::vector<std::shared_ptr<File>>                   current_files;

    std::shared_ptr<File>                                active_file;


};

