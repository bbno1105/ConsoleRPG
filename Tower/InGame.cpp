#include "InGame.h"
#include "GameManager.h"
#include "Monster.h"
#include "Title.h"

string Img_Village();
string Img_Tower();
string Image_Monster();
string Img_Quiz();

void InGame::Init()
{
	system("mode con: cols=71 lines=33");

	gdata.LoadGame();
	system("cls");
	if (gdata.pdata.GetName() == "")
	{
		string name;
		cout << "����� �̸��� �Է��ϼ���.\n�̸� : ";
		while (name == "")
		{
			cin >> name;
		}
		gdata.pdata.SetName(name);
	}

	text[0] = "ž�� ���迡 �������.";
	text[1] = "����� �Ƹ�����Ʈ�� ���� ���� �� �� ������,";
	text[2] = "�ܷ��� ���� ������ �� �ֽ��ϴ�.";
	text[3] = "��� �غ� ���ƴٸ� ž�� ���� �����غ�����.";

	Render();
}

void InGame::Update()
{
	srand(time(nullptr));

	int getKeyCode = _getch();

	if (getKeyCode == 224)
	{
		int button = _getch();
		switch (button)
		{
		case 72:
			if (selectMenu == 0) return;
			selectMenu--;
			break;
		case 80:
			if (selectMenu >= nowMenu[menuState] - 1) return;
			selectMenu++;
			break;
		}
	}

	if (getKeyCode == 32)
	{
		switch (menuState)
		{
		case 0 :
			menuState = selectMenu + 1;
			break;
		case 1 :
			Training();
			break;
		case 2 :
			Work();
			break;
		case 3:
			Travel(); 
			break;
		case 4: // ž
			Tower();
			break;
		case 5: // ����
			Monsters();
			break;
		case 6: // ����
			Quiz();
			break;
		}
		selectMenu = 0;
	}

	// ESC
	if (getKeyCode == 27)
	{
		if (menuState < 4)
		{
			menuState = 0;
			selectMenu = 0;
		}
	}

	if (getKeyCode == 'z' || gdata.GetFloor() >= 9)
	{
		// ���� Ŭ����
		system("cls");
		system("mode con: cols=51 lines=33");

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
		printf("\n ���۹� : ����Ű / ���� : Space / ��� : Esc ");

		SetText("���� Ŭ��� ���ϵ帳�ϴ�.", 12, 24);
		SetText("����� ž�� ������ ��¥ : ", 6, 26);
		printf("%2d ��  %2d ��", gdata.GetYear(), gdata.GetMonth());

		SetText("", 0, 29);

		gdata.ChangeSecene(3);
	}
}

void InGame::Render()
{
	system("cls");

	// �̹��� ȭ�� ������ ( x = 48 , y = 21 ) ��ü ( x = 70 , y = 30 )
	printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ������������������������������������������\n");
	printf("��                                                ������������������������������������������\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ���� Name :           ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ���� HP   :           ��\n");
	printf("��                                                ���� ATK  :           ��\n");
	printf("��                                                ���� TALK :           ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ���� Gold :           ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ������������������������������������������\n");
	printf("��                                                ������������������������������������������\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��                                                ����                  ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("��                                                                    ��\n");
	printf("��                                                                    ��\n");
	printf("��                                                                    ��\n");
	printf("��                                                                    ��\n");
	printf("��                                                                    ��\n");
	printf("��                                                                    ��\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������\n");

	// �̹���
	if (menuState < 4)
	{
		SetText(Img_Village(), 0, 1);
		// ��¥
		SetText(to_string(gdata.GetYear()), 53, 2);
		printf(" Ҵ  %d ��", gdata.GetMonth());
	}
	else
	{
		// ��¥
		SetText("", 53, 2);
		printf("ž %d / 9 ��", gdata.GetFloor());

		switch (menuState)
		{
		case 4 :
			SetText(Img_Tower(), 0, 1);
			break;
		case 5 :
			SetText(Image_Monster(), 0, 1);
			break;
		case 6 :
			SetText(Img_Quiz(), 0, 1);
			break;
		default:
			break;
		}
	}

	// �÷��̾� ����
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetNowHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetTalk()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// ������
	int menucount = nowMenu[menuState];
	for (int i = 0; i < menucount; i++)
	{
		SetText(Menu[menuState][i], 53, (18 + i), (selectMenu == i));
	}

	// �ؽ�Ʈ
	SetText(text[0], 3, 25);
	SetText(text[1], 3, 26);
	SetText(text[2], 3, 27);
	SetText(text[3], 3, 28);

	// ���۹�
	SetText(" ���۹� : ����Ű / ���� : Space / ��� : Esc ", 0, 31);
	printf("\n ������ �� ���� ���۵Ǹ� �ڵ����� ����˴ϴ�.");
}

void InGame::Release()
{

}

void InGame::Training()
{
	int bonus = rand() % 2;
	switch (selectMenu)
	{
	case 0: // ����ü��
		if (gdata.pdata.UpdateGold(-100))
		{
			switch (bonus)
			{
			case 0: // ����
				gdata.pdata.UpdateHP(100);
				text[0] = "�̹� ���� ����ü���� �ܷ��ϸ� �ð��� ���´�.";
				text[1] = "������ �� ���̾���.";
				text[2] = "";
				text[3] = "HP�� 100 ����ߴ�.";
				break;
			case 1: // �뼺��
				gdata.pdata.UpdateHP(150);
				text[0] = "�̹� ���� ����ü���� �ܷ��ϸ� �ð��� ���´�.";
				text[1] = "�������� �� ���̾���.";
				text[2] = "";
				text[3] = "HP�� 150 ����ߴ�.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "���� �����մϴ�.";
			text[1] = "";
			text[2] = "";
			text[3] = "";

		}
		break;

	case 1: // �ָԴܷ�
		if (gdata.pdata.UpdateGold(-150))
		{
			switch (bonus)
			{
			case 0: // ����
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "�̹� ���� �ָ��� �ܷ��ϸ� �ð��� ���´�.";
				text[1] = "������ �� ���̾���.";
				text[2] = "";
				text[3] = "���ݷ��� 10 ����ߴ�.";
				break;
			case 1: // �뼺��
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "�̹� ���� �ָ��� �ܷ��ϸ� �ð��� ���´�.";
				text[1] = "�������� �� ���̾���.";
				text[2] = "";
				text[3] = "���ݷ��� 10, HP�� 50 ����ߴ�.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "���� �����մϴ�.";
			text[1] = "";
			text[2] = "";
			text[3] = "";
		}
		break;

	case 2: // �޸���
		if (gdata.pdata.UpdateGold(-150))
		{
			switch (bonus)
			{
			case 0: // ����
				gdata.pdata.UpdateTalk(3);
				text[0] = "�̹� ���� å�� ������ �ð��� ���´�.";
				text[1] = "������ �� ���̾���.";
				text[2] = "";
				text[3] = "���ɷ��� 3 ����ߴ�.";
				break;
			case 1: // �뼺��
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateTalk(5);
				text[0] = "�̹� ���� å�� ������ �ð��� ���´�.";
				text[1] = "�������� �� ���̾���.";
				text[2] = "";
				text[3] = "���ɷ��� 5, HP�� 50 ����ߴ�.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "���� �����մϴ�.";
			text[1] = "";
			text[2] = "";
			text[3] = "";
		}
		break;
	}
}

void InGame::Work()
{
	int bonus = rand() % 2;
	switch (selectMenu)
	{
	case 0: // ����
		switch (bonus)
		{
		case 0: // ����
			gdata.pdata.UpdateGold(100);
			gdata.pdata.UpdateHP(10);
			text[0] = "�̹� ���� �����Ϸ� �ð��� ���´�.";
			text[1] = "���� �׷� �ð��� ���´�.";
			text[2] = "";
			text[3] = "100 ��带 �޾Ҵ�. HP�� 10 ����ߴ�.";
			break;
		case 1: // �뼺��
			gdata.pdata.UpdateGold(100);
			gdata.pdata.UpdateHP(50);
			text[0] = "�̹� ���� �����Ϸ� �ð��� ���´�.";
			text[1] = "�����Ͽ� ���� ������ ��������...?";
			text[2] = "";
			text[3] = "100 ��带 �޾Ҵ�, HP�� 50 ����ߴ�.";
			break;
		}
		menuState = 0;
		gdata.UpdateMonth(1);
		break;

	case 1: // ���ǹ��
		switch (bonus)
		{
		case 0: // ����
		{
			gdata.pdata.UpdateGold(50);
			text[0] = "�̹� ���� �������Ϸ� �ð��� ���´�.";
			text[1] = "�Ǽ��� ���Ҵ�...";
			text[2] = "";
			text[3] = "50 ��带 �޾Ҵ�.";
		}
		break;
		case 1: // �뼺��
		{
			gdata.pdata.UpdateGold(150);
			gdata.pdata.UpdateHP(50);
			gdata.pdata.UpdateTalk(2);
			text[0] = "�̹� ���� �������Ϸ� �ð��� ���´�.";
			text[1] = "�Ϻ��� �� ���̾���.";
			text[2] = "";
			text[3] = "150 ��带 �޾Ҵ�. HP�� 50 ����ߴ�. ���ɷ��� 2 ����ߴ�.";
		}
		break;
		}
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.SaveGame();
		break;
	case 2: // ����
		break;
	}
}

void InGame::Travel()
{
	switch (selectMenu)
	{
	case 0: // ž ������
		menuState = 4;
		text[0] = "ž�� �����ߴ�.";
		text[1] = "";
		text[2] = "�������� ��Ÿ����. ���� ����?";
		text[3] = "";
		break;
	case 1: // ����
		break;
	case 2: // ����
		break;
	}
}

Monster monster;

void InGame::Tower()
{
	switch (rand() % 2)
	{
	case 0:
		menuState = 5; // ����
		monster.Set((rand() % 10 * 10 + 50), (rand() % 10 + gdata.GetFloor() * 2), 30 * gdata.GetFloor());
		text[0] = "���Ͱ� ��Ÿ����.";
		text[1] = "";
		text[2] = "HP : ";
		text[2] += to_string(monster.GetNowHP());
		text[3] = "Atk : ";
		text[3] += to_string(monster.GetAttackPower());
		break;
	case 1:
		menuState = 6; // ����
		text[0] = QuizData[gdata.GetFloor()][0];
		text[1] = QuizData[gdata.GetFloor()][1];
		text[2] = QuizData[gdata.GetFloor()][2];
		text[3] = QuizData[gdata.GetFloor()][3];
		break;
	}
}

void InGame::Monsters()
{
	switch (selectMenu)
	{
	case 0 : // ����
		if (monster.UpdateNowHP(-1 * gdata.pdata.GetAttackPower()))
		{
			if (!gdata.pdata.UpdateNowHP(-1 * monster.GetAttackPower()))
			{
				// �÷��̾� �ֱ�
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "���Ϳ��� ��������.";
				text[1] = "...";
				text[2] = "�������� �� ���� �ð��� ���´�.";
				text[3] = "������� 100 Gold�� ����ߴ�.";
			}
			else
			{
				text[0] = "���Ϳ� ������ �ְ� �޾Ҵ�.";
				text[1] = "";
				text[2] = "HP : ";
				text[2] += to_string(monster.GetNowHP());
				text[3] = "Atk : ";
				text[3] += to_string(monster.GetAttackPower());
			}
		}
		else
		{
			//���� �ֱ�
			text[0] = "�ҽ��� ���͸� óġ�ߴ�!";
			text[1] = "�������� ";
			text[1] += to_string(monster.GetResult());
			text[1] += "�� ���ƴ�. ";
			text[2] = "";
			text[3] = "������ ���� ����?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		break;
	case 1: // ��ȭ
		if (gdata.pdata.GetTalk() >= rand() % 100) // ���ɷ� % Ȯ��
		{
			// ���� : Ŭ����
			text[0] = "��ȭ�� ���ߴ�!";
			text[1] = "������ ���͸� �����ƴ�.";
			text[2] = "";
			text[3] = "������ ���� ����?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		else
		{
			// ���� : �¾ƾ���
			if (gdata.pdata.UpdateNowHP(monster.GetAttackPower()))
			{
				// �÷��̾� �ֱ�
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "���Ϳ��� ��������.";
				text[1] = "...";
				text[2] = "�������� �� ���� �ð��� ���´�.";
				text[3] = "������� 100 Gold�� ����ߴ�.";
			}
		}
		break;
	case 2:
		// �÷��̾� ����
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.pdata.UpdateGold(-100);

		text[0] = "Ÿ������ �����ƴ�.";
		text[1] = "...";
		text[2] = "����ģ �ڽſ� ���� �ڱ����� �� ���� ���´�.";
		text[3] = "";
		break;
	}

}

void InGame::Quiz()
{
	if (selectMenu == QuizAnswer[gdata.GetFloor()])
	{
		// ����
		text[0] = "�����̴�!";
		text[1] = "������ ���� ����?";
		text[2] = "";
		text[3] = "";
		gdata.UpdateFloor(1);
		menuState = 4;
	}
	else
	{
		menuState = 0;
		gdata.UpdateMonth(1);

		text[0] = "��� Ʋ���� ž���� �i�ܳ���.";
		text[1] = "...";
		text[2] = "...";
		text[3] = "���� �� ���ΰ� �ʿ��� �� ����.";
		// ���� << ž �i�ܳ��� �� �� ����
	}
}

string Img_Village()
{
	string Img;
	Img += "��                                             \n";
	Img += "��                     ������������������               \n";
	Img += "��                    ����������������������              \n";
	Img += "��                   ��������������������������             \n";
	Img += "��                   ��������������������������             \n";
	Img += "��                  ������������������������������            \n";
	Img += "��                  ������������������������������            \n";
	Img += "��                 ����������������������������������           \n";
	Img += "��                 ����������������������������������           \n";
	Img += "��                 ������������     ������������           \n";
	Img += "�� ________________     /                      \n";
	Img += "�� _____________ /��    /                       \n";
	Img += "��            /��/ ��   /                        \n";
	Img += "��           / ��  ��  /                         \n";
	Img += "��          /  ��  �� /                          \n";
	Img += "�� ________/   ��   /                           \n";
	Img += "�� ����������������    ��  /                            \n";
	Img += "�� ����������������    �� /                             \n";
	Img += "�� ����������������     /                              \n";
	Img += "�� ����������������    /                               \n";
	Img += "�� ����������������   /                                \n";
 	return Img;
}
           
string Img_Tower()
{
	string Img;
	Img += "����                                      ��     \n";
	Img += "��  ��                                   ��      \n";
	Img += "��    ��                                ��       \n";
	Img += "��      ��                             ��        \n";
	Img += "��        ��                          ��         \n";
	Img += "��          ��_______________________��          \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��______________________��           \n";
	Img += "��          ��                       ��          \n";
	Img += "��         ��                          ��        \n";
	Img += "��        ��                             ��      \n";
	Img += "��       ��                                ��    \n";
	Img += "��      ��                                   ��  \n";
	Img += "��     ��                                      ��\n";
	return Img;
}

string Image_Monster()
{
	string Img;
	Img += "����                                      ��     \n";
	Img += "��  ��                                   ��      \n";
	Img += "��    ��                                ��       \n";
	Img += "��      ��                             ��        \n";
	Img += "��        ��                          ��         \n";
	Img += "��          ��_______________________��          \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��     ��������������������       ��           \n";
	Img += "��           ��___������        ������������__��           \n";
	Img += "��          ��  ����               ����  ��          \n";
	Img += "��         ��   ��  ��       ��    ������  ��        \n";
	Img += "��        ��   ����                   ����   ��      \n";
	Img += "��       ��    ��                     ��     ��    \n";
	Img += "��      ��     ����������������������������������������������       ��  \n";
	Img += "��     ��                                      ��\n";
	return Img;
}
 

string Img_Quiz()
{
	string Img;
	Img += "����                                      ��     \n";
	Img += "��  ��                                   ��      \n";
	Img += "��    ��                                ��       \n";
	Img += "��      ��                             ��        \n";
	Img += "��        ��                          ��         \n";
	Img += "��          ��_______________________��          \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           ��                      ��           \n";
	Img += "��           �� ���������������������������������������� ��           \n";
	Img += "��           �� ��                  �� ��           \n";
	Img += "��           �� ��   Q U I Z        �� ��           \n";
	Img += "��           �� ��       Q U I Z    �� ��           \n";
	Img += "��           ��_��                  ��_��           \n";
	Img += "��          �� ����������������������������������������  ��          \n";
	Img += "��         ��           ����             ��        \n";
	Img += "��        ��            ����               ��      \n";
	Img += "��       ��             ����                 ��    \n";
	Img += "��      ��              ����                   ��  \n";
	Img += "��     ��                                      ��\n";
	return Img;
}