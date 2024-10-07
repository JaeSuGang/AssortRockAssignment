// 057_FunctionPtr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class Button
{
public:
    void Click()
    {

    }

    // 이 방식을 콜백방식이라고 합니다.
    // 자신의 맴버가가 아닌 다른 객체나 함수를 호출해주는 것을
    // 콜백방식이라고 합니다.
    // 엔진을 이용하는데 정말 중요한 문법.
    void SetClickFunction(void(*_FunctionPtr)())
    {
        FunctionPtr = _FunctionPtr;
    }


private:
    void(*FunctionPtr)() = nullptr;
};

//class PlayerAttackButton : public Button
//{
//public:
//    void Click()
//    {
//        std::cout << "플레이어가 공격합니다" << std::endl;
//    }
//};

// 함수도 주소가 있고 주소를 알고 있으면
// 그 주소를 통해서 호출할수 있다.
// 함수 포인터 이다.
void PlayerAttack()
{
    std::cout << "플레이어가 공격합니다" << std::endl;
}

void MonsterSummon()
{
    std::cout << "몬스터가 소환됩니다." << std::endl;
}

class Test
{
    void Function()
    {

    }
};

void FightUnitGetAtt()
{

}

void PlayerGetAtt()
{

}

void(*__vfptrArr[2])();

class FightUnit
{
public:
    // void(*__vfptrArr[2])();
    // void(*__vfptrArr[2])();

    void(**__vfptr)() = reinterpret_cast<void(**)()>(__vfptrArr);

    virtual void GetAtt()
    {

    }

    virtual void StatusRender()
    {

    }


public:
    FightUnit()
    {
        __vfptr = FightUnitGetAtt;

    }
};

class Player : public FightUnit
{
public:

public:
    Player()
    {
        __vfptr = PlayerGetAtt;
    }
};

int main()
{
    Player NewPlayer = Player();

    int a =  sizeof(Test);

    // 함수포인터 선언법
    // int*
    
    //리턴값 인자
    void(*FunctionPtr)() = nullptr;
    FunctionPtr = FightUnitGetAtt;


    FunctionPtr();

    int PointerSize = sizeof(FunctionPtr);

    Button PlayerAttackButton;
    Button MonsterSummonButton;

    PlayerAttackButton.SetClickFunction(PlayerAttack);
    MonsterSummonButton.SetClickFunction(MonsterSummon);

    PlayerAttackButton.Click();

    int* Ptr;

    int Arr[10];

    Ptr = Arr;

    Ptr[5] = 10;

    //int intArr[100]; 
    //int* PtrArr[100]; 
    //// int*& Ptr = PtrArr[0];
    //// int** Ptr2 = &PtrArr[0];

    //void(*FunctionPtr[10])();

    //void(**FunctionPtrP)();


    std::cout << "Hello World!\n";
}
