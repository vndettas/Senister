#include "App.h"

App::App()
{

  file_manager = std::make_shared<FileManager>();
  profile_manager = std::make_unique<ProfileEngine>("/home/vendetta/github/Senister/profiles/");
  sound_engine = std::make_unique<SoundEngine>(profile_manager.get());
  std::shared_ptr<File> third_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
  std::shared_ptr<File> first_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
  file_manager->add_File(third_file);
  std::shared_ptr<File> second_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
  file_manager->add_File(second_file);
  std::shared_ptr<File> fourth_file = std::make_shared<File>("/home/vendetta/github/Senister/test/test.cpp");
  file_manager->add_File(fourth_file);
  window = std::make_unique<CodeUI>(file_manager, sound_engine.get());

  window->show();


}
