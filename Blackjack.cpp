/*Main source for running the main program.

	Blackjack.cpp
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Runs the main, seeds the random and calls some functions to make a simple Blackjack game.
*/
#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include <limits>   // for error checking
#include <string>   // string
#include "DeckofCards.h"
#include "HandOfCards.h"

using namespace std;
using namespace ben_h;

/**
 * This is an example program that shows how to seed a random number generator
 * using a number provided from the command line and then access those random numbers.
 *
 * It will use a number provided on the command line (e.g. test_random.exe 12321) if one exists
 * otherwise it will seed the random nmber using the current time in seconds
 *
 * @param argc the number of arguments provided to the main function (this includes the program name itself)
 * @param argv an array of strings containing each of the arguments
 *
 * @author Trent Houliston
 */
int main(int argc, char* argv[]) {
	
    // Make sure we have at least two arguments
    // The first argument will be the program name e.g. myCode.exe
    // The second argument will be the seed for the random number generator
    if (argc >= 2) {
        // Use atoi (ascii to integer) to convert our argument to a number
        // note that if the user enters an invalid number this will be 0
        int seed = atoi(argv[1]);

        // Use that number to seed the random number generator
        srand(seed);
    }
    // If we don't have at least two arguments seed the random number generator using the current time
    else {
        // Get the current time as an integer
        int seed = time(NULL);

        // Use that number to seed the random number generator
        srand(seed);
    }
	
	//Step 1: Create a new instance of DeckofCards and shuffle it.
	DeckofCards* newDeck = new DeckofCards();
	newDeck->shuffle();
	
	//Step 2: Create two instances of HandOfCards.
	HandOfCards* player1 = new HandOfCards();
	HandOfCards* dealer = new HandOfCards();
	
	//Step 3: Create two instances of HandOfCards.
	//Uses pop() to take a card from the newDeck and add it to the player and dealer's hand.
	player1->add(newDeck->pop(),true);
	dealer->add(newDeck->pop(),true);
	player1->add(newDeck->pop(),true);
	dealer->add(newDeck->pop(),false);
	
	//Step 4: Display each hand's content using overloaded cout operator.
	cout << "Player: " << player1 << "( " << player1->count() << " points)" << endl;
	cout << "Dealer: " << dealer << "( " << dealer->count() << " points)" << endl;
	
	//Step 5: Check if player or dealer have 21 Blackjack.
	if(player1->count() >= 21 || dealer->countAll() == 21)
	{
		if(player1->count() == 21 && dealer->countAll() == 21)
			{cout << "\nTie! There are no winners." << endl;}
		else if(player1->count() == 21)
			{cout << "\nThe player is the winner!" << endl;}
		else
			{cout << "\nThe dealer is the winner!" << endl;}
	}
	else
	{
		//Step 6: Ask the player if he would like to hit or stand.
		int x = 0;
		while(player1->count()<21) // While the player isnt bust or Blackjack.
		{
			cout << "\nPlayer, do you want to Hit (1) or Stand (2)?" << endl;
			
			// Error checking. If x is not an integer, clears the error state and discards characters and asks the player for another input.
			if(!(cin >> x)) 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			// If they have stood stop asking and continue to dealers play.
			if(x == 2)
				{break;}
			
			if(x == 1)
			{
				player1->add(newDeck->pop(),true); // Adds a card to the players hand and couts hands.
				
				cout << "\nPlayer: " << player1 << "( " << player1->count() << " points)" << endl;
				cout << "Dealer: " << dealer << "( " << dealer->count() << " points)" << endl;
			}
		}
		//Checks for bust or win before dealer's play.
		if(player1->count() >= 21)
			if(player1->count() > 21)
				{cout << "\nThe dealer is the winner!" << endl;}
			else
				{cout << "\nThe player is the winner!" << endl;}
		else
		{
			//Step 7: Dealer's play.		
			while(dealer->countAll() <= 16)
				{dealer->add(newDeck->pop(),true);}
			
			//Step 8: Make cards in dealer's hand face up and print the hand and values of both players.
			dealer->faceUp();
			
			//made variables for count() to make it faster when checking for win/loss.
			int player1Count = player1->count();
			int dealerCount = dealer->count();
			
			cout << "\nPlayer: " << player1 << "( " << player1Count << " points)" << endl;
			cout << "Dealer: " << dealer << "( " << dealerCount << " points)" << endl;
			
			//Step 9: Check who is the winner.
			if(player1Count > 21 && dealerCount > 21)
				{cout << "\nThere are no winners" << endl;}
			else
			{
				if(player1Count > dealerCount && player1Count < 22)
					{cout << "\nThe player is the winner!" << endl;}
				else if(dealerCount > player1Count && dealerCount < 22)
					{cout << "\nThe dealer is the winner!" << endl;}
				else if(player1Count == dealerCount)
					{cout << "\nTie! There are no winners." << endl;}
				else if(dealerCount > 21)
					{cout << "\nThe player is the winner!" << endl;}
				else
					{cout << "\nThere are no winners." << endl;}
			}
		}
	}
	//Clears the memory.
	delete newDeck;
	delete player1;
	delete dealer;
}