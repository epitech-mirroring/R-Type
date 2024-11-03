/*
** EPITECH PROJECT, 2024
** Stellar-Forge components
** File description:
** AudioSource.hpp
**/

#ifndef AUDIO_SOURCE_HPP
#define AUDIO_SOURCE_HPP

#include <SFML/Audio.hpp>

#include "../../common/components/AComponent.hpp"
#include "common/fields/groups/InvisibleFieldGroup.hpp"

class AudioSource final : public AComponent {
private:
  sf::Sound _sound;
  sf::SoundBuffer _buffer;
  std::string _clipPath;
  int _volume;
  bool _loop;
  bool _isPlaying;
  bool _mute;
  bool _playOnAwake;

public:
  explicit AudioSource(IObject *owner);
  AudioSource(IObject *owner, const std::string &clipPath, int volume, bool loop, bool playOnAwake);
  AudioSource(IObject *owner, const json::JsonObject *data);
  ~AudioSource() override = default;

  [[nodiscard]] json::IJsonObject *serializeData() override;
  void deserialize(const json::IJsonObject *data) override;
  [[nodiscard]] AudioSource *clone(IObject *owner) const override;
  void runComponent() override;

  void play();
  void pause();
  void stop();
  void setVolume(int volume);
  void setLoop(bool loop);
  void mute();

  class Meta final : public IMeta {
  protected:
    AudioSource *_owner;
    InvisibleFieldGroup _fieldGroup;

  public:
    explicit Meta(AudioSource *owner);
    [[nodiscard]] std::string getName() const override;
    [[nodiscard]] std::string getDescription() const override;
    [[nodiscard]] bool isUnique() const override;
    [[nodiscard]] bool canBeRemoved() const override;
    [[nodiscard]] std::vector<const IFieldGroup *> getFieldGroups() const override;
  };
};

#endif // AUDIO_SOURCE_HPP
