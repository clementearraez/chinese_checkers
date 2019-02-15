/*
    Project 1. Chinese Checkers
    ENEE150 Spring 2019
    chinese_checkers.h
    Clemente Rodriguez Arraez
*/

#define BOARD_SIZE_X 25
#define BOARD_SIZE_Y 17

#define TRUE 1
#define FALSE 0

#define VALID_MOVE 1
#define INVALID_MOVE 2

#define NO_DATA_GIVEN 50


/* definitions for pieces */
#define DA 0			/* disallowed */
#define RE 1			/* red */
#define GR 2			/* green */
#define EM 7			/* empty */


extern int the_board[BOARD_SIZE_Y][BOARD_SIZE_X];

/* Required Functions */
void print_board();
int check_neighbor(int x_from, int y_from, int x_to, int y_to);
int check_jump(int x_from, int y_from, int x_to, int y_to);
int check_move(int color, int x_from, int y_from, int x_to, int y_to);
int is_jumper(int x_from, int y_from, int x_to, int y_to);

/*Optional functions*/
/*---------------------------------------------------------------------------------------------------------------------*/
/*print_error uses a number code to identify the error. In this game we have 2 types of errors but we only use 1:
    -Error 50: In case that the file does not exist for read_file() function (Function not used because I hard coded the board)
    -Error 2: INVALID_MOVE: Not a valid move
*/
void print_error(int num_error);
/*----------------------------------------------------------------------------------------------------------------------*/
/*Read file is used for reading the board and saving it in the_board (Function not used because I hard coded the board)*/
void read_file();
/*----------------------------------------------------------------------------------------------------------------------*/
