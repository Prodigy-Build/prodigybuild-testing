

test2.java

// Java program for Tic-Tac-Toe game 
  
import java.util.Scanner; 
  
public class TicTacToe { 
  
    // Instance Variables 
    static char[][] board = new char[3][3]; 
    static Scanner sc = new Scanner(System.in); 
  
    // Main Method 
    public static void main(String[] args) { 
        // Initialize board 
        initializeBoard(); 
  
        // Play the game 
        playGame(); 
    } 
  
    // Method to initialize board 
    public static void initializeBoard() { 
        // Fill board with spaces 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                board[i][j] = ' '; 
            } 
        } 
    } 
  
    // Method to print board 
    public static void printBoard() { 
        System.out.println("-------------"); 
  
        for (int i = 0; i < 3; i++) { 
            System.out.print("| "); 
            for (int j = 0; j < 3; j++) { 
                System.out.print(board[i][j] + " | "); 
            } 
            System.out.println(); 
            System.out.println("-------------"); 
        } 
    } 
  
    // Method to play the game 
    public static void playGame() { 
        // Variables to keep track of turns 
        boolean XTurn = true; 
        int turn = 0; 
  
        // Keep playing until game is over 
        while (turn < 9) { 
            if (XTurn) { 
                System.out.println("X's turn"); 
                takeInput('X'); 
            } 
            else { 
                System.out.println("O's turn"); 
                takeInput('O'); 
            } 
  
            // Print board 
            printBoard(); 
  
            // Check for win 
            if (checkWin()) { 
                System.out.println("Game Over!"); 
                System.out.println((XTurn ? "X" : "O") + " wins!"); 
                break; 
            } 
  
            // No win, then change turn 
            XTurn = !XTurn; 
            turn++; 
        } 
  
        // If game is draw 
        if (turn == 9) { 
            System.out.println("Game Over!"); 
            System.out.println("It's a draw!"); 
        } 
    } 
  
    // Method to take input 
    public static void takeInput(char player) { 
        boolean inputTaken = false; 
  
        while (!inputTaken) { 
            System.out.println("Enter x and y coordinates: "); 
            int x = sc.nextInt(); 
            int y = sc.nextInt(); 
  
            // Check if cell is empty 
            if (board[x][y] == ' ') { 
                board[x][y] = player; 
                inputTaken = true; 
            } 
            else { 
                System.out.println("Cell already filled.\nPlease choose another cell"); 
            } 
        } 
    } 
  
    // Method to check if there is a win 
    public static boolean checkWin() { 
        // Check for all rows 
        for (int i = 0; i < 3; i++) { 
            if (checkRowCol(board[i][0], board[i][1], board[i][2]) == true) { 
                return true; 
            } 
        } 
  
        // Check for all columns 
        for (int i = 0; i < 3; i++) { 
            if (checkRowCol(board[0][i], board[1][i], board[2][i]) == true) { 
                return true; 
            } 
        } 
  
        // Check for diagonals 
        if (checkRowCol(board[0][0], board[1][1], board[2][2]) == true) { 
            return true; 
        } 
        if (checkRowCol(board[0][2], board[1][1], board[2][0]) == true) { 
            return true; 
        } 
  
        // No win 
        return false; 
    } 
  
    // Method to check if all three values are same (and not empty) 
    public static boolean checkRowCol(char c1, char c2