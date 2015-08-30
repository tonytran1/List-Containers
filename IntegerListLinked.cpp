// 7/28/2015
// File Name: IntegerListLinked.cpp
// This is the implementation file of the header file "IntegerListLinked.h".
// It contains the construction and functions method of the class IntegerListLinked,
// which is in the header file.

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "IntegerListLinked.h"
using namespace std;


/**
 * 	The default constructor initializes null pointer <b>list</b>.
 */
IntegerListLinked::IntegerListLinked() : head(NULL), length(0)
{}

/**
*	The destructor deletes all objects created
*/
IntegerListLinked::~IntegerListLinked()
{
	while (head != NULL)
	{
		this->pop();
	}
}

/**
 * 	The push() function adds an integer to the beginning of the list.
 *
 *  @param int <b>value</b> contains the integer that will be added to the list.
 *
 */
void IntegerListLinked::push(int value)
{
	Node<int>* newNode = new Node<int>;
	newNode->next = NULL;
	newNode->value = value;

	if (length == 0)
	{
		length++;
		head = newNode;
	}
	else
	{
		length++;
		newNode->next = head;
		head = newNode;
	}

}

/**
 * 	The pop() function removes and retrieves the integer from the beginning of the list.
 *
 * 	@returns int <b>popValue</b> containing the integer that is removed from the list.
 */
int IntegerListLinked::pop()
{
	try
	{
		if (length == 0)
		{
			head = NULL;
			throw logic_error("List is empty!");
		}

		int popValue = 0;

		if (length == 1)
		{
			length--;
			popValue = head->value;
			delete head;
			return popValue;
		}
		if (length > 1)
		{
			Node<int>* current = head;
			length--;
			popValue = current->value;
			current = current->next;
			delete head;
			head = current;
			return popValue;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}

/**
 *  The pushEnd() function adds an integer at the end of the list.
 *
 *	@param int <b>value</b> contains the integer that will be added to the list.
 */
void IntegerListLinked::pushEnd(int value)
{
	Node<int>* newNode = new Node<int>;
	newNode->next = NULL;
	newNode->value = value;

	if (length == 0)
	{
		length++;
		head = newNode;
	}
	else
	{
		length++;
		Node<int>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
	}
}

/**
 *	The popEnd() retrieves and removes the int from the end of the list.
 *
 *	@returns int that contains the integer that is removed from the list.
 */
int IntegerListLinked::popEnd()
{
	try
	{
		if (length == 0)
		{
			head = NULL;
			throw logic_error("Exception: List is empty!");
		}

		int popValue = 0;

		if (length == 1)
		{
			length--;
			popValue = head->value;
			delete head;
			return popValue;
		}
		if (length > 1)
		{
			length--;
			Node<int>* current = head;
			Node<int>* lastNode = NULL;
			while (current->next != NULL)
			{
				current = current->next;
			}

			lastNode = current;
			current = head;

			while (current->next != lastNode)
			{
				current = current->next;
			}
			popValue = current->next->value;
			current->next = NULL;
			delete lastNode;
			return popValue;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
/**
 *	The getLength() function obtains the length of the list.
 *
 *	@returns int containing the list length.
 */
int IntegerListLinked::getLength()
{
	return length;
}

/**
 *	The getElement() function gets the integer based on the element position in the list.
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerListLinked::getElement(int element)
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		if (element < 0 || element >= length)
			throw out_of_range("Exception: Index out of range!");

		int count = 0;
		Node<int>* current = head;
		while (current != NULL)
		{
			if (count == element)
				return current->value;
			current = current->next;
			count++;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
	catch (out_of_range& e)
	{
		cout << e.what();
	}
}

/**
*	The sort() function arranges the list to be in ascending integer order using the bubble
*	sort algorithm. The function compares all numbers on the list starting from the first two. 
*	If the first number is larger than the second number, the numbers will swap places. The 
*	function then compares the second and third number, the third and fourth number, and so on.
*	
*	Note: The position order of the numbers will change if swaps were made.
*	
*	The function then loops the list until no swaps are made. This will allow the function to know 
*	if the list is completely sorted via a boolean datatype.
*/

void IntegerListLinked::sort()
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		int count = 0;
		bool swap = true;
		int temp = 0;
		Node<int>* current = head;
		Node<int>* lastNode = NULL;
		// Obtaining last node location
		while (current != NULL)
		{
			current = current->next;
		}
		lastNode = current;
		current = head;
		while (swap)
		{
			current = head;
			swap = false;
			while (current->next != lastNode)
			{
				if (current->value > current->next->value)
				{
					swap = true;
					temp = current->value;
					current->value = current->next->value;
					current->next->value = temp;
				}
				current = current->next;
			} lastNode = current;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
