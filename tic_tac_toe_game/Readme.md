Tic-Tac-Toe Suite (C Language)

This repository contains two distinct implementations of the classic Tic-Tac-Toe game: a Console-based version that mirrors the classic terminal experience and a GTK3 Graphical User Interface (GUI) version for a modern desktop experience.

📋 Features
1. Console Version (tic_tac_toe_console.c)
Exact PDF Replication: Matches the specific visual layout, prompts, and win messages found in the project documentation.

Positional Input: Uses a numeric mapping system (1–9) for quick move entry.

ASCII Grid: Renders the board using standard characters like | and --- for cross-platform terminal compatibility.

Quit Functionality: Allows users to exit the game at any time by entering 'q' or 'Q'.

2. GUI Version (tic_tac_toe.c)
Interactive UI: Built with the GTK3 toolkit, featuring a windowed application with a 3x3 button grid.

Dynamic Feedback: Includes a status label that updates the current turn and announces the winner with emojis.

State Management: Automatically disables buttons after they are clicked to prevent invalid moves.

Instant Reset: Features a "Reset" button to clear the board and restart the game without relaunching the app.

3. Core Game Logic (Both Versions)
Automatic Win Detection: Both versions scan rows, columns, and diagonals to identify a winner immediately.

Draw Handling: The logic identifies a "Draw" or "Tie" state when all 9 moves are completed without a winner.

This README is designed for a GitHub repository that includes both the GTK3 Graphical Version and the Console Version, as these two files combined perfectly represent the logic and the visual output found in your documents.

Tic-Tac-Toe Suite (C Language)
This repository contains two distinct implementations of the classic Tic-Tac-Toe game: a Console-based version that mirrors the classic terminal experience and a GTK3 Graphical User Interface (GUI) version for a modern desktop experience.

📋 Features
1. Console Version (tic_tac_toe_console.c)
Exact PDF Replication: Matches the specific visual layout, prompts, and win messages found in the project documentation.

Positional Input: Uses a numeric mapping system (1–9) for quick move entry.

ASCII Grid: Renders the board using standard characters like | and --- for cross-platform terminal compatibility.

Quit Functionality: Allows users to exit the game at any time by entering 'q' or 'Q'.

2. GUI Version (tic_tac_toe.c)
Interactive UI: Built with the GTK3 toolkit, featuring a windowed application with a 3x3 button grid.

Dynamic Feedback: Includes a status label that updates the current turn and announces the winner with emojis.

State Management: Automatically disables buttons after they are clicked to prevent invalid moves.

Instant Reset: Features a "Reset" button to clear the board and restart the game without relaunching the app.

3. Core Game Logic (Both Versions)
Automatic Win Detection: Both versions scan rows, columns, and diagonals to identify a winner immediately.

Draw Handling: The logic identifies a "Draw" or "Tie" state when all 9 moves are completed without a winner.

Turn Cycling: Systems are in place to alternate turns strictly between Player X and Player O.

🛠 Prerequisites
To compile these programs, you will need a C compiler (like gcc). For the GUI version, the GTK3 development library is required:
Windows: Install via MSYS2: pacman -S mingw-w64-x86_64-gtk3
This README is designed for a GitHub repository that includes both the GTK3 Graphical Version and the Console Version, as these two files combined perfectly represent the logic and the visual output found in your documents.

Tic-Tac-Toe Suite (C Language)
This repository contains two distinct implementations of the classic Tic-Tac-Toe game: a Console-based version that mirrors the classic terminal experience and a GTK3 Graphical User Interface (GUI) version for a modern desktop experience.

📋 Features
1. Console Version (tic_tac_toe_console.c)
Exact PDF Replication: Matches the specific visual layout, prompts, and win messages found in the project documentation.

Positional Input: Uses a numeric mapping system (1–9) for quick move entry.

ASCII Grid: Renders the board using standard characters like | and --- for cross-platform terminal compatibility.

Quit Functionality: Allows users to exit the game at any time by entering 'q' or 'Q'.

2. GUI Version (tic_tac_toe.c)
Interactive UI: Built with the GTK3 toolkit, featuring a windowed application with a 3x3 button grid.

Dynamic Feedback: Includes a status label that updates the current turn and announces the winner with emojis.

State Management: Automatically disables buttons after they are clicked to prevent invalid moves.

Instant Reset: Features a "Reset" button to clear the board and restart the game without relaunching the app.

3. Core Game Logic (Both Versions)
Automatic Win Detection: Both versions scan rows, columns, and diagonals to identify a winner immediately.

Draw Handling: The logic identifies a "Draw" or "Tie" state when all 9 moves are completed without a winner.

Turn Cycling: Systems are in place to alternate turns strictly between Player X and Player O.

🛠 Prerequisites
To compile these programs, you will need a C compiler (like gcc). For the GUI version, the GTK3 development library is required:

Linux (Ubuntu/Debian): sudo apt-get install libgtk-3-dev

macOS: brew install gtk+3

Windows: Install via MSYS2: pacman -S mingw-w64-x86_64-gtk3

🚀 Compilation & Usage
Console Version
Bash

gcc tic_tac_toe_console.c -o ttt_console
./ttt_console
GUI Version
Bash

gcc tic_tac_toe.c -o ttt_gui `pkg-config --cflags --libs gtk+-3.0`
./ttt_gui



Turn Cycling: Systems are in place to alternate turns strictly between Player X and Player O.
