# Lexical Analysis

## 📖 Overview
This repository contains an implementation of a **Lexical Analyzer**, which is the first phase of a compiler. The lexical analyzer scans the source code and converts it into a sequence of tokens such as keywords, identifiers, operators, literals, and symbols.

This project is designed to demonstrate the fundamental concepts of **compiler design** and **tokenization**.

---

## 🎯 Features
- Tokenizes source code input
- Identifies:
  - Keywords
  - Identifiers
  - Operators
  - Delimiters / Symbols
  - Numeric and string literals
- Ignores whitespace and comments
- Detects invalid or unrecognized tokens

  🛠️ Technologies Used
- Programming Language: C

---- 
  .
├── src/        # Source code files

      input.txt      # Input source code file (with comments)
      
      output.txt     # Output file after removing comments and tokenized output
      
      RemoveComment.c
      
      LexicalAnlusis.c
      
├── README.md   # Project documentation

---


## ⚙️ Working Procedure

1. The program first opens the source code file from the `input` directory.
2. All comments (single-line and multi-line) are identified and removed.
3. The comment-free source code is written into a file in the `output` directory.
4. This generated output file is then used as the **input** for the lexical analysis phase.
5. The lexical analyzer processes the cleaned code and generates a list of tokens.

---

## 🔁 Workflow

Input Source Code -> Remove Comments -> Clean Code (output file) -> Lexical Analysis -> Token Stream


---

## 🧪 Example

### Input File (with comments)
```c
// This is a single-line comment
int a = 10; /* multi-line comment */

### Output File (after removing comments)

int a = 10;


