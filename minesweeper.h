const char *argp_program_version =
"Minesweeper_0.01";
const char *argp_program_bug_address =
"<admin@minesweeper.c>";


typedef struct Minesweeper{
unsigned short int nRows;
unsigned short int nCols;
unsigned short int nMines;
unsigned short int ** mask;
unsigned short int ** board;
} Minesweeper;


// Printing tools
void PrintHeader(/* ... */){
  printf("Welcome to Minesweeper!\n\n");
  //printf("ASCII-Code: %d = %c\n\n", 64, 64);
};

void PrintLine(Minesweeper *msw){
  int x;
  printf("   =");
  for(x=0; x<msw->nCols; x++){
    printf("====");
  }
  printf("\n");
};
void SetStringToBePrint( /* ... */ );

void PrintGrid(Minesweeper *msw){

  int i, j, x;

  //Obere Koordinaten
  printf("    ");
  for(x = 0; x<msw->nCols; x++){
    if (x<10) {
      printf(" %d  ", x);
    }
    else {
      printf("%d  ", x);
    }

  };
  printf("\n");
  PrintLine(msw);

  // Schleife fuer Zeilen, Y-Achse
  for(i=0; i<msw->nRows; i++) {
    if (i<10) {

      printf("%d  ", i); //Linke Koordinaten

    }
    else {

      printf("%d ", i); //Linke Koordinaten, falls i>=10

    }
     // Schleife fuer Spalten, X-Achse
      for(j=0; j<msw->nCols; j++) {
        printf("| %c ", 64);   //@ im Grid
         }
          printf("|  %d\n", i); //Rechte Koordinaten
          PrintLine(msw);

              //PrintLine();
        }

    //Untere Koordinaten
    printf("    ");
    for(x = 0; x<msw->nCols; x++){
      if (x<10) {
        printf(" %d  ", x);
      }
      else {
        printf("%d  ", x);
      }

    };
    printf("\n");
};

void YouLost(void);
void YouWon(void);

// Setup Minesweeper
Minesweeper ResetMinesweeper(void);
void AllocateMemory(/*Minesweeper *msw*/){

};
void FreeMemory(Minesweeper *msw ){
  free(msw);
};
unsigned short int DrawRandomNumberBetweenZeroAnd(int X){
  int number;

		/* initialize random seed: */
		srand(time(NULL));
		/* Generate a random number: 0 - x  (%x + 1) */
		number = rand() % x;
    //printf("%d\n", number);
};
bool IsSiteInsideTheGrid( /* ... */ );
void PutMinesOnBoard(Minesweeper *msw){
    int x, y;

for(int i = 0; i <msw->nMines; i++){
     // the square is N x N, so you want two numbers from 0 to N-1
     x = DrawRandomNumberBetweenZeroAnd(1);
     y = DrawRandomNumberBetweenZeroAnd(1);

    printf("x: %d, y: %d\n", x, y);
 }
};
void FillBoardWhithMineAdjacentNumbers( /* ... */ );
void InitBoard(Minesweeper *msw){



  int Grid[msw->nCols][msw->nRows] = {};
  //board[msw->nRows][msw->nCols]
  int x, y;
  int A[20][20]= {0};
  for(x=0; x<20; x++){
    for(y=0; y<20; y++){
      printf("%d", A[x][y]);
    }
    printf("\n");
  };

};
void InitMask( /* ... */ );
void InitMinesweeper( /* ... */ );

// Revealing tools
void RevealTilesFromEmptyOneOpeningFullSpace( /* ... */ );
bool RevealAdjacentTilesOfRevealedTile( /* ... */ );
bool RevealTile( /* ... */ );
void RevealMinesInMask( /* ... */ );

// Additional player actions
bool ArmTile( /* ... */ );
bool DisarmTile( /* ... */ );
void PrintInGameHelp( /* ... */ );
void QuitGame( /* ... */ );
bool MakeAction( /* ... */ );

// Handling user input
void GetCoordinatesAndAction( /* ... */ );
bool CheckActionAndCoordinates( /* ... */ );
unsigned short int CountTypeOfTileInMask( /* ... */ );

// Dealing with command line options
void CommandLineOptions(int argc, char **argv){

  /* Program documentation. */
  static char doc[] =
  "Minesweeper #1 -- a pretty minimal Minesweeper";

  /* A description of the arguments we accept. */
  static char args_doc[] = "ARG1 ARG2";

  /* Our argument parser.  The options, parser, and
   args_doc fields are zero because we have neither options or
   arguments; doc and argp_program_bug_address will be
   used in the output for ‘--help’, and the ‘--version’
   option will print out argp_program_version. */
  static struct argp argp = { 0, 0, 0, doc };

  argp_parse (&argp, argc, argv, 0, 0, 0);

  exit (0);

}
