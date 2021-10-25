#include <cstring>
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_audio.h"
#include "stm32746g_discovery_sdram.h"
#include "mbed_assert.h"
#include "AudioUtils.h"
#include "KWSInstance.h"
#include "DefineMacros.h"


typedef enum {
    BUFFER_OFFSET_NONE = 0,
    BUFFER_OFFSET_FULL = 1,
} BUFFER_StateTypeDef;

extern KWSInstance* KWSInstancePtr;

void BSP_AUDIO_IN_TransferComplete_CallBack(void)
{

}

void BSP_AUDIO_IN_HalfTransfer_CallBack(void)
{
}

/**
 * @brief  Audio IN Error callback function
 */
void BSP_AUDIO_IN_Error_CallBack(void)
{
    MBED_ASSERT(0);
}

AudioUtils::AudioUtils()
{
    this->initSDRAM();
}

AudioUtils::~AudioUtils()
{
}

void AudioUtils::initSDRAM(void){
    BSP_SDRAM_Init();
    memset((uint16_t*)AUDIO_BUFFER_IN, 0, AUDIO_BLOCK_SIZE * sizeof(uint16_t));
    printf("\nSDRAM init done\n");
}

void AudioUtils::initAudio(uint16_t* audioBufferIn, uint32_t numOfElements){
    if (BSP_AUDIO_IN_InitEx(INPUT_DEVICE_DIGITAL_MICROPHONE_2,DEFAULT_AUDIO_IN_FREQ, DEFAULT_AUDIO_IN_BIT_RESOLUTION, DEFAULT_AUDIO_IN_CHANNEL_NBR) != AUDIO_OK)
    {
        printf("BSP_AUDIO_IN_Init error\r\n");
    }

    /* Start Recording */
    if (BSP_AUDIO_IN_Record((uint16_t *)audioBufferIn, numOfElements) != AUDIO_OK)
    {
        printf("BSP_AUDIO_IN_Record init error\r\n");
    }

    /* Stop Recording until memory allocation etc for model is complete*/
    if (BSP_AUDIO_IN_Stop(CODEC_PDWN_SW) != AUDIO_OK)
    {
        printf("BSP_AUDIO_IN_Stop error\r\n");
    }

    this->audio_rec_buffer_state = BUFFER_OFFSET_NONE;

    printf("AUDIO recording configured from digital microphones (U20 & U21 components on board) \r\n");
}

void AudioUtils::startAudioRecording(uint16_t* audioBufferIn, uint32_t numOfElements){
    if (BSP_AUDIO_IN_Record(audioBufferIn, numOfElements) != AUDIO_OK)
    {
        printf("BSP_AUDIO_IN_Record error\r\n");
    }
}

void AudioUtils::stopAudioRecording(void){
    if (BSP_AUDIO_IN_Stop(CODEC_PDWN_SW) != AUDIO_OK)
    {
        printf("BSP_AUDIO_Stop error\r\n");
    }
}

bool AudioUtils::isAudioAvailable(void){
    return this->audio_rec_buffer_state == BUFFER_OFFSET_FULL;
}

bool AudioUtils::isAudioUnavailable(void){
    return this->audio_rec_buffer_state == BUFFER_OFFSET_NONE;
}

void AudioUtils::setAudioBufferEmpty(void){
    this->audio_rec_buffer_state = BUFFER_OFFSET_NONE;
}

void AudioUtils::setAudioBufferFull(void){
    this->audio_rec_buffer_state = BUFFER_OFFSET_FULL;
}