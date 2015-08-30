// 7/28/2015
// File Name: IntegerListArray.cpp
// This is the implementation file of the header file "IntegerListArray.h".
// It contains the construction and functions method of the class IntegerListArray,
// which is in the header file.

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "IntegerListArray.h"
using namespace std;

/**
 * 	The constructor initializes int <b>length</b> to be 0 and the null pointer <b>list</b>.
 */
IntegerListArray::IntegerListArray() :length(0), list(NULL)
{}

/**
*	The destructor deletes the dynamic array contents.
*/
IntegerListArray::~IntegerListArray()
{
	delete[] list;
}

/**
 * 	The push() function adds an integer to the beginning of the array.
 *
 *  @param int <b>value</b> contains the integer that be added to the array.
 *
 */
void IntegerListArray::push(int value)
{
	length++;
	int* listCopy = new int[length];
	listCopy[0] = value;
	for (int i = 0; i < length - 1; i++)
	{
		*(listCopy + i + 1) = *(list + i);
	}

	if (list != 0)
	{
		delete[] list;
	}
	list = listCopy;
}

/**
 * 	The pop() function removes and retrieves the integer from the beginning of the array
 *
 * 	@returns int <b>popValue</b> containing the integer that is removed from the array
 */
int IntegerListArray::pop()
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		length--;
		int popValue = *list;
		if (length != 0)
		{
			int* listCopy = new int[length];
			for (int i = 0; i < length; i++)
				*(listCopy + i) = *(list + i + 1);
			delete[] list;
			list = listCopy;
		}
		else {
			delete[] list;
		}

		return popValue;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}

/**
 *  The pushEnd() function adds an integer at the end of the array
 *
 *	@param int <b>value</b> contains the integer that will be added to the array
 */
void IntegerListArray::pushEnd(int value)
{
	length++;
	int* listCopy = new int[length];

	for (int i = 0; i < length - 1; i++)
		*(listCopy + i) = *(list + i);
	delete[] list;
	listCopy[length - 1] = value;
	list = listCopy;
}

/**
 *	The popEnd() retrieves and removes the int from the end of the array
 *
 *	@returns int that contains the integer that is removed from the array
 */
int IntegerListArray::popEnd()
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		length--;
		int popValue = list[length];
		if (length != 0)
		{
			int* listCopy = new int[length];
			for (int i = 0; i < length; i++)
			{
				*(listCopy + i) = *(list + i);
			}
			delete[] list;
			list = listCopy;
		}
		else
		{
			delete[] list;
		}

		return popValue;
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
/**
 *	The getLength() function obtains the amount of numbers inside the array.
 *
 *	@returns int containing the numbers of integers in the array
 */
int IntegerListArray::getLength()
{
	return length;
}

/**
 *	The getElement() function gets the integer based on the element position in the array
 *
 *	@param int <b>element</b> contains the integer referring to the index number
 *
 *	@returns int containing the integer of the list in the specific element position
 */
int IntegerListArray::getElement(int element)
{
	try
	{
		if (length == 0)
			throw logic_error("Exception: List is empty!");

		if (element < 0 || element >= length)
			throw out_of_range("Exception: Index out of range!");

		return list[element];
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
*	The sort() function sorts the list into ascending order using the bubble sort algorithm.
*	The algorithm compares two numbers; if the two numbers are compared and the lower number is higher on the
*	list in terms of array index, the lower number is swapped positions with the higher number. This comparison happens
*	with every index until no swaps are made throughout the entire loop. This means the numbers are sorted
*	and the sort function is completed.
*/
void IntegerListArray::sort()
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
				if (list[i] > list[i + 1])
				{
					swap = true;
					temp = list[i];
					list[i] = list[i + 1];
					list[i + 1] = temp;
				}
			}
		}
	}
	catch (logic_error& e)
	{
		cout << e.what() << endl;
	}
}
