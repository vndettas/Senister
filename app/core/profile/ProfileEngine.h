#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include <QString>
#include <map>
#include <QDirIterator>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class Profile {
public:

    QString                             profile_name;

    //QFont                               profile_font;

    QString                             background_music_path;

    std::vector<QString>                interactive_sounds_path;
 

private:

   
    //Every profile should have theme
    
    //I dont have much friends so i code

};


class ProfileEngine {
public:

  ProfileEngine()=delete;

  //Profile engine takes path to directory that stores profiles to initiliaze them
  ProfileEngine                         (const QString& dir_path);

  void                                  set_Current_Profile(Profile name);

  Profile                               get_Current_Profile();

  Profile                               create_Profile(QDir directory);

private:

  std::map<QString, Profile>            profiles;

  Profile                               current_profile;

};
