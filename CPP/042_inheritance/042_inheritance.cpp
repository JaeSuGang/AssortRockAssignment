// 042_inheritance.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 부모클래스
// 상속을 내려주는 클래스
class Parent
{
public:
    int publicInt;
    void publicFunction() {}

protected:
    int protectedInt;
    void protectedFunction() {}

private:
    int privateInt;
    void privateFunction() {}
};

// 100
// 랜더링 90~97 사이드
// 나머지 공격력 방어력
// 구 충돌 호 충돌 혹은 회전한 2차원 사각형.
// 8%

// API때는 랜더링을 빠르게할 수단이 거의 없습니다.

// public 이 아닌걸로 사용해본적이 일단 없습니다.
// 자식클래스라고 부릅니다.
// 바이트 패딩의 맞춤은 자식기준으로 다시 이루어진다.
// 상속에 사용되는 접근제한 지정자는 거의 public 
// C#이나 자바에서는 아예 public
class Child : public Parent
{
public:
    // 상속은 부모의 맴버변수를 자식이 가지게 되는 것과 같다.
    // 맞춤도 같이 변화했다는 이야기가 된다.
    
    // 상속의 접근제한 지정자는
    // 내려오고나서 바뀐다를 기억하셔야 합니다. 
    
    // public 상속
    //int publicInt; // public 비교 public
    //int protectedInt; // protected 비교 public
    //int privateInt; // private 비교 public

    // protected 상속
    //int publicInt; // public 비교 protected => protected
    //int protectedInt; // protected protected
    //int privateInt; // private private

    // protected 상속
    // private:
    //int publicInt; // public 비교 protected => private
    //int protectedInt; // protected private
    //int privateInt; // private private


    __int64 TestValue;

    void ChildFunction()
    {
        // 자식내부
        publicInt = 10;
        protectedInt = 20;

        publicFunction();
        protectedFunction();

        // privateInt = 30;
    }
};

//            외부     자식내부    내부
// public     접근     접근        접근
// protected  불가     접근        접근
// private    불가     불가        접근

int main()
{
    Child NewChild;

    // protected: 외부에서는 사용할수 없다.
    // NewChild.

    std::cout << "Hello World!\n";
}