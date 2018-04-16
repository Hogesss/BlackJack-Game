/*Header file for DeckofCards.cpp.

	DeckofCards.h
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates a Deck of Cards and uses functions to act as a normal deck.
*/

#ifndef NODE_DOC
#define NODE_DOC
#include "LinkedList.h"
#include "Card.h"
#include <iostream>
#include <string>
namespace ben_h
{
	class DeckofCards
	{
	public:		
		//CONSTRUCTOR / DECONSTRUCTOR
		
		// Preconditions: none
		// Postconditions: A new DeckofCards created in a LinkedList.
		DeckofCards();
		
		// Preconditions: none
		// Postconditions:
		~DeckofCards();
		
		
		
		
		//OTHER MEMBER FUNCTIONS
		
		// Preconditions: There is a DeckofCards object with nodes
		// Postconditions: Uses the Fisher Yates sorting algorithm by creating two pointers for nodes
		// and using the swap function to swap. 
		void shuffle();
		
		// Preconditions: none
		// Postconditions: returns the length of the LinkedList.
		const int length();
		
		// Preconditions: none
		// Postconditions: iterates through the LinkedList and compares single string input to Nodes data.
		// If found, returns the position in the list, if not returns -1.
		int position(const std::string data);
		
		// Preconditions: none
		// Postconditions: Iterates through the LinkedList and builds a string with all the data.
		// Returns the data in a printable display.
		std::string value();
		
		// Preconditions: none
		// Postconditions: Returns whether there are any cards in DeckofCards or not.
		bool empty() const;
		
		// Preconditions: none
		// Postconditions: takes a string argument and removes the corresponding card in DeckofCards.
		bool remove(const std::string data);
		
		// Preconditions: Required there are cards in the deck. 
		// Postconditions: Takes two positions in the DeckofCards and sets them to temp strings
		// Then sets them to each other to swap the cards in the deck.
		void swap(const int a, const int b);
		
		Card pop();
		
		void push(Card);
		
		
	private:
		// 1 private variable a LinkedList object. Not a pointer since a 
		// LinkedList object contains pointers and a size_t variable. 
		LinkedList<Card> list;
		Card card;
	};
	
	//FRIEND FUNCTION (can still access private objects).
	
	// Preconditions: none
    // Postconditions: Overloaded cout << operator prints the value() when a DeckofCards pointer is called.
	std::ostream& operator <<(std::ostream& outs, DeckofCards* newDeck);
	
}
#endif