#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "define.h"
#include "util.h"
class InputValidChecker
{
public:
    LoopProcess checkInputValidity(char buf[100], int& step, int& answer)
    {
        if (!strcmp(buf, "exit"))
        {
            printf("바이바이\n");
            return LoopProcess::BREAK;
        }

        // 숫자로 된 대답인지 확인
        char* checkNumber;
        answer = strtol(buf, &checkNumber, 10); // 문자열을 10진수로 변환

        // 입력받은 문자가 숫자가 아니라면
        if (*checkNumber != '\0')
        {
            printf("ERROR :: 숫자만 입력 가능\n");
            delay(800);
            return LoopProcess::CONTINUE;
        }

        if (isInputValid(step, answer) == false)
            return LoopProcess::CONTINUE;

        // 처음으로 돌아가기

        if (isInputReturn(step, answer) == true)
            return LoopProcess::CONTINUE;

        return LoopProcess::NO_WORK;
    }

    bool isInputValid(int step, int answer)
    {
        if (step == CarType_Q && !(answer >= 1 && answer <= 3))
        {
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            return false;
        }

        if (step == Engine_Q && !(answer >= 0 && answer <= 4))
        {
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            delay(800);
            return false;
        }

        if (step == brakeSystem_Q && !(answer >= 0 && answer <= 3))
        {
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            delay(800);
            return false;
        }

        if (step == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            delay(800);
            return false;
        }

        if (step == Run_Test && !(answer >= 0 && answer <= 2))
        {
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            delay(800);
            return false;
        }
        return true;
    }

    bool isInputReturn(int& step, int answer)
    {
        if (answer == 0 && step == Run_Test)
        {
            step = CarType_Q;
            return true;
        }

        // 이전으로 돌아가기
        if (answer == 0 && step >= 1)
        {
            step -= 1;
            return true;
        }
        return false;
    }
};