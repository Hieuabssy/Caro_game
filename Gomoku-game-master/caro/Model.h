#pragma once
#include<iostream>
#include"Control.h"
#include"View.h"
#include<conio.h>
#include"Allmenu.h"
#include<fstream>
#include<string>

using namespace std;

void Load();//tai game da luu
void SaveFileName();// luu danh sach ten cua file da luu
void SavePVP(); //luu game che do nguoi voi nguoi
void SavePVC(); //luu game che do nguoi voi may

void SavePVP() {
	GotoXY(78, 5);
	cout << "                                         ";
	GotoXY(78, 5);
	cout << "Enter a file name to save: ";
	cin >> filename;
	GotoXY(78, 5);
	cout << "                                         ";
	GotoXY(73, 7);
	cout << "                                                 ";
	ifstream check;
	check.open("filename.txt");
	string read;
	bool kt=0;
	while (getline(check, read)) {
		if (filename == read) {
			kt = 1;
			GotoXY(78, 5);
			cout << "                                          ";
			GotoXY(75, 7);
			cout << "Filename already exists, press F2 to try again! ";
		}
		if (read.length() > 15)
		{
			kt = 1;
			GotoXY(78, 5);
			cout << "                                           ";
			GotoXY(75, 7);
			cout << "Max length of Filename is 15, press F2 to try again! ";
		}
	}
	if (kt == 0) {
		GotoXY(75, 7);
		cout << "                                                 ";
		GotoXY(89, 5);
		SetColor(15, 4);
		cout << "Saved successfully!";
		SetColor(15, 0);
		ofstream SaveGame(filename);
		SaveGame << _TURN;
		SaveGame << endl;
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				SaveGame << _A[i][j].c << " ";
			}
			SaveGame << endl;
		}

		SaveGame << player1 << endl;
		SaveGame << x1 << " " << win1 << " " << lose1 << " " << draw1 << endl;
		SaveGame << player2 << endl;

		SaveGame << x2 << " " << win2 << " " << lose2 << " " << draw2 << endl;
		SaveGame << "PVP";
		SaveGame.close();
		SaveFileName();
	}
	
}

void SavePVC() {
	GotoXY(78, 5);
	cout << "                                          ";
	GotoXY(78, 5);
	cout << "Enter a file name to save: ";
	cin >> filename;
	GotoXY(78, 5);
	cout << "                                         ";
	GotoXY(73, 7);
	cout << "                                                 ";
	ifstream check;
	check.open("filename.txt");
	string read;
	bool kt = 0;
	while (getline(check, read)) {
		if (filename == read) {
			kt = 1;
			GotoXY(78, 5);
			cout << "                                          ";
			GotoXY(75, 7);
			cout << "Filename already exists, press F2 to try again! ";
		}
	}
	if (kt == 0) {
		GotoXY(75, 7);
		cout << "                                                 ";
		GotoXY(89, 5);
		SetColor(15, 4);
		cout <<"Saved successfully!";
		SetColor(15, 0);
		ofstream SaveGame(filename);
		SaveGame << _TURN;
		SaveGame << endl;
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				SaveGame << _A[i][j].c << " ";
			}
			SaveGame << endl;
		}
		SaveGame << player1 << endl;
		SaveGame << x1 << " " << win1 << " " << lose1 << " " << draw1 << endl;
		SaveGame << player2 << endl;

		SaveGame << x2 << " " << win2 << " " << lose2 << " " << draw2 << endl;
		SaveGame << option;
		SaveGame.close();
		SaveFileName();
	}
}



void Load() {
	ResetData();
	
	ifstream LoadGame;
	LoadGame.open(filename);
	LoadGame >> _TURN;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			LoadGame >> _A[i][j].c;
		}
	}
	LoadGame >> player1;
	LoadGame >> x1; LoadGame >> win1; LoadGame >> lose1; LoadGame >> draw1;
	LoadGame >> player2;
	LoadGame >> x2; LoadGame >> win2; LoadGame >> lose2; LoadGame >> draw2;
	
	LoadGame >> option;

	LoadGame.close();
	SetColor(15, 2);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 23);
	cout << "Player2: " << player2;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 23);
	cout << "Step:" << x2 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 23);
	cout << "W/L/D:" << win2 << "/" << lose2 << "/" << draw2<<" ";

	SetColor(15, 5);
	GotoXY(LEFT + 4 * BOARD_SIZE + 13, 21);
	cout << "Player1: " << player1;
	GotoXY(LEFT + 4 * BOARD_SIZE + 35, 21);
	cout << "Step:" << x1 << " ";
	GotoXY(LEFT + 4 * BOARD_SIZE + 50, 21);
	cout << "W/L/D:" << win1 << "/" << lose1 << "/" << draw1<<" ";
	DrawBoard(BOARD_SIZE, TOP, LEFT);

	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			_X = _A[i][j].x;
			_Y = _A[i][j].y;
			GotoXY(_X, _Y);
			if (_A[i][j].c == -1) {
				SetColor(15, 5);
				cout << "X";
			}
			if (_A[i][j].c == 1) {
				SetColor(15, 2);
				cout << "O";
			}
			if (_A[i][j].c == 0) {
				cout << " ";
			}
		}
	}
	
 }


void SaveFileName() 
{
	fstream SaveName;
	SaveName.open("filename.txt",ios::app);
	SaveName <<endl<<filename;
	SaveName.close();
}

void get_info() {
	ifstream get;
	get.open(filename);
	get >> _TURN;
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			get >> _A[i][j].c;
		}
	}
	get >> player1;
	get >> x1; get >> win1; get >> lose1; get >> draw1;
	get >> player2;
	get >> x2; get >> win2; get >> lose2; get >> draw2;

	get >> option;

	get.close();
}
