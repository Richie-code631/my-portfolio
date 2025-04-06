#include <stdio.h>


int main() {
    int x, y;
    char operation;

    //The while loop ensures that the program continues running until terminated by the user.
    while (1) {
        //This prompts the user for the first integer which is x.
        printf("Enter the first integer (x): ");
        if (scanf("%d", &x) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear invalid input
            continue;
        }

        
        printf("Enter the second integer (y): ");
        if (scanf("%d", &y) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n'); // Clear invalid inputs inputed by the user(input buffer)
            continue;
        }

        // This prompt the user for the operational symbol
        printf("Enter an operation (+, -, *, /) or 'q' to quit: ");
        while (getchar() != '\n'); // Clear invalid inputs inputed by the user(input buffer)
        scanf("%c", &operation);

        // This checks for 'q' to quit the program
        if (operation == 'q') {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Perform operation using a switch statement
        switch (operation) {
            case '+':
                printf("%d + %d = %d\n", x, y, x + y);
                break;
            case '-':
                printf("%d - %d = %d\n", x, y, x - y);
                break;
            case '*':
                printf("%d * %d = %d\n", x, y, x * y);
                break;
            case '/':
                if (y != 0) {
                    printf("%d / %d = %.2f\n", x, y, (float)x / y);  //The use of float is to convert the output to a floating number
                } else {
                    printf("Error: Division by zero is not allowed.\n");  //This is to prevent the program from attempting to divide by zero
                }
                break;
            default:
                printf("Error: Invalid operation symbol.\n");  //This displays an error message if the operation symbol is not valid
        }
    }

    return 0;
}







