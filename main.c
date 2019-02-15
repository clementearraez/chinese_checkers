/*
    Project 1. Chinese Checkers
    ENEE150 Spring 2019
    main.c
    Clemente Rodriguez Arraez
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "chinese_checkers.h"



int the_board[BOARD_SIZE_Y][BOARD_SIZE_X] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                                            {0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0},
                                            {0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0},
                                            {0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 0},
                                            {0, 0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 0, 0},
                                            {0, 0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0, 0},
                                            {0, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 0},
                                            {0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0},
                                            {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int x_from = 0;
int y_from = 0;
int x_to = 0;
int y_to = 0;



int main()
{
  int m = RE; //We start with RED
  int validation = VALID_MOVE;
  int multi_x_from, multi_x_to = 0;//x, y values for the possible multijump
  int multi_y_from, multi_y_to = 0;
  int start_board = 0;
  int jumper_mode = FALSE;
  //read_file(); //--> The board is hard coded

  while(TRUE){

    if(start_board ==0){
      print_board();
      start_board=1;
    }
    print_error(validation); //In case there's an error (INVALID_MOVE)

    if(m==RE){
      printf("RED's move:  ");
    }else{
      printf("GREEN's move:  ");
    }

    //Scan
    scanf(" %d %d %d %d", &x_from, &y_from, &x_to, &y_to);

    validation = check_move(m,x_from, y_from, x_to, y_to); //General movement


      if(jumper_mode ==TRUE){ //We've jumped and there's a possible jump
          if(x_from ==-1 && y_from ==-1 && x_to ==-1 && y_to ==-1){ //The player decides not to jump with this command
            jumper_mode = FALSE;
            validation = INVALID_MOVE;
          }else if(x_from!=multi_x_to || y_from != multi_y_to || x_to == multi_x_from|| y_to == multi_y_from){
            //We check if coordinates are correct (if the marble is the same, x_from = former x_from = multi_x_from)
            validation = INVALID_MOVE;
          }
      }else{ //In case there's no jump, the player can quit the game
        //Here, we check if the player wants to quit the game
        if(x_from ==-1 && y_from ==-1 && x_to ==-1 && y_to ==-1){
          exit(0);
        }
      }


    //If everything is correct and valid, then we can move the marble
    if(validation== VALID_MOVE){
      the_board[y_to][x_to] = m;
      the_board[y_from][x_from] =EM;

      if(check_jump(x_from, y_from, x_to, y_to) ==VALID_MOVE){//We check if a jump is made --> if it does, then we call is_jumper
          if(is_jumper(x_from, y_from, x_to, y_to)==FALSE){
              jumper_mode = FALSE;
          }else{
            if(jumper_mode != TRUE){
              multi_x_to = x_to;//First
              multi_y_to = y_to;
              multi_x_from = x_from;
              multi_y_from = y_from;
              jumper_mode = TRUE;
              printf("\n");
              print_board();
            }
          }
      }


      if(jumper_mode == FALSE){//We change player here if there's no possible jump and VALID_MOVE
        printf("\n");
          if (m==RE){
              m= GR;
          }else{
              m=RE;
          }
          print_board();
      }
    }
  }
}
