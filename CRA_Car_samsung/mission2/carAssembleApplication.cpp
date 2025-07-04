
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "prompter.h"
#include "inputDataProcessor.cpp"
#include "inputValidChecker.cpp"
#include "carAssembler.cpp"



char buf[100];


class CarAssembleApplication
{
public:

    int process();
    int step = CarType_Q;
    int answer = 0;
};

int CarAssembleApplication:: process()
{
    while (1)
    {
        Prompter p;
        p.printQuestion(step);

        InputDataProcessor i;
        InputValidChecker v;
        i.getUserInput(buf);

        LoopProcess loopProcess;

        loopProcess = v.checkInputValidity(buf, step, answer);

        if (loopProcess == BREAK)
            break;
        else if (loopProcess == CONTINUE)
            continue;
        CarAssembler c;

        c.assemble(step, answer);
    }
}




