#include "SoundEngine.h"

SoundEngine::SoundEngine(ProfileEngine* engine)
{

  profile_engine = engine; 
  play_background_music(profile_engine->get_Current_Profile().background_music_path);
}

void
SoundEngine::play_background_music(const QString& path)
{

  media_player->setSource(QUrl::fromLocalFile(path));
  media_player->play();


}
