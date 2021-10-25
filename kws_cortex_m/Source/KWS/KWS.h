#include <arm_math.h>

class KWS
{
private:
    /* data */
public:
    KWS(int recording_window, int sliding_window_len);
    ~KWS();
    void ExtractFeatures(void);
    void Classify(void);
};

KWS::KWS(int recording_window, int sliding_window_len)
{
}

KWS::~KWS()
{
}
