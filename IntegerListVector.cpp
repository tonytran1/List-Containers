// 7/28/2015
// File Name: IntegerListVector.cpp
// This is the implementation file of the header file "IntegerListVector.h".
// It contains the construction and functions method of the class IntegerListVector,
// which is in the header file.

#include <iostream>
#include <vector>
#include <stdexcept>
#include "IntegerListVector.h"
using namespace std;

/**
 * 	The constructor initializes null pointer <b>list</b>.
 */
IntegerListVector::IntegerListVector() : length(0)
{
	list = new vector<int>(0);
}

/**
*	The destructor clears the vector list.
*/
IntegerListVector::~IntegerListVector()
{
	list->clear();
}
/**
 * 	The push() function adds an integer to the beginning of the list.
 *
 *  @param int <b>value</b> contains the integer that be added to the list.
 *
 */
void IntegerListVector::push(int value)
{
	length++;
	list->insert(list->begin(), value);
}

/**
 * 	The pop() function removes and retrieves the integer from the beginning of the list.
 *
 * 	@returns int <b>popValue</b> containing the integer that is removed from the list.
 */
int IntegerListVector::pop()
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		length--;
		int popValue = list->front();
		list->erase(list->begin());
		return popValue;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}

/**
 *  The pushEnd() function adds an integer at the end of the vector list.
 *
 *	@param int <b>value</b> contains the integer that will be added to the end of the list.
 */
void IntegerListVector::pushEnd(int value)
{
	length++;
	list->push_back(value);
}

/**
 *	The popEnd() retrieves and removes the int from the end of the vector list.
 *
 *	@returns int that contains the integer that is removed from the vector list.
 */
int IntegerListVector::popEnd()
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		length--;
		int popValue = list->back();
		list->pop_back();
		return popValue;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
/**
 *	The getLength() function obtains the length of the list.
 *
 *	@returns int containing the numbers of integers in the vector list.
 */
int IntegerListVector::getLength()
{
	return length;
}

/**
 *	The getElement() function obtains the integer based on the element position selected in the vector list.
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerListVector::getElement(int element)
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		if (element < 0 || element >= length)
			throw out_of_range("Exception: Index out of range!");

		return list->at(element);
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
*	The sort() function takes all integers within the list and sorts them in ascending order
*	using the bubbleSort algorithm. The function compares all numbers on the list starting from the first two. 
*	If the first number is larger than the second number, the numbers will swap places. The 
*	function then compares the second and third number, the third and fourth number, and so on depending on
*	the length of the list.
*	
*	Note: The position order of the numbers will change if swaps were made.
*	
*	The function then loops the list until no swaps are made. This will allow the function to know 
*	if the list is completely sorted via a boolean datatype.
*/
void IntegerListVector::sort() 
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		int temp = 0;
		bool swap = true;
		for (int skipLastIndex = 1; skipLastIndex <= length && swap; skipLastIndex++)
		{
			swap = false;
			for (int i = 0; i < length - skipLastIndex; i++)
			{
				if (list->at(i) > list->at(i + 1))
				{
					temp = list->at(i);
					list->at(i) = list->at(i + 1);
					list->at(i + 1) = temp;
					swap = true;
				}
			}
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}

}
