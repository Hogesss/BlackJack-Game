/*Source file for creating and manipulating HandOfCards.

	HandOfCards.cpp
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates Cards in a Hand of Cards.
*/

#include <string>
#include "HandOfCards.h"

using namespace std;
namespace ben_h
{
	HandOfCards::HandOfCards()
	{
		hand = new LinkedList<Card>();
		currentCard = NULL;
	}
	
	HandOfCards::~HandOfCards()
	{
		hand->~LinkedList();
		currentCard = NULL;
		hand = NULL;
	}
	
	const int HandOfCards::count()
	{
		hand->moveToHead();
		int totalValue = 0;
		
		for(size_t x = 0; x < hand->size(); x++)// loops through all cards in the hand.
		{
			currentCard = &hand->getCurrent();
			if(currentCard->getFaceUp() == true)// checks if the card is face up then get the value
			{
				totalValue += currentCard->getValue();
				hand->forward();
			}
			else// if not continue checking until no cards left in hand.
			{
				hand->forward();
			}
		}
		currentCard = NULL;
		return totalValue;
	}
	
	const int HandOfCards::countAll()
	{
		hand->moveToHead();
		int totalValue = 0;
		
		for(size_t x = 0; x < hand->size(); x++)
		{
			// doesn't require if the card is face up and loops through adding the value of the cards.
			currentCard = &hand->getCurrent();
			totalValue += currentCard->getValue();
			hand->forward();
		}
		currentCard = NULL;
		return totalValue;
	}
	
	ostream& operator << (ostream& outs, HandOfCards* newHand)
	{
		return outs << newHand->value(); // calls the value function.
	}
	
	const string HandOfCards::value()
	{
		hand->moveToHead();
		string temp = "";
		
		for(size_t x = 0; x<hand->size(); x++) // loops through the hand
		{
			currentCard = &hand->getCurrent();
			if(currentCard->getFaceUp() == false)// if the card is face down
			{
				temp += "?-? "; // returns question marks.
			}
			else
			{
				
				temp += currentCard->getFace() + " "; // gets the string face value of the card.
			}
			hand->forward();
		}
		currentCard = NULL;
		return temp;
	}
	
	void HandOfCards::faceUp()
	{
		hand->moveToHead();
		for(size_t x = 0; x < hand->size(); x++)
		{
			currentCard = &hand->getCurrent();
			currentCard->setFaceUp(true); // sets all card faces true to allow value() and count() to print all the values of the cards in the hand.
			hand->forward();
		}
		currentCard = NULL;
	}
	
	void HandOfCards::add(Card card, bool face)
	{
		card.setFaceUp(face); // sets the FaceUp and adds the card to the hand.
		hand->addToTail(card);
	}
	
	
	
}