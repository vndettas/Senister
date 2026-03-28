#pragma once
#include <QObject>
#include <iostream>
#include <QSoundEffect>
#include "../../core/profile/ProfileEngine.h"
#include <QMediaPlayer>
#include <QString>
#include <QAudioOutput>

enum class SoundAction{
  Insert_Key,
  Delete_x,
  Switch_To_Normal,
  Switch_To_Insert
};

class SoundEngine {

public:

  SoundEngine                       (ProfileEngine* sound_engine);

  void                              play_background_music(const QString& path);

private:

  ProfileEngine*                    profile_engine;

  QMediaPlayer*                     media_player;

  QAudioOutput*                     audio_output;


};
