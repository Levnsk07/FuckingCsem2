#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *input;
size_t pos = 0;

double parse_expression();
double parse_term();
double parse_factor();

void skip_whitespace() {
    while (isspace(input[pos])) pos++;
}

double parse_expression() {
    double result = parse_term();
    skip_whitespace();
    while (input[pos] == '+' || input[pos] == '-') {
        char op = input[pos++];
        double term = parse_term();
        if (op == '+') result += term;
        else result -= term;
        skip_whitespace();
    }
    return result;
}

double parse_term() {
    double result = parse_factor();
    skip_whitespace();
    while (input[pos] == '*' || input[pos] == '/') {
        char op = input[pos++];
        double factor = parse_factor();
        if (op == '*') result *= factor;
        else result /= factor;
        skip_whitespace();
    }
    return result;
}

double parse_factor() {
    skip_whitespace();
    if (input[pos] == '(') {
        pos++;
        double result = parse_expression();
        skip_whitespace();
        pos++; // skip ')'
        return result;
    } else if (input[pos] == '-') {
        pos++;
        return -parse_factor();
    } else {
        char *end;
        double result = strtod(input + pos, &end);
        pos = end - input;
        return result;
    }
}

int main() {

    freopen("input.txt", "r", stdin);

    char buffer[500001];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    input = buffer;

    double result = parse_expression();
    printf("%.20f\n", result);

    return 0;
}
