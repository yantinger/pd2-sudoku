#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;
class Sudoku {
	public:
			void giveQuestion();
			void readIn();
			void solve();
			void changeNum(int a, int b) ;
			void changeRow(int a, int b) ;
			void changeCol(int a,int b) ;
			void rotate(int n) ;
			void flip(int n) ;
			void transform();
			void arrIntemp();
			void change();
			void coutarr();
			int check(int sudoku[][9], int row, int col, int num);
			int fill(int sudoku[][9], int row, int col);
			int fill2(int sudoku[][9], int row, int col);


	private:
			int question[9][9];
			int temp[9][9];
			int arr[9][9];
			int arr1[9][9];

};
