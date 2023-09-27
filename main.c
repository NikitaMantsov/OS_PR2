#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));

    int bet;
    int reels[5];
    int i;

    printf("Welcome to the 'Slot Machine' game!\n");

    while (1) {
        printf("Your bet (or 0 to exit): ");
        scanf("%d", &bet);

        if (bet == 0) {
            printf("Game over. Thank you for playing!\n");
            break;
        }

        if (bet < 1) {
            printf("Invalid bet. Please enter a valid bet.\n");
            continue;
        }

        for (i = 0; i < 5; i++) {
            reels[i] = randomInt(1, 9);
            //reels[i] = 1;
            //reels[i] = 7;
        }

        printf("Result: ");
        for (i = 0; i < 5; i++) {
            printf("%d ", reels[i]);
        }
        printf("\n");

        int hasSeven = 0;
        for (i = 0; i < 5; i++) {
            if (reels[i] == 7) {
                hasSeven = 1;
                break;
            }
        }

        if (hasSeven) {
            if (reels[0] == 7 && reels[1] == 7 && reels[2] == 7 && reels[3] == 7 && reels[4] == 7) {
                printf("All numbers are sevens! Your bet is tripled.\n");
                bet *= 3;
            } else {
                printf("At least one seven! Your bet is returned.\n");
            }
        } else if (reels[0] == reels[1] && reels[1] == reels[2] && reels[2] == reels[3] && reels[3] == reels[4]) {
            printf("All numbers are the same! Your bet is doubled.\n");
            bet *= 2;
        } else {
            int sameCount = 0;
            for (i = 0; i < 5; i++) {
                int count = 1;
                for (int j = i + 1; j < 5; j++) {
                    if (reels[i] == reels[j]) {
                        count++;
                    }
                }
                if (count >= 2) {
                    sameCount = 1;
                    break;
                }
            }

            if (sameCount) {
                printf("At least one-third of the numbers are the same! You win your bet.\n");
            } else {
                printf("Sorry, you lose.\n");
                bet = 0;
            }
        }

        printf("Your prize: %d\n", bet);
    }

    return 0;
}
