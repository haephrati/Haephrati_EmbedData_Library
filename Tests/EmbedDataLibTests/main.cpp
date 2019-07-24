#include <cstdio>
#include <cstdlib>
#include "iconStaticData.h"

static void Fail(const char* msg)
{
    std::printf("FAIL %s\n", msg);
    std::exit(1);
}

int main()
{
    if (s_byIconData[0] != 0x00 || s_byIconData[1] != 0x00)
        Fail("reserved");
    if (s_byIconData[2] != 0x01 || s_byIconData[3] != 0x00)
        Fail("type");
    if (s_byIconData[4] != 0x05 || s_byIconData[5] != 0x00)
        Fail("count");
    if (s_byIconData[6] != 0x10 || s_byIconData[7] != 0x10)
        Fail("first size");
    std::printf("OK EmbedDataLibTests\n");
    return 0;
}
