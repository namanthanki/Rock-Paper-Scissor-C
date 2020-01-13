#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define DRAW 0
#define USER_WIN 1
#define COMP_WIN 2

int rock_paper_scissor(int user, int comp) {

    int result;
    
    if ( user == ROCK && comp == PAPER ) {
        result = COMP_WIN;
    }

    else if ( user == ROCK && comp == SCISSOR )
    {
        result = USER_WIN;
    }

    else if ( user == PAPER && comp == ROCK ) {
        result = USER_WIN;
    }

    else if ( user == PAPER && comp == SCISSOR ) {
        result = COMP_WIN;
    }

    else if ( user == SCISSOR && comp == ROCK ) {
        result = COMP_WIN;
    }

    else if ( user == SCISSOR && comp == PAPER ) {
        result = USER_WIN;
    }

    else {
        result = DRAW;
    }
}

int get_user_input() {
    
    int choice;

    do {
        printf(" 1.ROCK\n ");
        printf("2.PAPER\n ");
        printf("3.SCISSOR\n ");
        printf("Please Input [1,2,3]: ");
        scanf("%d", &choice);

        if (! ( choice>=1 && choice<=3 ) )
        {
            printf("Invalid input, please enter any one among 1 to 3");
        }
        
    } while ( !( choice>=1 && choice<=3 ) );

    return choice;
}

void print_word ( int v ) {

    if ( v == ROCK ) {
        printf("Rock\n");
    }

    else if ( v == PAPER ) {
        printf("Paper\n");
    }

    else if ( v == SCISSOR ) {
        printf("Scissor\n");
    }

}

int main () {

    int user_socre = 0;
    int comp_score = 0;
    srand( time(NULL) );

    int quit = 0;

    while (!quit)
    {

        int user_input = get_user_input();
        int comp_choice = rand() % 3;

        printf("Computer chose: ");
        print_word(comp_choice);

        printf("User chose: ");
        print_word(user_input);

        int result = rock_paper_scissor( user_input, comp_choice );

        if ( result == DRAW ) {
            printf("It is a Draw\n");
        }

        else if ( result == USER_WIN ) {
            printf("User WINS! and Computer LOST the game\n ");
            user_socre++;
        }

        else if ( result == COMP_WIN ) {
            printf("Computer WINS! and User LOST the game\n");
            comp_score++;
        }

        printf("\n");
        printf("-------------------------------------------------------------------\n");

        printf("User score: %d\n", user_socre);
        printf("Computer score: %d\n", comp_score);

        printf("-------------------------------------------------------------------\n");
        printf("\n\n");

        printf("If you want to continue playing, press any key or 0 to exit the game.");

        int response;

        scanf("%d", &response);

        if ( response == 0 ) {
            quit = 1;
        }
 
    }
    
    printf("Final score...\n");

    printf("\n");
    printf("-------------------------------------------------------------------\n");

    printf("User score: %d\n", user_socre);
    printf("Computer score: %d\n", comp_score);

    printf("-------------------------------------------------------------------\n");
    printf("\n\n");

    if ( user_socre == comp_score ) {
        printf("Game DRAW\n");
    }

    else if ( user_socre > comp_score ) {
        printf ("User WINS! the game\n");
    }

    else {
        printf("Computer WINS the game\n");
    }

    return 0;
}