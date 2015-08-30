// 7/28/2015
// File Name: List.hxx
// This is the implementation file of the header file "List.h".
// This file contains the construction, destruction, and function methods of the class List.

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "List.h"
using namespace std;

/**
 * 	The constructor initializes null pointer <b>head</b>.
 */
template <typename T>
List<T>::List() : head(NULL), length(0)
{}

/**
*	The destructor deletes all objects created
*/
template <typename T>
List<T>::~List()
{
	while (head != NULL)
	{
		this->pop();
	}
}

/**
* 	The push() function adds an generic <b>T<b> value to the beginning of the list.
*
*  @param T <b>value</b> contains the value to be added to the list.
*
*/
template <typename T>
void List<T>::push(T value)
{
	Node<T>* newNode = new Node<T>;
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
* 	The pop() function removes and retrieves the generic type value from the beginning of the list.
*
* 	@returns T <b>popValue</b> containing the generic type value that is removed from the list.
*/
template <typename T>
T List<T>::pop()
{
	try
	{
		if (length == 0)
		{
			head = NULL;
			throw logic_error("List is empty!");
		}
/*	No value assigned to popValue or else may cause error when working with string lists; 
			NULL and/or 0 cannot be assigned to string datatype. */
		T popValue;

		if (length == 1)
		{
			length--;
			popValue = head->value;
			delete head;
			head = NULL;
			return popValue;
		}
		if (length > 1)
		{
			Node<T>* current = head;
			length--;
			popValue = current->value;
			current = current->next;
			delete head;
			head = NULL;
			head = current;
			return popValue;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
		exit(0);
	}
}

/**
*  The pushEnd() function adds the generic type value at the end of the list
*
*	@param T <b>value</b> contains the generic type value that will be added to the list
*/
template <typename T>
void List<T>::pushEnd(T value)
{
	Node<T>* newNode = new Node<T>;
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
		Node<T>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
	}
}

/**
*	The popEnd() retrieves and removes the generic type value at the end of the list.
*
*	@returns T popValue that contains the value that is removed from the end of the list.
*/
template <typename T>
T List<T>::popEnd()
{
	try
	{
		if (length == 0)
		{
			head = NULL;
			throw logic_error("Exception: List is empty!");
		}
/*	No value assigned to popValue or else may cause error when working with string lists
		NULL or 0 cannot be assigned to a string object. */
		T popValue;

		if (length == 1)
		{
			length--;
			popValue = head->value;
			delete head;
			head = NULL;
			return popValue;
		}
		if (length > 1)
		{
			length--;
			Node<T>* current = head;
			Node<T>* lastNode = NULL;
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
			lastNode = NULL;
			return popValue;
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
		exit(0);
	}
}

/**
*	The getLength() function obtains the length of the list.
*
*	@returns int containing the length of the list.
*/
template <typename T>
int List<T>::getLength()
{
	return length;
}

/**
*	The getElement() function retrieves the value based on the location of the index number input.
*
*	@param int <b>element</b> contains the integer referring to the index number.
*
*	@returns an generic value containing the value of the specific element position.
*/
template <typename T>
T List<T>::getElement(int element)
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		if (element < 0 || element >= length)
			throw out_of_range("Exception: Index out of range!");

		int count = 0;
		Node<T>* current = head;
		while (current != NULL)
		{
			if (count == element)
				return current->value;
			current = current->next;
			count++;
		}
		throw 1;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
		exit(0);
	}
	catch (out_of_range& e)
	{
		cout << e.what();
		exit(0);
	}
}

