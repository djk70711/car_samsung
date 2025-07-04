#include "carValidator.h"

bool CarValidator::validate(Car* car) {
    Engine* engine = car->getEngine();
    BrakeSystem* brakeSystem = car->getBrakeSystem();
    SteeringSystem* steeringSystem = car->getSteeringSystem();

    if (car->getCarType() == SEDAN && brakeSystem->getBrakeSystemName() == CONTINENTAL)                     return false;
    if (car->getCarType() == SUV && engine->getEngineName() == TOYOTA)                                      return false;
    if (car->getCarType() == TRUCK && engine->getEngineName() == WIA)                                       return false;
    if (car->getCarType() == TRUCK && brakeSystem->getBrakeSystemName() == MANDO)                           return false;
    if (brakeSystem->getBrakeSystemName() == BOSCH_B && steeringSystem->getSteeringSystemName() != BOSCH_S) return false;

    return true;
}

void CarValidator::testProducedCar(Car* car) {
    Engine* engine = car->getEngine();
    BrakeSystem* brakeSystem = car->getBrakeSystem();
    SteeringSystem* steeringSystem = car->getSteeringSystem();

    if (car->getCarType() == SEDAN && brakeSystem->getBrakeSystemName() == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        return;
    }
    if (car->getCarType() == SUV && engine->getEngineName() == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        return;
    }
    if (car->getCarType() == TRUCK && engine->getEngineName() == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
        return;
    }
    if (car->getCarType() == TRUCK && brakeSystem->getBrakeSystemName() == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
        return;
    }
    if (brakeSystem->getBrakeSystemName() == BOSCH_B && steeringSystem->getSteeringSystemName() != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch ������ġ �̿� ��� �Ұ�\n");
        return;
    }

    printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
}