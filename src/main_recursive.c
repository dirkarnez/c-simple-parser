#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *input;
int pos = 0;

int parse_number() {
    int num = 0;
    while (isdigit(input[pos])) {
        num = num * 10 + (input[pos] - '0');
        pos++;
    }
    return num;
}

int parse_expression();

int parse_factor() {
    if (input[pos] == '(') {
        pos++; // consume '('
        int result = parse_expression();
        pos++; // consume ')'
        return result;
    } else {
        return parse_number();
    }
}

int parse_term() {
    int result = parse_factor();
    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos];
        pos++;
        if (op == '*') {
            result *= parse_factor();
        } else {
            result /= parse_factor();
        }
    }
    return result;
}

int parse_expression() {
    int result = parse_term();
    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos];
        pos++;
        if (op == '+') {
            result += parse_term();
        } else {
            result -= parse_term();
        }
    }
    return result;
}

int main() {
    input = "6*(4+2)";//"(1+2)*(3+4)";
    int result = parse_expression();
    printf("Result: %d\n", result);
    return 0;
}