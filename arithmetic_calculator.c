
#include <stdio.h>

int main(void)
{
    int a, b, choice;

    printf("Enter two numbers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("\n===== ARITHMETIC OPERATIONS MENU =====\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus (remainder)\n");
    printf("Enter your choice: ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    switch (choice) {
    case 1:
        printf("Addition is=%d\n", a + b);
        break;
    case 2:
        printf("Subtraction is=%d\n", a - b);
        break;
    case 3:
        printf("Multiplication is=%d\n", a * b);
        break;
    case 4:
        if (b == 0)
            printf("Division by zero is not possible.\n");
        else
            printf("Division is=%.2f\n", (float)a / b);
        break;
    case 5:
        if (b == 0)
            printf("Modulus by zero is not possible.\n");
        else
            printf("Modulus is=%d\n", a % b);
        break;
    default:
        printf("Invalid choice. Please enter a number from 1 to 5.\n");
    }

    return 0;
}
