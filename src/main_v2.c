#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    char *expression;
    int length;
    unsigned int pos;
} Parser;

int parser_parse(Parser *parser);


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
        result = parser_parse(parser);
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

void parser_set_pos(Parser *parser, unsigned int new_pos) {
    parser->pos = new_pos;
}

unsigned int parser_current_pos(Parser *parser) {
    return parser->pos;
}


char parser_get_char_at(Parser *parser, unsigned int at) {
    return parser->expression[at];
}

int parser_parse_number(Parser *parser) {
    return 0;
}

int parser_parse(Parser *parser) {
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
            unsigned int at = current_pos; 
            int operand = 0;
            char scanning = '\0';
            for (; is_digit((scanning = parser_get_char_at(parser, at))); at++) {
                operand = operand * 10 + (scanning - '0');
        
            }
            printf("operand is %d\n", operand);
            parser_set_pos(parser, at);
        } else if (is_operator(current_char)) {
            // unsigned int at = current_pos; 
            // int operand = 0;
            // for (; is_digit(parser_get_char_at(parser, at)); at++) {
            //     operand = operand * 10 + (parser_get_char_at(parser, at) - '0');
        
            // }
            // printf("operand is %d", operand);
            // parser_set_pos(parser, at);
        }

                   
            // while (isdigit(c)) {
                
            //     c = expression[++i];
            // }
            // operandStack.push(operand);
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
    Parser parser = {expression, strlen(expression), 0};
    return parser_parse(&parser);
}

int main() {
    // char expression[256];
    // printf("Enter an expression: ");
    // fgets(expression, sizeof(expression), stdin);
    // expression[strcspn(expression, "\n")] = 0; // remove newline character
    int result = evaluate("37 + 5");
    printf("Result: %d\n", result);
    return 0;
}
