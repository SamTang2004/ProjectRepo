
#include <cstdlib>
#include <iostream>
#include <cctype>
#include <ctime>      // for time(NULL)
#include "geesespotter_lib.h"
#include "geesespotter.h"
void startGame(char * & board, std::size_t & xdim, std::size_t & ydim, unsigned int & numgeese);
char getAction();
void actionShow(char * & board, std::size_t & xdim, std::size_t & ydim, unsigned int & numgeese);
void actionMark(char * board, std::size_t xdim, std::size_t ydim);
std::size_t readSizeT();
std::size_t xdim_max();
std::size_t ydim_max();
char markedBit();
char hiddenBit();
char valueMask();
void spreadGeese(char * board, std::size_t xdim, std::size_t ydim, unsigned int numgeese);

//to be implemented
char *createBoard(std::size_t xdim, std::size_t ydim);
void cleanBoard(char *board);
void printBoard(char *board, std::size_t xdim, std::size_t ydim);
void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim);
void hideBoard(char *board, std::size_t xdim, std::size_t ydim);
int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc);
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc);
bool isGameWon(char *board, std::size_t xdim, std::size_t ydim);
char* createBoard(std::size_t xdim, std::size_t ydim){
    char* board = new char[xdim * ydim]{0};
    return board;
}

void cleanBoard(char *board){
    delete [] board;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){
    for (int i =0; i < xdim*ydim;i++){

        if (board[i]&hiddenBit()){
            std::cout<<"*";
        }
        if (!(board[i] & (hiddenBit()))&&!(board[i]&(markedBit()))){
            std::cout<<(board[i] - ((board[i]>>5)<<5));
        }
        if (board[i]&markedBit()){
            std::cout<<"M";
        }
        if (i % xdim == xdim-1){
            std::cout<<std::endl;
        }
    }

    for (int i =0; i < xdim*ydim;i++){

        std::cout<<std::hex<<(int)board[i]<<" ";
        if (i % xdim == xdim-1){
            std::cout<<std::endl;
        }
    }
}
bool isGameWon(char *board, std::size_t xdim, std::size_t ydim){

    for (int i{0}; i < xdim *ydim; i++){
        if (board[i]%16 != 9 && board[i]/16*16 == hiddenBit()){
            return 0;
        }
    }

    return 1;
}

int reveal(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc){
    // expand board into 2d array
    char plane[ydim][xdim]{0};

    for (int i = 0; i < xdim * ydim; i++){
        plane[i/xdim][i%xdim] = board[i];
    }

    if (!(plane[yloc][xloc]&(1<<5))){
        return 2;
    }
    if (plane[yloc][xloc]&markedBit()){
        return 1;
    }

    // implementation

    plane[yloc][xloc] = plane[yloc][xloc]%16;
    if (plane[yloc][xloc] == 9){
        board[xloc + yloc*xdim] = 9;
        return 9;
    }
    if (plane[yloc][xloc]%16==0){
    if (xloc + 1 < xdim && !(plane[yloc][xloc+1]&markedBit())){
        plane[yloc][xloc+1]&=valueMask();
    }
    if (xloc >= 1&&!(plane[yloc][xloc-1]&markedBit())){
        plane[yloc][xloc-1]&=valueMask();
    }

    if (yloc+1<ydim){

        if (xloc+1 < xdim && !(plane[yloc+1][xloc+1]&markedBit())){
            plane[yloc+1][xloc+1]&=valueMask();
        }

        if (xloc >= 1&&!(plane[yloc+1][xloc-1]&markedBit())){
            plane[yloc+1][xloc-1]&=valueMask();
        }
        if (!(plane[yloc+1][xloc]&markedBit())){
        plane[yloc+1][xloc]&=valueMask();}

    }

    if (yloc>=1){
        if (xloc+1 < xdim&&!(plane[yloc-1][xloc+1]&markedBit())){
            plane[yloc-1][xloc+1]&=valueMask();
        }
        if (xloc >= 1&&!(plane[yloc-1][xloc-1]&markedBit())){
            plane[yloc-1][xloc-1]&=valueMask();
        }
        if (!(plane[yloc-1][xloc]&markedBit())){
        plane[yloc-1][xloc]&=valueMask();}
    }
    }

/*
    std::cout<<"2darray from arr:"<<std::endl;
    for (int i = 0;i < ydim; i++){
        for (int j = 0; j <xdim; j++){
            std::cout<<std::hex<<(int)plane[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
*/
    // operations ended. Rewrite information to board
    for (int i = 0; i < xdim * ydim; i++){
        board[i] = plane[i/xdim][i%xdim];
    }
    return 0;
}
int mark(char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc,std::size_t yloc){

    if (board[xloc + yloc*xdim] / 16 == 0){
        return 2;
    }else{
        board[xloc + yloc*xdim] ^= markedBit();
    }
    return 0;

}

void computeNeighbors(char *board, std::size_t xdim, std::size_t ydim){

    char plane[ydim][xdim]{0};

    for (int i = 0; i < xdim * ydim; i++){
        plane[i/xdim][i%xdim] = board[i];
    }

    for (int i = 0; i<ydim;i++){
        for (int j = 0; j < xdim; j ++){
            if (plane[i][j] == 9){
                // same level
                if (j + 1 < xdim && plane[i][j+1] != 9){
                    plane[i][j+1] += 1;
                }
                if (j >= 1 && plane[i][j-1] != 9){
                    plane[i][j-1] += 1;
                }
                // one level up
                if (j + 1 < xdim && i+1 < ydim && plane[i+1][j+1] != 9){
                    plane[i+1][j+1] += 1;
                }
                if (i+1 < ydim && plane[i+1][j] != 9){
                    plane[i+1][j] += 1;
                }
                if (j >= 1 && i+1 < ydim && plane[i+1][j-1] != 9){
                    plane[i+1][j-1] += 1;
                }
                // one level down
                if (j + 1 < xdim && i >=1 && plane[i-1][j+1] != 9){
                    plane[i-1][j+1] += 1;
                }
                if (i >=1 && plane[i-1][j] != 9){
                    plane[i-1][j] += 1;
                }
                if (j >=1 && i >=1 && plane[i-1][j-1] != 9){
                    plane[i-1][j-1] += 1;
                }

            }


        }
    }
    /*
    std::cout<<"2darray from arr:"<<std::endl;
    for (int i = 0;i < ydim; i++){
        for (int j = 0; j <xdim; j++){
            std::cout<<(int)plane[i][j]<<" ";
        }
        std::cout<<std::endl;
    }*/
    for (int i = 0; i < xdim * ydim; i++){
        board[i] = plane[i/xdim][i%xdim];
    }

}

void hideBoard(char *board, std::size_t xdim, std::size_t ydim){

    for (int i = 0; i < xdim*ydim;i++){
        board[i] ^=hiddenBit();
    }
}


////////////////////////////////////////////////////////////////////////////////////


int main()
{
  srand(time(NULL));
  game();
  return 0;
}

bool game()
{
  std::size_t xdim {0};
  std::size_t ydim {0};
  unsigned int numgeese {0};
  char * gameBoard {NULL};

  startGame(gameBoard, xdim, ydim, numgeese);

  char currAction {0};
  while(currAction != 'Q')
  {
    switch (currAction)
    {
      case 'S' :  // show
      {
        actionShow(gameBoard, xdim, ydim, numgeese);
        break;
      }
      case 'M' :  // mark
      {
        actionMark(gameBoard, xdim, ydim);
        break;
      }
      case 'R' :  // restart
      {
        std::cout << "Restarting the game." << std::endl;
        startGame(gameBoard, xdim, ydim, numgeese);
        break;
      }
    }
    printBoard(gameBoard, xdim, ydim);
    if (isGameWon(gameBoard, xdim, ydim))
    {
      std::cout << "You have revealed all the fields without disturbing a goose!" << std::endl;
      std::cout << "YOU WON!!!" << std::endl;
      for (std::size_t reveal_row {0}; reveal_row < ydim; reveal_row++)
      {
        for (std::size_t reveal_col {0}; reveal_col < xdim; reveal_col++)
        {
          gameBoard[reveal_row*xdim + reveal_col] = (gameBoard[reveal_row*xdim + reveal_col] & valueMask());
        }
      }
      printBoard(gameBoard, xdim, ydim);
      std::cout << "Resetting the game board." << std::endl;
      startGame(gameBoard, xdim, ydim, numgeese);
      printBoard(gameBoard, xdim, ydim);
    }
    currAction = getAction();
  }

  cleanBoard(gameBoard);
  return true;
}

void startGame(char * & board, std::size_t & xdim, std::size_t & ydim, unsigned int & numgeese)
{
  std::cout << "Welcome to GeeseSpotter!" << std::endl;
  do {
    std::cout << "Please enter the x dimension (max " << xdim_max() << "): ";
    std::cin >> xdim;
  } while(xdim < 1 || xdim > xdim_max());
  do {
    std::cout << "Please enter the y dimension (max " << ydim_max() << "): ";
    std::cin >> ydim;
  } while(ydim < 1 || ydim > ydim_max());

  std::cout << "Please enter the number of geese: ";
  std::cin >> numgeese;
  while (numgeese > xdim * ydim)
  {
    std::cout << "That's too many geese!" << std::endl;
    std::cout << "Please enter the number of geese: ";
    std::cin >> numgeese;
  }

  cleanBoard(board);

  board = createBoard(xdim, ydim);
  spreadGeese(board, xdim, ydim, numgeese);
  computeNeighbors(board, xdim, ydim);
  hideBoard(board, xdim, ydim);
}

char getAction()
{
  char action {0};

  std::cout << "Please enter the action ([S]how, [M]ark, [R]estart, [Q]uit): ";
  std::cin >> action;

  if (islower(action))
    action = toupper(action);

  return action;
}

void actionShow(char * & board, std::size_t & xdim, std::size_t & ydim, unsigned int & numgeese)
{
  std::size_t reveal_x {0};
  std::size_t reveal_y {0};
  std::cout << "Please enter the x location to show: ";
  std::cin >> reveal_x;
  std::cout << "Please enter the y location to show: ";
  std::cin >> reveal_y;

  if (reveal_x >= xdim || reveal_y >= ydim)
  {
    std::cout << "Location entered is not on the board." << std::endl;
  }
  else if (board[xdim*reveal_y + reveal_x] & markedBit())
  {
    std::cout << "Location is marked, and therefore cannot be revealed." << std::endl;
    std::cout << "Use Mark on location to unmark." << std::endl;
  }
  else if (reveal(board, xdim, ydim, reveal_x, reveal_y) == 9)
  {
    std::cout << "You disturbed a goose! Your game has ended." << std::endl;
    printBoard(board, xdim, ydim);
    std::cout << "Starting a new game." << std::endl;
    startGame(board, xdim, ydim, numgeese);
  }
}

void actionMark(char * board, std::size_t xdim, std::size_t ydim)
{
  std::size_t mark_x {0};
  std::size_t mark_y {0};
  std::cout << "Please enter the x location to mark: ";
  std::cin >> mark_x;
  std::cout << "Please enter the y location to mark: ";
  std::cin >> mark_y;

  if (mark_x >= xdim || mark_y >= ydim)
  {
    std::cout << "Location entered is not on the board." << std::endl;
  }
  else if (mark(board, xdim, ydim, mark_x, mark_y) == 2)
  {
    std::cout << "Position already revealed, so cannot be marked." << std::endl;
  }
}

std::size_t readSizeT()
{
  return 0;
}

std::size_t xdim_max()
{
  return 60;
}

std::size_t ydim_max()
{
  return 20;
}

char markedBit()
{
  return 0x10;
}

char hiddenBit()
{
  return 0x20;
}

char valueMask()
{
  return 0x0F;
}

void spreadGeese(char * board, std::size_t xdim, std::size_t ydim, unsigned int numgeese)
{
  if (board != NULL)
  {
    for (unsigned int gen_goose {0}; gen_goose < numgeese; gen_goose++)
    {
      std::size_t try_position {0};
      do {
         try_position = rand() % (xdim * ydim);
      } while (board[try_position] != 0);

      board[try_position] = 9;
    }
  }
}
