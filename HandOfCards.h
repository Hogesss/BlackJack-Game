/*Header file for HandOfCards.cpp.

	HandOfCards.h
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates Cards in a Hand of Cards.
*/

#ifndef NODE_HOC
#define NODE_HOC
#include "LinkedList.h"
#include "Card.h"

#include <string>
namespace ben_h
{
	class HandOfCards
	{
	public:
		//CONSTRUCTORS / DECONSTRUCTOR
		HandOfCards();
		
		~HandOfCards();
		
		
		//OTHER MEMBER FUNCTIONS
		
		// Preconditions: none
		// Postconditions: counts the value of the Cards stored in HandOfCards only facing up.
		const int count();
		
		// Preconditions: none
		// Postconditions: returns the value of the Cards stored in HandOfCards either down or up.
		const int countAll();
		
		// Preconditions: none
		// Postconditions: returns a string displaying the sequence of cards stored in HandOfCards.
		const std::string value();
		
		// Preconditions: none
		// Postconditions: makes all Cards face up.
		void faceUp();
		
		// Preconditions: none
		// Postconditions: adds the card to the HandOfCards.
		void add(Card card, bool face);
		
		
	private:
		//2 private member variables for the LinkedList data structure and Card.
		LinkedList<Card>* hand;
		Card* currentCard;
	};
	
	//FRIEND FUNCTION (can still access private objects).
	
	// Preconditions: none
    // Postconditions: Overloaded cout << operator prints the value() when a HandOfCards is called.
	std::ostream& operator <<(std::ostream& outs, HandOfCards* newHand);
	
	
}
#endif