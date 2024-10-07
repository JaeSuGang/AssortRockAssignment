#pragma once
#include "StatusUnit.h"


// 귀찮음이 있으면 큰일 납니다.
class UZone : public UObject
{
public:
	void InMsgPrint();

	// 지역과 지역을 연결한다.
	void Link(UZone* _LinkZone);

	// void LinkPrint();

protected:


private:
	// 어떤 클래스 자신의 내부에 
	// dhkswjs 
	UZone* LinkZone[5] = {nullptr,};
};