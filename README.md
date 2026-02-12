---

# BeboCalc

**BeboCalc** is a minimal arithmetic expression interpreter written in **C**, built to explore low-level parsing, tokenization, and recursive descent evaluation.

This project is designed as a learning-focused interpreter, demonstrating how simple programming language components (lexer + parser) work together while remaining small and readable.

---

## Features

* **Interactive REPL-style prompt**
* Supports integer arithmetic expressions
* **Operators**:

  * `+` (addition)
  * `-` (subtraction)
  * `*` (multiplication)
  * `/` (division)
* **Operator precedence handling**

  * `*` and `/` evaluated before `+` and `-`
* **Whitespace-tolerant parsing**
* **Error handling**:

  * Unknown characters
  * Missing operands
  * Division by zero

---

## How It Works

* **Tokenizer (Lexer)**
  Converts raw input into tokens (`INT` or `OP`).

* **Recursive Descent Parser**

  * `parse()` handles addition and subtraction.
  * `parse_term()` handles multiplication and division.
  * `parse_number()` reads multi-digit integers.

This structure mirrors how real interpreters and compilers process expressions.

---

## Build

Requires a Unix-like system (Linux recommended) and **GCC**.

```sh
gcc interpreter.c -o bebocalc
```

---

## Run

After compiling:

```sh
./bebocalc
```

You’ll see an interactive prompt:

```sh
> 2 + 3 * 4
result: 14
```

---

## Example Usage

```sh
> 10 + 5
result: 15

> 8 * 3 - 4
result: 20

> 20 / 5 + 6
result: 10
```

---

## Notes

* Only **integer arithmetic** is supported.
* No parentheses support (yet).
* The project is intentionally minimal and educational.
* Errors terminate the program.

---

## Future Improvements

* Parentheses support `(` `)`
* Floating-point numbers
* Better error recovery (instead of exiting)
* Unary operators (e.g., negative numbers)
* Variables and assignments

---

## License

This project is under the **MIT License**.

---
