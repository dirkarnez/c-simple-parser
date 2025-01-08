#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *expression;
    int length;
    int pos;
} Parser;

int parseExpression(Parser *parser);

int parseNumber(Parser *parser) {
    int number = 0;
    while (parser->pos < parser->length && isdigit(parser->expression[parser->pos])) {
        number = number * 10 + (parser->expression[parser->pos] - '0');
        parser->pos++;
    }
    return number;
}

int parseFactor(Parser *parser) {
    int result;
    if (parser->expression[parser->pos] == '(') {
        parser->pos++; // skip '('
        result = parseExpression(parser);
        parser->pos++; // skip ')'
    } else {
        result = parseNumber(parser);
    }
    return result;
}

int parseTerm(Parser *parser) {
    int result = parseFactor(parser);
    while (parser->pos < parser->length && (parser->expression[parser->pos] == '*' || parser->expression[parser->pos] == '/')) {
        char op = parser->expression[parser->pos];
        parser->pos++;
        int factor = parseFactor(parser);
        if (op == '*') {
            result *= factor;
        } else {
            result /= factor;
        }
    }
    return result;
}

int parseExpression(Parser *parser) {
    int result = parseTerm(parser);
    while (parser->pos < parser->length && (parser->expression[parser->pos] == '+' || parser->expression[parser->pos] == '-')) {
        char op = parser->expression[parser->pos];
        parser->pos++;
        int term = parseTerm(parser);
        if (op == '+') {
            result += term;
        } else {
            result -= term;
        }
    }
    return result;
}

int evaluate(char *expression) {
    Parser parser = {expression, strlen(expression), 0};
    return parseExpression(&parser);
}

int main() {
    // char expression[256];
    // printf("Enter an expression: ");
    // fgets(expression, sizeof(expression), stdin);
    // expression[strcspn(expression, "\n")] = 0; // remove newline character
    int result = evaluate("3 + 5");
    printf("Result: %d\n", result);
    return 0;
}
