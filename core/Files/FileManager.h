#pragma once

#include "File.h"
#include <vector>
#include <memory>
#include "../Text/PieceOfTable.h"
#include "../Text/TextEngine.h"

class File;


class FileManager {

public:

    // void add_File(File&& file) noexcept;

    const std::vector<std::shared_ptr<File>>& get_Files() const { return files; };

    void add_File(std::shared_ptr<File> file);

    std::shared_ptr<File> get_Active_File(){ return active_file; };



private:

    std::vector<std::shared_ptr<File>> files;

    std::shared_ptr<File> active_file;


};

