

test2.java

// Java program for Tic-Tac-Toe game 

import java.util.Random; 

public class TicTacToe 
{ 
	static int[][] board = new int[3][3]; 
	static Random rand = new Random(); 

	// Function to initialize the board 
	static void initBoard() 
	{ 
		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
				board[i][j] = -10; 
		} 
	} 

	// Function to print the board 
	static void printBoard() 
	{ 
		System.out.println(); 

		for (int i = 0; i<3; i++) 
		{ 
			for (int j = 0; j<3; j++) 
			{ 
				if (board[i][j] == -10) 
					System.out.print("- "); 
				else if (board[i][j] == -1) 
					System.out.print("O "); 
				else
					System.out.print("X "); 
			} 
			System.out.println(); 
		} 
	} 

	// Function to check if any player has won 
	static boolean checkWin() 
	{ 
		// Checking for Rows for X or O victory. 
		for (int i = 0; i<3; i++) 
		{ 
			if (board[i][0] == board[i][1] && 
				board[i][1] == board[i][2]) 
			{ 
				if (board[i][0] == -1) 
					return true; 
				else if (board[i][0] == 0) 
					return true; 
			} 
		} 

		// Checking for Columns for X or O victory. 
		for (int i = 0; i<3; i++) 
		{ 
			if (board[0][i] == board[1][i] && 
				board[1][i] == board[2][i]) 
			{ 
				if (board[0][i] == -1) 
					return true; 
				else if (board[0][i] == 0) 
					return true; 
			} 
		} 

		// Checking for Diagonals for X or O victory. 
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
		{ 
			if (board[0][0] == -1) 
				return true; 
			else if (board[0][0] == 0) 
				return true; 
		} 

		if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
		{ 
			if (board[0][2] == -1) 
				return true; 
			else if (board[0][2] == 0) 
				return true; 
		} 

		// Else if none of them have won then return 0 
		return false; 
	} 

	// Function to check if the board is full 
	static boolean isBoardFull() 
	{ 
		for (int i = 0; i<3; i++) 
			for (int j = 0; j<3; j++) 
				if (board[i][j] == -10) 
					return false; 
		return true; 
	} 

	// Function to make move 
	static void makeMove(int x, int y, int player) 
	{ 
		if(x<0 || x>2 || y<0 || y>2) 
		{ 
			System.out.println("Invalid move"); 
			return;