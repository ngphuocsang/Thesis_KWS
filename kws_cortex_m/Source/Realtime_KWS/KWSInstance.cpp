#include "KWSInstance.h"
#include "DefineMacros.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_audio.h"

KWSInstance *KWSInstance::_instance = NULL;

KWSInstance *KWSInstance::getInstance(){
    if(_instance == NULL){
        _instance = new KWSInstance();
    }
    return _instance;
}

KWSInstance::KWSInstance(int recording_window, int sliding_window_len, std::vector<std::string>& output_class, int detection_threshold)
        : KWS(recording_window, sliding_window_len)     
{
    
}

