#pragma once
#include "Common.h"

// �Էºθ� ������Ʈ�Ѵ�.
// ���� �������� Ű ���� ���� �� ���� �������� Ű ���¸� �����;� ��.
void Input_Update(void);

// ���� �����ӿ� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyDown(uint8_t vkey);

// ���� �����ӿ� Ű�� �����ٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKeyUp(uint8_t vkey);

// ���� �����Ӱ� ���� �����ӿ� ��� Ű�� ���ȴٸ� true, �ƴϸ� false
// vkey : ���� Ű�ڵ�
bool Input_GetKey(uint8_t vkey);
