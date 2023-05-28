#include<stdio.h>
#include "console.h"
#include <Windows.h>
#include<iostream>
#include<conio.h>
#include<time.h>
#include <fstream>
#include<string>
#include<iomanip>
using namespace std;

#define consolengang 80
#define consoledoc 29
#define bienphai 30

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConCurInf;

	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = CursorVisibility;

	SetConsoleCursorInfo(handle, &ConCurInf);
}
void DisableSelection()
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);

	SetConsoleMode(hStdin, ~ENABLE_QUICK_EDIT_MODE);
}
struct toado
{
	int x, y; // x là hoành độ , y là tung độ
};


struct shape
{
	char a[3][3];
	char b;
};


struct car
{
	toado td;
	shape hd;
	int score;
	int life;
	int speed;
	int doben;
};

struct barrier
{
	toado td;
	shape hd;
};


void create(car& car, barrier bar[])
{
#define HD car.hd.a 
	car.score = 0;
	car.life = 15;
	car.td.y = consoledoc - 1;
	car.td.x = bienphai / 2;
	car.speed = 0;
	car.doben = car.life;

	HD[0][0] = HD[2][0] = HD[2][2] = HD[0][2] = 'O';
	HD[0][1] = '-';
	HD[1][0] = HD[1][2] = '|';
	HD[2][1] = '^';
	HD[1][1] = '0';


	////////// bar

	srand(time(0));

	bar[0].td.x = 2 + rand() % (bienphai - 4);
	bar[0].td.y = 1;

	bar[1].td.x = 2 + rand() % (bienphai - 4);
	bar[1].td.y = 1;


	bar[2].td.x = 2 + rand() % (bienphai - 4);
	bar[2].td.y = 1;

	bar[3].td.x = 2 + rand() % (bienphai - 4);
	bar[3].td.y = 1;

	bar[4].td.x = 2 + rand() % (bienphai - 4);
	bar[4].td.y = 1;


	for (int i = 0; i < 3; i++)
		for (int i1 = 0; i1 < 3; i1++)
			bar[2].hd.a[i][i1] = '8';

	for (int i = 0; i < 3; i++)
		for (int i1 = 0; i1 < 3; i1++)
			bar[1].hd.a[i][i1] = 'D';

	for (int i = 0; i < 3; i++)
		for (int i1 = 0; i1 < 3; i1++)
			bar[0].hd.a[i][i1] = '#';

	for (int i = 0; i < 3; i++)
		for (int i1 = 0; i1 < 3; i1++)
			bar[3].hd.a[i][i1] = '/';

	for (int i = 0; i < 3; i++)
		for (int i1 = 0; i1 < 3; i1++)
			bar[4].hd.a[i][i1] = '*';


}





void show(car car, barrier bar[5], int& dem)
{
	clrscr();
	// Huong dan su dung
	TextColor(14);
	gotoXY(bienphai + 5, 0);

	cout << "Huong dan su dung";

	gotoXY(bienphai + 4, 1);
	cout << "*Bam w de di chuyen len tren    ^";

	gotoXY(bienphai + 4, 2);
	cout << "*Bam a de di chuyen sang trai <";

	gotoXY(bienphai + 4, 3);
	cout << "*Bam s de di chuyen xuong       v";

	gotoXY(bienphai + 4, 4);
	cout << "*Luu y: Neu do ben duoi 0 thi ban se chet!";
		
	gotoXY(bienphai + 4, 5);
	cout <<"Neu mat 5 do ben se mat 1 mang ^^";

	gotoXY(bienphai + 38, 2);
	cout << "> *Bam d de di chuyen sang phai ";
	// Bonus

	if (car.score >= 2000)
	{
		TextColor(rand() % 16);
		gotoXY(bienphai + 20, 25);
		cout << "BONUSSSSS TIMESSS";
		gotoXY(bienphai + 20, 26);
		cout << "HARDDD MODEEE : ON";
	}
	if (car.score >= 10000)
	{
		TextColor(rand() % 16);
		gotoXY(bienphai + 20, 26);
		cout << "WELCOMEE TO THE HELL!!!";
	}
	if (car.score >= 25000 && car.score < 60000)
	{
		TextColor(rand() % 16);
		gotoXY(bienphai + 15, 26);
		cout << "THUA DI CHA NOI HACK AH ?????";
	}
	if (car.score >= 60000)
	{
		TextColor(rand() % 16);
		gotoXY(bienphai + 15, 26);
		cout << "AN GI DE CON CUNG!!";
	}
	// score 
	TextColor(default_ColorCode);
	gotoXY(bienphai + 5, 10);
	cout << "Score: " << car.score << endl;


	gotoXY(bienphai + 5, 11);
	cout << "LIFE: " << car.life / 5;

	gotoXY(bienphai + 5, consoledoc);
	cout << "Speed: " << car.speed;

	gotoXY(bienphai + 17, consoledoc);
	cout << "km / h";

	gotoXY(bienphai + 30, consoledoc);
	cout << "Do ben: " << car.life - 5;

	gotoXY(bienphai + 30, 11);
	cout << "*Nhan ESC de thoat ve man hinh chinh";

	gotoXY(bienphai + 30, 10);
	cout << "*Nhan SPACE de tam dung";
	// bien 
	TextColor(default_ColorCode);
	for (int i = 0; i <= consoledoc; i++)
	{
		gotoXY(bienphai, i);
		cout << "|";
	}

	for (int i = 0; i <= consoledoc; i++)
	{
		gotoXY(bienphai / 2, i);
		putchar(1);
	}

	for (int i = 0; i <= consoledoc; i++)
	{
		gotoXY(0, i);
		cout << "|";
	}

	// xe 

	TextColor(14);
	for (int dong = -1; dong <= 1; dong++)
		for (int cot = -1; cot <= 1; cot++)
		{
			int x = cot + car.td.x;
			int y = dong + car.td.y;

			gotoXY(x, y);
			putchar(car.hd.a[dong + 1][cot + 1]);
		}


	// bar 
	TextColor(12);
	for (int dong = -1; dong <= 1; dong++)
		for (int cot = -1; cot <= 1; cot++)
		{
			int x = cot + bar[0].td.x;
			int y = dong + bar[0].td.y;

			if (y >= 0 && y < consoledoc)
			{
				gotoXY(x, y);
				putchar(bar[0].hd.a[dong + 1][cot + 1]);
			}
		}
	if (dem >= 5)
	{
		for (int dong = -1; dong <= 1; dong++)
			for (int cot = -1; cot <= 1; cot++)
			{
				int x = cot + bar[1].td.x;
				int y = dong + bar[1].td.y;

				if (y >= 0 && y < consoledoc)
				{
					gotoXY(x, y);
					putchar(bar[1].hd.a[dong + 1][cot + 1]);
				}
			}
	}
	if (dem >= 13)
	{
		for (int dong = -1; dong <= 1; dong++)						//Vi tri xuat hien
			for (int cot = -1; cot <= 1; cot++)
			{
				int x = cot + bar[2].td.x;
				int y = dong + bar[2].td.y;

				if (y >= 0 && y < consoledoc)
				{
					gotoXY(x, y);
					putchar(bar[2].hd.a[dong + 1][cot + 1]);
				}
			}
	}

	if (dem >= 22)
	{
		for (int dong = -1; dong <= 1; dong++)						//Vi tri xuat hien
			for (int cot = -1; cot <= 1; cot++)
			{
				int x = cot + bar[3].td.x;
				int y = dong + bar[3].td.y;

				if (y >= 0 && y < consoledoc)
				{
					gotoXY(x, y);
					putchar(bar[3].hd.a[dong + 1][cot + 1]);
				}
			}
	}

	if (dem >= 45)
	{
		for (int dong = -1; dong <= 1; dong++)						//Vi tri xuat hien
			for (int cot = -1; cot <= 1; cot++)
			{
				int x = cot + bar[4].td.x;
				int y = dong + bar[4].td.y;

				if (y >= 0 && y < consoledoc)
				{
					gotoXY(x, y);
					putchar(bar[4].hd.a[dong + 1][cot + 1]);
				}
			}
	}

	// phan chia

	for (int i = bienphai + 1; i < 120; i++)
	{
		gotoXY(i, 8);
		putchar(179);
	}
}


void control(car& car, int& a)
{
	if (_kbhit())
	{
		long key = _getch();

		if ((key == 'A' || key == 'a') && car.td.x > 2)
			car.td.x--;
		else if ((key == 'D' || key == 'd') && car.td.x < bienphai - 2)
			car.td.x++;
		else if ((key == 'S' || key == 's') && car.td.y < consoledoc - 1)
			car.td.y++;
		else if ((key == 'W' || key == 'w') && car.td.y > 2)
			car.td.y--;
		else if (key == 27)
			a = 1;
		else if (key == ' ')
			a = 2;
	}
}

int move(car& car, barrier bar[5], int& speed, int& life, int& dem, long chon)
{



	// move xuong 
	bar[0].td.y++;

	bar[1].td.y++;

	bar[2].td.y++;

	bar[3].td.y++;

	bar[4].td.y++;

	for (int i = 0; i <= 4; i++)
		if (bar[i].td.y > consoledoc - 1)
		{
			if (speed <= 200 && speed > 100)
			{
				car.score += 2;
				car.speed += 1;
			}
			if (speed <= 300 && speed > 250)
			{
				car.score++;
				car.speed += 1;
			}
			if (speed <= 250 && speed > 200)
			{
				car.score += 3;
				car.speed += 2;
			}
			if (speed <= 100 && speed > 60)
			{
				car.score += 4;
				car.speed += 3;
			}
			if (speed <= 60)
			{
				car.score += 10;
				car.speed += 4;
			}
			if (speed <= 50)
			{
				car.score += 20;
				car.speed += 5;
			}
			if (speed == 20)
			{
				car.score += 100;
				car.speed += 6;
			}
			if (speed == 10)
			{
				car.score += 200;
				car.speed += 7;
			}
			if (speed == 7)
				car.score += 400;

			bar[i].td.x = 2 + rand() % (bienphai - 4);
			bar[i].td.y = 1;

			if (speed >= 40)
				speed -= 5;
			if (car.score >= 1500)
				speed = 20;
			if (car.score >= 5000)
				speed = 10;
			if (car.score >= 12000)
				speed = 7;
		}

	if (bar[0].td.y == 5)
	{
		bar[1].td.x = 2 + rand() % (bienphai - 4);
		bar[1].td.y = 1;
	}

	if (bar[1].td.y == 10)
	{
		bar[2].td.x = 2 + rand() % (bienphai - 4);
		bar[2].td.y = 1;

	}

	if (bar[2].td.y == 10)
	{
		bar[3].td.x = 2 + rand() % (bienphai - 4);
		bar[3].td.y = 1;

	}

	if (bar[0].td.y == consoledoc - 11)
	{
		bar[4].td.x = 2 + rand() % (bienphai - 4);
		bar[4].td.y = 1;

	}
	// va cham neu tung do hoac toa do <= 2 

	int X, Y;
	for (int i = 0; i <= 4; i++)
	{
		X = abs(car.td.x - bar[i].td.x);
		Y = abs(car.td.y - bar[i].td.y);

		if (X < 3 && Y < 3)
		{
			if (chon != 787898)
				car.life--;
			return 2;

		}
		if (car.life / 5 == 0)
			return -1;
	}

	return 0;
}



void mainscreen(long& chon)
{

	TextColor(7);
	cout << "\n       ####          ##      #          #  #######        ####      ##     ##      ##            ##      ##  #######";
	cout << "\n     ##     ##      ####     ###       ##  #######        ##  ##    ##     ##     ####            ##    ##   #######";
	cout << "\n    ##      ##     ##  ##    ####    ####  ##             ##    ##  ##     ##    ##  ##            ##  ##    ##";
	cout << "\n    ##            ##    ##   ## ##  ## ##  ##             ##    ##  ##     ##   ##    ##            ####     ##";
	cout << "\n    ##            ########   ##  ####  ##  #######        ##    ##  ##     ##   ########             ##      #######";
	cout << "\n    ##     ####   ########   ##   ##   ##  ##             ##    ##  ##     ##   ########            ####     ##";
	cout << "\n    ##      ##   ##      ##  ##        ##  ##             ##    ##  ##     ##  ##      ##          ##  ##    ##";
	cout << "\n     ##     ##   ##      ##  ##        ##  #######        ##  ##     ##   ##   ##      ##         ##    ##   #######";
	cout << "\n       ####      ##      ##  ##        ##  #######        ####        #####    ##      ##        ##      ##  #######";


	TextColor(5);
	gotoXY(consolengang / 2, consoledoc / 2);
	cout << "1. De";
	gotoXY(consolengang / 2, consoledoc / 2 + 1);
	cout << "2. Trung binh";
	gotoXY(consolengang / 2, consoledoc / 2 + 2);
	cout << "3. Kho";
	gotoXY(consolengang / 2, consoledoc / 2 + 3);
	cout << "4. Bang xep hang";
	gotoXY(consolengang / 2, consoledoc / 2 + 9);
	cout << "Lua chon cua ban la: ";
	cin >> chon;


}


void luu(string ten[], int diem[], int dem4)
{
	for (int i = 0; i < dem4 - 1; i++)
	{
		for (int i1 = i + 1; i1 < dem4; i1++)
		{
			if (diem[i] < diem[i1])
			{
				swap(diem[i], diem[i1]);
				swap(ten[i], ten[i1]);
			}
		}
	}
}
int main()
{

	ShowCur(0);
	DisableSelection();

	string hoten;
	int p = 0; // ki hieu game over
	int life, z = 0; //z ki hieu dung
	long chon;
	int dem = 0, dem2 = 0;
	int speed = 300;
	srand(time(0));
	car car;
	barrier bar[6];
	string ten[100];
	int diem[100], dung = 0;

	ifstream inData;
	inData.open("diem.txt");

	long dem3 = 15, dem4 = 0, diem1;
	while (!inData.eof())
	{

		getline(inData, hoten, '-');

		inData >> diem1;

		inData.ignore(1);

		ten[dem4] = hoten;
		diem[dem4] = diem1;
		dem4++;
	}

	do
	{
		z = 0;
		do {
			clrscr();
			mainscreen(chon);

			if (chon == 4)
			{
				clrscr();
				long dem5 = 0, dem6 = 0;
				luu(ten, diem, dem4);
				cout << "Bang xep hang hien tai: " << endl;
				TextColor(15);
				for (int i = 0; i < dem4; i++)
				{
					if (i == 1)
						continue;
					cout << ten[i] << "\t" << diem[i] << endl;
					if (dem5 == 4)
						break;
					dem5++;
				}
				inData.close();
				_getch();
			}
		} while ((chon < 1 || chon > 3) && chon != 787898);
		if (chon == 1 || chon == 787898)
			speed = 200;
		if (chon == 2)
			speed = 150;
		if (chon == 3)
			speed = 120;

		create(car, bar);

		while (true)
		{


			show(car, bar, dem);
		
			control(car,z);

			if (z == 1)
			{
				dung = 1;
				dem = 0;
				break;
			}

			if (z == 2)
			{
				_getch();
				z = 0;
			}
			p = move(car, bar, speed, life, dem, chon);


			if (p == 2)
				continue;


			if (p == -1)
			{
				gotoXY(consoledoc / 2 +30, bienphai / 2);
				cout << "Ban ga qua";

				gotoXY(consolengang / 2, consoledoc);

				while (_getch() != 13); // bam enter de dung
				break;

			}

			Sleep(speed);
			dem++;
		}
		if (z == 0)
		{
			clrscr();
			gotoXY(consolengang - 38, consoledoc / 2);
			cout << "Nhap ho ten:";
			cin >> hoten;
			clrscr();
			ofstream outData;

			outData.open("diem.txt", ios::app);

			outData << hoten << "-" << car.score << endl;
			outData.close();

			ifstream inData;
			inData.open("diem.txt");

			long dem3 = 15, dem4 = 0, diem1;
			while (!inData.eof())
			{

				getline(inData, hoten, '-');

				inData >> diem1;

				inData.ignore(1);

				ten[dem4] = hoten;
				diem[dem4] = diem1;
				dem4++;
			}
			long dem5 = 0, dem6 = 0;
			luu(ten, diem, dem4);
			cout << "Bang xep hang top 5 hien tai: " << endl;
			for (int i = 0; i < dem4; i++)
			{
				if (diem[i] == car.score && dem5 == 1)
				{
					dem6++;
					continue;
				}
				cout << ten[i] << "\t" << diem[i] << endl;
				if (dem5 == 4)
					break;
				dem5++;
			}
			inData.close();

			cout << "Nhap 1 de choi lai: ";
			cin >> dung;

			dem = 0;
		}
	}while (dung == 1);
	return 0;
}
// 15