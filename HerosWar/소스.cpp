#include <iostream>
#include <cmath>
#include "console.h"

using namespace std;

int playerNumber = 3;
int enemyNumders[6] = {};
int maxFloor = 0;

void EnemyNumberSetting();
void MapSetting();
void SizePut(string s, int number);
int sizeofint(int data);

int main()
{
	bool gameover = false;
	while (!gameover)
	{
		EnemyNumberSetting();
		system("cls");
		MapSetting();

		int clearFloorCnt = 0;
		for (; clearFloorCnt < 5;)
		{
			int floor;
			cout << "이동할 층 수를 적어주세요: "; cin >> floor;
			if (enemyNumders[floor] != NULL && floor > 0 && floor < 6)
			{
				if (playerNumber > enemyNumders[floor])
				{
					playerNumber += enemyNumders[floor];
					enemyNumders[floor] = NULL;
					clearFloorCnt++;
					maxFloor++;
				}
				else if (playerNumber <= enemyNumders[floor])
				{
					playerNumber = NULL;
					system("cls");
					MapSetting();
					Sleep(300);
					clearFloorCnt = INT_MAX;
					gameover = true;
				}
			}
			system("cls");
			MapSetting();
		}
		Sleep(300);
	}
	cout << "게임오버!  최대 격파한 수 : " << maxFloor;
}

void EnemyNumberSetting()
{
	srand((unsigned int)time(NULL));
	enemyNumders[1] = playerNumber - (playerNumber / 2) + (rand() % (playerNumber / 2));
	for (int i = 2; i < 6; i++)
	{
		enemyNumders[i] = enemyNumders[i - 1] + (enemyNumders[i - 1] / 2) + (rand() % (enemyNumders[i - 1] / 2));
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 4 + 1;
		idx2 = rand() % 4 + 1;
		iTemp = enemyNumders[idx1];
		enemyNumders[idx1] = enemyNumders[idx2];
		enemyNumders[idx2] = iTemp;
	}
}

void MapSetting()
{
	for (int i = 5; i > 0; i--)
	{
		if (i == 1)
		{
			//cout << "------ ------" << endl;
			cout << "----";
			SizePut("-", playerNumber); cout << " ";
			cout << "----";
			SizePut("-", enemyNumders[i]); cout << " " << endl;

			cout << "| " << playerNumber << " | | " << enemyNumders[i] << " |" << endl;

			cout << "| ■";
			SizePut(" ", playerNumber);
			cout << "| | □";
			SizePut(" ", enemyNumders[i]); cout << "|" << endl;

			cout << "----";
			SizePut("-", playerNumber); cout << " ";
			cout << "----";
			SizePut("-", enemyNumders[i]); cout << endl;

			/*cout << "| " << playerNumber << " | | " << enemyNumders[i] << " |" << endl;
			cout << "| ■  | | □  |" << endl;
			cout << "------ ------" << endl;*/
		}
		else
		{
			cout << "     ";
			SizePut(" ", playerNumber);
			cout << "----";
			SizePut("-", enemyNumders[i]); cout << endl;

			cout << "     ";
			SizePut(" ", playerNumber);
			cout << "| " << enemyNumders[i] << " |" << endl;

			cout << "     ";
			SizePut(" ", playerNumber);
			cout << "| □";
			SizePut(" ", enemyNumders[i]); cout << "|" << endl;

			cout << "     ";
			SizePut(" ", playerNumber);
			cout << "----";
			SizePut("-", enemyNumders[i]); cout << endl;
		}
	}
}

void SizePut(string s, int number)
{
	for (int i = 0; i < sizeofint(number); i++)
	{
		cout << s;
	}
}

int sizeofint(int data)
{
	int pos = 1, i;


	if (data < 0) data *= (-1);

	for (i = 0; ; i++, pos++)
	{
		if ((data /= 10) <= 0)
			break;
	}
	return(pos);
}