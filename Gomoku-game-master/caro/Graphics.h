#pragma once
#include<iostream>
#include<Windows.h>
#include"Control.h"
#include<conio.h>

using namespace std;

void menu_display(); //in ra chu caro
void Remote_Graphic();  //ve remote
void XO_Graphic(); // ve hinh caro
void draw();  // ve chu draw khi hoa
void listgame_Graphic();  //ve ra hinh tap ghi chep
void owin();  //ve ra chu owin
void xwin();  //ve ra chu x win


void menu_display() {
	// C (black)
	HighLight(35, 4, 2, 1, 0);
	HighLight(35, 9, 2, 1, 0);
	HighLight(42, 9, 2, 1, 0);
	HighLight(42, 4, 2, 1, 0);
	for (int i = 0; i <= 5; i++)
	{
		HighLight(36 + i, 3, 2, 1, 0);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(34, 5 + i, 2, 1, 0);
	}
	for (int i = 0; i <= 5; i++)
	{
		HighLight(36 + i, 10, 2, 1, 0);
	}
	//chu C ( blue)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(33, 5 + i, 1, 1, 11);
	}

	HighLight(34, 4, 1, 1, 11);
	HighLight(36, 3, 1, 1, 11);
	HighLight(34, 9, 1, 1, 11);
	HighLight(35, 10, 1, 1, 11);
	HighLight(41, 4, 1, 1, 11);
	HighLight(41, 9, 1, 1, 11);
	// chu C ( red)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(36, 5 + i, 1, 1, 4);
	}
	HighLight(37, 4, 1, 1, 4);
	HighLight(37, 9, 1, 1, 4);
	HighLight(44, 4, 1, 1, 4);
	HighLight(43, 3, 1, 1, 4);
	HighLight(44, 9, 1, 1, 4);
	HighLight(43, 10, 1, 1, 4);
	// A (black)
	for (int i = 0; i <= 5; i++) {

		HighLight(50, 10 - i, 2, 1, 0);
	}
	HighLight(51, 4, 2, 1, 0);
	for (int i = 0; i <= 4; i++) {

		HighLight(52 + i, 3, 2, 1, 0);
	}
	HighLight(57, 4, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(58, 10 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {

		HighLight(52 + i, 7, 2, 1, 0);
	}
	// chu A (blue)
	for (int i = 0; i <= 5; i++)
	{
		HighLight(49, 5 + i, 1, 1, 11);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(57, 5 + i, 1, 1, 11);
	}
	HighLight(56, 4, 1, 1, 11);
	HighLight(50, 4, 1, 1, 11);
	HighLight(51, 3, 1, 1, 11);
	//chu A( red) 
	for (int i = 0; i <= 5; i++)
	{
		HighLight(60, 5 + i, 1, 1, 4);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(52, 5 + i, 1, 1, 4);
	}
	HighLight(59, 4, 1, 1, 4);
	HighLight(53, 4, 1, 1, 4);
	HighLight(58, 3, 1, 1, 4);
	// R (black)
	for (int i = 0; i <= 7; i++) {

		HighLight(66, 10 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 6; i++) {

		HighLight(66 + i, 3, 2, 1, 0);
	}
	HighLight(72, 4, 2, 1, 0);
	HighLight(73, 4, 2, 1, 0);
	HighLight(73, 5, 2, 1, 0);
	HighLight(72, 6, 2, 1, 0);
	HighLight(73, 9, 2, 1, 0);
	HighLight(72, 8, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(66 + i, 7, 2, 1, 0);
	}
	HighLight(71, 8, 2, 1, 0);
	HighLight(72, 9, 2, 1, 0);
	HighLight(73, 10, 2, 1, 0);
	// R(blue)
	for (int i = 0; i <= 7; i++)
	{
		HighLight(65, 3 + i, 1, 1, 11);
	}
	HighLight(71, 4, 1, 1, 11);
	HighLight(72, 5, 1, 1, 11);
	HighLight(71, 6, 1, 1, 11);
	HighLight(70, 8, 1, 1, 11);
	HighLight(71, 9, 1, 1, 11);
	HighLight(72, 10, 1, 1, 11);
	// R(red)
	for (int i = 0; i <= 6; i++)
	{
		if (i == 3) {
			continue;
		}
		HighLight(68, 4 + i, 1, 1, 4);
	}
	HighLight(74, 3, 1, 1, 4);
	HighLight(75, 4, 1, 1, 4);
	HighLight(75, 5, 1, 1, 4);
	HighLight(74, 6, 1, 1, 4);
	HighLight(73, 7, 1, 1, 4);
	HighLight(74, 8, 1, 1, 4);
	HighLight(75, 9, 1, 1, 4);
	HighLight(75, 10, 1, 1, 4);

	//O (black)
	for (int i = 0; i <= 3; i++) {

		HighLight(80, 8 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {
		HighLight(82 + i, 3, 2, 1, 0);
	}
	for (int i = 0; i <= 3; i++) {

		HighLight(88, 8 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {
		HighLight(82 + i, 10, 2, 1, 0);
	}
	HighLight(81, 9, 2, 1, 0);
	HighLight(87, 9, 2, 1, 0);
	HighLight(81, 4, 2, 1, 0);
	HighLight(87, 4, 2, 1, 0);
	// O (blue)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(79, 5 + i, 1, 1, 11);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(87, 5 + i, 1, 1, 11);
	}
	HighLight(86, 4, 1, 1, 11);
	HighLight(86, 9, 1, 1, 11);
	HighLight(80, 4, 1, 1, 11);
	HighLight(80, 9, 1, 1, 11);
	HighLight(81, 3, 1, 1, 11);
	HighLight(81, 10, 1, 1, 11);
	// 0 (red)
	for (int i = 0; i <= 3; i++)
	{
		HighLight(82, 5 + i, 1, 1, 4);
	}
	for (int i = 0; i <= 3; i++)
	{
		HighLight(90, 5 + i, 1, 1, 4);
	}
	HighLight(83, 4, 1, 1, 4);
	HighLight(83, 9, 1, 1, 4);
	HighLight(89, 4, 1, 1, 4);
	HighLight(89, 9, 1, 1, 4);
	HighLight(88, 3, 1, 1, 4);
	HighLight(88, 10, 1, 1, 4);

	// logo game 
// BLACK
	//2 thanh d?c
}

void Remote_Graphic() {
	HighLight(88, 16, 2, 6, 0);
	HighLight(120, 16, 2, 6, 0);
	// trên
	HighLight(90, 15, 2, 1, 0);
	HighLight(92, 14, 8, 1, 0);
	HighLight(100, 15, 10, 1, 0);
	HighLight(118, 15, 2, 1, 0);
	HighLight(110, 14, 8, 1, 0);
	//d??i
	HighLight(90, 22, 2, 1, 0);
	HighLight(118, 22, 2, 1, 0);
	HighLight(92, 23, 6, 1, 0);
	HighLight(112, 23, 6, 1, 0);
	HighLight(98, 21, 2, 2, 0);
	HighLight(110, 21, 2, 2, 0);
	HighLight(100, 20, 10, 1, 0);
	//grey
	HighLight(90, 20, 2, 1, 8);
	HighLight(98, 20, 2, 1, 8);
	HighLight(110, 20, 2, 1, 8);
	HighLight(118, 20, 2, 1, 8);
	HighLight(90, 21, 8, 1, 8);
	HighLight(112, 21, 8, 1, 8);
	HighLight(92, 22, 6, 1, 8);
	HighLight(112, 22, 6, 1, 8);
	//chu thap 4 màu
	HighLight(114, 16, 2, 1, 2);
	HighLight(112, 17, 2, 1, 1);
	HighLight(116, 17, 2, 1, 4);
	HighLight(114, 18, 2, 1, 6);

	//chu thap BLACK
	HighLight(94, 16, 2, 1, 0);
	HighLight(92, 17, 2, 1, 0);
	HighLight(96, 17, 2, 1, 0);
	HighLight(94, 18, 2, 1, 0);
	HighLight(94, 17, 2, 1, 0);

}

void XO_Graphic() {
	// CH? X, O ngoài MENU
		//ch? X
	for (int i = 0; i <= 10; i++) {
		HighLight(14 + 2 * i, 14 + i, 2, 1, 11);
		HighLight(34 - 2 * i, 14 + i, 2, 1, 11);
	}
	// 4 ch? O
	HighLight(22, 23, 2, 1, 4);
	HighLight(24, 22, 2, 1, 4);
	HighLight(24, 24, 2, 1, 4);
	HighLight(26, 23, 2, 1, 4);

	HighLight(22, 15, 2, 1, 4);
	HighLight(24, 14, 2, 1, 4);
	HighLight(24, 16, 2, 1, 4);
	HighLight(26, 15, 2, 1, 4);

	HighLight(30, 19, 2, 1, 4);
	HighLight(32, 18, 2, 1, 4);
	HighLight(32, 20, 2, 1, 4);
	HighLight(34, 19, 2, 1, 4);

	HighLight(14, 19, 2, 1, 4);
	HighLight(16, 18, 2, 1, 4);
	HighLight(16, 20, 2, 1, 4);
	HighLight(18, 19, 2, 1, 4);
}


void xwin() {
	// ch? X

	// black
	for (int i = 0; i <= 8; i++) {
		HighLight(84 + 2 * i, 4 + i, 2, 1, 0);
		HighLight(100 - 2 * i, 4 + i, 2, 1, 0);
	}
	// blue
	for (int i = 0; i <= 8; i++) {
		HighLight(83 + 2 * i, 4 + i, 1, 1, 11);
		HighLight(99 - 2 * i, 4 + i, 1, 1, 11);
	}
	//red
	for (int i = 0; i <= 8; i++) {
		HighLight(86 + 2 * i, 4 + i, 1, 1, 4);
		HighLight(102 - 2 * i, 4 + i, 1, 1, 4);
	}
	//W
	for (int i = 0; i <= 6; i++) {
		HighLight(67 + i, 16 + i, 2, 1, 0);
		HighLight(66 + i, 16 + i, 1, 1, 11);
		HighLight(69 + i, 16 + i, 1, 1, 4);

		HighLight(89 - i, 16 + i, 2, 1, 0);
		HighLight(88 - i, 16 + i, 1, 1, 11);
		HighLight(91 - i, 16 + i, 1, 1, 4);

	}
	for (int i = 0; i <= 2; i++) {
		HighLight(79 + i, 19 + i, 2, 1, 0);
		HighLight(78 + i, 19 + i, 1, 1, 11);
		HighLight(81 + i, 19 + i, 1, 1, 4);

		HighLight(77 - i, 19 + i, 2, 1, 0);
		HighLight(76 - i, 19 + i, 1, 1, 11);
		if (i != 0) {
			HighLight(79 - i, 19 + i, 1, 1, 4);
		}
	}
	//I
	HighLight(95, 16, 2, 7, 0);
	HighLight(94, 16, 1, 7, 4);
	HighLight(97, 16, 1, 7, 11);
	//N

	HighLight(102, 16, 2, 7, 0);
	HighLight(101, 16, 1, 7, 11);
	HighLight(104, 16, 1, 7, 4);

	HighLight(112, 16, 2, 7, 0);
	HighLight(111, 16, 1, 7, 11);
	HighLight(114, 16, 1, 7, 4);

	for (int i = 0; i <= 6; i++) {
		HighLight(104 + i, 16 + i, 2, 1, 0);
		if (i <= 4) {
			HighLight(106 + i, 16 + i, 1, 1, 4);
		}
		if (i >= 2) {
			HighLight(103 + i, 16 + i, 1, 1, 11);
		}

	}

}
void owin() {
	// ch? O
	for (int i = 0; i <= 5; i++) {

		HighLight(88, 11 - i, 2, 1, 0);
		HighLight(87, 11 - i, 1, 1, 11);
		HighLight(90, 11 - i, 1, 1, 4);
	}
	for (int i = 0; i <= 6; i++) {
		HighLight(92 + i, 4, 2, 1, 0);
	}
	for (int i = 0; i <= 5; i++) {

		HighLight(102, 11 - i, 2, 1, 0);
		HighLight(101, 11 - i, 1, 1, 11);
		HighLight(104, 11 - i, 1, 1, 4);
	}
	for (int i = 0; i <= 6; i++) {
		HighLight(92 + i, 13, 2, 1, 0);
	}
	HighLight(89, 12, 4, 1, 0);
	HighLight(89, 5, 4, 1, 0);
	HighLight(99, 12, 4, 1, 0);
	HighLight(99, 5, 4, 1, 0);

	// mau xanh
	HighLight(91, 4, 1, 1, 11);
	HighLight(91, 13, 1, 1, 11);
	HighLight(88, 12, 1, 1, 11);
	HighLight(88, 5, 1, 1, 11);
	HighLight(98, 12, 1, 1, 11);
	HighLight(98, 5, 1, 1, 11);
	// mau ??
	HighLight(100, 4, 1, 1, 4);
	HighLight(100, 13, 1, 1, 4);
	HighLight(93, 12, 1, 1, 4);
	HighLight(93, 5, 1, 1, 4);
	HighLight(103, 12, 1, 1, 4);
	HighLight(103, 5, 1, 1, 4);

	//W
	for (int i = 0; i <= 6; i++) {
		HighLight(67 + i, 16 + i, 2, 1, 0);
		HighLight(66 + i, 16 + i, 1, 1, 11);
		HighLight(69 + i, 16 + i, 1, 1, 4);

		HighLight(89 - i, 16 + i, 2, 1, 0);
		HighLight(88 - i, 16 + i, 1, 1, 11);
		HighLight(91 - i, 16 + i, 1, 1, 4);

	}
	for (int i = 0; i <= 2; i++) {
		HighLight(79 + i, 19 + i, 2, 1, 0);
		HighLight(78 + i, 19 + i, 1, 1, 11);
		HighLight(81 + i, 19 + i, 1, 1, 4);

		HighLight(77 - i, 19 + i, 2, 1, 0);
		HighLight(76 - i, 19 + i, 1, 1, 11);
		if (i != 0) {
			HighLight(79 - i, 19 + i, 1, 1, 4);
		}
	}
	//I
	HighLight(95, 16, 2, 7, 0);
	HighLight(94, 16, 1, 7, 4);
	HighLight(97, 16, 1, 7, 11);
	//N

	HighLight(102, 16, 2, 7, 0);
	HighLight(101, 16, 1, 7, 11);
	HighLight(104, 16, 1, 7, 4);

	HighLight(112, 16, 2, 7, 0);
	HighLight(111, 16, 1, 7, 11);
	HighLight(114, 16, 1, 7, 4);

	for (int i = 0; i <= 6; i++) {
		HighLight(104 + i, 16 + i, 2, 1, 0);
		if (i <= 4) {
			HighLight(106 + i, 16 + i, 1, 1, 4);
		}
		if (i >= 2) {
			HighLight(103 + i, 16 + i, 1, 1, 11);
		}

	}
}

void listgame_Graphic() {
	// black
	HighLight(12, 12, 2, 14, 0);
	HighLight(14, 11, 2, 1, 0);
	HighLight(16, 10, 20, 1, 0);
	HighLight(36, 11, 2, 1, 0);
	HighLight(38, 12, 2, 14, 0);
	HighLight(36, 26, 2, 1, 0);
	HighLight(14, 26, 2, 1, 0);
	HighLight(16, 27, 20, 1, 0);
	//grey
	HighLight(14, 12, 2, 14, 8);
	HighLight(16, 11, 20, 1, 8);
	HighLight(36, 12, 2, 14, 8);
	HighLight(16, 26, 20, 1, 8);

	//list
	HighLight(20, 17, 12, 1, 2);
	HighLight(20, 19, 12, 1, 1);
	HighLight(20, 21, 12, 1, 4);
	HighLight(20, 23, 12, 1, 6);

	//chu thap 4 màu
	HighLight(30, 13, 2, 1, 0);
	HighLight(28, 14, 2, 1, 0);
	HighLight(32, 14, 2, 1, 0);
	HighLight(30, 15, 2, 1, 0);

	//chu thap BLACK
	HighLight(18, 13, 2, 1, 0);
	HighLight(18, 15, 2, 1, 0);
	HighLight(22, 13, 2, 1, 0);
	HighLight(20, 14, 2, 1, 0);
	HighLight(22, 15, 2, 1, 0);

}

void draw() {
	//D
	HighLight(67, 6, 2, 7, 0);
	HighLight(67, 5, 8, 1, 0);
	HighLight(67, 12, 8, 1, 0);
	HighLight(74, 6, 2, 1, 0);
	HighLight(75, 7, 2, 4, 0);
	HighLight(74, 11, 2, 1, 0);

	HighLight(66, 5, 1, 8, 11);
	HighLight(74, 7, 1, 4, 11);
	HighLight(73, 6, 1, 1, 11);
	HighLight(73, 11, 1, 1, 11);

	HighLight(69, 6, 1, 6, 4);
	HighLight(77, 7, 1, 4, 4);
	HighLight(76, 6, 1, 1, 4);
	HighLight(75, 5, 1, 1, 4);
	HighLight(76, 11, 1, 1, 4);
	HighLight(75, 12, 1, 1, 4);



	// R (black)
	for (int i = 0; i <= 7; i++) {

		HighLight(81, 12 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 6; i++) {

		HighLight(81 + i, 5, 2, 1, 0);
	}
	HighLight(86, 6, 2, 1, 0);
	HighLight(88, 6, 2, 1, 0);
	HighLight(88, 7, 2, 1, 0);
	HighLight(87, 8, 2, 1, 0);
	HighLight(88, 11, 2, 1, 0);
	HighLight(87, 10, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(81 + i, 9, 2, 1, 0);
	}
	HighLight(86, 10, 2, 1, 0);
	HighLight(87, 11, 2, 1, 0);
	HighLight(88, 12, 2, 1, 0);
	// R(blue)
	for (int i = 0; i <= 7; i++)
	{
		HighLight(80, 5 + i, 1, 1, 11);
	}
	HighLight(86, 6, 1, 1, 11);
	HighLight(87, 7, 1, 1, 11);
	HighLight(86, 8, 1, 1, 11);
	HighLight(85, 10, 1, 1, 11);
	HighLight(86, 11, 1, 1, 11);
	HighLight(87, 12, 1, 1, 11);
	// R(red)
	for (int i = 0; i <= 6; i++)
	{
		if (i == 3) {
			continue;
		}
		HighLight(83, 6 + i, 1, 1, 4);
	}
	HighLight(89, 5, 1, 1, 4);
	HighLight(90, 6, 1, 1, 4);
	HighLight(90, 7, 1, 1, 4);
	HighLight(89, 8, 1, 1, 4);
	HighLight(88, 9, 1, 1, 4);
	HighLight(89, 10, 1, 1, 4);
	HighLight(90, 11, 1, 1, 4);
	HighLight(90, 12, 1, 1, 4);

	//W
	HighLight(108, 5, 2, 4, 0);
	HighLight(107, 5, 1, 4, 11);
	HighLight(110, 5, 1, 4, 4);

	HighLight(124, 5, 2, 4, 0);
	HighLight(123, 5, 1, 4, 11);
	HighLight(126, 5, 1, 4, 4);

	for (int i = 0; i <= 3; i++) {
		HighLight(108 + i, 9 + i, 2, 1, 0);
		HighLight(107 + i, 9 + i, 1, 1, 11);
		HighLight(110 + i, 9 + i, 1, 1, 4);

		HighLight(124 - i, 9 + i, 2, 1, 0);
		HighLight(123 - i, 9 + i, 1, 1, 11);
		HighLight(126 - i, 9 + i, 1, 1, 4);

	}
	for (int i = 0; i <= 2; i++) {
		HighLight(117 + i, 9 + i, 2, 1, 0);
		HighLight(116 + i, 9 + i, 1, 1, 11);
		HighLight(119 + i, 9 + i, 1, 1, 4);

		HighLight(115 - i, 9 + i, 2, 1, 0);
		HighLight(114 - i, 9 + i, 1, 1, 11);
		if (i != 0) {
			HighLight(117 - i, 9 + i, 1, 1, 4);
		}
	}
	//chu A
	for (int i = 0; i <= 5; i++) {

		HighLight(94, 12 - i, 2, 1, 0);
	}
	HighLight(95, 6, 2, 1, 0);
	for (int i = 0; i <= 4; i++) {

		HighLight(96 + i, 5, 2, 1, 0);
	}
	HighLight(101, 6, 2, 1, 0);
	for (int i = 0; i <= 5; i++) {

		HighLight(102, 12 - i, 2, 1, 0);
	}
	for (int i = 0; i <= 4; i++) {

		HighLight(96 + i, 9, 2, 1, 0);
	}
	// chu A (blue)
	for (int i = 0; i <= 5; i++)
	{
		HighLight(93, 7 + i, 1, 1, 11);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(101, 7 + i, 1, 1, 11);
	}
	HighLight(100, 6, 1, 1, 11);
	HighLight(94, 6, 1, 1, 11);
	HighLight(95, 5, 1, 1, 11);
	//chu A( red) 
	for (int i = 0; i <= 5; i++)
	{
		HighLight(104, 7 + i, 1, 1, 4);
	}
	for (int i = 0; i <= 5; i++)
	{
		if (i == 2) {
			continue;
		}
		HighLight(96, 7 + i, 1, 1, 4);
	}
	HighLight(103, 6, 1, 1, 4);
	HighLight(97, 6, 1, 1, 4);
	HighLight(102, 5, 1, 1, 4);

}





void box_menu() {
	GotoXY(54, 16);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 73) putchar(187);
		else putchar(205);
	}
	for (int i = 17; i <= 17; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(73, i); putchar(186);
	}
	GotoXY(54, 18);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 73) putchar(188);
		else putchar(205);
	}
	// hop help
	GotoXY(54, 19);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 73) putchar(187);
		else putchar(205);
	}
	for (int i = 20; i <= 20; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(73, i); putchar(186);
	}
	GotoXY(54, 21);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 73) putchar(188);
		else putchar(205);
	}
	//
	GotoXY(54, 22);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 73) putchar(187);
		else putchar(205);
	}
	for (int i = 23; i <= 23; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(73, i); putchar(186);
	}
	GotoXY(54, 24);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 73) putchar(188);
		else putchar(205);
	}
	//

	GotoXY(54, 28);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 73) putchar(187);
		else putchar(205);
	}
	for (int i = 29; i <= 29; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(73, i); putchar(186);
	}
	GotoXY(54, 30);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 73) putchar(188);
		else putchar(205);
	}
	//

	GotoXY(54, 25);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 73) putchar(187);
		else putchar(205);
	}
	for (int i = 26; i <= 26; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(73, i); putchar(186);
	}
	GotoXY(54, 27);
	for (int i = 54; i <= 73; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 73) putchar(188);
		else putchar(205);
	}
}

void box_about() {
	GotoXY(3,3);
	for (int i = 3; i <= 55; i++)
	{
		if (i == 3) putchar(201);
		else if (i == 55) putchar(187);
		else putchar(205);
	}
	for (int i = 4; i <= 15; i++)
	{
		GotoXY(3, i); putchar(186);
		GotoXY(55, i); putchar(186);
	}
	GotoXY(3, 16);
	for (int i = 3; i <= 55; i++)
	{
		if (i ==3) putchar(200);
		else if (i == 55) putchar(188);
		else putchar(205);
	}
}

void box_newgame() {
	GotoXY(54, 16);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 77) putchar(187);
		else putchar(205);
	}
	for (int i = 17; i <= 17; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(77, i); putchar(186);
	}
	GotoXY(54, 18);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 77) putchar(188);
		else putchar(205);
	}
	// 
	GotoXY(54, 24);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 77) putchar(187);
		else putchar(205);
	}
	for (int i = 25; i <= 25; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(77, i); putchar(186);
	}
	GotoXY(54, 26);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 77) putchar(188);
		else putchar(205);
	}
	//
	GotoXY(54, 20);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(201);
		else if (i == 77) putchar(187);
		else putchar(205);
	}
	for (int i = 21; i <= 21; i++)
	{
		GotoXY(54, i); putchar(186);
		GotoXY(77, i); putchar(186);
	}
	GotoXY(54, 22);
	for (int i = 54; i <= 77; i++)
	{
		if (i == 54) putchar(200);
		else if (i == 77) putchar(188);
		else putchar(205);
	}
}

void box_newgamepvp() {
	GotoXY(16, 16);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(201);
		else if (i == 45) putchar(187);
		else putchar(205);
	}
	for (int i = 17; i <= 17; i++)
	{
		GotoXY(16, i); putchar(186);
		GotoXY(45, i); putchar(186);
	}
	GotoXY(16, 18);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(200);
		else if (i == 45) putchar(188);
		else putchar(205);
	}
	// 
	GotoXY(16, 20);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(201);
		else if (i == 45) putchar(187);
		else putchar(205);
	}
	for (int i = 21; i <= 21; i++)
	{
		GotoXY(16, i); putchar(186);
		GotoXY(45, i); putchar(186);
	}
	GotoXY(16, 22);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(200);
		else if (i == 45) putchar(188);
		else putchar(205);
	}
}

void box_newgamepvc() {
	GotoXY(16, 16);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(201);
		else if (i == 45) putchar(187);
		else putchar(205);
	}
	for (int i = 17; i <= 17; i++)
	{
		GotoXY(16, i); putchar(186);
		GotoXY(45, i); putchar(186);
	}
	GotoXY(16, 18);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(200);
		else if (i == 45) putchar(188);
		else putchar(205);
	}
	// 
	GotoXY(16, 20);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(201);
		else if (i == 45) putchar(187);
		else putchar(205);
	}
	for (int i = 21; i <= 21; i++)
	{
		GotoXY(16, i); putchar(186);
		GotoXY(45, i); putchar(186);
	}
	GotoXY(16, 22);
	for (int i = 16; i <= 45; i++)
	{
		if (i == 16) putchar(200);
		else if (i == 45) putchar(188);
		else putchar(205);
	}
}

void sound_op1() {
	GotoXY(15, 28);
	for (int i = 15; i <= 28; i++)
	{
		if (i == 15) putchar(201);
		else if (i == 28) putchar(187);
		else putchar(205);
	}
	for (int i = 29; i <= 29; i++)
	{
		GotoXY(15, i); putchar(186);
		GotoXY(28, i); putchar(186);
	}
	GotoXY(15, 30);
	for (int i = 15; i <= 28; i++)
	{
		if (i == 15) putchar(200);
		else if (i == 28) putchar(188);
		else putchar(205);
	}
}


void sound_op2() {
	GotoXY(105, 28);
	for (int i = 105; i <= 119; i++)
	{
		if (i == 105) putchar(201);
		else if (i == 119) putchar(187);
		else putchar(205);
	}
	for (int i = 29; i <= 29; i++)
	{
		GotoXY(105, i); putchar(186);
		GotoXY(119, i); putchar(186);
	}
	GotoXY(105, 30);
	for (int i = 105; i <= 119; i++)
	{
		if (i == 105) putchar(200);
		else if (i == 119) putchar(188);
		else putchar(205);
	}
}

void sound_op3() {
	GotoXY(18, 3);
	for (int i = 18; i <= 32; i++)
	{
		if (i == 18) putchar(201);
		else if (i == 32) putchar(187);
		else putchar(205);
	}
	for (int i = 4; i <= 4; i++)
	{
		GotoXY(18, i); putchar(186);
		GotoXY(32, i); putchar(186);
	}
	GotoXY(18, 5);
	for (int i = 18; i <= 32; i++)
	{
		if (i == 18) putchar(200);
		else if (i == 32) putchar(188);
		else putchar(205);
	}
}


void box_load() {
	GotoXY(48, 4);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(201);
		else if (i == 72) putchar(187);
		else putchar(205);
	}
	for (int i = 5; i <= 19; i++)
	{
		GotoXY(48, i); putchar(186);
		GotoXY(72, i); putchar(186);
	}
	GotoXY(48, 20);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(200);
		else if (i == 72) putchar(188);
		else putchar(205);
	}
}


void box_option() {
	//
	GotoXY(48, 22);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(201);
		else if (i == 72) putchar(187);
		else putchar(205);
	}
	for (int i = 23; i <= 23; i++)
	{
		GotoXY(48, i); putchar(186);
		GotoXY(72, i); putchar(186);
	}
	GotoXY(48, 24);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(200);
		else if (i == 72) putchar(188);
		else putchar(205);
	}
	//

	GotoXY(48, 28);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(201);
		else if (i == 72) putchar(187);
		else putchar(205);
	}
	for (int i = 29; i <= 29; i++)
	{
		GotoXY(48, i); putchar(186);
		GotoXY(72, i); putchar(186);
	}
	GotoXY(48, 30);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(200);
		else if (i == 72) putchar(188);
		else putchar(205);
	}
	//

	GotoXY(48, 25);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(201);
		else if (i == 72) putchar(187);
		else putchar(205);
	}
	for (int i = 26; i <= 26; i++)
	{
		GotoXY(48, i); putchar(186);
		GotoXY(72, i); putchar(186);
	}
	GotoXY(48, 27);
	for (int i = 48; i <= 72; i++)
	{
		if (i == 48) putchar(200);
		else if (i == 72) putchar(188);
		else putchar(205);
	}
}