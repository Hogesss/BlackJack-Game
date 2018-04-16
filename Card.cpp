/*Source file for creating and manipulating Cards.

	Card.cpp
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates data for a Card.
*/
#include <iostream>
#include <string>
#include "Card.h"

using namespace std;
namespace ben_h
{
    Card::Card()
	{
		face = "";
		value = 0;
		faceUp = true;
	}
	
	Card::~Card()
	{
		face = "";
		value = 0;
	}
	
	Card::Card(const string& data, const int& size)
	{
		face = data;
		value = size;
		faceUp = true;
	}
	
	void Card::setFace(const string& data)
	{
		face = data;
	}
	
	string& Card::getFace()
	{
		return face;
	}
	
	const string& Card::getFace() const
	{
		return face;
	}
	
	void Card::setValue(const int& card_value)
	{
		value = card_value;
	}
	
	const int& Card::getValue()
	{
		return value;
	}
	
	void Card::setFaceUp(bool side)
	{
		faceUp = side;
	}
	
	const bool Card::getFaceUp()
	{
		return faceUp;
	}
	
	ostream& operator << (ostream& outs, Card card)
	{
		return outs << card.getFace() << endl; // calls the getFace function.
	}
	
}