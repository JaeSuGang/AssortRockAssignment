﻿// TextRPG002inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>

//class PlayerSaveData
//{
//public:
//    int Hp;
//    int Att;
//};

const int LINECOUNT = 50;

const int NAMELEN = 20;

// 다중상속을 부정적으로 생각하는 사람이 많아요.
// 1. 다중상속을 제대로 못쓰니까.
// 2. 제대로 쓸줄 알아도 다른 사람들을 못믿으니까.

// 좀더 근본에 가까운 기능과 데이터들이 뭐냐를 판단하는 능력.
// 상속구조의 절대 금기.

class StatusUnit
{
public:
    void StatusRender()
    {
        printf_s("%s Status", Name);
        int NameLan = static_cast<int>(strlen(Name));
        int StatusRand = static_cast<int>(strlen(" Status"));
        int nameLineCount = LINECOUNT - NameLan - StatusRand;
        for (int i = 0; i < nameLineCount; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("공격력 : %d ~ %d\n", MinAtt, MaxAtt);
        printf_s("체력 : %d\n", Hp);

        for (int i = 0; i < LINECOUNT; i += 1)
        {
            printf_s("-");
        }
        printf_s("\n");
    }

    // Set을 체크하는것을 좋아해서
    // private:

    void SetName(const char* const _Name)
    {
        if (NAMELEN <= strlen(_Name))
        {
            // 이 사태가 벌어졌다는것을 어떻게 인지할건가요?
            return;
        }

        strcpy_s(Name, _Name);
    }

protected:
    char Name[NAMELEN] = "NONE";
    int Hp = 100;
    int MinAtt = 10;
    int MaxAtt = 20;
    int Speed = 10;

private:
};

class FightUnit : public StatusUnit
{
public:
    // MinMax
    int GetDamage() const
    {
        // minAtt ~ MaxAtt 사이의 숫자가 리턴되는 함수를 만드세요.
        return MinAtt + (rand() % (MaxAtt - MinAtt + 1));
    }

    void Damage(const FightUnit& _AttUnit)
    {
        int Damage = _AttUnit.GetDamage();
        DamageLogic(Damage);
        DamageRender(_AttUnit, Damage);
    }

    // 클래스의 레퍼런스를 넣어주는것이 많은게 간단해 집니다.
    void DamageLogic(const int _Damage)
    {
        // _AttUnit => 나를 공격하려는 상대
        Hp -= _Damage;
    }

    // 잘못된 코딩이다.
    void DamageRender(const FightUnit& _AttUnit, int _Damage)
    {
        printf_s("%s 가 %s를 공격해서 %d의 데미지를 입혔습니다.\n", _AttUnit.Name, Name, _Damage);
    }

    const char* GetName() const
    {
        return Name;
    }

protected:


private:
};

// 컴포넌트 방식이라는 것과 차이가 거의 없다.
// 보통 상속구조와 컴포넌트 기반구조가 게임의 로직계를 지배하고 있다.
// 

class Player : public FightUnit
{
};

class Monster : public FightUnit
{

};


// 게임을 만들다보면
// 일반적인 로직클래스 Player
// 리소스 클래스 <= 
// 데이터 전담클래스가 <= 내부에 변수밖에 없다. 
// 맴버변수도 public을 사용합니다.

int main()
{
    
    srand(static_cast<unsigned int>(time(0)));

    Player NewPlayer;
    Monster NewMonster;

    NewPlayer.SetName("Player");
    NewMonster.SetName("fadshjklfasdhjklfasdhjk");


    while (true)
    {
        system("cls");
        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        _getch();

        system("cls");
        int PlayerDamage = NewPlayer.GetDamage();
        NewMonster.DamageLogic(PlayerDamage);
        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        NewMonster.DamageRender(NewPlayer, PlayerDamage);


        _getch();

        system("cls");
        int MonsterDamage = NewMonster.GetDamage();
        NewPlayer.DamageLogic(MonsterDamage);

        NewPlayer.StatusRender();
        NewMonster.StatusRender();
        NewMonster.DamageRender(NewPlayer, PlayerDamage);
        NewPlayer.DamageRender(NewMonster, MonsterDamage);


        _getch();

    }

    // NewPlayer.
}
