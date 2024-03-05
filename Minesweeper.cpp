#include <iostream>
#include <Windows.h>
#include<random>
#include <cstdlib>

//all 4 pillars implemented
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);



//ABSTRACT CLASS:
class Minesweeper
{
	//ENCAPSULATION:
protected:
	int Sides = 0;
	int Mines = 0;
	int Flags = 0;

	void makeMove(int* a, int* b)                       //SIMPLE INPUT (JO ACTUAL MEIN MOUSE CLICK HOTA WO WALA KAM)
	{
		cout << "enter the row number: ";
		cin >> *a;
		cout << "enter the column number: ";
		cin >> *b;


	}

	int checkRange(int rows, int cols)
	{
		if ((rows >= 0) && (rows < Sides) && (cols >= 0) && (cols < Sides))  //HADOOD DEFINE
		{
			return 1;
		}
		else

			return 0;
	}    //base case



	int checkFlag(int rows, int cols, char gameBoard[][16])           //BAHI FLAG HE BHI K NAI
	{
		if (gameBoard[rows][cols] == 'F')
			return 1;
		else
			return 0;
	}   //base case

	void setFlag(int rows, int cols, char gameBoard[][16])
	{
		checkFlag(rows, cols, gameBoard);
		int count = Sides * Sides;

		gameBoard[rows][cols] = 'F';


	}


	int checkMine(int rows, int cols, char board[][16])           //BAHI MINES HE BHI K NAI
	{
		if (board[rows][cols] == '*')
			return 1;
		else
			return 0;
	}   //base case


		//recursive case(indirect)
	int countMines(int rows, int cols, int mines[][2], char dataBoard[][16])
	{
		int count = 0;


		//for tile b:
		if (checkRange(rows - 1, cols) == 1)
		{
			if (checkMine(rows - 1, cols, dataBoard) == 1)
				count++;
		}
		//for tile g:
		if (checkRange(rows + 1, cols) == 1)
		{
			if (checkMine(rows + 1, cols, dataBoard) == 1)
				count++;
		}
		//for tile e:
		if (checkRange(rows, cols + 1) == 1)
		{
			if (checkMine(rows, cols + 1, dataBoard) == 1)
				count++;
		}
		//for tile d:
		if (checkRange(rows, cols - 1) == 1)
		{
			if (checkMine(rows, cols - 1, dataBoard) == 1)
				count++;
		}
		//for tile c:
		if (checkRange(rows - 1, cols + 1) == 1)
		{
			if (checkMine(rows - 1, cols + 1, dataBoard) == 1)
				count++;
		}
		//for tile a:
		if (checkRange(rows - 1, cols - 1) == 1)
		{
			if (checkMine(rows - 1, cols - 1, dataBoard) == 1)
				count++;
		}
		//for tile h:
		if (checkRange(rows + 1, cols + 1) == 1)
		{
			if (checkMine(rows + 1, cols + 1, dataBoard) == 1)
				count++;
		}
		//for tile f:
		if (checkRange(rows + 1, cols - 1) == 1)
		{
			if (checkMine(rows + 1, cols - 1, dataBoard) == 1)
				count++;
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		return count;



	}


	//ye isliye takay ap pheli input pr game na har jao
	void change_first_Mine(int rows, int cols, char board[][16])
	{
		for (int i = 0; i < Sides; i++)
		{
			for (int j = 0; j < Sides; j++)
			{
				if (board[i][j] != '*')
				{
					board[i][j] = '*';
					board[rows][cols] = '-';
					return;
				}
			}
		}
		return;
	}

	void showMines(char realBoard[][16])
	{
		setBoard(realBoard);
		return;
	}



	//PURE VIRTUAL FUNCTION
	virtual void setMines(int mines[][2], char dataBoard[][16]) = 0;



	void setBoard(char gameBoard[][16])
	{

		cout << "   ";

		for (int i = 0; i < Sides; i++)
		{
			cout << i << "  ";    //cols number
		}
		cout << endl;

		for (int i = 0; i < Sides; i++)
		{
			cout << i << "  ";    //rows number
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE); // Set the console background color

			for (int j = 0; j < Sides; j++)
			{
				if (gameBoard[i][j] == '-')
				{
					cout << "   ";
				}
				else if (gameBoard[i][j] == '*')
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_RED); // Set the  color MINES K LIYE
					cout << " * ";
					SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE); // Reset the console background color
				}

				else if (gameBoard[i][j] == 'F')
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);  //SET COLOR
					cout << " F ";                                            // FLAG WALA KAM KRNA ABHI
					SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE); // Reset the console background color
				}

				else
				{
					SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE); // Reset the console background color
					cout << " " << gameBoard[i][j] << " ";
				}

			}

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Reset the console color
			cout << endl;
		}
	}




	//RECURSIVE FUNCTION to  reveal gameBoard
	int checkGametill(char gameBoard[][16], char dataBoard[][16], int mines[][2], int rows, int cols, int* remaining_moves)
	{

		char choice;
		if (gameBoard[rows][cols] != '-')
		{
			return 0;
		}


		if (dataBoard[rows][cols] == '*')
		{
			gameBoard[rows][cols] = '*';
			for (int i = 0; i < Mines; i++)
				gameBoard[mines[i][0]][mines[i][1]] = '*';

			setBoard(gameBoard);
			cout << endl << endl;

			//// Set the console background color to red
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, BACKGROUND_RED);
			cout << "   YOU LOST   ";
			///Reset the console color

			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			cout << endl;

			cout << " DO YOU WANT TO PLAY AGAIN ? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				system("cls");
				cout << "HELLO, PRESS ANY BUTTON TO OPEN MENU SCREEN" << endl;
				chooseLevel();

				playGame();
			}
			else
			{
				cout << "THANKS FOR PLAYING" << endl;
				exit(0);
			}
			return 1;
		}
		else
		{  //giving value of count to the tile
			int count = countMines(rows, cols, mines, dataBoard);

			(*remaining_moves)--;


			gameBoard[rows][cols] = count + '0';
			if (!count)

			{
				//for revealing tile
				//for tile b:
				if (checkRange(rows - 1, cols) == 1)
				{
					if (checkMine(rows - 1, cols, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile g:
				if (checkRange(rows + 1, cols) == 1)
				{
					if (checkMine(rows + 1, cols, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile e:
				if (checkRange(rows, cols + 1) == 1)
				{
					if (checkMine(rows, cols + 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile d:
				if (checkRange(rows, cols - 1) == 1)
				{
					if (checkMine(rows, cols - 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile c:
				if (checkRange(rows - 1, cols + 1) == 1)
				{
					if (checkMine(rows - 1, cols + 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile a:
				if (checkRange(rows - 1, cols - 1) == 1)
				{
					if (checkMine(rows - 1, cols - 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile h:
				if (checkRange(rows + 1, cols + 1) == 1)
				{
					if (checkMine(rows + 1, cols + 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
				//for tile f:
				if (checkRange(rows + 1, cols - 1) == 1)
				{
					if (checkMine(rows + 1, cols - 1, dataBoard) == 0)
						checkGametill(gameBoard, dataBoard, mines, rows - 1, cols, remaining_moves);
				}
			}
			return 0;

		}
	}

public:
	void intializeBoard(char dataBoard[][16], char gameBoard[][16])
	{
		Flags = 0;
		srand(time(NULL));
		for (int i = 0; i < Sides; i++)
		{
			for (int j = 0; j < Sides; j++)
			{
				gameBoard[i][j] = dataBoard[i][j] = '-';
			}
		}

		return;
	}

	void chooseLevel()
	{

		while (1)
		{
			char level;


			cin >> level;

			if (level == 'B' || level == 'b')
			{

				Sides = 9;
				Mines = 10;

			}

			if (level == 'E' || level == 'e')
			{

				Sides = 16;
				Mines = 40;

			}
			if (level == 'L' || level == 'l')
			{
				break;
			}
			return;

		}
	}

	void playGame()
	{


		int x = 0;
		int y = 0;
		int count1 = 0;
		int endGame = 0;

		cout << "		**************************MINESWEEPER**************************		 " << endl;


		cout << "			MENU			" << endl;
		cout << "			Select the Difficulty Level			" << endl;
		cout << "			Press B for BEGINNER (9 * 9 Cells and 10 Mines)			" << endl;
		cout << "			Press E for EXPERT (16 * 16 Cells and 40 Mines)			" << endl;
		cout << "			Press L to exit game		" << endl;


		cout << "		****************************************************************		 " << endl;

		cout << endl;
		cout << endl << endl;
		chooseLevel();

		char dataBoard[16][16];
		char  gameBoard[16][16];

		int  remaining_moves = (16 * 16) - Mines;

		int mines[40][2];
		intializeBoard(dataBoard, gameBoard);
		cout << endl << endl;
		setMines(mines, dataBoard);
		cout << endl << endl;


		cout << endl << endl;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


		// MINES JAB SHOW NAI KRANI YE COMMENT OUT KRDENA
		cout << endl << endl;
		cout << "data board:" << endl;
		showMines(dataBoard);
		cout << endl << endl;


		while (endGame == 0)
		{
			setBoard(gameBoard);

			char ch{};
			cout << "M for move, F to place flag" << endl;
			cin >> ch;
			cout << endl;
			if (ch == 'm' || ch == 'M')
			{
				cout << "ENTER YOUR MOVE as per (rows,cols) with the range of rows and cols being from 0 to 8 " << endl;
				makeMove(&x, &y);
				cout << endl;
			}

			else if (ch == 'f' || ch == 'F')
			{
				int k;
				int l;
				cout << "SPECIFY LOCATION OF FLAG as per (rows,cols) with the range of rows and cols being from 0 to 8" << endl;
				cout << "enter the row number: ";
				cin >> k;
				cout << "enter the col number: ";
				cin >> l;
				setFlag(k, l, gameBoard);
			}
			else
			{
				cout << "Invalid choice. Please try again." << endl;
				cout << endl;
			}


			if (count1 == 0)
			{
				if (checkMine(x, y, dataBoard) == 1)
					change_first_Mine(x, y, dataBoard);
			}
			count1++;
			endGame = checkGametill(gameBoard, dataBoard, mines, x, y, &remaining_moves);

			if ((endGame == 0) && (remaining_moves == 0))
			{
				HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
				cout << "YOU WON ";

				cout << endl;

				///   Reset the console color
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

				endGame = 1;
				if (endGame == 1)
				{
					char choice;
					cout << endl;
					cout << " DO YOU WANT TO PLAY AGAIN?(Y/N)";
					cin >> choice;

					if (choice == 'Y' || choice == 'y')
					{
						system("cls");
						cout << "HELLO, PRESS ANY BUTTON TO OPEN MENU SCREEN" << endl;
						chooseLevel();
						playGame();
					}
					else
					{
						cout << "THANKS FOR PLAYING;" << endl;
						break;
					}

				}
			}
		}



	}


};

class Beginner : public Minesweeper
{
public:
	int Sides = 9;
	int Mines = 10;


	void setMines(int mines[][2], char dataBoard[][16]) override
	{
		int count = 0;
		bool flag[9 * 9];
		//saray meber kept false first:
		memset(flag, false, sizeof(flag));

		while (count < Mines)
		{
			int random = rand() % (Sides * Sides);
			int x = random / Sides;
			int y = random % Sides;

			// Add the mine if no mine is placed at this
			// position on the board
			if (!flag[random])
			{
				mines[count][0] = x;
				mines[count][1] = y;
				dataBoard[x][y] = '*';
				flag[random] = true;
				count++;
			}
		}

	}

};


class Expert : public Minesweeper
{
public:

	int Sides = 16;
	int Mines1 = 40;
	void setMines(int mines[][2], char dataBoard[][16]) override
	{
		int count1 = 0;
		bool flag[16 * 16];
		//saray member kept false first:
		memset(flag, false, sizeof(flag));

		while (count1 < Mines1)
		{

			int random = rand() % (Sides * Sides);
			int x = random / Sides;
			int y = random % Sides;

			// Add the mine if no mine is placed at this
			// position on the board
			if (!flag[random])
			{
				mines[count1][0] = x;
				mines[count1][1] = y;
				dataBoard[x][y] = '*';
				flag[random] = true;
				count1++;
			}
		}
	}


};

int main()
{

	cout << "HELLO, PRESS ANY BUTTON TO OPEN MENU SCREEN" << endl;
	Beginner b1;
	b1.chooseLevel();
	b1.playGame();


	Expert e1;
	e1.chooseLevel();
	e1.playGame();

	return 0;
	system("pause");

}