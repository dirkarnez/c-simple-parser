c-simple-parser
===============
### TODOs
- [ ] The parsing logic should be generated (prefer node.js) to avoid using third-party
- [ ] The stack should support persistence

### Tutorials
- [grammars-v4/calculator/calculator.g4 at master · antlr/grammars-v4](https://github.com/antlr/grammars-v4/blob/master/calculator/calculator.g4)

```c
// 6 * (4 + 2)
struct Program {
    union struct expression_t expressions
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


