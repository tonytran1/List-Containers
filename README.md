# List-Containers

Title: Implementations of the List Class.

Author: Tony Tran

Background: The following programs will be implemented using the C++ programming language. These implementations will include the use of dynamic arrays, the vector class, linked lists, and templates.

Objective:  Building multiple programs by using different implementation methods to create a container class. Each implementation will include a destructor to eliminate all traces of memory leaks as well as exception handlers for handling empty lists and out of bounds abnormality.  

1.	The IntegerListArray implementation includes using Dynamic Arrays to create a integer list which has the following operations: 
•	Push: Adds an integer to the beginning of the list.
•	Pop: Retrieves and removes the integer at the beginning of the list.
•	pushEnd: Adds an integer at the end of the list.
•	popEnd: Retrieves and removes the integer at the end of the list.
•	getLength: Retrieves the current length of the list.
•	getElement: Retrieves the value at the specific element location.
•	Sort: Sorts the list in ascending order.

Note: These operations will be common ground within the majority of the implementations.

2.	The IntegerListVector implementation uses the Vector Class to provide all the operations that the first implementation (Dynamic Arrays) delivers.

3.	The IntegerListLinked implementation includes using Linked Lists to provide an understanding of the difference between the first two implementations and Linked Lists. The third implementation also provides all the same operations as the first implementation (Dynamic Arrays).

5.	The List implementation includes using a Linked List Template to provide the user with a list class that can hold any data type. Although most operations from the first implementation (Dynamic Arrays) are available for the Linked List Template implementation, the sort operation will not be provided.

