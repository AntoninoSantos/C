#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char randomColour()
{
    char colours[6] = {'Y', 'B', 'G', 'R', 'P', 'W'};

    return colours[rand() % 6];
}

void mastermind(int chooseSequence);

void fillBoard(char board[11][4]);

void printBoard(char board[11][4]);

void writeSequence(char sequence[4]);

void generateSequence(char sequence[4]);

void printSequence(char sequence[4]);

int isAnswerCorrect(char sequence[4], char answer[4], int *correctColours);

int main()
{
    int op;

    srand(time(NULL));

    printf("Welcome to Mastermind!\n\n");

    do
    {
        printf("1 - Play selected sequence\n");
        printf("2 - Play random sequence\n");
        printf("0 - Exit\n");
        printf("Option: ");
        scanf(" %d", &op);

        switch (op)
        {
        case 1:
            mastermind(1);
            break;

        case 2:
            mastermind(0);
            break;

        case 0:
            printf("Goodbye!\n\n");
            break;

        default:
            printf("Please select a valid option\n\n");
            break;
        }
    } while (op != 0);
}

void mastermind(int chooseSequence)
{
    int checkSequence;
    char sequence[4];
    char board[11][4];

    fillBoard(board);

    if (chooseSequence)
    {
        writeSequence(sequence);
    }
    else
    {
        generateSequence(sequence);
    }

    printf("Check sequence (1 - Yes/0 - No): ");
    scanf(" %d", &checkSequence);

    if (checkSequence)
    {
        printSequence(sequence);
    }

    for (int i = 0; i < 11; i++)
    {
        int correctColours = 0;
        
        printBoard(board);

        for (int j = 0; j < 4; j++)
        {
            char colour;

            printSequence(board[i]);

            printf("Colour %d (Y, B, G, R, P, W): ", j + 1);
            scanf(" %c", &colour);

            if (colour != 'Y' && colour != 'B' && colour != 'G' && colour != 'R' && colour != 'P' && colour != 'W')
            {
                printf("Please select a valid colour\n\n");

                j--;
            }
            else
            {
                board[i][j] = colour;
            }
        }

        if(isAnswerCorrect(sequence, board[i], &correctColours))
        {
    	    printBoard(board);

            printSequence(sequence);

            printf("CONGRATULATIONS! YOU WON!\n\n");

            return;
        }
        else
        {
            printf("You've got %d correct colours\n\n", correctColours);
        }
    }

    printf("GAME OVER\n\n");

    printBoard(board);

    printf("The correct sequence was: ");

    printSequence(sequence);
}

void fillBoard(char board[11][4])
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[11][4])
{
    for (int i = 0; i < 11; i++)
    {
        printf("[");

        for (int j = 0; j < 4; j++)
        {
            printf("%c", board[i][j]);

            if (j != 3)
            {
                printf("|");
            }
        }

        printf("]\n");
    }

    printf("\n");
}

void writeSequence(char sequence[4])
{
    for (int i = 0; i < 4; i++)
    {
        char colour;

        printf("Colour %d (Y, B, G, R, P, W): ", i + 1);
        scanf(" %c", &colour);

        if (colour != 'Y' && colour != 'B' && colour != 'G' && colour != 'R' && colour != 'P' && colour != 'W')
        {
            printf("Please select a valid colour\n\n");

            i--;
        }
        else
        {
            sequence[i] = colour;
        }
    }
}

void generateSequence(char sequence[4])
{
    for (int i = 0; i < 4; i++)
    {
        sequence[i] = randomColour();
    }
}

void printSequence(char sequence[4])
{
    printf("[");

    for (int i = 0; i < 4; i++)
    {
        printf("%c", sequence[i]);

        if (i != 3)
        {
            printf("|");
        }
    }

    printf("]\n\n");
}

int isAnswerCorrect(char sequence[4], char answer[4], int *correctColours)
{
    for (int i = 0; i < 4; i++)
    {
        if (sequence[i] == answer[i])
        {
            (*correctColours)++;
        }
    }
    
    return (*correctColours) == 4;
}