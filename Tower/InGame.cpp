#include "InGame.h"
#include "GameManager.h"

string Img_village();
string Img_NextDay();

#define DELAYTIME 3000

void InGame::Init()
{
	string name;
	cout << "����� �̸��� �Է��ϼ���.\n�̸� : ";
	cin >> name;
	gdata.pdata.SetName(name);
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
		int bonus = rand() % 2;
		switch (menuState)
		{
		case 0 :
			menuState = selectMenu + 1;
			Sleep(100);
			break;

		case 1 :
			switch (selectMenu)
			{
			case 0: // ����ü��
				if (gdata.pdata.UpdateGold(-100))
				{
					switch (bonus)
					{
					case 0 : // ����
						gdata.pdata.UpdateHP(100);
						text[0] = "�̹� ���� ������ �ð��� ���´�.";
						text[1] = "";
						text[2] = "HP�� 100 ����ߴ�.";
						text[3] = "";
						break;
					case 1 : // �뼺��
						gdata.pdata.UpdateHP(150);
						text[0] = "�̹� ���� �������� �ð��� ���´�.";
						text[1] = "";
						text[2] = "HP�� 150 ����ߴ�.";
						text[3] = "";
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
					case 0 : // ����
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "�̹� ���� ������ �ð��� ���´�.";
						text[1] = "";
						text[2] = "���ݷ��� 10 ����ߴ�.";
						text[3] = "";
						break;
					case 1 : // �뼺��
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "�̹� ���� �������� �ð��� ���´�.";
						text[1] = "";
						text[2] = "���ݷ��� 10, HP�� 50 ����ߴ�.";
						text[3] = "";
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
						gdata.pdata.UpdateSpeed(1);
						text[0] = "�̹� ���� ������ �ð��� ���´�.";
						text[1] = "";
						text[2] = "�ӵ��� 1 ����ߴ�.";
						text[3] = "";
						break;
					case 1: // �뼺��
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "�̹� ���� �������� �ð��� ���´�.";
						text[1] = "";
						text[2] = "�ӵ��� 1, HP�� 50 ����ߴ�.";
						text[3] = "";
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
			break;
		case 2 :
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
						text[0] = "�̹� ���� ����Ϸ� �ð��� ���´�.";
						text[1] = "��� �Ǽ��� ���Ҵ�...";
						text[2] = "";
						text[3] = "50 ��带 �޾Ҵ�.";
					}
					break;
				case 1: // �뼺��
					{	
						gdata.pdata.UpdateGold(150);
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "�̹� ���� ����Ϸ� �ð��� ���´�.";
						text[1] = "�Ϻ��� ����� �̷�� �´�.";
						text[2] = "";
						text[3] = "150 ��带 �޾Ҵ�. HP�� 50 ����ߴ�. �ӵ��� 1 ����ߴ�.";
					}
					break;
				}
				menuState = 0;
				gdata.UpdateMonth(1);
				break;
			case 2: // ����
				break;
			}
			break;
		case 3:
			switch (selectMenu)
			{
			case 0: // ž ������

				break;
			case 1: // ����
				break;
			case 2: // ����
				break;
			}
			break;
		}
		selectMenu = 0;
	}

	if (getKeyCode == 27)
	{
		menuState = 0;
		selectMenu = 0;
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
	printf("��                                                ���� SPD  :           ��\n");
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
	SetText(Img_village(), 0, 1);

	// ��¥
	SetText(to_string(gdata.GetYear()), 53, 2);
	printf(" Ҵ  %d ��", gdata.GetMonth());

	// �÷��̾� ����
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetSpeed()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// ������
	for (int i = 0; i < nowMenu[menuState]; i++)	
	{
		SetText(Menu[menuState][i], 53, 18 + i, (selectMenu == i));
	}

	// �ؽ�Ʈ
	SetText(text[0], 3, 25);
	SetText(text[1], 3, 26);
	SetText(text[2], 3, 27);
	SetText(text[3], 3, 28);
}

void InGame::Release()
{

}

string Img_village()
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
           
string Img_NextDay()
{
	string Img;
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	Img += "��      \n";
	return Img;
}


 