#include"a.h"
void Sudoku::giveQuestion()
{

	ifstream fin("Q1.txt");
	for(int i=0;i<=8;i++)
	for(int j=0;j<=8;j++)
		fin>>question[i][j];
	fin.close();
	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
			 cout<<question[i][j];
			 cout<<" ";
		}

	cout<<endl;

	}	
}


void Sudoku::coutarr()
{
for(int i=0;i<=8;i++)
{
for(int j=0;j<=8;j++)
{
cout<<arr[i][j];
cout<<" ";
}

cout<<endl;
}
cout<<endl;

}

int Sudoku::check(int sudoku[][9], int row, int col, int num)
{
	int i, j;
	for(i=0; i<9; ++i)
		if( (sudoku[row][i] == num) || ( sudoku[i][col] == num )  )//checking in row and col
			return 0;

	int rowStart = (row/3) * 3;//checking in the grid
	int colStart = (col/3) * 3;
	for(i=rowStart; i<(rowStart+3); ++i)
	{
		for(j=colStart; j<(colStart+3); ++j)
		{
			if( sudoku[i][j] == num )
				return 0;
		}
	}
	return 1;
}

int Sudoku::fill(int sudoku[][9], int row, int col)
{
	int i;
	if( row<9 && col<9 )
	{
		if( sudoku[row][col] != 0 )//pre filled
		{
			if( (col+1)<9 )
				return fill(sudoku, row, col+1);
			else if( (row+1)<9 )
				return fill(sudoku, row+1, 0);
			else
				return 1;
		}
		else
		{
			for(i=0; i<9; ++i)
			{
				if( check(sudoku, row, col, i+1) )
				{
					sudoku[row][col] = i+1;

					if( (col+1)<9 )
					{
						if( fill(sudoku, row, col +1) )
							return 1;
						else
							sudoku[row][col] = 0;
					}
					else if( (row+1)<9 )
					{
						if( fill(sudoku, row+1, 0) )
							return 1;
						else
							sudoku[row][col] = 0;
					}
					else
						return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int Sudoku::fill2(int sudoku[][9], int row, int col)
{
	int i;
	if( row<9 && col<9 )
	{
		if( sudoku[row][col] != 0 )//pre filled
		{
			if( (col+1)<9 )
				return fill2(sudoku, row, col+1);
			else if( (row+1)<9 )
				return fill2(sudoku, row+1, 0);
			else
				return 1;
		}
		else
		{
			for(i=8; i>=0; i--)
			{
				if(check(sudoku, row, col, i+1) )
				{
					sudoku[row][col] = i+1;

					if( (col+1)<9 )
					{
						if( fill2(sudoku, row, col +1) )
							return 1;
						else
							sudoku[row][col] = 0;
					}
					else if( (row+1)<9 )
					{
						if( fill2(sudoku, row+1, 0) )
							return 1;
						else
							sudoku[row][col] = 0;
					}
					else
						return 1;
				}
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}




void Sudoku::solve()
{
	int i,j;


	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			arr1[i][j]=arr[i][j];
		}
	}

	if( fill(arr, 0, 0) )
	{

		if( fill2(arr1, 0, 0) )
		{

			for(i=0;i<=8;i++)
			{
				for(j=0;j<=8;j++)
				{
				
				if(arr[i][j]!=arr1[i][j])//相同 表一解
				{
					cout<<"2"<<endl;
					exit(0);
				}
				}
			}
			
					cout<<"1"<<endl;
					for(i=0;i<=8;i++)
					{
						for(j=0;j<=8;j++)
						{
							cout<<arr[i][j];
							cout<<" ";
						
						}
						cout<<endl;
					
					}

				
		}
	}
	

	else cout<<"0"<<endl;

}




void Sudoku::readIn()
{
	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
		cin>>arr[i][j];	
	
		}
	}

}






void Sudoku::arrIntemp()//將arr寫入temp
{
for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}
}


void Sudoku::changeNum(int a, int b) 
{
for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}
for (int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		if(arr[i][j]==a)arr[i][j]=b;
		else if(arr[i][j]==b)arr[i][j]=a;

	}
}
for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}

}

void Sudoku::changeRow(int a, int b) 
{

for(;;)
{


	if(a==0)
	{

		int dis[9][9];
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=8;j++)
			{
				dis[i][j]=arr[i][j];
			}
		}

		if(b==0) break;

		else if(b==1)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i][j]=arr[i+3][j];
					arr[i+3][j]=dis[i][j];

				}
			}
			break;
		}

		else if(b==2)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i][j]=arr[i+6][j];
					arr[i+6][j]=dis[i][j];

				}
			}
			break;
		}
	}


	if(a==1)
	{

		int dis[9][9];
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=8;j++)
			{
				dis[i][j]=arr[i+3][j];
			}
		}


		if(b==0)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i+3][j]=arr[i][j];
					arr[i][j]=dis[i][j];

				}
			}
			break;
		}

		else if(b==1) break;

		else if(b==2)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i+3][j]=arr[i+6][j];
					arr[i+6][j]=dis[i][j];

				}
			}
			break;
		}
	}

	if(a==2)
	{

		int dis[9][9];
		for(int i=0;i<=2;i++)
		{
			for(int j=0;j<=8;j++)
			{
				dis[i][j]=arr[i+6][j];
			}
		}


		if(b==0)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i+6][j]=arr[i][j];
					arr[i][j]=dis[i][j];
				}
			}
			break;
		}

		else if(b==1)
		{
			for(int i=0;i<=2;i++)
			{
				for(int j=0;j<=8;j++)
				{
					arr[i+6][j]=arr[i+3][j];
					arr[i+3][j]=dis[i][j];

				}
			}
			break;
		}

		else if(b==2)break;
	}

}

for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}

}

void Sudoku::changeCol(int a,int b) 
{

for(;;)
{


	if(a==0)
	{

		int dis[9][9];
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=2;j++)
			{
				dis[i][j]=arr[i][j];
			}
		}

		if(b==0) break;

		else if(b==1)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j]=arr[i][j+3];
					arr[i][j+3]=dis[i][j];

				}
			}
			break;
		}

		else if(b==2)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j]=arr[i][j+6];
					arr[i][j+6]=dis[i][j];

				}
			}
			break;
		}
	}


	if(a==1)
	{

		int dis[9][9];
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=2;j++)
			{
				dis[i][j]=arr[i][j+3];
			}
		}


		if(b==0)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j+3]=arr[i][j];
					arr[i][j]=dis[i][j];

				}
			}
			break;
		}

		else if(b==1) break;

		else if(b==2)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j+3]=arr[i][j+6];
					arr[i][j+6]=dis[i][j];

				}
			}
			break;
		}
	}

	if(a==2)
	{

		int dis[9][9];
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=2;j++)
			{
				dis[i][j]=arr[i][j+6];
			}
		}


		if(b==0)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j+6]=arr[i][j];
					arr[i][j]=dis[i][j];
				}
			}
			break;
		}

		else if(b==1)
		{
			for(int i=0;i<=8;i++)
			{
				for(int j=0;j<=2;j++)
				{
					arr[i][j+6]=arr[i][j+3];
					arr[i][j+3]=dis[i][j];

				}
			}
			break;
		}

		else if(b==2)break;
	}



}

for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}


}
void Sudoku::rotate(int n) 
{

for(;;)
{

	if(n==0)break;


	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
			arr[i][j]=temp[j+8-2*j][i];

		}
	}

for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}

	if(n==1)break;


	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
			arr[i][j]=temp[j+8-2*j][i];
		}
	}
for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}


	if(n==2)break;


	for(int i=0;i<=8;i++)
	{
		for(int j=0;j<=8;j++)
		{
			arr[i][j]=temp[j+8-2*j][i];

		}
	}

for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}


	if(n==3)break;
}
}



void Sudoku::flip(int n) 
{


	if(n==0)
	{
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=8;j++)
			{
				arr[i][j]=temp[8-i][j];

			}
		}

	}



	else if(n==1)
	{
		for(int i=0;i<=8;i++)
		{
			for(int j=0;j<=8;j++)
			{
				arr[i][j]=temp[i][8-j];

			}
		}

	}

for(int i=0;i<=8;i++)
{
	for(int j=0;j<=8;j++)
	{
		temp[i][j]=arr[i][j];
	}
}


}



void Sudoku::change()
{
	srand(time(NULL));

	changeNum(rand()%9+1, rand()%9+1) ;

	changeRow(rand()%3, rand()%3) ;

	changeCol(rand()%3, rand()%3) ;

	rotate(rand()%4) ;

	flip(rand()%2) ;
}


void Sudoku::transform()
{
	readIn();
	change();
}

