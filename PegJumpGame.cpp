#include <stdio.h>
#include <ctype.h>
#pragma warning(disable:4996)
/*
Peg Jump Game
System: Windows 10, Visual Studio
Author: Eric Lo
*/


//Function to print out the heading
void heading() {
	printf("Author: Eric Lo\n");
	printf("Peg Jump\n\n");
	return;
}


//Function for the intro to peg jump
void intro() {
	//Intro
	printf("This program represents the peg jumping puzzle.\n\n");
	printf("The board starts out with a single blank position, represented by\n");
	printf("the 'O'.  To make a move, select the letter of the peg to be moved,\n");
	printf("then the letter of the destination position. (e.g. the first move\n");
	printf("might be: d a, meaning we move peg 'd' over some peg into blank position 'a'.)\n");
	printf("A peg must be able to jump over an adjacent peg into a blank for a\n");
	printf("move to be valid.  The jumped peg is then removed from the board.\n");
	printf("The game is over when there are no valid moves left to be made, or\n");
	printf("when there is a single peg left.\n\n");
	printf("At any point enter 'x' to exit the program.\n");

	return;
}


//Function that will display the board
void pegBoard(char p1, char p2, char p3, char p4, char p5, char p6, char p7, char p8,
	char p9, char p10, char p11, char p12, char p13, char p14, char p15) {

	//Print a line to make indication or seperate boards
	printf("------------------------------------------\n");
	//Now print the board
	printf("     Board           Positions \n");
	printf("       %c                 A  \n", p1);
	printf("      %c %c               B C  \n", p2, p3);
	printf("     %c %c %c             D E F  \n", p4, p5, p6);
	printf("    %c %c %c %c           G H I J  \n", p7, p8, p9, p10);
	printf("   %c %c %c %c %c         K L M N O  \n\n", p11, p12, p13, p14, p15);

	return;
}


//Function that will set any imputted piece to that location
void setPiece(char pieceToSet, char setLocation, char *p1, char *p2, char *p3, char *p4,
	char *p5, char *p6, char *p7, char *p8, char *p9, char *p10, char *p11, char *p12,
	char *p13, char *p14, char *p15) {

	//Create switch statement that will determine which piece will have the pieceToSet at
	switch (setLocation) {
		//Each case corresponding to the 30 characters 
	case 'A': *p1 = pieceToSet; break;
	case 'B': *p2 = pieceToSet; break;
	case 'C': *p3 = pieceToSet; break;
	case 'D': *p4 = pieceToSet; break;
	case 'E': *p5 = pieceToSet; break;
	case 'F': *p6 = pieceToSet; break;
	case 'G': *p7 = pieceToSet; break;
	case 'H': *p8 = pieceToSet; break;
	case 'I': *p9 = pieceToSet; break;
	case 'J': *p10 = pieceToSet; break;
	case 'K': *p11 = pieceToSet; break;
	case 'L': *p12 = pieceToSet; break;
	case 'M': *p13 = pieceToSet; break;
	case 'N': *p14 = pieceToSet; break;
	case 'O': *p15 = pieceToSet; break;

	case 'a': *p1 = pieceToSet; break;
	case 'b': *p2 = pieceToSet; break;
	case 'c': *p3 = pieceToSet; break;
	case 'd': *p4 = pieceToSet; break;
	case 'e': *p5 = pieceToSet; break;
	case 'f': *p6 = pieceToSet; break;
	case 'g': *p7 = pieceToSet; break;
	case 'h': *p8 = pieceToSet; break;
	case 'i': *p9 = pieceToSet; break;
	case 'j': *p10 = pieceToSet; break;
	case 'k': *p11 = pieceToSet; break;
	case 'l': *p12 = pieceToSet; break;
	case 'm': *p13 = pieceToSet; break;
	case 'n': *p14 = pieceToSet; break;
	case 'o': *p15 = pieceToSet; break;
	}

}


//Function that will get the corresponding desired piece the user wants
char getPiece(char pieceToGet, char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {

	//Another switch statement that will translate the user imput to the corresponding piece
	switch (pieceToGet) {
		// 30 case statements for each piece
	case 'A': return p1; break;
	case 'B': return p2; break;
	case 'C': return p3; break;
	case 'D': return p4; break;
	case 'E': return p5; break;
	case 'F': return p6; break;
	case 'G': return p7; break;
	case 'H': return p8; break;
	case 'I': return p9; break;
	case 'J': return p10; break;
	case 'K': return p11; break;
	case 'L': return p12; break;
	case 'M': return p13; break;
	case 'N': return p14; break;
	case 'O': return p15; break;

	case 'a': return p1; break;
	case 'b': return p2; break;
	case 'c': return p3; break;
	case 'd': return p4; break;
	case 'e': return p5; break;
	case 'f': return p6; break;
	case 'g': return p7; break;
	case 'h': return p8; break;
	case 'i': return p9; break;
	case 'j': return p10; break;
	case 'k': return p11; break;
	case 'l': return p12; break;
	case 'm': return p13; break;
	case 'n': return p14; break;
	case 'o': return p15; break;
	}

}


//Function that will move the desired pieces the user wants
void movePieces(char from, char to, char *p1, char *p2, char *p3, char *p4, char *p5, char *p6,
	char *p7, char *p8, char *p9, char *p10, char *p11, char *p12, char *p13, char *p14,
	char *p15) {

	//First gets the piece that we are from (should be a '+')
	char fromPiece = getPiece(from, *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11,
		*p12, *p13, *p14, *p15);
	//Now set that piece to 'to'
	setPiece(fromPiece, to, &*p1, &*p2, &*p3, &*p4, &*p5, &*p6, &*p7, &*p8, &*p9, &*p10, &*p11,
		&*p12, &*p13, &*p14, &*p15);

	//Figure out what the jumped piece is
	char jumpedPiece = ((toupper(from) + toupper(to)) / 2);
	//Set the jumped piece to 'o'
	setPiece('o', jumpedPiece, &*p1, &*p2, &*p3, &*p4, &*p5, &*p6, &*p7, &*p8, &*p9, &*p10, &*p11,
		&*p12, &*p13, &*p14, &*p15);

	//Sets the piece where the user is coming from to 'o'
	setPiece('o', from, &*p1, &*p2, &*p3, &*p4, &*p5, &*p6, &*p7, &*p8, &*p9, &*p10, &*p11,
		&*p12, &*p13, &*p14, &*p15);
}


//Function that will determine the number of pegs left
int pegsLeft(char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {

	//Declare variable for number of pegs
	int pegNumber = 0;

	//Adds one to pegNumber if a peg is detected
	if (p1 == '+') { pegNumber = pegNumber + 1; }
	if (p2 == '+') { pegNumber = pegNumber + 1; }
	if (p3 == '+') { pegNumber = pegNumber + 1; }
	if (p4 == '+') { pegNumber = pegNumber + 1; }
	if (p5 == '+') { pegNumber = pegNumber + 1; }
	if (p6 == '+') { pegNumber = pegNumber + 1; }
	if (p7 == '+') { pegNumber = pegNumber + 1; }
	if (p8 == '+') { pegNumber = pegNumber + 1; }
	if (p9 == '+') { pegNumber = pegNumber + 1; }
	if (p10 == '+') { pegNumber = pegNumber + 1; }
	if (p11 == '+') { pegNumber = pegNumber + 1; }
	if (p12 == '+') { pegNumber = pegNumber + 1; }
	if (p13 == '+') { pegNumber = pegNumber + 1; }
	if (p14 == '+') { pegNumber = pegNumber + 1; }
	if (p15 == '+') { pegNumber = pegNumber + 1; }

	return (pegNumber);
}


//Function that will show the score board with the message
void scoreBoard(int pegCount) {

	//First create the table
	printf("   Pegs Left |           Rating\n");
	printf("-------------|--------------------------------\n");
	printf("      >4     |           Horrible\n");
	printf("       4     |           Poor\n");
	printf("       3     |           Meh\n");
	printf("       2     |           Pretty Good\n");
	printf("       1     |     Smartest Person on Earth\n\n");

	//Now give the user their rating 
	if (pegCount > 4) {
		printf("You had %d pegs left. You are horrible at this game.\n\n", pegCount);
	}

	if (pegCount == 4) {
		printf("You had %d pegs left. You are poor at this game.\n\n", pegCount);
	}

	if (pegCount == 3) {
		printf("You had %d pegs left. Meh, an average score.\n\n", pegCount);
	}

	if (pegCount == 2) {
		printf("You had %d pegs left. You are pretty good this game.\n\n", pegCount);
	}

	if (pegCount == 1) {
		printf("You had %d pegs left. You are the smartest person on Earth!! (Don't take it to seriously).\n\n", pegCount);
	}

	printf("Thanks for playing!!\n");
}


//Function that checks if entered from char is valid
int checkFromChar(char from) {
	//Convert the char in from to an int
	int fromInt = from;

	//Check if the from char is valid
	if ((fromInt <= 79 && fromInt >= 65) || (fromInt <= 111 && fromInt >= 97)) {
		return 1;
	}
	else {
		printf("You've entered an invalid piece to move from.\n");
		return 0;
	}
}


//Function that checks if entered to char is valid
int checkToChar(char to) {
	//Similar steps taken in checkFromChar
	int toInt = to;

	if ((toInt <= 79 && toInt >= 65) || (toInt <= 111 && toInt >= 97)) {
		return 1;
	}
	else {
		printf("You've entered an invalid piece to move to.\n");
		return 0;
	}
}


//Function that checks if piece user is moving from is a peg
int checkForPegFrom(char from, char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {
	//First get the char that is in from
	char fromChar = getPiece(from, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

	//Now see if that char is a peg
	if (fromChar == '+') {
		return 1;
	}
	else {
		printf("The piece you have chosen from is not a peg.\n");
		return 0;
	}
}


//Function that checks if piece use is moving to is open
int checkForSpace(char to, char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {
	//Similar steps taken for checkForPegFrom
	char toChar = getPiece(to, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

	if (toChar == 'o') {
		return 1;
	}
	else {
		printf("The piece you are moving to is occupied.\n");
		return 0;
	}
}


//Function that checks if the jumped piece is a peg
int checkForPegMid(char from, char to, char p1, char p2, char p3, char p4, char p5, char p6, char p7,
	char p8, char p9, char p10, char p11, char p12, char p13, char p14, char p15) {
	//Similar steps taken for the the previous two functions, only need to calculate the middle piece
	int jumpedPiece = ((toupper(from) + toupper(to)) / 2);
	//Now get the jumpedPiece
	char jumpedChar = getPiece(jumpedPiece, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

	//Determine if jumped piece is a peg
	if (jumpedChar == '+') {
		return 1;
	}
	else {
		printf("The piece you are trying to jump is not a peg.\n");
		return 0;
	}
}


//Main Function
int main() {

	//Create the 15 char variables
	char p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15;
	//Set char p2-p15 to +
	p2 = p3 = p4 = p5 = p6 = p7 = p8 = p9 = p10 = p11 = p12 = p13 = p14 = p15 = '+';
	//Set char p1 = o
	p1 = 'o';
	/*Also create char variables named from and to to indicate where the user
	wants to move from and to
	*/
	char from, to;
	//Need variable for number of pegs
	int pegCount = 14;
	//Variables that will help check if move is valid
	int checker = 0;
	int fromCheck = 0;
	int toCheck = 0;
	int pegCheck = 0;
	int spaceCheck = 0;
	int midCheck = 0;

	//Start by including heading, intro, and the peg board
	heading();
	intro();
	pegBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

	//The loop that will function as the game
	//As long as there is more than one peg, the game will keep going unless X or x is entered
	while (pegCount != 1) {
		//Prompt of move
		printf("Enter your move: ");
		scanf(" %c", &from);
		//Each imput is checked to see if they are X or x
		if (from == 'X' || from == 'x') {
			break;
		}

		scanf(" %c", &to);
		if (to == 'X' || to == 'x') {
			break;
		}

		//While loop to check if move is valid, if not prompts user again for imput
		while (checker != 1) {
			fromCheck = checkToChar(from);
			toCheck = checkToChar(to);
			pegCheck = checkForPegFrom(from, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
			midCheck = checkForPegMid(from, to, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
			spaceCheck = checkForSpace(to, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

			//If all checks are 1, then checker will be set to 1 and the loop will stop
			if (fromCheck == 1 && toCheck == 1 && pegCheck == 1 && midCheck == 1 && spaceCheck == 1) {
				break;
			}
			//If not satisfied, imput is required again
			else {
				checker = 0;
				printf("Please try again\n");
				printf("Enter valid characters please: ");
				scanf(" %c", &from);
				scanf(" %c", &to);
				printf("\n");

				if (from == 'X' || from == 'x') {
					return 0;
				}
				if (to == 'X' || to == 'x') {
					return 0;
				}
			}
		}

		//Just adding spaces
		printf("\n\n");

		//Moves the piece and displays the board afterwards
		movePieces(from, to, &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &p9, &p10, &p11, &p12,
			&p13, &p14, &p15);

		pegBoard(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);

		//Gets the number of pegs one the board, also shows the user the number of pegs left
		pegCount = pegsLeft(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
		printf("There are %d pegs on the board.\n\n", pegCount);

	}

	//Display Scoreboard
	scoreBoard(pegCount);

	return 0;
}
