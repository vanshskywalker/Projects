#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print_usage(const char *prog) {
    printf("Usage:\n");
    printf("  %s <num1> <operator> <num2>\n", prog);
    printf("Operators: +  -  *  /  %%\n");
    printf("Examples:\n");
    printf("  %s 5 + 3\n", prog);
    printf("  %s 10 / 4\n", prog);
    printf("  %s 15 %% 6\n", prog);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage(argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[3]);
    char op = argv[2][0];
    int result;
    int valid = 1;

    switch (op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': 
            if (b == 0) {
                printf("Error: division by zero\n");
                return 1;
            }
            result = a / b;
            break;
        case '%':
            if (b == 0) {
                printf("Error: modulo by zero\n");
                return 1;
            }
            result = a % b;
            break;
        default:
            printf("Error: unknown operator '%c'\n", op);
            valid = 0;
    }

    if (valid) {
        printf("%d %c %d = %d\n", a, op, b, result);
    }
    return 0;
}
