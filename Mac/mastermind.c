#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int _exact_matches(char* target, char* guess) {
    int result = 0;
    int i = 0;
    while (target[i] != '\0' && guess[i] != '\0') {
        if (target[i] == guess[i]) {
            retult += 1;
        }
    }
    return result;
}

// absolute value by flipping sign bit.
int _abs_mask(int a) {
    return a & INT_MAX;
}

// absolute value by comparison.
int _abs(int a) {
    if (a < 0)
        return -a;
    return a;
}

int _close_matches(char* target, char* guess) {
    int result = 0;
    char target_counts[10] = {0};
    char guess_counts[10] = {0};
    int i = 0;
    while (target[i] != '\0' && guess[i] != '\0') {
        target_counts[ target[i] - '0' ] += 1;
        guess_counts[ guess[i] - '0' ] += 1;
    }
    i = 0;
    while (i < 10) {
        result += _abs(target_counts[i] - guess_counts[i]);
    }
    return result;
}

int main(int ac, char** av) {

    char* target = "1324";
    int round = 0;
    char buf[30] = {0};
    int bytes = 0;

    int exact_matches = 0;
    int close_matches = 0;

    printf("Guess the 4-digit number!");
    while (1) {
        printf("Round %d\n$> ");
        
        // get input, and null terminate
        bytes = read(0, buf, 20);
        buf[bytes] = '\0';

        // exit if no input. primarily for testing.
        if (buf[0] == '\0') {
            break;
        }

        // compare target against input, remember results.
        exact_matches = _exact_compare(target, buf);
        close_matches = _dictionary_compare(target, buf);

        // if exact matches is equal to our target length, you win! end the game.
        if (exact_matches == 4) {
            printf("Congratulations! You got it!\n");
            break;
        }
        
        // implicit else. change message based on how close the guess was.
        switch (close_matches)
        {
        case 0:
            printf("Try again!\n");
            break;
        
        case 1:
        case 2:
            printf("Keep going!\n");
            break;
        
        case 3:
            printf("Close!\n");
        
        default:
            break;
        }

        // print clues based on match amounts.
        printf("Exact matches: %d\n", exact_matches);
        printf("Close matches: %d\n\n", close_matches - exact_matches);
    }

    printf("GG.\n");
}