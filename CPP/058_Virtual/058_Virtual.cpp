// 058_Virtual.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

class StatusUnit
{
public:
    void StatusRender()
    {
        std::cout << "Status Render" << std::endl;
    }

    // 함수는 다형성이 되었습니다.
    // 오버라이드가 되었다고 합니다.
    // 즉 자식이 완전히 동일한 함수를 구현했다면
    // 철자하나도 틀리면 안된다.
    // 자식의 함수가 호출되는 문법입니다.
    // 부모의 virtual은 생략할수 없다. 
    virtual int GetAtt()
    {
        return Att;
    }

protected:
    int Att = 10;
    int Hp = 100;
};

class FightUnit : public StatusUnit
{
public:
    // 암시적 형변환중
    //            Player                           FightUnit
    // 업캐스팅 => 자식자료형이 자연(암시적으로)스럽게 부모 자료형이 되는것.
    // 매우 권장되고 자주 사용할수록 구조가 좋아지는 캐스팅 방식.
    void Damage(FightUnit& _AttUnit)
    {
        // 다형성 => 눈에보이는 형태는 같지만(여기들어온게 플레이어 일까요 몬스터일까요?)
        //                                 플레이어인지 몬스터인지는 안중요해
        //                                 둘다 fightUnit 잖아요.
        // 겉으로 드러나는 인터페이스 도 같고 GetAtt()
        // 내부의 코드와 실행 결과는 달라질수 있다.

        // 플레이어는 15가 나와야 하고
        // 몬스터 10이 나와야 한다.
        int Value = _AttUnit.GetAtt();

        // 구조가 무너지는 첫번째 신호.
        // 다운캐스팅 FightUnit => Player, Monster;
        // 부모 자료형이 자식자료형이 되는 것.
        // 위험성이 150% 이걸 써서 해결할수밖에 다 개소리입니다.
        // 정말정말정말정말 안전하게 사용하는 법으로 사용할때 빼고는 안쓸겁니다.
        // Player* Ptr = (Player*)&_AttUnit;

        Hp -= Value;
    }

    // 암시적 형변환중
    //            Player                           FightUnit
    // 업캐스팅 => 자식자료형이 자연(암시적으로)스럽게 부모 자료형이 되는것.
    // 매우 권장되고 자주 사용할수록 구조가 좋아지는 캐스팅 방식.
};

class Monster : public FightUnit
{
public:
    void StatusRender()
    {
        std::cout << "Player Status Render" << std::endl;
    }
};

class Player : public FightUnit
{
public:
    void StatusRender()
    {
        std::cout << "Player Status Render" << std::endl;
    }

    // override 명시적으로 안붙여주면 예의가 없다.
    // 자식에서는 override 명시적으로
    // 부모의 함수를 재정의 했다는 겁니다.
    int GetAtt() override
    {
        // 부모함수 호출법.
        return StatusUnit::GetAtt() + EquipAtt;
    }

    int EquipAtt = 5;
};

int main()
{
    // 업캐스팅 다운캐스팅

    Player NewPlayer;
    Monster NewMonster;

    // 내가 뭘 해줘야 하나요?
    FightUnit& Unit = NewPlayer;

    int PlayerAtt =  NewPlayer.GetAtt();

    // 다형성의 극치
    NewMonster.Damage(Unit);
    NewPlayer.Damage(NewMonster);
    
}
