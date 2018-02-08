#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include <argp.h>

#include"minesweeper.h"


//Mainfunction
int main(int argc, char **argv)
{

  Minesweeper MSW;

  int Rows, Columns, Mines;

  //CommandLineOptions(argc, argv);

  PrintHeader();

  //printf("Choose a Number of Columns: ");
  //scanf("%d", &Columns);
  //printf("Choose a Number of Rows: ");
  //scanf("%d", &Rows);
  //printf("Choose a Number of Mines: ");
  scanf("%d", &Mines);
  printf("\n");

  MSW.nRows = Rows;
  MSW.nCols = Columns;
  MSW.nMines = Mines;

  //PrintGrid(&MSW);

  PutMinesOnBoard(&MSW);





  DrawRandomNumberBetweenZeroAnd(10);
  //printf("\nargc: %d\n", argc);


  return 0 ;

}
