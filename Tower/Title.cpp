#include "Title.h"
#include "GameManager.h"

void Title::Init()
{
	Render();
}

void Title::Update()
{
	int getKeyCode = _getch();

	if (getKeyCode == 224)
	{
		int button = _getch();
		switch (button)
		{
		case 72 :
			if (nowMenu == 0) return;
			nowMenu--;
			break;
		case 80:
			if (nowMenu == 2) return;
			nowMenu++;
			break;
		}
	}

	if (getKeyCode == 'z')
	{
		switch (nowMenu)
		{
		case Title::NEW:
			
			break;
		case Title::LOAD:
			if (true) // ������ �ִ°�
			{
				// ���� �ε�
				gdata.LoadGame();
				// scene.Change(SCENE_INGAME);
			}
			else
			{
				// �ҷ��� ���� ����
			}
			break;
		case Title::EXIT:
			break;
		}
	}

}

void Title::Render()
{
	system("cls");

	// ���� 50 x ���� 15
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                 ������������������������������                ��\n");
	printf("��                ����������������������������������               ��\n");
	printf("��                ����������������������������������               ��\n");
	printf("��                ����������������������������������               ��\n");
	printf("��               ��������������������������������������              ��\n");
	printf("��               ��������������������������������������              ��\n");
	printf("��               ��������������������������������������              ��\n");
	printf("��              ������������������������������������������             ��\n");
	printf("��              ������������������������������������������             ��\n");
	printf("��              ������������������������������������������             ��\n");
	printf("��             ����������������������������������������������            ��\n");
	printf("��             ����������������������������������������������            ��\n");
	printf("��             ������������������     ������������������            ��\n");
	printf("��                                                ��\n");
	printf("�� �����   ���    �� �� ��  �����  ����  ��\n");
	printf("��    ��    ��    ��  �� �� ��  ��        ��    �ᦢ\n");
	printf("��    ��    ��    ��  �� �� ��  �����  ����  ��\n");
	printf("��    ��    ��    ��  �� �� ��  ��        ��    �ᦢ\n");
	printf("��    ��      ���     ��  ��   �����  ��    �ᦢ\n");
	printf("��                                                ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("����������������������������������������������������������������������������������������������������\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("��                                                ��\n");
	printf("����������������������������������������������������������������������������������������������������\n");

	SetText(newGame[nowLocale], 20, 24, (nowMenu == NEW));
	SetText(loadGame[nowLocale], 20, 25, (nowMenu == LOAD));
	SetText(exitGame[nowLocale], 20, 26, (nowMenu == EXIT));
}

void Title::Release()
{

}