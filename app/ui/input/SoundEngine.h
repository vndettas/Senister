#pragma once
#include <QObject>
#include <iostream>
#include <QSoundEffect>
#include "../../core/profile/ProfileEngine.h"
#include <QMediaPlayer>
#include <QString>
#include <QAudioOutput>
#include <QRandomGenerator>

enum class SoundAction{
  Insert_Key,
  Delete_x,
  Switch_To_Normal,
  Switch_To_Insert
};

class SoundEngine : public QObject{

  Q_OBJECT

public:

  SoundEngine                       (ProfileEngine* sound_engine);

  void                              play_Background_Music(const QString& path);

  //void                              update_Current_Profie();

  void                              play_Interactive_Sound(SoundAction action);

  void                              play_Interactive_Sound(const QString& path);

private:

  ProfileEngine*                    profile_engine;

  Profile                           current_profile;

  QMediaPlayer*                     media_player;

  QAudioOutput*                     audio_output;

  QSoundEffect*                     sound_effect;

};
