#include "Title.h"
#include "GameManager.h"

void Title::Init()
{
	system("mode con: cols=51 lines=31");

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

	if (getKeyCode == 32)
	{
		switch (nowMenu)
		{
		case Title::NEW: // �ű� ����
			gdata.pdata.Init(); // �÷��̾� ������ �ʱ�ȭ
			gdata.SaveGame(); // �������� ����
			gdata.ChangeSecene(2);
			break;
		case Title::LOAD: // �ҷ�����
			if (gdata.LoadGame()) // ������ �ִ°�
			{
				// ���� �ε�
				gdata.ChangeSecene(2);
			}
			else
			{
				SetText("                      ", 13, 24);
				SetText("����� �����Ͱ� �����ϴ�.", 13, 25);
				SetText("                      ", 13, 26);
				SetText("", 0, 29);

				Sleep(2000);
			}

			break;
		case Title::EXIT:
			gdata.ChangeSecene(3);
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

	SetText("���۹� : ����Ű / ���� : Space / ��� : Esc ", 0, 29);

}

void Title::Release()
{

}