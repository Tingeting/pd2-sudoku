/*sudoku.h*/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>

using namespace std;

class Sudoku {

	public :

		void giveQuestion();
		void readIn();
		void solve();
		
		void changeNum(int, int);
		void changeRow(int, int);
		void changeCol(int, int);
		
		void rotate(int);
		void flip(int);
		void transform();
		void printS();
	
	private :

		int cube[81];
		int map[9][9];
		int ans;
		void Solver();
		int test(int,int,int);
		int mapans[9][9];
		bool first();
};
