#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *expression;
    int length;
    unsigned int pos;
    unsigned int second_pos;
} Parser;

int parseExpression(Parser *parser);


bool is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool is_whitespace(char c) {
    return c == 0x20 || c == 0x9 || c == 0xD;
}

bool is_digit(char c) {
    return c >= 0x30 && c <= 0x39;
}

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

bool still_has_content(Parser *parser) {
    return parser->pos < parser->length;
}

char parser_get_current_char(Parser *parser) {
    return parser->expression[parser->pos];
}

void parser_next_pos(Parser *parser) {
    parser->pos++;
}

unsigned int parser_current_pos(Parser *parser) {
    return parser->pos;
}



int parseExpression(Parser *parser) {
    // int result = parseTerm(parser);
    for (
        unsigned int previous_pos = 0;
        still_has_content(parser); 
        parser_next_pos(parser) 
    ) 
    {
        unsigned int current_pos = parser_current_pos(parser);
        char current_char = parser_get_current_char(parser);
        if (is_whitespace(current_char)) {
            continue;;
        }

        if (is_digit(current_char)) {
            
            int number = 0;
            printf("%c", current_char);
        }
    }

    // ->expression[parser->pos] == '+' || parser->expression[parser->pos] == '-')) {
    //     char op = parser->expression[parser->pos];
    //     parser->pos++;
    //     int term = parseTerm(parser);
    //     if (op == '+') {
    //         result += term;
    //     } else {
    //         result -= term;
    //     }
    // }
    // return result;
    return 0;
}

int evaluate(char *expression) {
    Parser parser = {expression, strlen(expression), 0, 0};
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
