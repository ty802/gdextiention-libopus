#include <defs.h>
HEADER_SUPRESS
#include "opus_classes.h"
#include <godot_cpp/classes/audio_stream.hpp>
#include <godot_cpp/godot.hpp>
class AudioStreamLiveRawOpus;
class AudioStreamLiveRawOpus : public godot::AudioStream {
  GDCLASS(AudioStreamLiveRawOpus, AudioStream);

  double bpm = 0;
  int beat_count = 0;
  int bar_beats = 4;

public:
  AudioStreamLiveRawOpus();
  virtual ~AudioStreamLiveRawOpus();

private:
  opus_decoder decoder;
};
DIAG_pop
