# Problem 5 — Implement car and cdr (Jane Street)

## Problem Statement
`cons(a, b)` constructs a pair. `car(pair)` returns the first element and `cdr(pair)` returns the second. Given the closure-based `cons`, implement `car` and `cdr`.

## Approach — Higher-Order Functions / Church Encoding

`cons` stores `a` and `b` inside a closure that accepts a selector function `f` and returns `f(a, b)`.

- **`car`** passes `(a, b) => a` — selects the first argument.
- **`cdr`** passes `(a, b) => b` — selects the second argument.

This is the lambda-calculus / Church encoding of pairs: data is encoded entirely as functions.

```
car(cons(3, 4))
= cons(3, 4)(f => f selects a)
= f(3, 4) where f = (a,_) => a
= 3
```

In languages without first-class closures (C), we use a plain struct as the equivalent "pair" and accessor functions instead.

## Complexity
- **Time:** O(1)
- **Space:** O(1)
