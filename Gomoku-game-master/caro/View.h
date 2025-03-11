#pragma once
#include<iostream>
#include<Windows.h>
#include"Control.h"
#include<conio.h>
using namespace std;


#define BOARD_SIZE 15
#define LEFT 1									 
#define TOP 1	

const  long Defend_Score1[7] = { 0, 8, 512, 32768, 2097152, 134217728 };
const  long Attack_Score1[7] = { 0, 64, 4096, 262144, 16777216, 1073741824 };

const  long Defend_Score2[7] = { 1, 2, 3, 1, 1, 1 };
const  long Attack_Score2[7] = { 2, 3, 4, 5, 6, 7 };


struct _POINT {
	int x, y, c;
};
_POINT _A[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X;
int _Y;
string filename="";
string option="";
string player1="";
string player2="";
int x1 = 0;
int x2 = 0;
int win1 = 0, lose1 = 0, draw1 = 0;
int win2 = 0, lose2 = 0, draw2 = 0;
bool sound = true;

void FixConsoleWindow();  //co dinh man hinh console
void setConsoleWindow(int, int);  //dat kich thuoc cho man hinh console
void Nocursortype();   //an con tro chuot
void UnNocursortype(); //hien thi con tro chuot
void GotoXY(int , int);  //di chuyen den toa do (x,y) 
void SetColor(int, int);  // ham dat mau cho chu
void HighLight(int, int, int, int, int); //ve khoi hinh chu nhat co chieu cao h va chieu rong w tren man hinh
void Background();  //dat man hinh nen la mau trang
void DrawBoard(int, int, int); //ham ve bang
void ResetData();//thiet lap du lieu cho ban co
int CheckBoard(int , int ); //gan gia tri cho o co khi bam Enter
void StartGame(); // ham bat dau cho choi
int CheckTick(int, int);  //ham kiem tra gia tri o co
int testBoard(int, int, int);  //kiem tra thang thua hoa
void DrawLineWin(int, int); // ham hien thi chien thang

long SoDiemTanCong_DuyetNgang(long, long,const long[],const long[]); //tinh diem tan cong ngang
long SoDiemTanCong_DuyetDoc(long, long);//tinh diem tan cong doc
long SoDiemTanCong_DuyetCheo1(long, long); //tinh diem tan cong cheo phai sang trai
long SoDiemTanCong_DuyetCheo2(long, long);//tinh diem tan cong trai sang phai
long SoDiemPhongThu_DuyetNgang(long, long);//tinh diem phong thu ngang
long SoDiemPhongThu_DuyetDoc(long, long);//tinh diem phong thu doc
long SoDiemPhongThu_DuyetCheo1(long, long);//tinh diem phong thu cheo phai sang trai
long SoDiemPhongThu_DuyetCheo2(long, long);//tinh diem phong thu cheo trai sang phai
_POINT Tim_Kiem_NuocDi(); // lua chon nuoc di dua tren so diem da tinh

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void setConsoleWindow(int w, int h)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void UnNocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}


void GotoXY(int pX, int pY)
{
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void SetColor(int backgound_color, int text_color) {
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}


void Background() 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hConsole, &csbi);

	// Đặt màu nền cho toàn bộ console thành màu trắng
	FillConsoleOutputAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
}

void HighLight(int x, int y, int w, int h, int color) {
	SetColor(color, color);
	for (int i = x; i < x + w; i++)
		for (int j = y; j < y + h; j++) {
			GotoXY(i, j);
			cout << " ";
		}
	SetColor(15, 0);

}

// ham ve bang
void DrawBoard(int _size, int _top, int _left) {
	GotoXY(1, 1);
	HighLight(0, 0, 0, 0, 0);
	for (int i = 1; i <= _left + 4 * _size; i++)
	{

		if (i == 1) putchar(201);
		else if (i == _left + 4 * _size) putchar(187);
		else putchar(205);

	}
	for (int i = 2; i <= _top + 2 * _size; i++)
	{
		GotoXY(1, i); putchar(186);
		GotoXY(_left + 4 * _size, i); putchar(186);
	}
	GotoXY(1, _top + 2 * _size);
	for (int i = 1; i <= _left + 4 * _size; i++)
	{
		if (i == 1) putchar(200);
		else if (i == _left + 4 * _size) putchar(188);
		else putchar(205);

	}
	for (int j = 1; j <= _size - 1; j++) {
		GotoXY(2, j * 2 + 1);
		for (int i = 2; i <= _left + 4 * _size - 1; i++) {
			putchar(196);
		}

	}
	for (int j = 1; j <= _size; j++) {
		for (int i = 1; i <= _size - 1; i++) {
			GotoXY(4 * i + 1, 2 * j); putchar(179);
			GotoXY(4 * i + 1, 2 * j + 1); putchar(197);

		}
		GotoXY(2, _top + 2 * _size);
		for (int i = 2; i <= _left + 4 * _size - 1; i++) {
			putchar(205);
		}
	}
	GotoXY(_left + 4 * _size + 20, 10);
	cout << "F1 : New Game";
	GotoXY(_left + 4 * _size + 20, 12);
	cout << "F2 : Save Game";
	GotoXY(_left + 4 * _size + 40, 10);
	cout << "F3 : Load Game";
	GotoXY(_left + 4 * _size + 40, 12);
	cout << "F4 : Undo Step";
	GotoXY(_left + 4 * _size + 29, 14);
	cout << "ESC: Return Menu!";
	GotoXY(_left + 4 * _size + 28, 19);
	cout << "<<GAME INFOMATION>>";

	GotoXY(_left + 4 * _size + 15, 2);
	for (int i = _left + 4 * _size + 15; i <= _left + 4 * _size + 60; i++)
	{
		if (i == _left + 4 * _size + 15) putchar(201);
		else if (i == _left + 4 * _size + 60) putchar(187);
		else putchar(205);
	}
	for (int i = 3; i <= 6; i++)
	{
		GotoXY(_left + 4 * _size + 15, i); putchar(186);
		GotoXY(_left + 4 * _size + 60, i); putchar(186);
	}
	GotoXY(_left + 4 * _size + 15, 6);
	for (int i = _left + 4 * _size + 15; i <= _left + 4 * _size + 60; i++)
	{
		if (i == _left + 4 * _size + 15) putchar(200);
		else if (i == _left + 4 * _size + 60) putchar(188);
		else putchar(205);
	}
}


void ResetData() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_A[i][j].x = 4 * j + LEFT + 2; // Trùng với hoành độ màn hình bàn cờ
			_A[i][j].y = 2 * i + TOP + 1; // Trùng với tung độ màn hình bàn cờ
			_A[i][j].c = 0; // 0 nghĩa là chưa ai đánh dấu, nếu đánh dấu phải theo quy
			
		}
	}
	_COMMAND = -1; // Gán phím mặc định
	_X = _A[0][0].x; _Y = _A[0][0].y; // Thiết lập lại tọa độ hiện hành ban đầu
}


int CheckBoard(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) //Lượt của người 1 
					_A[i][j].c = -1; //c= -1 tức là X
				else _A[i][j].c = 1; //c=1 tức là O
				return _A[i][j].c;
			}
		}
	}
	return 0;
}


void StartGame() {
	system("cls");
	x1 = 0;
	x2 = 0;
	SetColor(15, 2);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
	cout << "Player2: " << player2;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
	cout << "Step:" << x2 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
	cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2 << " ";

	SetColor(15, 5);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
	cout << "Player1: " << player1;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
	cout << "Step:" << x1 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
	cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1 << " ";
	SetColor(15, 0);
	ResetData(); // Khởi tạo dữ liệu gốc
	DrawBoard(BOARD_SIZE, TOP, LEFT); // Vẽ màn hình
}

int CheckTick(int pX, int pY) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY)
				return _A[i][j].c;
		}
	}
}
int testBoard(int pX, int pY, int _size)
{
	// Xu ly hoa
	int dem = 0;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_A[i][j].c != 0)
			{
				dem++;
				
			}
		}
	}
	if (dem >= 180) return 0;

	//Xu ly thang/thua
	int x = 0;
	int y = 0;

	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			if (_A[i][j].x == pX && _A[i][j].y == pY)
			{
				x = i;
				y = j;
				break;
			}
		}
	}
	int res = 0;
	int xStart = (x - 4 > 0) ? x - 4 : 0;
	int yStart = (y - 4 > 0) ? y - 4 : 0;

	int xEnd = (x + 4 >= _size) ? _size - 1 : x + 4;
	int yEnd = (y + 4 >= _size) ? _size - 1 : y + 4;

	int x1, x2, y1, y2;

	for (int i = xStart; i <= x; i++)
	{
		if (i + 4 < _size)
		{
			res = _A[i][y].c + _A[i + 1][y].c + _A[i + 2][y].c
				+ _A[i + 3][y].c + _A[i + 4][y].c;

			x1 = i - 1 >= 0 ? i - 1 : xStart;
			y1 = y;

			x2 = i + 5 >= _size ? x + 4 : i + 5;
			y2 = y;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			
			pX = i;
			pY = y;
			return 1;
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			pX = i;
			pY = y;
			return -1;
		}
	}

	for (int i = yStart; i <= y; i++)
	{
		if (i + 4 < _size)
		{
			res = _A[x][i].c + _A[x][i + 1].c + _A[x][i + 2].c
				+ _A[x][i + 3].c + _A[x][i + 4].c;

			x1 = x;
			y1 = i - 1 >= 0 ? i - 1 : yStart;

			x2 = x;
			y2 = i + 5 >= _size ? y + 4 : i + 5;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			pX = x;
			pY = i;
			return 1;
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			pX = x;
			pY = i;
			return -1;
		}
	}

	for (int i = xStart; i <= x; i++)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i - j == x - y && i + 4 < _size && j + 4 < _size)
			{
				res = _A[i][j].c + _A[i + 1][j + 1].c + _A[i + 2][j + 2].c
					+ _A[i + 3][j + 3].c + _A[i + 4][j + 4].c;
				x1 = i - 1;
				y1 = j - 1;
				if (x1 < 0 || y1 < 0)
				{
					x1 = i;
					y1 = j;
				}
				x2 = i + 5;
				y2 = j + 5;
				if (x2 >= _size || y2 >= _size)
				{
					y2 = j;
					x2 = i;
				}
			}

			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}

	for (int i = xEnd; i >= x; i--)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i + j == x + y && j + 4 < _size && i - 4 >= 0)
			{
				res = _A[i][j].c + _A[i - 1][j + 1].c + _A[i - 2][j + 2].c
					+ _A[i - 3][j + 3].c + _A[i - 4][j + 4].c;
				x1 = i + 1;
				y1 = j - 1;
				if (x1 >= _size || y1 < 0)
				{
					x1 = i;
					y1 = i;
				}
				x2 = i - 5;
				y2 = j + 5;
				if (x2<0 || y2>_size)
				{
					x2 = i;
					y2 = j;
				}
			}
			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				pX = i;
				pY = j;
				return 1;
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				pX = i;
				pY = j;
				return -1;
			}
		}
	}

	return 2;
}

void DrawLineWin(int pX, int pY)
{
	int x = 0;
	int y = 0;

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].x == pX && _A[i][j].y == pY)
			{
				x = i;
				y = j;
				break;
			}
		}
	}
	int res = 0;
	int xStart = (x - 4 > 0) ? x - 4 : 0;
	int yStart = (y - 4 > 0) ? y - 4 : 0;

	int xEnd = (x + 4 >= BOARD_SIZE) ? BOARD_SIZE - 1 : x + 4;
	int yEnd = (y + 4 >= BOARD_SIZE) ? BOARD_SIZE - 1 : y + 4;

	int x1, x2, y1, y2;

	for (int i = xStart; i <= x; i++)
	{
		if (i + 4 < BOARD_SIZE)
		{
			res = _A[i][y].c + _A[i + 1][y].c + _A[i + 2][y].c
				+ _A[i + 3][y].c + _A[i + 4][y].c;

			x1 = i - 1 >= 0 ? i - 1 : xStart;
			y1 = y;

			x2 = i + 5 >= BOARD_SIZE ? x + 4 : i + 5;
			y2 = y;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			int j = 0;
			while (_A[i+j][y].c ==1) {
				GotoXY(y * 4 + LEFT + 2, (i + j) * 2 + TOP + 1);
				cout << "O";
				j++;
				
			}
			return ;//1
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			int j = 0;
			while (_A[i + j][y].c == -1) {
				GotoXY(y * 4 + LEFT + 2, (i + j) * 2 + TOP + 1);
				cout << "X";
				j++;
			}
			return ;//-1
		}
	}

	for (int i = yStart; i <= y; i++)
	{
		if (i + 4 < BOARD_SIZE)
		{
			res = _A[x][i].c + _A[x][i + 1].c + _A[x][i + 2].c
				+ _A[x][i + 3].c + _A[x][i + 4].c;

			x1 = x;
			y1 = i - 1 >= 0 ? i - 1 : yStart;

			x2 = x;
			y2 = i + 5 >= BOARD_SIZE ? y + 4 : i + 5;
		}

		if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
		{
			int j = 0;
			while (_A[x ][i+j].c == 1) {
				GotoXY((i+j) * 4 + LEFT + 2, x * 2 + TOP + 1);
				cout << "O";
				j++;
			}
			return ;//1
		}
		if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
		{
			int j = 0;
			while (_A[x][i + j].c == -1) {
				GotoXY((i+j) * 4 + LEFT + 2, x * 2 + TOP + 1);
				cout << "X";
				j++;
			}
			return ;//-1
		}
	}

	for (int i = xStart; i <= x; i++)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i - j == x - y && i + 4 < BOARD_SIZE && j + 4 < BOARD_SIZE)
			{
				res = _A[i][j].c + _A[i + 1][j + 1].c + _A[i + 2][j + 2].c
					+ _A[i + 3][j + 3].c + _A[i + 4][j + 4].c;
				x1 = i - 1;
				y1 = j - 1;
				if (x1 < 0 || y1 < 0)
				{
					x1 = i;
					y1 = j;
				}
				x2 = i + 5;
				y2 = j + 5;
				if (x2 >= BOARD_SIZE || y2 >= BOARD_SIZE)
				{
					y2 = j;
					x2 = i;
				}
			}

			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				int h = 0;
				while (_A[i + h][j + h].c == 1) {
					GotoXY((j + h) * 4 + LEFT + 2, (i + h) * 2 + TOP + 1);
					cout << "O";
					h++;
				}
				return ;//1
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				int h = 0;
				while (_A[i + h][j + h].c == -1) {
					GotoXY((j + h) * 4 + LEFT + 2, (i + h) * 2 + TOP + 1);
					cout << "X";
					h++;
				}
				return ;//-1
			}
		}
	}

	for (int i = xEnd; i >= x; i--)
	{
		for (int j = yStart; j <= y; j++)
		{
			if (i + j == x + y && j + 4 < BOARD_SIZE && i - 4 >= 0)
			{
				res = _A[i][j].c + _A[i - 1][j + 1].c + _A[i - 2][j + 2].c
					+ _A[i - 3][j + 3].c + _A[i - 4][j + 4].c;
				x1 = i + 1;
				y1 = j - 1;
				if (x1 >= BOARD_SIZE || y1 < 0)
				{
					x1 = i;
					y1 = i;
				}
				x2 = i - 5;
				y2 = j + 5;
				if (x2<0 || y2>BOARD_SIZE)
				{
					x2 = i;
					y2 = j;
				}
			}
			if (res == 5 && (_A[x1][y1].c != -1 || _A[x2][y2].c != -1))
			{
				int h = 0;
				while (_A[i-h][j+h].c == 1) {
					GotoXY((j + h) * 4 + LEFT + 2, (i - h) * 2 + TOP + 1);
					cout << "O";
					h++;
				}
				return ;
			}
			if (res == -5 && (_A[x1][y1].c != 1 || _A[x2][y2].c != 1))
			{
				int h = 0;
				while (_A[i-h][j+h].c == -1) {
					GotoXY((j + h) * 4 + LEFT + 2, (i - h) * 2 + TOP + 1);
					cout << "X";
					h++;
				}
				return ;
			}
		}
	}
}
long SoDiemTanCong_DuyetNgang(long Dong, long Cot,const long defense[], const long attack[])
{
	long iScoreTempNgang = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong][Cot + iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong][Cot + iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong][Cot + iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong][Cot + iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong][Cot + iDem2].c == 0)
					break;
			}
			break;
		}
	}


	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_A[Dong][Cot - iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong][Cot - iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong][Cot - iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong][Cot - iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong][Cot - iDem2].c == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempNgang += attack[iSoQuanTa] * 2;
	else
		iScoreTempNgang += attack[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempNgang += attack[iSoQuanTa2] * 2;
	else
		iScoreTempNgang += attack[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanTa == 4)
		iScoreTempNgang *= 2;
	if (iSoQuanTa == 0)
		iScoreTempNgang += defense[iSoQuanDich] * 2;
	else
		iScoreTempNgang += defense[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempNgang += defense[iSoQuanDich2] * 2;
	else
		iScoreTempNgang += defense[iSoQuanDich2];
	return iScoreTempNgang;
}
long SoDiemTanCong_DuyetDoc(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempDoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot].c == 1)
			iSoQuanTa++;
		if (_A[Dong + iDem][Cot].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong + iDem][Cot].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot].c == 1)
					iSoQuanTa2++;
				if (_A[Dong + iDem2][Cot].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong + iDem2][Cot].c == 0)
					break;
			}
			break;
		}

	}


	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot].c == 1)
			iSoQuanTa++;
		if (_A[Dong - iDem][Cot].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong - iDem][Cot].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot].c == 1)
					iSoQuanTa2++;
				if (_A[Dong - iDem2][Cot].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong - iDem2][Cot].c == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempDoc += attack[iSoQuanTa] * 2;
	else
		iScoreTempDoc += attack[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempDoc += attack[iSoQuanTa2] * 2;
	else
		iScoreTempDoc += attack[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempDoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempDoc += defense[iSoQuanDich] * 2;
	else
		iScoreTempDoc += defense[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempDoc += defense[iSoQuanDich2] * 2;
	else
		iScoreTempDoc += defense[iSoQuanDich2];
	return iScoreTempDoc;
}

long SoDiemTanCong_DuyetCheo1(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempCheoNguoc = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot + iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong + iDem][Cot + iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong + iDem][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < BOARD_SIZE && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot + iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong + iDem2][Cot + iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong + iDem2][Cot + iDem2].c == 0)
				{
					break;
				}
			}
			break;
		}
	}
	

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot - iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong - iDem][Cot - iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong - iDem][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot - iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong - iDem2][Cot - iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong - iDem2][Cot - iDem2].c == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoNguoc += attack[iSoQuanTa] * 2;
	else
		iScoreTempCheoNguoc += attack[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoNguoc += attack[iSoQuanTa2] * 2;
	else
		iScoreTempCheoNguoc += attack[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoNguoc *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += defense[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += defense[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoNguoc += defense[iSoQuanDich2] * 2;
	else
		iScoreTempCheoNguoc += defense[iSoQuanDich2];
	return iScoreTempCheoNguoc;
}
long SoDiemTanCong_DuyetCheo2(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreAttack = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa2 = 0;
	int iSoQuanDich2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot - iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong + iDem][Cot - iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong + iDem][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot - iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong + iDem2][Cot - iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong + iDem2][Cot - iDem2].c == 0)
					break;
			}
			break;
		}
	}


	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot + iDem].c == 1)
			iSoQuanTa++;
		if (_A[Dong - iDem][Cot + iDem].c == -1)
		{
			iSoQuanDich++;
			break;
		}
		if (_A[Dong - iDem][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < BOARD_SIZE && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot + iDem2].c == 1)
					iSoQuanTa2++;
				if (_A[Dong - iDem2][Cot + iDem2].c == -1)
				{
					iSoQuanDich2++;
					break;
				}
				if (_A[Dong - iDem2][Cot + iDem2].c == 0)
					break;
			}
			break;
		}
	}
	if (iSoQuanDich == 2)
		return 0;
	if (iSoQuanDich == 0)
		iScoreTempCheoXuoi += attack[iSoQuanTa] * 2;
	else
		iScoreTempCheoXuoi += attack[iSoQuanTa];
	if (iSoQuanDich2 == 0)
		iScoreTempCheoXuoi += attack[iSoQuanTa2] * 2;
	else
		iScoreTempCheoXuoi += attack[iSoQuanTa2];

	if (iSoQuanTa >= iSoQuanTa2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanTa == 4)
		iScoreTempCheoXuoi *= 2;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += defense[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += defense[iSoQuanDich];
	if (iSoQuanTa2 == 0)
		iScoreTempCheoXuoi += defense[iSoQuanDich2] * 2;
	else
		iScoreTempCheoXuoi += defense[iSoQuanDich2];
	return iScoreTempCheoXuoi;
}

long SoDiemPhongThu_DuyetDoc(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempDoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong + iDem][Cot].c == -1)
			iSoQuanDich++;
		if (_A[Dong + iDem][Cot].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong + iDem2][Cot].c == -1)
					iSoQuanDich2++;
				if (_A[Dong + iDem2][Cot].c == 0)
					break;
			}
			break;
		}
	}


	for (int iDem = 1; iDem < 6 && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong - iDem][Cot].c == -1)
			iSoQuanDich++;
		if (_A[Dong - iDem][Cot].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong - iDem2][Cot].c == -1)
					iSoQuanDich2++;
				if (_A[Dong - iDem2][Cot].c == 0)
					break;
			}
			break;
		}
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempDoc += defense[iSoQuanDich] * 2;
	else
		iScoreTempDoc += defense[iSoQuanDich];
	
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempDoc -= 1;
	else
		iScoreTempDoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempDoc *= 2;
	return iScoreTempDoc;
}

long SoDiemPhongThu_DuyetNgang(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempNgang = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong][Cot + iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong][Cot + iDem].c == -1)
			iSoQuanDich++;
		if (_A[Dong][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong][Cot + iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong][Cot + iDem2].c == -1)
					iSoQuanDich2++;
				if (_A[Dong][Cot + iDem2].c == 0)
					break;
			}
			break;
		}
	}
	

	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0; iDem++)
	{
		if (_A[Dong][Cot - iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong][Cot - iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong][Cot - iDem2].c == 0)
					break;
				if (_A[Dong][Cot - iDem2].c == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_A[Dong][Cot - iDem].c == -1)
			iSoQuanDich++;
	}

	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempNgang += defense[iSoQuanDich] * 2;
	else
		iScoreTempNgang += defense[iSoQuanDich];
	
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempNgang -= 1;
	else
		iScoreTempNgang -= 2;
	if (iSoQuanDich == 4)
		iScoreTempNgang *= 2;
	return iScoreTempNgang;
}

long SoDiemPhongThu_DuyetCheo1(long Dong, long Cot, const long defense[], const long attack[])
{

	long iScoreTempCheoNguoc = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot + iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong + iDem][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot + iDem2 < BOARD_SIZE && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot + iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong + iDem2][Cot + iDem2].c == 0)
					break;
				if (_A[Dong + iDem2][Cot + iDem2].c == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_A[Dong + iDem][Cot + iDem].c == -1)
			iSoQuanDich++;
	}


	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot - iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}

		if (_A[Dong - iDem][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot - iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}

				if (_A[Dong - iDem2][Cot - iDem2].c == 0)
					break;
				if (_A[Dong - iDem2][Cot - iDem2].c == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_A[Dong - iDem][Cot - iDem].c == -1)
			iSoQuanDich++;
	}
	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoNguoc += defense[iSoQuanDich] * 2;
	else
		iScoreTempCheoNguoc += defense[iSoQuanDich];
	
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoNguoc -= 1;
	else
		iScoreTempCheoNguoc -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoNguoc *= 2;
	return iScoreTempCheoNguoc;
}

long SoDiemPhongThu_DuyetCheo2(long Dong, long Cot, const long defense[], const long attack[])
{
	long iScoreTempCheoXuoi = 0;
	long iScoreDefend = 0;
	int iSoQuanDich = 0;
	int iSoQuanTa = 0;
	int iSoQuanDich2 = 0;
	int iSoQuanTa2 = 0;
	for (int iDem = 1; iDem < 6 && Cot - iDem >= 0 && Dong + iDem < BOARD_SIZE; iDem++)
	{
		if (_A[Dong + iDem][Cot - iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong + iDem][Cot - iDem].c == 0)
		{
			for (int iDem2 = 2; iDem2 < 7 && Cot - iDem2 >= 0 && Dong + iDem2 < BOARD_SIZE; iDem2++)
			{
				if (_A[Dong + iDem2][Cot - iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong + iDem2][Cot - iDem2].c == 0)
					break;
				if (_A[Dong + iDem2][Cot - iDem2].c == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_A[Dong + iDem][Cot - iDem].c == -1)
			iSoQuanDich++;
	}
	

	for (int iDem = 1; iDem < 6 && Cot + iDem < BOARD_SIZE && Dong - iDem >= 0; iDem++)
	{
		if (_A[Dong - iDem][Cot + iDem].c == 1)
		{
			iSoQuanTa++;
			break;
		}
		if (_A[Dong - iDem][Cot + iDem].c == 0)
		{
			for (int iDem2 = 2; iDem < 7 && Cot + iDem2 < BOARD_SIZE && Dong - iDem2 >= 0; iDem2++)
			{
				if (_A[Dong - iDem2][Cot + iDem2].c == 1)
				{
					iSoQuanTa2++;
					break;
				}
				if (_A[Dong - iDem2][Cot + iDem2].c == 0)
					break;
				if (_A[Dong - iDem2][Cot + iDem2].c == -1)
					iSoQuanDich2++;
			}
			break;
		}
		if (_A[Dong - iDem][Cot + iDem].c == -1)
			iSoQuanDich++;
	}


	if (iSoQuanTa == 2)
		return 0;
	if (iSoQuanTa == 0)
		iScoreTempCheoXuoi += defense[iSoQuanDich] * 2;
	else
		iScoreTempCheoXuoi += defense[iSoQuanDich];
	
	if (iSoQuanDich >= iSoQuanDich2)
		iScoreTempCheoXuoi -= 1;
	else
		iScoreTempCheoXuoi -= 2;
	if (iSoQuanDich == 4)
		iScoreTempCheoXuoi *= 2;
	return iScoreTempCheoXuoi;
}

_POINT Tim_Kiem_NuocDi_hard()
{
	_POINT Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_A[i][j].c == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);
				//////////////////////////////////////////////
				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.x=(cot * 4 + 2+LEFT);
	Oco.y=(dong * 2 + 1+TOP);
	
	return Oco;
}


_POINT Tim_Kiem_NuocDi_easy()
{
	_POINT Oco;
	int dong = 0, cot = 0;
	long Diem = 0;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			long DiemTanCong = 0;
			long DiemPhongThu = 0;
			if (_A[i][j].c == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);
				//////////////////////////////////////////////
				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						dong = i;
						cot = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						dong = i;
						cot = j;
					}
				}
			}
		}
	}
	Oco.x = (cot * 4 + 2 + LEFT);
	Oco.y = (dong * 2 + 1 + TOP);

	return Oco;
}

