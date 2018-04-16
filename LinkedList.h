/*Header file for LinkedList.template.

	LinkedList.h
	
	*Author: Benjamin Hogan
	*Student No: c3256846
	*Date: 28/9/2016
	*Descripion:
	*	Creates and manipulates a LinkedList.
*/

#ifndef NODE_LL
#define NODE_LL

#include "Node.h"
#include <string>
namespace ben_h
{
	template <typename value_type>
	class LinkedList
	{
	public:
	
		//CONSTRUCTOR / DECONSTRUCTOR
		
		// Preconditions: none
		// Postconditions: A new LinkedList is created with 
		// NULL head, tail and current pointers. It is of length 0.
		LinkedList();
		
		// Preconditions: none
		// Postconditions: A new LinkedList is created with 
		// an initial node with data initial_data. It is of length 1.
		LinkedList(const value_type);
		
		// Preconditions: none
		// Postconditions: loops through LinkedList removing from tail which deletes all of the nodes.
		~LinkedList();
		
		
		
		
		//OTHER MEMBER FUNCTIONS
		
		// Preconditions: head is either NULL or already pointing to a node.
		// Postconditions: adds a new node to the head of the LinkedList and 
		// sets the head pointer to the new node. Length is increased by 1.
		void addToHead(const value_type data);
		
		// Preconditions: tail is either NULL or already pointing to a node.
		// Postconditions: adds to the tail of the LinkedList and 
		// sets the tail pointer to the new node. Length is increased by 1.
		void addToTail(const value_type data);
		
		// Preconditions: Current is either NULL or already pointing to a node.
		// Postconditions: inserts the node that current is pointing at of the LinkedList and 
		// sets the current pointer to the new node. Length is increased by 1.
		void addToCurrent(const value_type data);
		
		// Preconditions: Current is pointing to a node
		// Postconditions: Removes the node current is pointing to and connects its prev and next
		// nodes together so the list functions correctly. Sets current to the next of current.
		void removeFromCurrent();		
		
		// Preconditions: head is pointing to a node
		// Postconditions: Removes the head of the linkedlist and sets the next of head to the new head.
		void removeFromHead();
		
		// Preconditions: tail is pointing to a node
		// Postconditions: Removes the tail of the linkedlist and sets the previous of tail to the new tail.
		void removeFromTail();
		
		// Preconditions: none
		// Postconditions: moves the current pointer to the next node in the list.
		void forward();
		
		// Preconditions: none
		// Postconditions: moves the current pointer to the previous node in the list.
		void back();
		
		// Preconditions: none
		// Postconditions: moves the current pointer to the head node in the list.
		void moveToHead();
		
		// Preconditions: none
		// Postconditions: moves the current pointer to the tail node in the list.
		void moveToTail();
		
		// Preconditions: none
		// Postconditions: Moves the current pointer to the xth position in the LinkedList.
		void moveToCurrent(const int x);
		
		// Preconditions: none
		// Postconditions: sets the current node's data to data.
		void setCurrentData(const value_type& node);
		
		// Preconditions: none
		// Postconditions: returns the data that current is pointing at.
		value_type& getCurrent();
		
		// Preconditions: none
		// Postconditions: returns the constant data that current is pointing at.
		const value_type& getCurrent() const;
		
		// Preconditions: none
		// Postconditions: returns the length of the list as size_t form.
		const size_t size();
		
	private:
		// 4 private variables, node pointers and length of list.
		Node<value_type>* head;
		Node<value_type>* tail;
		Node<value_type>* current;
		std::size_t length;
	};
}
#include "LinkedList.template"
#endif