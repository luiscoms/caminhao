#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>

# define CHAR_UP 72
# define CHAR_DOWN 80
# define CHAR_LEFT 75
# define CHAR_RIGHT 77
//# define CHAR_DELETE 127
# define CHAR_ENTER 13
# define CHAR_ESC 27

# define MAIN_MENU "\nMENU \
  \n------------------\
  \n1- New Game\
  \nESC | q - Quit\
  \nOption: "

# define HElPER "\nHELP \
  \n---------------------------------------------------------------------------\
  \n[ UP | w - Charge ] [ DOWN | s - Uncharge ] [ Left | a - Backward ] [ Right | d - Forward ]\
  \nMove: "

# define POSITIONS 10
# define MAX_FUEL 7

#define TRUE ~0
#define FALSE 0

typedef struct Truck
{
    int position;
    int fuel;
} Truck;

void helper() {
    printf(HElPER);
}

void printStatus(Truck* truck, int* fuels) {
    if (truck == NULL) return;
    int i;
    printf("GAME\n[");
    for (i = 0; i < POSITIONS; i++) {
        if (truck->position == i) {
            printf(" [%d] ", fuels[i]);
        } else {
            printf(" %d ", fuels[i]);
        }
    }
    printf("]");
    printf("\t[ Fuel: %d, Position: %d ]", truck->fuel, truck->position);
}

int gameOver(Truck* truck) {
    if ((truck->position == POSITIONS-1) || (truck->fuel <= 0)) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void game() {
    char op;// = CHAR_UP;

    Truck* truck = (Truck*)malloc(sizeof(Truck));
    truck->position = 0;
    truck->fuel = MAX_FUEL;

    int* fuels = (int*)malloc(POSITIONS * sizeof(int));
    int i;
    for (i = 0; i < POSITIONS; i++) {
        fuels[i] = 0;
    }

    do {
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

        printStatus(truck, fuels);
        //printf("\n\n%s", STATUS);
        helper();
        fflush(stdin);
        scanf("%c", &op);

        switch (op) {
            case 'a':
            case CHAR_LEFT:
                if (truck->position > 0) {
                    truck->position--;
                    truck->fuel--;
                }
                break;
            case 'd':
            case CHAR_RIGHT:
                truck->position++;
                truck->fuel--;
                break;
            case 's':
            case CHAR_DOWN:
                if (truck->position > 0) {
                    fuels[truck->position]++;
                    truck->fuel--;
                }
                break;
            case 'w':
            case CHAR_UP:
                if (truck->fuel + fuels[truck->position] <= MAX_FUEL) {
                    truck->fuel += fuels[truck->position];
                    fuels[truck->position] = 0;
                } else {
                    fuels[truck->position] = truck->fuel+fuels[truck->position]-MAX_FUEL;
                    truck->fuel = MAX_FUEL;
                }
                break;
        }
        if (truck->position == 0) truck->fuel = MAX_FUEL;

    } while(!gameOver(truck) && op != CHAR_ESC && op != 'q');

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printStatus(truck, fuels);

    if (truck->position == POSITIONS-1) {
        printf("\n\nYOU WIN\n\n");
    } else {
        printf("\n\nGAME OVER\n\n");
    }

    free(truck);
    fflush(stdin);
    scanf("%c", &op);
}

char printMenu(char MsgMenu[]) {
    char op;
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n%s", MsgMenu);
    fflush(stdin);
    scanf("%c", &op);
    return op;
}

int main() {
    while (1) {
        switch (printMenu(MAIN_MENU)) {
            case 'q':
            case CHAR_ESC:
                 exit(0);
                 break;
            case '1' : game();break;
        }
    }
    return 0;
}

