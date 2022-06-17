#pragma once
#include <iostream>
#include <corecrt_wstdio.h>

class Gdata
{
private:
	FILE* savefp;

public :
	void Init()
	{
		if (savefp = fopen("saveData.bin", "rb"))
		{
			// ���̺� ���� �ε�
			while (fread(&gdata->pData, sizeof(gdata->pData), 1, savefp) == 1)
			{
			}
			LogInfo("map : %d", gdata->pData.mapSaveID);
			LogInfo("POS.X : %d", gdata->pData.playerSavePos.X);
			LogInfo("POS.Y : %d", gdata->pData.playerSavePos.Y);
			LogInfo("DIECOUNT : %d", gdata->pData.youDieCount);

			fclose(savefp);
		}
		else
		{
			// ���̺� ���� ����
			SaveData();
		}
	}
	void SaveGame()
	{
		savefp = fopen("saveData.bin", "wb");

		gdata->pData.mapSaveID = gdata->map.ID;
		gdata->pData.playerSavePos.X = gdata->map.RespawnPoint.X;
		gdata->pData.playerSavePos.Y = gdata->map.RespawnPoint.Y;

		fwrite(&gdata->pData, sizeof(gdata->pData), 1, savefp);
		fclose(savefp);
	}
	void LoadGame();
}