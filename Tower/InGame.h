#pragma once

#include "Common.h"

class InGame
{
private:
	int selectMenu = 0;

	int nowMenu[4] = { 3, 3, 2, 1 };
	int menuState = 0;

	string Menu[4][3] = { { "�ܷ��ϱ�", "�Ƹ�����Ʈ", "Ž���ϱ�" },
						  { "����ü��(-100G)", "�ָԴܷ�(-150G)", "�޸���(-150G)" },
						  { "����(100G)", "���(50,150G)", ""},
						  { "ž ������", "", ""}};

	string text[4] = { "" };

public:
	void Init();
	void Update();
	void Render();
	void Release();
};