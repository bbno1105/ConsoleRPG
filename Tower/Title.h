#pragma once
#include "Common.h"
#include "GameManager.h"
#include "InGame.h"

class Title
{
private :
	int nowLocale = ENG;
	int nowMenu = NEW;

	string newGame[2] = { "New Game", "���ο� ����" };
	string loadGame[2] = { "Load Game", "�̾��ϱ�" };
	string exitGame[2] = { "Exit", "���� ����" };

	enum LOCALE
	{
		ENG,
		KOR
	};

	enum MENU
	{
		NEW,
		LOAD,
		EXIT
	};
	
public:
	void Init();
	void Update();
	void Render();
	void Release();
};

__declspec(selectany) Title title;