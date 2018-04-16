/*Source file for creating a DeckofCards.

	DeckofCards.cpp
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates a Deck of Cards and uses functions to act as a normal deck.
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include "DeckofCards.h"

using namespace std;
namespace ben_h

{
	DeckofCards::DeckofCards()
	{
		int x;
		int y;
		// uses arrays for the suit and card number.
		string suit [] = {"S", "H", "C", "D"};
		string number [] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
		
		//loops through all possible card combinations and matches them with a "-".
		for(y = 0; y<4; y++)
		{
			for(x = 0; x<13; x++)
			{
				if(x<9) //If card isnt a special card, then enter the value of the card
					{card = Card(number[x]+ "-" +suit[y], x+2);}
				else{
					if(x==12)
						{card = Card(number[x]+ "-" +suit[y], 11);}
					else
						{card = Card(number[x]+ "-" +suit[y], 10);}
				}
				this->push(card); //adds to the head of the LinkedList.
			}
		}
	}
	
	DeckofCards::~DeckofCards()
	{
		list.~LinkedList(); // calls the LinkedList destructor to remove the deck.
	}
	
	ostream& operator << (ostream& outs, DeckofCards* newDeck)
	{
		return outs << newDeck->value() << endl; // calls the value function.
	}
	
	string DeckofCards::value()
	{
		list.moveToHead();
		string temp = "";
		
		for(size_t x = 0; x<list.size(); x++)
		{
			card = list.getCurrent();
			temp += card.getFace() + " ";
			list.forward(); // moves current to the next node in the LinkedList.
		}
		return temp;
	}
	
	int DeckofCards::position(const string data)
	{
		int pos = 0;
		list.moveToHead();
		
		for(size_t x=0; x<list.size(); x++)
		{
			card = list.getCurrent();
			if(card.getFace() == data)
			{// sets the position in the deck that data matches to pos and returns an int.
				pos = x;
				return pos;
			}
			else
			{
				list.forward();
			}
		}
		//else returns that the data isnt in the list
		return -1;
	}
	
	const int DeckofCards::length()
	{
		return list.size();
	}
	
	bool DeckofCards::remove(const string data)
	{
		int pos = position(data);
		if(pos != -1)
		{
			list.moveToCurrent(pos);
			
			if(pos == 0) //if the position is the very first node, remove from head instead of current.
			{
				list.removeFromHead();
				return 1;
			}
			else if(pos == (int) list.size()-1) //if the position is the last, remove from tail instead of current.
			{
				list.removeFromTail();
				return 1;
			}
			else // remove from current.
			{
				list.removeFromCurrent();
				return 1;
			}
		}
		
		return 0;
	}
	
	bool DeckofCards::empty() const
	{
		Card tempCard = list.getCurrent();
		if(tempCard.getFace() == "")
			{
				return 1;
			}
		return 0;
	}
	
	void DeckofCards::swap(const int x, const int y)
	// Preconditions: none
    // Postconditions: .
	{
		//searchs and finds a[j] and makes current it.
		list.moveToCurrent(y);
		//stores the data of a[j] in old y.
		Card old_y = list.getCurrent();
		//searchs and finds a[i] and makes current it.
		list.moveToCurrent(x);
		//stores the data of a[i] in old x.
		Card old_x = list.getCurrent();

		//Then sets the opposite data to swap each card.
		list.moveToCurrent(x);
		list.setCurrentData(old_y);
		list.moveToCurrent(y);
		list.setCurrentData(old_x);
	}
	
	void DeckofCards::shuffle()
	{
		list.moveToHead();
		card = list.getCurrent();
		if(card.getFace() != "")
		{
			for(int i = list.size()-1; i>0; i--) //starts at the list size -1 down to 1.
			// finds a random number between 0 and i through seed or time and calls the swap function.
			{
			  int j = (rand() % (i+1));
			  swap(i, j);
			}
		}
	}
	
	Card DeckofCards::pop()
	{
		list.moveToHead();
		card = list.getCurrent(); // gets the card on top of the deck
		list.removeFromHead(); // Removes it from the deck and returns it for the hand.
		return card;
	}
	
	void DeckofCards::push(Card card)
	{
		list.addToHead(card); // pushes a card on the top of the deck.
	}
}