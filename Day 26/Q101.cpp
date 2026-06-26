
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0))); // Seed for random number

	int secretNumber = rand() % 100 + 1; // Random number between 1 and 100
	int guess;

	cout << "===== Number Guessing Game =====" << endl;
	cout << "Guess a number between 1 and 100." << endl;

	do
	{
		cout << "Enter your guess: ";
		if (!(cin >> guess)) {
			cout << "Invalid input. Please enter an integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

		if (guess > secretNumber)
		{
			cout << "Too High! Try Again." << endl;
		}
		else if (guess < secretNumber)
		{
			cout << "Too Low! Try Again." << endl;
		}
		else
		{
			cout << "Congratulations! You guessed the correct number." << endl;
		}

	} while (guess != secretNumber);

	return 0;
}
