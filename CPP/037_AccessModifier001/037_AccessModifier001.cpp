#include <iostream>


class Player
{
public: 
    // 뭔가를 선언하면 모든곳에 공개한다.
    Player()
    {
    }

    void SetHp(int _Hp)
    {
        // 이 함수를 거치지 않으면
        // Hp 수정자체가 불가능합니다.
        if (_Hp == 0)
        {
            int a = 0;
        }

        Hp = _Hp;
    }

    //void Damage(int _Att)
    //{
    //    SetHp(Hp - _Att);
    //}


protected:
    // 자식에게도 공개한다.

private:
    // 내부에서만 공개한다.
    int Hp;

};

//              외부      자식내부      내부
// public:      접근      접근         접근
// protected:   불가      접근         접근
// private:     불가      불가         접근

int main()
{
    Player NewPlayer = Player();

    // 메모리 덤프 
    // reinterpret_cast<int*>(&NewPlayer);

    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(0);
    NewPlayer.SetHp(100);
    NewPlayer.SetHp(100);
    // NewPlayer.Hp = 100;
}
