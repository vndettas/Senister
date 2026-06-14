#include "SoundEngine.h"
#include <QDebug>

SoundEngine::SoundEngine()
{

  media_player = new QMediaPlayer(this);
  audio_output = new QAudioOutput(this);
  sound_effect = new QSoundEffect(this);
  media_player->setAudioOutput(audio_output);
  audio_output->setVolume(0.1);
  
  play_Background_Music(active_profile.background_music_path);


}

void
SoundEngine::play_Background_Music(const QString& path)
{

  media_player->setSource(QUrl::fromLocalFile(path));
  media_player->play();
  media_player->setLoops(QMediaPlayer::Loops::Infinite);


}

void
SoundEngine::set_Active_Profile(Profile profile)
{

  active_profile = profile;


}


void
SoundEngine::play_Interactive_Sound(const QString& path)
{

  sound_effect->setSource(QUrl::fromLocalFile(path));
  sound_effect->setVolume(0.2);
  sound_effect->play();


}

void
SoundEngine::play_Interactive_Sound(SoundAction action)
{
  switch (action) {
    case SoundAction::Insert_Key:
      {

      uint32_t insert_variations_count = active_profile.insert_sounds_path.size();
      QString sound_path = active_profile.insert_sounds_path[QRandomGenerator::global()->bounded(insert_variations_count - 1)];
      play_Interactive_Sound(sound_path);
      break;
      }

    case SoundAction::Switch_To_Normal:
      {
      play_Interactive_Sound(active_profile.switch_normal_path);
      break;
      }

    case SoundAction::Switch_To_Insert:
      {
      play_Interactive_Sound(active_profile.switch_insert_path);
      break;
      }

    case SoundAction::Delete_x:
      {
      play_Interactive_Sound(active_profile.x_delete_path);
      break;
      }

    default:

      {
      break;
      }

}


}
