#include<stdio.h>

void printboard();
int makeMove();
void go(int loc);
int hasWon(int loc, int symbol);
int posWin(char c);
void play(int turn);
void evenMove(int turn);


int board[9], move=0, winMove,is_valid,cell_no;

int main(){
    int choice;
    printf("\n\n\tTIC - TAC - TOE\n\n");
    printf("\n\t 1 - PLAYER 1(X)");
    printf("\n\t 2 - PLAYER 2(O)");
    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    for(int i=0; i<9; i++){
        board[i] = 2;
    }


    if(choice == 1)
        play(0);
    else
        play(1);

    return 0;
}


void evenMove(int turn){
    switch(!turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE");
        }while(is_valid==0);

        move++;
        go(cell_no);


        int isWinning= hasWon(cell_no, 5);
        if(isWinning){
            printf("\n\n\tYOU WON!!");
        }
        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(posWin('O')){
            go(winMove);
            printboard();
            printf("\n\n\tCOMPUTER WON!!");
            return;
        }
        else if(posWin('X'))
            go(winMove);
        else
            go(makeMove());

        printboard();
    }
}


void printboard(){

    for(int i=0; i<9; i++){
        if(i%3 == 0)
            printf("\n\t ---------------------- \n\t");

        if(board[i] == 2)
            printf("|   %d   ",i+1, board[i]);
        else if(board[i] == 3)
            printf("|   X  ", board[i]);
        else
            printf("|   O  ", board[i]);

        if(i%3 == 2)
            printf("|");
    }
    printf("\n\t ---------------------- ");
}

int makeMove(){
    for(int i=0; i<9; i++){
        if(board[i]==2)
            return i;

    }

    return -1;
}

void go(int loc){
    if(move%2 == 0)
        board[loc] = 5;
    else
        board[loc] = 3;
}

int hasWon(int loc, int symbol){

    if(loc%3 == 0){
        if((board[loc] == board[loc+1]) && (board[loc] == board[loc+2]) && (board[loc] == symbol))
            return 1;
        else if((board[0] == board[3]) && (board[0] == board[6]) && (board[0] == symbol))
            return 1;
    }
    else if(loc%3 == 1){
        if((board[loc] == board[loc-1]) && (board[loc] == board[loc+1]) && (board[loc] == symbol))
            return 1;
        else if((board[1] == board[4]) && (board[1] == board[7]) && (board[1] == symbol))
            return 1;
    }
    else{
        if((board[loc] == board[loc-1]) && (board[loc] == board[loc-2]) && (board[loc] == symbol))
            return 1;
        else if((board[2] == board[5]) && (board[2] == board[8]) && (board[2] == symbol))
            return 1;
    }

    //left diagonal check
    if((board[0] == board[4]) && (board[0] == board[8]) && (board[0] == symbol))
            return 1;

    //right diagonal check
    if((board[2] == board[4]) && (board[2] == board[6]) && (board[2] == symbol))
            return 1;

    return 0;
}

int posWin(char c){
    int winProd=0, prodMove;
    if(c=='X')
        winProd = 18;
    else
        winProd = 50 ;

    //row check
    for(int i=0; i<9; i+=3){
        prodMove=0;
        prodMove = board[i] * board[i+1] * board[i+2];

        if(prodMove == winProd){
            if(board[i] == board[i+1])
                winMove = i+2;
            else if(board[i+1] == board[i+2])
                winMove = i;
            else
                winMove = i+1;

            return 1;
        }
    }

    for(int i=0; i<3; i++){
        prodMove = board[i] * board[i+3] * board[i+6];

        if(prodMove == winProd){
            if(board[i] == board[i+3])
                winMove = i+6;
            else if(board[i+3] == board[i+6])
                winMove = i;
            else
                winMove = i+3;

            return 1;
        }
    }

    prodMove = board[0] * board[4] * board[8];
    if(prodMove == winProd){
        if(board[0] == board[4])
            winMove = 9;
        else if(board[4] == board[8])
            winMove = 1;
        else
            winMove = 5;

        return 1;
    }


    prodMove = board[2] * board[4] * board[6];
    if(prodMove == winProd){
        if(board[2] == board[4])
            winMove = 7;
        else if(board[4] == board[6])
            winMove = 3;
        else
            winMove = 5;

        return 1;
    }

    return 0;
}


void play(int turn){

    int cell_no, is_valid=0;
    //case-0 == for player
    //case-1 == for computer

    //first move
    switch(turn){
    case 0:
        printboard();
        printf("\nENTER YOUR MOVE : ");
        scanf("%d", &cell_no);
        cell_no=cell_no-1;
        move++;
        go(cell_no);

        break;

    case 1:
        move++;
        printf("\n\nCOMPUTER'S MOVE : ");
        go(4);
        printboard();
        break;
    }

    //second move
    switch(!turn){
    case 0:
        is_valid=0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);

        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(board[4]==2)
            go(4);
        else
            go(0);
        printboard();
    }


    //third move
    switch(turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);

        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(board[0]==2)
            go(0);
        else
            go(2);
        printboard();
    }


    //fourth move
    switch(!turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);

        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        //blocking opponent's loc if it is likely to win in its next move
        if(posWin('X'))
            go(winMove);
        else{
            if(board[2]==2)
                go(2);
            else
                go(6);
        }
        printboard();
    }

    //fifth move
    switch(turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);

        int isWinning= hasWon(cell_no, 3);
        if(isWinning){
            printf("\n\n\tYOU WON!!");
            return;
        }
        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(posWin('X')){
            go(winMove);
            printboard();
            printf("\n\n\tCOMPUTER WON");
            return;
        }
        else if(posWin('O'))
            go(winMove);
        else{
            if(board[6]==2)
                go(6);
            else
                go(8);
        }
        printboard();
    }


    //sixth move
    evenMove(turn);


    //seventh move
    switch(turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);


        int isWinning= hasWon(cell_no, 3);
        if(isWinning){
            printf("\n\n\tYOU WON!!");
        }
        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(posWin('X')){
            go(winMove);
            printboard();
            printf("\n\n\tCOMPUTER WON");
            return;
        }
        else if(posWin('O'))
            go(winMove);
        else
            go(makeMove());

        printboard();
    }

    //eighth move
    evenMove(turn);

    //ninth move
    switch(turn){
    case 0:
        is_valid = 0;
        do{
            printf("\nENTER YOUR MOVE : ");
            scanf("%d", &cell_no);
            cell_no=cell_no-1;
            if(board[cell_no]==2)
                is_valid=1;
            else
                printf("\nINVALID CHOICE!");
        }while(is_valid==0);

        move++;
        go(cell_no);

        printboard();
        int isWinning= hasWon(cell_no, 3);

        if(isWinning)
            printf("\n\n\tYOU WON!!");
        else
            printf("\n\n\tIT'S A DRAW");
        break;

    case 1:
        printf("\n\nCOMPUTER'S MOVE : ");
        move++;
        if(posWin('X')){
            go(winMove);
            printboard();
            printf("\n\n\tCOMPUTER WON!!");
            return;
        }
        else{
            go(makeMove());
            printboard();
            printf("\n\n\tIT'S A DRAW");
        }


    }
}
