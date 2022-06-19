#pragma once
#include "Common.h"
#include "Character.h"

using namespace std;

class Pdata : public Character
{
private:
	
	// �÷��̾� ����
	string _name = "";
	int _gold = 0;

public :
	Pdata() = default;
	~Pdata() = default;

	// [ ĳ���� ���� ]
	void SetHP(string HP);
	
	void SetAttackPower(string attackPower);
	
	void SetSpeed(string speed);

	// [ �÷��̾� ���� ]
	string GetName();
	void SetName(string name);

	int GetGold();
	void SetGold(int gold);
	void SetGold(string gold);
	bool UpdateGold(int gold);

	// [ �÷��̾� �ൿ ]
	void Attack();

};
