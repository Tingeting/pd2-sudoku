#include<iostream>
#include<cstdio>
#include<ctime>
#include"Sudoku.h"
using namespace std;

int main(){

	Sudoku s;

	s.readIn();
	s.solve();

//	s.readIn();

/*	s.rotate(93);
	s.printS();
	s.rotate(94);
	s.printS();
	s.rotate(95);
	s.printS();
	s.rotate(96);
	s.printS();*/
//	s.readIn();
//	s.flip(0);
//	s.printS();
}
