#include "Player.h"

void Pdata::Init()
{
	_HP = 100;
	_attackPower = 10;
	_talk = 10;
	_gold = 100;
	SetNowHP(GetHP());
}

void Pdata::SetHP(string HP) { _HP = stoi(HP); }

void Pdata::SetAttackPower(string attackPower) { _attackPower = stoi(attackPower); }

void Pdata::SetSpeed(string speed) { _talk = stoi(speed); }

// [ �÷��̾� ���� ]
string Pdata::GetName() { return _name; }
void Pdata::SetName(string name) { _name = name; }

int Pdata::GetGold() { return _gold; }
void Pdata::SetGold(int gold) { _gold = gold; }
void Pdata::SetGold(string gold) { _gold = stoi(gold); }
bool Pdata::UpdateGold(int gold)
{
	if (_gold + gold >= 0)
	{
		_gold += gold;
		return true;
	}
	else 
	{
		return false; // ���� ������ �� ���� (���� ������ ���)
	}

}


// [ �÷��̾� �ൿ ]
void Pdata::Attack()
{

}