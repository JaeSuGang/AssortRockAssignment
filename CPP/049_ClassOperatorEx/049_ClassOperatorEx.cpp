// 049_ClassOperatorEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 수학관련 클래스들은 아래와 같은 꼴을 가진다.
class MyInt
{
public:
    // 리턴하면서 새로운 복사본을 하나더 만들어냈다.
    // MyInt operator=(const int& _Other)

    // 복사본이 생기지 않고 자기자신의 참조리턴
    MyInt& operator=(const int& _Other)
    {
        Value = _Other;

        // MyInt* Ptr;
        // *Ptr = 20;
        // *Ptr == MyInt&
        return *this;
    }

    // bool operator>(const int& _Other)
    int operator>(const int& _Other)
    {

    }

    int operator[](const int& _Other)
    {
        return Value;
    }

    // 함수객체라고 합니다.
    // 객체를 함수처럼 쓰는 방법
    int operator()(int Value0, int Value2)
    {
        Value = Value0 / Value2;

        return Value;
    }





    int ArrReturn(const int& _Other)
    {
        return Value;
    }

    //MyInt()
    //{
    //}

    MyInt(int Value)
    {
    }

    // 형변환 연산자.
    // int로 

    // 암시적 형변환
    operator int()
    {
        return Value;
    }

    operator bool()
    {
        return Value;
    }

    

protected:

private:
    int Value = 0;
};

// 클래스는 완
class IntPtr
{
public:
    IntPtr(int* _Ptr)
        : Value(_Ptr)
    {
        // 지적당할수 있다.
        // Value = _Ptr;
    }


    // 아래와 같이 해줘야 한다고 봤는데 확실하지 않다
    // int& operator*(int)
    int& operator*()
    {
        return *Value;
    }

private:
    int* Value = nullptr;
};

class Item
{

};

class Inventory
{
    Item Arr[100];

    Inventory()
    {

    }

    // 랜덤 접근 할때만 사용된다.
    Item operator[](int _Value)
    {
        return Arr[_Value];
    }

    Item GetItem(int _Index)
    {
        return Arr[_Index];
    }
};


int main()
{

    {
        int NewValue = int(0);
        int TestValue = int(20);

        // const int = 33
        (NewValue = TestValue = NewValue = 10) = 33;

        // MyInt NewMyInt = MyInt(0);
        MyInt NewMyInt = 0;
        // NewMyInt.operator=(10) = 20;

        // NewMyInt[10];

        NewMyInt(10, 20);

        NewMyInt.operator[](10);
        NewMyInt.ArrReturn(10);

        (NewMyInt = TestValue = NewMyInt = 10) = 33;

        MyInt& Ref = NewMyInt.operator=(10);
        Ref.operator int();

        (NewMyInt = TestValue = NewMyInt = 10) = 33;
        // (NewMyInt.operator=(TestValue = NewMyInt.operator=(10).operator int())) = 33;


        NewMyInt = NewMyInt = 0;
    }

    {
        MyInt ArrTest[10] = {10,};
        // MyInt()
        // MyInt()
        // MyInt()
        // MyInt()
        // MyInt()
        // MyInt()
        // MyInt()
        // MyInt()

        int NewValue = int(0);

// typedef int* IntPtr;

        IntPtr NewPtr = &NewValue;

        *NewPtr = 20;

        int a = 0;
    }
    {
        std::cout << 10;
        std::cout.operator<<(10);

        std::cout << 20 << 30;

        std::cout.operator<<(20).operator<<(30);
    }
}
