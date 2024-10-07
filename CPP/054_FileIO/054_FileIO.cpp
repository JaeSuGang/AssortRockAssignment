// 054_FileIO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <io.h>
#include "EngineFile.h"

// 기분 구문 넘어가고서 부터는 이제 순서는 의미 없다.
// for넘어가고 나면 

struct PlayerSaveData
{
    // 포인터는 저장하는게 의미 있을까요?
public:
    // 리터럴 초기화 => 프로그래머 들끼라만 
    // int* Ptr; => 아무의미 없다.
    // const char* Name = "TestPlayer";

    // 초기화 할때 넣어주는 값 "TestPlayer" => 리터럴 값
    // 리터럴 초기화라고 하지는 않는다.
    // 디폴트 맴버 이니셜라이저
    char Name[100] = "TestPlayer";
    int Hp = 30;
    int Att = 100;
};

class MyInt
{
public:
    int Value = 0;
    MyInt(int _Value)
    {

    }
};

int main()
{
    int a = 0;
    MyInt Mya = 0;

    PlayerSaveData PlayerData;

    // 클래스화 시킨다
    // 클래스로 랩핑

    /*UEngineFile NewFile;
    NewFile.SetPath("SaveFIle.txt");

    if (NewFile.IsExist())
    {
        NewFile.Open("wb");
        NewFile.Save("aaaaaa", strlen("aaaaaa"));
    }
    else {
        NewFile.Open("rb");
    }*/

    // 객체를 쓰는 것처럼 보인다.
    // 
    UEngineFile NewFile;
    NewFile.SetPath("SaveFIle.txt");

    if (false == NewFile.IsExits())
    {
        // 없으면 만들어
        NewFile.FileOpen("wt");

        //PlayerData.Att = 9999;
        //PlayerData.Hp = 312321;
        //strcpy_s(PlayerData.Name, "MyName");
        //int Size = sizeof(PlayerSaveData);
        // NewFile.Write(&PlayerData, Size);


        // NewFile.Write("SaveFile\n", strlen("SaveFile\n"));
        int Value = 100;
        NewFile.Write(&Value, sizeof(int));
        int Value0 = 10;
        NewFile.Write(&Value, sizeof(int));

    }
    else 
    {
        NewFile.FileOpen("rb");

        NewFile.Read(&PlayerData, sizeof(PlayerSaveData));
    }

    // 플랫폼 기능이 우선입니다.
    // 기본적으로 OS가 지원해 줘야 합니다.
    // 하나의 완전히 분리된 클래스를 통해서만 아래의 기능들을 사용하려는 겁니다.

    // 파일명을 넣는곳은 일반적으로 경로 자체를 넣어주는게 기본입니다.

    return 1;

    int Result = _access("SaveFIle.txt", 00);
    if (0 != Result)
    {
        // 어떤 종류의 위치라고 할수 있고
        // C에서 8바이트 정수의 의미로 사용된다.
        FILE* File = nullptr;
        // fopen은 파일을 여는 함수입니다.
        // 여태까지 다양한 함수들에 _s버전과 아닌 버전들이 보일때가 
        // _s 시큐리티 옛날 C 및 c++함수들은 메모리 후킹
        // 그래서 _s 메모리를 확인하기 힘든 함수들이 만들어졌습니다.
        // 우린 느낄수도 없죠.

        // 파일을 열겠다.
        // 연 파일의 주소값을
        // 하드디스크의 파일에 간섭할수 있는 주소를 우리에게 준다.
        // 핸들 방식

        // 모드인데.

        // "wb" "wt"
        // "rb" "rt"
        // 앞쪽 w r
        // 두번째 b 바이너리
        // 두번째 t 텍스트
        // b 무조건 문제가 안됩니다.
        // t 가 문제입니다.
        // 

        // 만약에 그 파일이 없으면
        // 만들어 냅니다.
        fopen_s(&File, "SaveFIle.txt", "wb");

        PlayerData.Att = 9999;
        PlayerData.Hp = 312321;
        strcpy_s(PlayerData.Name, "MyName");

        int Size = sizeof(PlayerSaveData);

        fwrite(&PlayerData, sizeof(PlayerData), 1, File);


        // 파일 다 썼어요.
        fclose(File);
        // '1' 1;
    }
    else 
    {
        FILE* File = nullptr;

        fopen_s(&File, "SaveFIle.txt", "rb");

        fread(& PlayerData, sizeof(PlayerData), 1, File);

        fclose(File);

        // 파일을 읽어오면 된다.
    }
}
