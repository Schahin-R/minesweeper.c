const char *argp_program_version = "Minesweeper_0.01";
const char *argp_program_bug_address ="<admin@minesweeper.c>";


typedef struct Minesweeper{
unsigned short int nRows;
unsigned short int nCols;
unsigned short int nMines;
unsigned short int **mask;
unsigned short int **board;
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

void PrintGrid(Minesweeper *msw, unsigned short int *A[]){

  {

    int i, j, x;

    //msw->mask[i][j] = 0;

    //Obere Koordinaten(Upper Coordinates)
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

        printf("%d  ", i); //Linke Koordinaten(Left Coordinates)

      }
      else {

        printf("%d ", i); //Linke Koordinaten, falls i>=10

      }
       // Schleife fuer Spalten, X-Achse
        for(j=0; j<msw->nCols; j++) {
          printf("| %c ", A[i][j]);   //@ im Grid
           }
            printf("|  %d\n", i); //Rechte Koordinaten(Right Coordinates)
            PrintLine(msw);

                //PrintLine();
          }

      //Untere Koordinaten(Lower Coordinates)
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


};


void SetStringToBePrint( /* ... */ );
void YouLost(void){
  printf("\nCiao! You lost the Game!\n");
};
void YouWon(void){
  printf("\nNice! You won the Game!\n");
};

// Setup Minesweeper
Minesweeper ResetMinesweeper(void);
void AllocateMemory(Minesweeper *msw){

    int t;

// Zunaechst ein N-elementiges eindimsionales Array von usigned short int *-Werten ...

    if((msw->board = (unsigned short int**)malloc((msw->nRows)*sizeof(unsigned short int *))) == NULL)
    {
      printf("Fehler: malloc fehlgeschlagen!\n");
      exit(0);
    }
// ... dann fuer jeden dieser Zeiger ein weiteres N-elementiges
// eindimsionales Array von double-Werten.
    for(t = 0; t < msw->nCols; t++)
    {
  // !!!!! hier sind die Klammern um (msw->board) == *board essentiell !!!!!
      if(((msw->board)[t] = (unsigned short int *)malloc((msw->nCols)*sizeof(unsigned short int*))) == NULL)
        {
          printf("Fehler: malloc fehlgeschlagen!\n");
          exit(0);
        }
    }


    if((msw->mask = (unsigned short int**)malloc((msw->nRows)*sizeof(unsigned short int *))) == NULL)
    {
      printf("Fehler: malloc fehlgeschlagen!\n");
      exit(0);
    }

    for(t = 0; t < msw->nCols; t++)
    {
      if(((msw->mask)[t] = (unsigned short int *)malloc((msw->nCols)*sizeof(unsigned short int*))) == NULL)
        {
            printf("Fehler: malloc fehlgeschlagen!\n");
            exit(0);
        }
    }
};

void FreeMemory(Minesweeper *msw ){
  free(msw);
  msw = NULL;
};

unsigned short int DrawRandomNumberBetweenZeroAnd(int X){
  int number;

		/* initialize random seed: */
		//srand(time(NULL));
		/* Generate a random number: 0 - x  (%x + 1) */
		number = rand() % X;
    //printf("%d\n", number);
    return number;
};

bool IsSiteInsideTheGrid(Minesweeper *msw, int x, int y){
  if(x>=msw->nRows || y>=msw->nCols){
    printf("The Coordinates are outside the Game!");
    return false;
  }
};


void FillBoardWhithMineAdjacentNumbers( /* ... */ );

void InitBoard(Minesweeper *msw){

  //AllocateMemory(msw);

  int x, y;

  for(x=0; x<msw->nRows; x++){
    for(y=0; y<msw->nCols; y++){
     msw->board[x][y] = 32;
    }
    //printf("\n");
  };

  //PrintGrid(msw, msw->board);
};


void PutMinesOnBoard(Minesweeper *msw){

    int x, y;
    int z = msw->nMines;

    srand(time(NULL));

for(int i = 0; i<z;){
  // Generate Random Coordinates (Mines) for the Board
  x = DrawRandomNumberBetweenZeroAnd(msw->nRows);

  y = DrawRandomNumberBetweenZeroAnd(msw->nCols);


  if (msw->board[x][y] != 42) {  // make shure there are z diffrent mines
    msw->board[x][y] = 42;
    //  printf("x: %d, y: %d\n", x, y);
    i++;
    }
}
};


void InitMask(Minesweeper *msw){


    AllocateMemory(msw);

    int i, j;

    for(i=0; i<msw->nRows; i++){
      for(j=0; j<msw->nCols; j++){
      msw->mask[i][j] = 64;
      }
      //printf("\n");
    };
    //msw->mask[i][j] = 64;
    //PrintGrid(msw, msw->mask);

    printf("\n");

    //msw->mask[0][5] = 32;


    //for(i=0; i<msw->nRows; i++){
      //for(j=0; j<msw->nCols; j++){
       //printf("%c", msw->mask[i][j]);
      //}
      //printf("\n");
    //};

  PrintGrid(msw, msw->mask);


};
void InitMinesweeper(Minesweeper *msw){
  PrintHeader();
  //AllocateMemory(msw);
  InitMask(msw);
  InitBoard(msw);
  PutMinesOnBoard(msw);
};

// Revealing tools
unsigned short int GetPosition(int i, int j, Minesweeper *msw){

 return i*(msw->nRows)+j;

};

void Floodfill(Minesweeper *msw, int x, int y) //RevealTilesFromEmptyOneOpeningFullSpace
{
    if(msw->mask[x][y] == msw->board[x][y])
    {
      int k, s;
      for(k = x-1; k<msw->nRows; k++)
        for(s = y-1; s<msw->nCols; s++){
          msw->mask[x][y] = msw->board[x][y];
        }
        //putpixel(x,y,newcolor);
        //floodFill(x+1,y,oldcolor,newcolor);
        //floodFill(x,y+1,oldcolor,newcolor);
        //floodFill(x-1,y,oldcolor,newcolor);
        //floodFill(x,y-1,oldcolor,newcolor);
    }
};

//bool RevealAdjacentTilesOfRevealedTile( /* ... */ );
bool RevealTile(Minesweeper *msw){

  int x, y;

  printf("\nChoose X,Y - Coordinates: ");
  scanf("%d %d", &x, &y);
  if (IsSiteInsideTheGrid(msw, x, y) == true) {
    if(msw->board[x][y] == 42){
      PrintGrid(msw, msw->board);
      YouLost();
      return false;
    }
    else {
      msw->mask[x][y] = msw->board[x][y];
      PrintGrid(msw, msw->mask);

    }
  }
  //printf("%d\n", GetPosition(x,y, msw));

  else{
    printf("Try other Coordinates in the Field!");
    return true;
  }




};
void RevealMinesInMask(Minesweeper *msw){
  PrintGrid(msw, msw->board);
};

// Additional player actions
bool ArmTile( /* ... */ );
bool DisarmTile( /* ... */ );
void PrintInGameHelp( /* ... */ );
void QuitGame( /* ... */ ){

};
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
