# Student Record Management System

A command-line application for managing student records, built in C using binary file handling for persistent storage (no external database required).

## Features

- **Add** a new student record (ID, Name, Marks) , rejects duplicate IDs
- **Search** for a student by ID
- **Update** an existing student's name and marks
- **Delete** a student record by ID
- **Display** all stored student records
- Menu-driven CLI loop for continuous interaction

## Tech Stack

- **Language:** C
- **Storage:** Binary file I/O (`fread`/`fwrite`) , no database dependency
- **Data structure:** `struct student { int id; char name[100]; float marks; }`

## How to Run

1. Compile:
   ```bash
   gcc student_records.c -o student_records
   ```

2. Run:
   ```bash
   ./student_records
   ```

3. Use the on-screen menu to add, search, update, delete, or display records. Data is persisted to `student.dat` in the same directory, so records remain available across runs.

## Sample Usage

```
 ***MENU*** 
1. Add student 
2. search student 
3. Update Details 
4. delete student 
5. Display all the records 
6. Exit 
Enter your choice: 
1
enter student id: 
101
enter student's name: 
Priya
enter student's marks: 
89.5
Student added! 

 ***MENU*** 
Enter your choice: 
5
--students' records-- 
ID: 101 |Name: Priya |Marks: 89.500000 |
```

## Design Notes

- Update and Delete operations follow a **read-write-temp-file pattern**: records are streamed from `student.dat` into a `temp.dat`, modified/filtered as needed, and the original file is then replaced — a common approach for editing binary files without in-place record shifting.
- Duplicate ID checks run on every `Add` to maintain record uniqueness.

## Possible Improvements

- Input validation (currently assumes well-formed input via `scanf`)
- Replace fixed-size `char name[100]` with safer bounded input handling
- Add sorting/filtering options for the display view
