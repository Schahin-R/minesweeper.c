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


  //CommandLineOptions(argc, argv);


  printf("Choose a Number of Columns: ");
  scanf("%hu", &MSW.nRows);
  printf("Choose a Number of Rows: ");
  scanf("%hu", &MSW.nCols);
  printf("Choose a Number of Mines: ");
  scanf("%hu", &MSW.nMines);
  printf("\n");



  InitMinesweeper(&MSW);

  bool outcome;
  
  do {
    outcome = RevealTile(&MSW);
  } while(outcome == true);





  //printf("\nargc: %d\n", argc);


  return 0 ;

}
