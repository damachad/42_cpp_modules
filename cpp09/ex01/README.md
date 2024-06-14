# 📐 Reverse Polish Notation (RPN)

## 🚀 Overview

This program reads an RPN expression and computes its result. In [RPN](https://mathworld.wolfram.com/ReversePolishNotation.html), operators follow their operands, eliminating the need for parentheses to define the order of operations.

### 📥 Input
- The program receives a string containing an RPN expression.
- Example: `"3 4 + 2 * 7 /"`

### 📤 Output
- The program outputs the result of the RPN expression.
- For the example above, the output would be: `2`

## ✨ Features

- **Efficient RPN Evaluation:** The calculator efficiently evaluates expressions written in Reverse Polish Notation.
- **Supports Basic Operations:** Handles addition, subtraction, multiplication, and division operations.
- **Error Handling:** Provides error messages for invalid input expressions, including division by zero and unbalanced numbers of operands and operators.
- **Extensible:** Easily extendable for additional functionality or custom operators.

## 🛠️ Usage

1. Clone this repository;
2. Compile the program: `make`;
3. Run: `./RPN <RPN_expression>`; 
This will output the result of the RPN expression.
