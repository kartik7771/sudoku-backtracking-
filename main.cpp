#include<iostream>
using namespace std;

bool check(int board[][9], int x, int y, int num)
{
    for(int i=0; i<9;i++)

    {
        if(board[i][y]==num)
            return false;
    }

    for(int j=0;j<9;j++)
    {

        if(board[x][j]==num)
            return false;
    }

    int rowf=x/3;
    int colf=y/3;

    for(int i=(3*rowf); i<(3*(rowf+1)); i++)
    {
        for(int j=(3*colf); j<(3*(colf+1)); j++)
        {

            if(board[i][j]==num)
                return false;
        }

    }

    return true;
}

bool findpos(int board[][9], int &row, int &col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }

        }
    }

    return false;

}

bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */

    int row,col;
    if(!findpos(board,row,col))
        return true;

    else
    {
        for(int k=1;k<=9;k++)
        {

            if(check(board,row,col,k))
            {
                board[row][col]=k;

                if(sudokuSolver(board))
                {
                    return true;
                }

                //else{

                board[row][col]=0;
                //return false;
                //}
            }

        }

    }

    return false;
}


int main(){

  int n = 9;
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }
  }
  if(sudokuSolver(board)){
	cout << "true";
  }else{
	cout << "false";
  }
}


