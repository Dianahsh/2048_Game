#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int array[4][4];

void  go_up();
void go_down();
void go_right();
void go_left();
void random();
void print();
int emty();
int score();

int main() {

    char direction = 'O' , inEnter;
    printf("r = Right  l = Left  u = up  d = down  Q = quit\n");
    random();
    while(direction != 'Q') {
        random();
        print();
        scanf("%c%c",&direction,&inEnter);
        if(direction == 'Q')
            break;
        switch (direction) {
            case 'u':
                go_up();
                break;
            case 'd':
                go_down();
                break;
            case 'r':
                go_right();
                break;
            case 'l':
                go_left();
                break;
        }
        int value = score();
        if (value == 2) {
            printf("YOU WIN :)\n");
            break;
        }
        else if(value == 0) {
            printf("GAME OVER! \n");
            break;
        }
    }
    return 0;
}
int emty() { //count if their is any empty
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(array[i][j] == 0)
                return 1;
        }
    }
    return 0;
}
void print() { //print the game
    printf("-------------------------\n");
    for(int i=0;i<4;i++) {
        printf("|");
        for(int j=0;j<4;j++) {
            if(array[i][j] == 0)
                printf("     |");
            else if(array[i][j] >= 1000)
                printf(" %d|",array[i][j]);
            else if(array[i][j] >= 100)
                printf(" %d |",array[i][j]);
            else if(array[i][j] >= 10)
                printf("  %d |",array[i][j]);
            else
                printf("  %d  |",array[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------\n");
}
int score() { //show if the user can play or win or lose
    int s=0;
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(array[i][j] == 2048) {
                return 2;
            }
            else if(array[i][j] == 0 || (array[i][j] == array[i-1][j] && i != 0) || (array[i][j] == array[i+1][j] && i != 3) || (array[i][j] == array[i][j-1] && j != 0) ||  (array[i][j] == array[i][j+1] && j != 3)) {
                s=1;
            }
        }
    }
    return s;
}
void random() { //put 2 or 4 randomly
    int a,b;
    if(emty() == 1) {
        srand(time(NULL));
        a = rand()%4;
        b = rand()%4;

        while(array[a][b] != 0) {
            a = rand()%4;
            b = rand()%4;
        }
        int chance = rand() %10 ;
        if(chance == 0 || chance == 1)
            array[a][b] = 4;
        else
            array[a][b] = 2;
    }
}
void  go_up() {

    for(int j=0;j<4;j++) {
        for(int i=0;i<4;i++) {
            if(array[i][j] == 0) {
                for(int k=0;k+i<4;k++){
                    if(array[i+k][j] != 0) {
                        array[i][j] = array[i+k][j];
                        array[i+k][j] = 0;
                        break;
                    }
                }
            }
            for(int k=1;k+i<4;k++) {
                if(array[i][j] == array[i+k][j]) {
                    array[i][j]*=2;
                    array[i+k][j] = 0;
                    break;
                }
                else if(array[i+k][j] != 0) {
                    array[i+1][j] = array[i+k][j];
                    if(k != 1)
                        array[i+k][j] = 0;
                    break;
                }
            }
        }
    }
}
void go_down() {

    for(int j=0;j<4;j++) {
        for(int i=3;i>=0;i--) {
            if(array[i][j] == 0) {
                for(int k=0;i-k>=0;k++){
                    if(array[i-k][j] != 0) {
                        array[i][j] = array[i-k][j];
                        array[i-k][j] = 0;
                        break;
                    }
                }
            }
            for(int k=1;i-k>=0;k++) {
                if(array[i][j] == array[i-k][j]) {
                    array[i][j]*=2;
                    array[i-k][j] = 0;
                    break;
                }
                else if(array[i-k][j] != 0) {
                    array[i-1][j] = array[i-k][j];
                    if(k != 1)
                        array[i-k][j] = 0;
                    break;
                }
            }
        }
    }
}
void go_right() {

    for(int i=0;i<4;i++) {
        for(int j=3;j>0;j--) {
            if(array[i][j] == 0) {
                for(int k=0;j-k>=0;k++){
                    if(array[i][j-k] != 0) {
                        array[i][j] = array[i][j-k];
                        array[i][j-k] = 0;
                        break;
                    }
                }
            }
            for(int k=1;j-k>=0;k++) {
                if(array[i][j] == array[i][j-k]) {
                    array[i][j]*=2;
                    array[i][j-k] = 0;
                    break;
                }
                else if(array[i][j-k] != 0) {
                    array[i][j-1] = array[i][j-k];
                    if(k != 1)
                        array[i][j-k] = 0;
                    break;
                }
             }
        }
    }
}
void go_left() {

    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++) {
            if(array[i][j] == 0) {
                for(int k=0;j+k<4;k++){
                    if(array[i][j+k] != 0) {
                        array[i][j] = array[i][j+k];
                        array[i][j+k] = 0;
                        break;
                    }
                }
            }
            for(int k=1;k+j<4;k++) {
                if(array[i][j] == array[i][j+k]) {
                    array[i][j]*=2;
                    array[i][j+k] = 0;
                    break;
                }
                else if(array[i][j+k] != 0) {
                    array[i][j+1] = array[i][j+k];
                    if(k != 1)
                        array[i][j+k] = 0;
                    break;
                }
            }
        }
    }
}