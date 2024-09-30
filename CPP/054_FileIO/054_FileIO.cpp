// 054_FileIO.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <io.h>

struct PlayerSaveData
{
    // 포인터는 저장하는게 의미 있을까요?
public:
    // int* Ptr; => 아무의미 없다.
    // const char* Name = "TestPlayer";

    char Name[100] = "TestPlayer";
    int Hp = 30;
    int Att = 100;
};

class Player
{

};

int main()
{
    PlayerSaveData PlayerData;

    UEngineFile NewFile;
    NewFile.SetPath("SaveFIle.txt");

    if (NewFile.IsExist())
    {
        NewFile.Open("wb");
        NewFile.Save("aaaaaa", strlen("aaaaaa"));
    }
    else {
        NewFile.Open("rb");
    }

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
