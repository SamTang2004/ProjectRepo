     // for time(NULL)
#include "geesespotter_lib.h"
#include "geesespotter.h"
char* createBoard(std::size_t xdim, std::size_t ydim){
    char* board = new char[xdim * ydim]{0};
    return board;
}

void cleanBoard(char *board){
    delete [] board;
    board = nullptr;
}

void printBoard(char *board, std::size_t xdim, std::size_t ydim){
    for (int i =0; i < xdim*ydim;i++){
        if (board[i]&markedBit()){
            std::cout<<"M";
        }else if (!(board[i] & (hiddenBit()))&&!(board[i]&(markedBit()))){
            std::cout<<(board[i] - ((board[i]>>5)<<5));
        }
        else if (board[i]&hiddenBit()){
            std::cout<<"*";
        }

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

