/*Header file for Node.template.

	Node.h
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates Nodes in Linked Lists.
*/

#ifndef NODE_N
#define NODE_N
#include "Card.h"

#include <string>
namespace ben_h
{
	template <typename value_type>
	class Node
	{
	public:
		//CONSTRUCTORS / DECONSTRUCTOR
		
		// Preconditions: none
		// Postconditions: A new node is created with no links and empty data.
		Node();
		
		// Preconditions: initial_data is of value_type for Node's data.
		// Postconditions: A new node is created with no links and initial_data.
		Node(const value_type initial_data);
		
		// Preconditions: There is a node.
		// Postconditions: Node is deleted.
		~Node();
		
		
		
		
		//OTHER MEMBER FUNCTIONS
		
		// Preconditions: initial_data is of value_type for Node's data.
		// Postconditions: data is set to new_data in the node.
		void set_data(const value_type& new_data);
		
		// Preconditions: none
		// Postconditions: next link is set to a node new_link.
		void set_next(Node* new_link);
		
		// Preconditions: none
		// Postconditions: previous link is set to node new_link.
		void set_prev(Node* new_link);
		
		// Preconditions: data is of value_type.
		// Postconditions: returns the data inside the node.
		value_type& get_data();
		
		// Preconditions: none
		// Postconditions: returns a const data which cannot be altered.
		const value_type& get_data() const;
		
		// Preconditions: none
		// Postconditions: returns the nodes next link.
		const Node* get_next() const;
		
		// Preconditions: none
		// Postconditions: returns the nodes next link.
		Node* get_next();
		
		// Preconditions: none
		// Postconditions: returns the nodes next link.
		const Node* get_prev() const;
		
		// Preconditions: none
		// Postconditions: returns the nodes next link.
		Node* get_prev();
		
	private:
		//3 private member variables for links and data of the node.
		Node* prev;
		Node* next;
		value_type data;
	};
}
#include "Node.template"
#endif