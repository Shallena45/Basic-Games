#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int chances = 5;
string message = "You have 3 chances!";


int guess_check(char guess, string real_month, string &hide_month)
{
	int match = 0;
	int len = real_month.length();

	for (int i = 0; i < len; i++)
	{
		if (guess == hide_month[i])
		{
			return 0;
		}
		if (guess == real_month[i])
		{
			hide_month[i] = guess;
			match++;
		}
	}
	return match;
}


void hangman(char state)
{
	string head_string = "|";
	string stage = "=";

	if (state == 'f')
	{
		head_string = " ";
	}
	else if (state == 'h')
	{
		stage = " ";
	}

	cout << "\t\t\t\t_______________" << endl;
	cout << "\t\t\t\t       "<<head_string<<"   " << endl;
	cout << "\t\t\t\t       O      |" << endl;
	cout << "\t\t\t\t      /|\\     |" <<"\t   " << message << endl;
	cout << "\t\t\t\t       |      |             /" << endl;
	cout << "\t\t\t\t      / \\     |           O" << endl;
	cout << "\t\t\t\t   =="<<stage<<stage<<stage<<stage<<stage<<"==  |          /|\\ " << endl;
	cout << "\t\t\t\t   |       |  |           |  " << endl;
	cout << "\t\t\t\t   |       |  |          / \\" << endl;
	cout << "\t\t\t\t=====================================" << endl;
}


int main()
{
	char letter;
	string guess_month;
	string months[] = 
	{
		"January" , "February" , "March" , "April" , "May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"
	};

	srand(time(NULL));
	int month_number = rand() % 12;
	guess_month = months[month_number];

	string hidden_month(guess_month.length(), 'X');
	system("cls");

	while (chances != 0)
	{
		hangman('n');
		cout << "\t\t\t\tLife: " << chances << endl;
		cout << "\t\t\t\t" << hidden_month << endl;
		cout << "\t\t\t\tGuess a letter: ";
		cin >> letter;
		system("cls");

		if (guess_check(letter, guess_month, hidden_month) == 0)
		{
			message = "Incorrect Letter!";
			chances--;
		}
		else
		{
			message = "Correct Guess!";
		}

		if (hidden_month == guess_month)
		{
			cout << "You are free (^_^)";
			hangman('f');
			cout << "\t\t\t\tLife : " << chances << endl;
			cout << "\t\t\t\t\tThe month is: " << guess_month << endl;
			break;
		}
	}
	
	if (chances == 0)
	{
		message = "Time for your Punishment (x_x)";
		hangman('h');
		cout << "\t\t\t\tLife : " << chances << endl;
		cout << "\t\t\t\t\tThe month is: " << guess_month << endl;
	}
	return 0;
}