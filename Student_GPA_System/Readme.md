FUUAST Student GPA Record System
A graphical user interface (GUI) application developed in C using the GTK library. This project is built using Function-Oriented Programming (FOP) principles, focusing on modularity, structured data, and event-driven logic.

Project Overview
The system provides a desktop interface for users to input and manage student academic records. It allows for the entry of personal and academic details, which are then stored in memory and displayed dynamically within the application.

Key Features
Comprehensive Data Entry: Includes dedicated input fields for Name, Father Name, Roll Number, Academic Program, Semester, and GPA.

Structured Data Storage: Utilizes C struct to group student information into a single data type for efficient management.

Dynamic Record Display: Features a non-editable GtkTextView that automatically updates to show a list of all added students.

Input Handling: Uses standard C functions like atof() to convert string inputs from the GUI into numerical data for GPA processing.

Responsive Layout: Employs a GtkGrid container to ensure all labels, entries, and buttons are organized in a clean, professional alignment.

Fundamentals of Programming (FOP) Highlights
Modular Functions: The logic is separated into distinct blocks, such as main() for UI initialization and add_student() for data processing.

Event-Driven Architecture: Uses the GTK signal system (g_signal_connect) to trigger specific procedures when a user interacts with the "Add Student" button.

Global State Management: Manages an array of structures and a counter to keep track of the application's data throughout its lifecycle.

Compilation and Execution
To run this project, ensure you have the GTK development environment installed. Use the following command to compile:

Bash

gcc `pkg-config --cflags gtk+-3.0` -o gpa_system student_management_system.c `pkg-config --libs gtk+-3.0`
./gpa_system
