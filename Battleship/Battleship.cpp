#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Constants
const int BOARD_SIZE = 5; // Size of board
const int NUM_SHIPS = 5; // Number of ships

// Global variables
char board[BOARD_SIZE][BOARD_SIZE]; // The game board

// Function prototypes
void initialize(); // Deploy ships
void processSelection(int x, int y, int& numHits); // Process the user's selection
void printBoard(bool showSolution); // Print game board

int main() {
    // Print the author's name and UAID
    cout << "Author: Dylan Pallasigui\n";

    // Initialize the game board
    initialize();

    // Start game
    int numHits = 0;
    int numRounds = 0;
    bool gameOver = false;

    while (!gameOver) {
        // Print board
        printBoard(false);

        // Get user's selection
        int x, y;
        cout << "Enter the x-coordinate (0-4): ";
        cin >> x;
        cout << "Enter the y-coordinate (0-4): ";
        cin >> y;

        // Process user selection
        processSelection(x, y, numHits);

        // Check if game over
        numRounds++;
        gameOver = (numHits == NUM_SHIPS);

        // Quit game if user enters Q or q
        char quit;
        cout << "Enter Q to quit or any other key to continue: ";
        cin >> quit;

        if (quit == 'Q' || quit == 'q') {
            gameOver = true;
        }
    }

    // Print final board
    printBoard(true);

    // Print number of rounds it took to win
    cout << "You " << (numHits == NUM_SHIPS ? "won" : "lost") << " in " << numRounds << " rounds!\n";

    return 0;
}

// Set up game/board
void initialize() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }

    // Deploy the ships
    board[1][1] = 'S';
    board[2][1] = 'S';
    board[3][1] = 'S';
    board[4][1] = 'S';
    board[0][3] = 'S';
}

// Print sol
void printBoard(bool showSolution) {
    cout << "\n  0 1 2 3 4\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        cout << i << " ";
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-' || (board[i][j] == 'S' && !showSolution)) {
                cout << "- ";
            } else {
                cout << board[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// Selection after choosing, check
void processSelection(int x, int y, int &numHits) {
    // Check if coordinates are valid
    if (x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
        cout << "Invalid coordinates. Please enter values between 0 and 4.\n";
        return;
    }

    // Check if user has already selected location
    if (board[x][y] == 'H' || board[x][y] == 'M') {
        cout << "You have already selected this location. Please select a different location.\n";
        return;
    }

    // Check if user hits ship
    if (board[x][y] == 'S') {
        cout << "Hit!\n";
        board[x][y] = 'H';
        numHits++;
    } else {
        cout << "Miss!\n";
        board[x][y] = 'M';
    }
}