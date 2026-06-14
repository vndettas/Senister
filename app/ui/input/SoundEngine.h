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

  SoundEngine                       ();

  void                              play_Background_Music(const QString& path);

  void                              play_Interactive_Sound(SoundAction action);

  void                              play_Interactive_Sound(const QString& path);

public slots:

    void                                                                    set_Active_Profile(Profile profile);

private:

  ProfileEngine*                    profile_engine;

  Profile                           active_profile;

  QMediaPlayer*                     media_player;

  QAudioOutput*                     audio_output;

  QSoundEffect*                     sound_effect;

};
