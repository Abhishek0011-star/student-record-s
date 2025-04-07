# student-record-s
Student Record System in C
This is a simple Student Record System written in C that allows you to perform basic CRUD (Create, Read, Update, Delete) operations on student data using file handling. Each student record contains a roll number, name, and marks. All data is stored persistently in a binary file.

Features
Add a new student record

View all student records

Search for a student by roll number

Update an existing student record

Delete a student record

Data persistence using file handling (students.dat)

Prerequisites
To compile and run the program, you need:

A C compiler (e.g., GCC)

Compilation
Use the following command to compile the program:

bash
Copy
Edit
gcc student_record.c -o student_record
Running the Program
After compilation, run the program using:

bash
Copy
Edit
./student_record
Program Menu
When you run the program, you will see a menu like this:

pgsql
Copy
Edit
--- Student Record System ---
1. Add Student
2. View Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
Enter the corresponding number to perform an operation.

File Information
Student data is stored in a binary file named students.dat.

Temporary file temp.dat is used during delete operations.
