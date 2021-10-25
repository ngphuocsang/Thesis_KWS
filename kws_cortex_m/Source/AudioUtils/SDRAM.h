#include <stdint.h>
#include <cstring>
#include "DefineMacros.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_sdram.h"


class SDRAM
{
private:
    /* data */
public:
    SDRAM(/* args */);
    ~SDRAM();
    void InitSDRAM();
    void assign(int16_t value, uint32_t numOfElements);
    int16_t* data();
    int16_t at(int32_t elementAddr);
};

SDRAM::SDRAM(/* args */)
{
}

SDRAM::~SDRAM()
{
}

void SDRAM::InitSDRAM(){
    BSP_SDRAM_Init();
    memset((uint16_t*)SDRAM_DEVICE_ADDR, 0, )
}

void
