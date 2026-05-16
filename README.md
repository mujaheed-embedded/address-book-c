# 📁 Memory-Optimized Address Book (Pure C)

A modular, command-line Address Book system built in pure C. This project demonstrates **defensive coding** and **memory optimization** patterns required for embedded firmware engineering.

---

## ⚡ Technical Highlights (5-Second Summary)

- **Memory-Safe Architecture:** Replaced dangerous inputs with bounded string matchers (`%49[^\n]`, `%14s`) to entirely prevent stack buffer overflows.
- **Microcontroller-Optimized Sorting:** Used a lightweight **integer index map** for sorting rather than copying massive structures. This reduced stack RAM overhead from **16,500 bytes to just 400 bytes**—preventing Stack Overflows.
- **Structural Bounds Checking:** Implemented defensive guard clauses (`contactCount >= 100`) to strictly block out-of-bounds memory writes.
- **Data Persistence:** Implemented custom file handling pipelines (`fopen`, `fprintf`, `fscanf`) to save and parse structured database entries inside a `.csv` file.

---

## 🛠️ Tech Stack & Architecture

- **Language:** Pure C / Embedded C paradigms
- **Concepts:** Custom `structs`, Pointer Manipulation, File I/O, Algorithmic Sorting, Modular Project Layout
- **File Structure:** 
  - `addressbook.h` (Data blueprints & function declarations)
  - `addressbook.c` (Core validation, sorting, and data logic)
  - `main.c` (System driver & interactive interface menu loop)

---

## 💻 How to Compile and Run

```bash
gcc main.c addressbook.c -o addressbook_app
./addressbook_app
```
