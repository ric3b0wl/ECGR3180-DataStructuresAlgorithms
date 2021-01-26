#include "board.h"

void solveSingle(Board& b);
bool solveHelperSingleSoln(Board& b, int col);

int main()
{
	Board chess;
	
    solveSingle(chess);
	
	return 0;
}

void solveSingle(Board& b) 
{
  solveHelperSingleSoln(b,0);
}

bool solveHelperSingleSoln(Board& b, int col) 
{
    
}
