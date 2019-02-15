/*
    Project 1. Chinese Checkers
    ENEE150 Spring 2019
    functions.c
    Clemente Rodriguez Arraez
*/

#include <stdio.h>
#include "chinese_checkers.h"
#include <stdlib.h>


int check_neighbor(int x_from, int y_from, int x_to, int y_to){
  if((abs(x_to-x_from) ==1 && abs(y_to-y_from)==1) || ((abs(x_to -x_from)==2) && abs(y_to-y_from)==0)){
      return VALID_MOVE;
  }else{
      return INVALID_MOVE;
  }
}


int check_jump(int x_from, int y_from, int x_to, int y_to){

  //Here, we check that this movement is a possible jump
  if((abs(x_to-x_from) ==2 && abs(y_to-y_from)==2) || (abs(x_to-x_from) ==4 && abs(y_to-y_from)==0) || (abs(x_to-x_from) ==3 && abs(y_to-y_from)==1) ||(abs(x_to - x_from)==0 && abs(y_to -y_from)==2) || the_board[y_to][x_to] != GR || the_board[y_to][x_to] != RE){
    if((abs(x_to-x_from) ==2 && abs(y_to-y_from)==2) || (abs(x_to-x_from) ==4 && abs(y_to-y_from)==0)){
      //Here we identify the neighbor marble (Case 1)
      int aux1 = (x_to + x_from)/2;
      int aux2 = (y_to + y_from)/2;

      //And here, we check that this possible jump is valid or not
      if(the_board[aux2][aux1] == RE || the_board[aux2][aux1] ==GR){
        return VALID_MOVE;
      }else{
        return INVALID_MOVE;
      }
    }else if(abs(x_to-x_from) ==3 && abs(y_to-y_from)==1){
      //Here we identify the neighbor marble (Case 2)
      int px_to = x_from;
      int py_to = y_from;

      if(x_to > x_from){
        px_to= x_from +2;
      }else{
        px_to= x_from-2;
      }


      if(the_board[py_to][px_to] == RE || the_board[py_to][px_to] ==GR){
        return VALID_MOVE;
      }else{
        return INVALID_MOVE;
      }
    }else if(abs(x_to - x_from)==0 && abs(y_to -y_from)==2){
      //Here we identify the neighbor marble (Case 3)
      int px1_to = x_from + 1;
      int px2_to = x_from - 1;
      int py_to = y_from;

      if(y_to < y_from){
        py_to = y_from -1;
      }else{
        py_to = y_from +1;
      }

      if(the_board[py_to][px1_to] == RE || the_board[py_to][px1_to] ==GR || the_board[py_to][px2_to] == RE || the_board[py_to][px2_to] ==GR ){
        return VALID_MOVE;
      }else{
        return INVALID_MOVE;
      }
    }else{
      return INVALID_MOVE;
    }
  }else{
    return INVALID_MOVE;
  }
}
int check_move(int color, int x_from, int y_from, int x_to, int y_to){
//We check if the marble is in its place and if there's valid space in x_to, y_to
  if(the_board[y_from][x_from] != color || the_board[y_to][x_to] != EM){
    return INVALID_MOVE;
  }else{
    if(check_neighbor(x_from, y_from, x_to, y_to) == VALID_MOVE){
      return VALID_MOVE;
    }else if(check_jump(x_from, y_from, x_to, y_to) == VALID_MOVE){
      return VALID_MOVE;
    }else{
      return INVALID_MOVE;
    }
  }

  return VALID_MOVE;

}
int is_jumper(int x_from, int y_from, int x_to, int y_to){
//Here, we use check_jump for the different cases in which there's a possible jump (and we avoid comming back to the same place)
  if(check_jump(x_to, y_to, x_to+2, y_to-2) == VALID_MOVE && (x_to +2 !=x_from && y_to-2 !=y_from) ){
    return TRUE;
  }else if(check_jump(x_to, y_to, x_to+2, y_to +2) == VALID_MOVE && (x_to +2 !=x_from && y_to+2 !=y_from)){
    return TRUE;
  }else if(check_jump(x_to, y_to, x_to-2, y_to +2) == VALID_MOVE && (x_to -2 !=x_from && y_to+2 !=y_from)){
    return TRUE;
  }else if(check_jump(x_to, y_to, x_to-4, y_to) == VALID_MOVE && (x_to -4 !=x_from && y_to !=y_from)){
    return TRUE;
  }else if(check_jump(x_to, y_to, x_to+4, y_to) == VALID_MOVE && (x_to +4 !=x_from && y_to !=y_from)){
    return TRUE;
  }else if(check_jump(x_to, y_to, x_to-2, y_to -2) == VALID_MOVE && (x_to -2 !=x_from && y_to-2 !=y_from)){
    return TRUE;
  }else{
    return FALSE;
  }

}


void print_board(){
  int i, j=0;
  for(i=0; i<BOARD_SIZE_Y+1; i++){
    if(i!=0){ //Print column numbers
      if(i>=11)//I solve the problem of spaces from line 10 and following ones
      printf("%d ", i-1);
      else
      printf(" %d ", i-1);

    }
    for(j=0; j<BOARD_SIZE_X;j++){

        if(i==0){ //Print row numbers
          if(j==0){
          printf("   ");//White space (up and left)
          }else{
            if(j>10){
            printf("%d ", j-1);
            }else{
            printf(" %d ", j-1);
            }
            if(j==BOARD_SIZE_X -1) //Last element: 24
            printf("%d ", BOARD_SIZE_X -1);
          }
        }else{

        switch(the_board[i-1][j]){
          case 0:
            printf("   ");
            break;
          case 7:
            printf(" - ");
            break;
          case 1:
            printf(" R ");
            break;
          case 2:
            printf(" G ");
            break;
          default :
            printf("   ");
        }
        }

    }
    printf("\n");
  }
  printf("\n");

}

void print_error(int num_error){
  switch (num_error) {
    case 50: //Only in the case the board is not hard coded.
      printf("No data given: please, insert the file to load the board\n");
      break;
    case INVALID_MOVE:
      printf("INVALID MOVE.  TRY AGAIN!!\n");
      break;
    default:
      break;
  }
}


void read_file(){ //Just in case we wanted to read the file (This function is not used in the game)
  int i, j =0;
  FILE *inFile;

  inFile = fopen("hw1.3.in", "r");
  if(inFile == NULL){
    print_error(NO_DATA_GIVEN);
    exit(0);
  }
  for (i = 0; i < BOARD_SIZE_Y; i++) {
    for (j = 0; j < BOARD_SIZE_X; j++) {
      fscanf(inFile, "%d", &the_board[i][j]);
    }
  }
}
