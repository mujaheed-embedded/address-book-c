# 📁 Memory-Optimized Modular Address Book Application in C

A production-ready command-line interface (CLI) Address Book system architected from scratch in pure C. This portfolio repository showcases high-discipline defensive programming paradigms, manual data stream serialization, and rigorous data structure constraints tailored specifically for memory-constrained embedded application runtimes.

---

## 🚀 Key Engineering & Architecture Architectural Pillars

### 1. Robust Defensive Programming & Boundary Guarding
- **Static Memory Guarding:** Implemented rigid constraint vectors directly tracking active stack elements (`contactCount >= 100`) to completely eliminate unindexed data writes and avoid structural array out-of-bounds segmentation errors.
- **Bounded Input Constraints:** Replaced traditional, dangerous string collection utilities with explicit, width-limited stream extractors (`%49[^\n]`, `%14s`) to shield function stack allocation maps from hostile execution overflows or inputs exceeding target structural bounds.
- **Buffer Stream Scrubbing:** Built inline input-stream flush mechanics (`while (getchar() != '\n')`) to purge trailing memory configurations, ensuring continuous execution stability during interactive terminal runtime operations.

### 2. High-Performance Memory Optimization (Low-RAM Overhead)
- **Lightweight Index Mapping:** Re-engineered traditional database display systems. Instead of allocating bulky `struct Contact` object twins directly onto the hardware runtime stack (which risks a fatal Stack Overflow on microcontrollers with small 2KB–4KB limits), this architecture maps a simple, lightweight 400-byte integer pointer index cache.
- **CPU Cycle Reduction:** Algorithmic lookups and in-place Bubble Sort functions swap tiny index map values rather than moving heavy 165-byte structural properties, minimizing memory thrashing and maximizing CPU register cycle performance.

### 3. File System Persistence & Data Handling
- **Manual Data Serialization:** Built custom structured data pipelines using core file operations (`fopen`, `fprintf`, `fscanf`, `fclose`) to systematically stream active database matrices straight into a persistent `.csv` storage disk format.
- **Formatted Scanset Deserialization:** Leveraged precise regex parsing matchers (`%[^,]`) inside automated data loading sequences to correctly parse file content, removing dependencies on heavy third-party parsing tools.

---

## ⚙️ Software Component Architecture

The source engine is built with standard modular separation principles to divide configuration blueprints cleanly from operational driver code:
- **`addressbook.h`:** Architectural blueprint definition; maps explicit data parameters (`struct Contact`, `struct AddressBook`) and declares operational firmware functions.
- **`addressbook.c`:** Core engine implementation managing structured array routines, bound validation checks, database index maps, and data storage logic.
- **`main.c`:** System entry driver. Manages automatic persistent storage initialization, handles input matching lookups, and runs the interactive menu control loop.

---

## 🛠️ System Features & Validation Specs

- **Add Secure Contact:** Performs multi-step validations (guarantees unique phone entries, rejects trailing spaces, verifies alpha-only character arrays, and validates `@gmail.com` syntax frames).
- **Print Specific Target:** Leverages algorithmic string matchers (`strcmp`) to quickly pull and report isolated parameters for a particular user record.
- **Print All Contacts (Sorted):** Renders alphabetically sorted output lists utilizing the memory-saving integer index sorting array.
- **Persistent Save Routine:** Automatically and manually synchronizes all in-memory changes back into the physical persistent CSV tracking ledger.
- **Modify/Delete Engine:** Shifts tracking elements leftwards dynamically to re-index the contiguous structural directory safely without wasting heap addresses or creating empty gaps.

---

## 💻 How to Compile and Execute Locally

To run this application, ensure you have a standard C compiler (like `gcc`) installed on your local machine:

```bash
# Compile using explicit modular linking dependencies
gcc main.c addressbook.c -o addressbook_app

# Execute the binary target file
./addressbook_app
```
