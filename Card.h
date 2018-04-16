/*Header file for Card.cpp.

	Card.h
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates data for a Card.
*/

#ifndef NODE_C
#define NODE_C

#include <iostream>
#include <string>
namespace ben_h
{
	class Card
	{
	public:
	
		//CONSTRUCTOR / DECONSTRUCTOR
		
		// Preconditions: none
		// Postconditions: A new Card is created with empty data.
		Card();
		
		~Card();
		
		// Preconditions: none
		// Postconditions: A new Card is created with string data and int size as parameters.
		Card(const std::string& data, const int& size);
		
		
		//OTHER MEMBER FUNCTIONS
		
		// Preconditions: none
		// Postconditions: Sets a Card face with string data.
		void setFace(const std::string& data);
		
		// Preconditions: none
		// Postconditions: returns the string data in face.
		std::string& getFace();
		
		// Preconditions: none
		// Postconditions: returns the const string data in face.
		const std::string& getFace() const;
		
		// Preconditions: none
		// Postconditions: sets the Card value of the face.
		void setValue(const int& card_value);
		
		// Preconditions: none
		// Postconditions: returns the value of the Card face. 
		const int& getValue();
		
		// Preconditions: none
		// Postconditions: sets the card face whether it be up(true) or down(false).
		void setFaceUp(bool side);
		
		// Preconditions: none
		// Postconditions: returns the bool faceUp.
		const bool getFaceUp();
		
	private:
		// 3 private variables for Card properties.
		std::string face;
		int value;
		bool faceUp;
	};
	
	//FRIEND FUNCTION (can still access private objects).
	
	// Preconditions: none
    // Postconditions: Overloaded cout << operator prints the getValue() when a Card is called.
	std::ostream& operator << (std::ostream& outs, Card card);
	
}
#endif