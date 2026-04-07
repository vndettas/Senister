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

    QString                             font;
    
    int                                 font_size;

    QString                             background_music_path;

    QString                             switch_normal_path;

    QString                             switch_insert_path;

    QString                             x_delete_path;

    std::vector<QString>                insert_sounds_path;
 

private:

   
    //Every profile should have theme
    
    //I dont have much friends so i code

};


class ProfileEngine : public QObject {

  Q_OBJECT

public:

  ProfileEngine()=delete;

  //Profile engine takes path to directory that stores profiles to initiliaze them
  ProfileEngine                         (const QString& dir_path);

  Profile                               create_Profile(QDir directory);

public slots:

  void                                  set_Active_Profile(QString profile_name);

signals:

  void                                  update_Active_Profile(Profile profile);

private:

  std::map<QString, Profile>            profiles;

  Profile                               active_profile;

};
