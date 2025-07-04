#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "carAssembleApplication.cpp"

int main()
{
    CarAssembleApplication c;
    c.process();

    return 0;
}



#endif