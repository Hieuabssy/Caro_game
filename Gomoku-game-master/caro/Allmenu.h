#pragma once
#include<iostream>
#include"Control.h"
#include"View.h"
#include<conio.h>
#include<Windows.h>
#include<string>
#include<fstream>
#include"Graphics.h"

using namespace std;

void Help();   //in ra giao dien cua help
void About(); //in ra dao dien cua about

void Help() {
	GotoXY(37, 3);
	cout << "Play PVP";
	GotoXY(16, 5);
	cout << "Player1";
	GotoXY(10, 7);
	cout << "-Press W to move up";
	GotoXY(10, 8);
	cout << "-Press S to move down";
	GotoXY(10, 9);
	cout << "-Press D to move right";
	GotoXY(10, 10);
	cout << "-Press A to move left";
	GotoXY(10, 12);
	cout << "-Press Enter to tick";
	GotoXY(59, 5);
	cout << "Player 2:";
	GotoXY(50, 7);
	cout << "-Press Top key to move up";
	GotoXY(50, 8);
	cout << "-Press Down key to move down";
	GotoXY(50, 9);
	cout << "-Press Right key to move right";
	GotoXY(50, 10);
	cout << "-Press Left key to move left";
	GotoXY(50, 12);
	cout << "-Press Space to tick";
	GotoXY(37, 17);
	cout << "Play PVC";
	GotoXY(31, 19);
	cout << "-Press W to move up";
	GotoXY(31, 20);
	cout << "-Press S to move down";
	GotoXY(31, 21);
	cout << "-Press D to move right";
	GotoXY(31, 22);
	cout << "-Press A to move left";
	GotoXY(31, 23);
	cout << "-Press Enter to tick";
	GotoXY(27, 30);
	cout << "<-----Press Esc to quit----->";
	
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) break;
	}
	system("cls");
}

void About() {
	box_about();
	GotoXY(10, 4);
	cout << "GROUP 10";
	GotoXY(10, 6);
	cout << "MEMBER:";
	GotoXY(10, 7);
	cout << "1.Vu Nguyen Trung Hieu";
	GotoXY(10, 8);
	cout << "2.Doan Quang Thang";
	GotoXY(10, 9);
	cout << "3.Chau Van Minh Khoa";
	GotoXY(10, 10);
	cout << "4.Phan Ngoc Quan";
	GotoXY(10, 12);
	cout << "----------------------------------";
	GotoXY(10, 13);
	cout << "Instructor: PhD.Truong Toan Thinh";
	GotoXY(10, 15);
	cout << "<--------Press Esc to quit-------->";
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) break;
	}
	system("cls");
}





