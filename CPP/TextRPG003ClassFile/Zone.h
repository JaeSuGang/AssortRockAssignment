#pragma once
#include "StatusUnit.h"


// �������� ������ ū�� ���ϴ�.
class UZone : public UObject
{
public:
	void InMsgPrint();

	// ������ ������ �����Ѵ�.
	void Link(UZone* _LinkZone);

	// void LinkPrint();

protected:


private:
	// � Ŭ���� �ڽ��� ���ο� 
	// dhkswjs 
	UZone* LinkZone[5] = {nullptr,};
};