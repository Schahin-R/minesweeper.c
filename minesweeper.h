typedef struct Minesweeper{
unsigned short int nRows;
unsigned short int nCols;
unsigned short int nMines;
unsigned short int ** mask;
unsigned short int ** board;
} Minesweeper;


// Printing tools
void PrintHeader(/* ... */){
  printf("Welcome to Minesweeper!\n");
  printf("ASCII-Code: %d = %c\n\n", 64, 64);
};

void PrintLine( /* ... */ ){
  printf("=========================================\n");
};
void SetStringToBePrint( /* ... */ );

void PrintGrid(/* ... */){

  Minesweeper Hallo;
  Hallo.nCols = 5;
  Hallo.nRows = 10;

  int i, j;

  // Schleife fuer Zeilen, Y-Achse
  for(i=0; i<Hallo.nCols; i++) {
     // Schleife fuer Spalten, X-Achse
      for(j=0; j<Hallo.nRows; j++) {
        printf("| %c ", 64);
         }
          printf("|\n");
          PrintLine();
        }
};

void YouLost(void);
void YouWon(void);

// Setup Minesweeper
Minesweeper ResetMinesweeper(void);
void AllocateMemory( /* ... */ );
void FreeMemory( /* ... */ );
unsigned short int DrawRandomNumberBetweenZeroAnd(){
  int number;
		/* initialize random seed: */
		srand(time(NULL));
		/* Generate a random number: 0 - 19  (%20 + 1) */
		number = rand() % 20 + 1;
    printf("%d\n", number);
};
bool IsSiteInsideTheGrid( /* ... */ );
void PutMinesOnBoard( /* ... */ );
void FillBoardWhithMineAdjacentNumbers( /* ... */ );
void InitBoard( /* ... */ );
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
void PrintHelper(void);
void ParseCommandLineOptions( /* ... */ );
void CheckParsedCommandLineOptions( /* ... */ );
