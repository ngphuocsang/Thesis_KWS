#include <cstring>
#include <vector>
#include <string>
#include "KWS.h"

using namespace std;

class KWSInstance : public KWS
{
private:
    static KWSInstance *_instance;
    KWSInstance();
    KWSInstance(int recording_window, int sliding_window_len, std::vector<std::string>& output_class, int detection_threshold);
    ~KWSInstance();
public:
    static KWSInstance* getInstance();
    void StartKWS(void);
    void RunKWS(void);
    void StartRecording(void);
    void StopRecording(void);
    void SetAudioBufferEmpty(void);
    void ConvertStereoBufToMonoBuffer(void);

    
};


extern KWSInstance* KWSInstancePtr;