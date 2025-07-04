#include "carRunner.h"

void CarRunner::runProducedCar(Car* car)
{
    Engine* engine = car->getEngine();
    BrakeSystem* brakeSystem = car->getBrakeSystem();
    SteeringSystem* steeringSystem = car->getSteeringSystem();

    if (CarValidator::validate(car) == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (engine->getEngineName() == BROKEN)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        return;
    }

    if (car->getCarType() == SEDAN)                             printf("Car Type : Sedan\n");
    else if (car->getCarType() == SUV)                          printf("Car Type : SUV\n");
    else if (car->getCarType() == TRUCK)                        printf("Car Type : Truck\n");

    if (engine->getEngineName() == GM)                          printf("Engine : GM\n");
    else if (engine->getEngineName() == TOYOTA)                 printf("Engine : TOYOTA\n");
    else if (engine->getEngineName() == WIA)                    printf("Engine : WIA\n");

    if (brakeSystem->getBrakeSystemName() == MANDO)             printf("Brake System : Mando");
    else if (brakeSystem->getBrakeSystemName() == CONTINENTAL)  printf("Brake System : Continental\n");
    else if (brakeSystem->getBrakeSystemName() == BOSCH_B)      printf("Brake System : Bosch\n");

    if (steeringSystem->getSteeringSystemName() == BOSCH_S)     printf("SteeringSystem : Bosch\n");
    else if (steeringSystem->getSteeringSystemName() == MOBIS)  printf("SteeringSystem : Mobis\n");

    printf("�ڵ����� ���۵˴ϴ�.\n");
}