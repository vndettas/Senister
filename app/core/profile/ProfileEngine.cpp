#include "ProfileEngine.h"
#include "profile.h"
#include <QDebug>

ProfileEngine::ProfileEngine(const QString& path)
{

   QDirIterator iterator(path, QDir::Dirs | QDir::NoDotAndDotDot);

    while(iterator.hasNext()){
    QString dirPath = iterator.next();
    QDir directory(dirPath); 

    Profile profile = create_Profile(directory);

    profiles[directory.dirName()] = profile;
   }

  set_Current_Profile(profiles["default"]);

  qDebug() << "total profiles loaded:" << profiles.size();


}

Profile
ProfileEngine::create_Profile(QDir directory)
{
    Profile profile;

    QFile file(directory.filePath("config.json"));

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Could not open file:" << file.fileName() << "Error:" << file.errorString();
        return Profile(); 
    }
    
    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();

    //parse font later
    QJsonObject sfxObj = obj["sfx"].toObject();

    profile.background_music_path = directory.absoluteFilePath(sfxObj["background_music"].toString());

    profile.switch_insert_path = directory.absoluteFilePath(sfxObj["insert_mode"].toString());

    profile.switch_normal_path = directory.absoluteFilePath(sfxObj["normal_mode"].toString());

    profile.x_delete_path =  directory.absoluteFilePath(sfxObj["x"].toString());

    QJsonArray insertSounds = sfxObj["insert"].toArray();
    for (const QJsonValue &value : insertSounds) {
        QString relPath = value.toString();
            profile.insert_sounds_path.push_back(directory.absoluteFilePath(relPath));
    }

    return profile;


}

void
ProfileEngine::set_Current_Profile(Profile profile)
{

  current_profile = profile;


}

Profile
ProfileEngine::get_Current_Profile()
{

  return current_profile;


}

