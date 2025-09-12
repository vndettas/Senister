//
// SPDX-License-Identifier: MIT
// /file  : FileManager.h
// Last modified: 2025-08-28 15:06
//

#pragma once
#include <files/File.h>
#include <vector>
#include <memory>
#include <text/PieceOfTable.h>
#include <text/TextEngine.h>

class File;


class FileManager {

public:

    void                                                        set_Active_File_Index(uint32_t index);

    void                                                        add_File(std::shared_ptr<File> file);

    [[nodiscard]] std::shared_ptr<File>                         file_By_Index(uint32_t index) const;

    [[nodiscard]] std::shared_ptr<File>                         active_File() const;

    const std::vector<std::shared_ptr<File>>&                   files() const;

private:

    std::vector<std::shared_ptr<File>>                   current_files;

    std::shared_ptr<File>                                active_file = nullptr;


};
