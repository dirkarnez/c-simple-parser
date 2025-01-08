c-simple-parser
===============
### TODOs
- [ ] Must be streaming
- [ ] The parsing logic should be generated (prefer node.js) to avoid using third-party
- [ ] The stack should support persistence

### Tutorials
- [grammars-v4/calculator/calculator.g4 at master · antlr/grammars-v4](https://github.com/antlr/grammars-v4/blob/master/calculator/calculator.g4)
- [cpp-iterative-parser/src/main.cpp at main · dirkarnez/cpp-iterative-parser](https://github.com/dirkarnez/cpp-iterative-parser/blob/main/src/main.cpp)
- [antlr4-calculator/src/main/antlr4/nl/arothuis/antlr4calculator/core/parser/Calculator.g4 at master · arothuis/antlr4-calculator](https://github.com/arothuis/antlr4-calculator/blob/master/src/main/antlr4/nl/arothuis/antlr4calculator/core/parser/Calculator.g4)
- [c-html-table-parser/src/main.c at main · dirkarnez/c-html-table-parser](https://github.com/dirkarnez/c-html-table-parser/blob/main/src/main.c)

```c
// 6 * (4 + 2)
// 6 * ((6 + 5 ) * (5 - 2) - (3 / (5 + 2)))
// 6 * @@@ ((6 + 5 ) * (5 - 2) - (3 / (5 + 2)))
// 11 * 3 - @@@(3 / (5 + 2))
// 5 + 2 
struct Program {
    union struct expression_t expressions
}

struct value_t {
    bool is_undefined
    int answer
    int* pending
    unsigned int pending_length
}
```

list of expression_t
each of expression_t 



```
bracketed_expression = '(' + addition_expression | subtraction_expression | multiplication_expression | division_expression  + ')'
addition_expression  = atom + '-' + atom
subtraction_expression = atom + '-' + atom
multiplication_expression = atom + '-' + atom
division_expression = atom + '-' + atom
atom = ${number}
```

### extra
```
message = "Even" if x % 2 == 0 else "Odd"
```