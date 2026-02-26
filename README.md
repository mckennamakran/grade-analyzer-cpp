# 🎓 Smart Student Grade Analyzer

Author: McKenna Makran

A console-based C++ application that analyzes student grades and generates detailed statistics including averages, pass rate, and grade distribution.

This project demonstrates strong foundational C++ concepts such as modular programming, vectors, input validation, and formatted output.

---

## 📌 Project Overview

The **Smart Student Grade Analyzer** allows users to:

- Enter the number of students
- Input validated marks (0–100)
- Automatically calculate:
  - 📊 Average score  
  - 🥇 Highest score  
  - 🥉 Lowest score  
  - ✅ Pass rate (default passing grade: 60%)
- Display full grade distribution (A–F)
- Present results in a clean, formatted summary

---

## 🛠️ Concepts Demonstrated

This project showcases:

- Functions & function prototypes  
- Passing vectors by reference  
- Const correctness  
- Default parameters  
- Input validation using `cin.fail()`  
- Clearing input buffer using `numeric_limits`  
- Use of STL `vector`  
- Formatted output with `iomanip`  
- Modular and readable program structure  

---

## 🧠 Program Structure

### 1️⃣ Input Handling
- Validates the number of students (must be positive)
- Validates each student mark (must be between 0 and 100)

### 2️⃣ Data Storage
- Uses a `vector<double>` to store student marks dynamically

### 3️⃣ Statistical Calculations
- `calculateAverage()`  
- `findHighest()`  
- `findLowest()`  
- `calculatePassRate()`  

### 4️⃣ Summary Display
- Individual marks (formatted to 2 decimal places)
- Overall statistics
- Grade distribution breakdown

---

## 📊 Grade Distribution Scale

| Grade | Range     |
|-------|-----------|
| A     | 90–100    |
| B     | 80–89     |
| C     | 70–79     |
| D     | 60–69     |
| F     | 0–59      |
