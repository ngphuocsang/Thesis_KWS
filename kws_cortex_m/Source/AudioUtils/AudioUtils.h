#include <cstdint>

using namespace std;


class AudioUtils
{
private:
    /* data */

public:
    AudioUtils();
    ~AudioUtils();
    void initAudio(uint16_t* audioBufferIn, uint32_t numOfElements);
    void initSDRAM(void);
    void startAudioRecording(uint16_t* audioBufferIn, uint32_t numOfElements);
    void stopAudioRecording(void);
    void setAudioBufferEmpty(void);
    void setAudioBufferFull(void);
    bool isAudioAvailable(void);
    bool isAudioUnavailable(void);

    uint32_t audio_rec_buffer_state;
};

