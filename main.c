#include "forca_OnMyOwn.h"

//Constants
enum{
    OP_UNSELECTED,
    OP_SINGLEPLAYER,
    OP_MULTIPLAYER,
    OP_EXIT,
};

//Prototype
int menu();

int main(){
    int option = OP_UNSELECTED;

    while(option != OP_EXIT){
        option = menu();

        switch(option){
            case OP_SINGLEPLAYER:
                printf("\n| --------> SINGLE PLAYER MODE <--------|");
                //categorySelection();
                singlePlayer();
                break;

            case OP_MULTIPLAYER:
                printf("\n|---------> MULTIPLAYER MODE <----------|");
                multiPlayer();
                break;

            case OP_EXIT:
                printf("\nFeel free to come back anytime!\n\n");
                break;

            default:
                printf("\nInvalid choice. Try again!\n\n");

        }
    }

    return 0;

}

int menu(){
    int op = OP_UNSELECTED;

    printf("| x = x = x  THE HANGMAN GAME x = x = x |");
    printf("\n|\t   Main Menu\t\t\t|");
    printf("\n|\t  %d. Single player\t\t|", OP_SINGLEPLAYER);
    printf("\n|\t  %d. Multiplayer\t\t|", OP_MULTIPLAYER);
    printf("\n|\t  %d. Exit\t\t\t|", OP_EXIT);
    printf("\n|\t  Input an option: \t\t");
    scanf("%d", &op);
    getchar();

    return op;
}