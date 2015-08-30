/**
* \mainpage
*		<h3>
*			File Name: IntegerListLinked.h <br>
*		</h3>
*
*		<p>
*			This program is a Linked List implementation of an integer List.
*
*			The program features <b>six operations:</b>
*			<ol type="1">
* 				<li>Integers can be added to the beginning of the list by using
*             		the push function.</li>
* 				<li>Integers can be retrieved and removed from the beginning of
*              	the list by using the pop function.</li>
*				<li>Integers can be added to the end of the list by using the
*              	pushEnd function.</li>
* 				<li>Integers can be retrieved and removed from the end of the
*              	list by using the popEnd function.</li>
*				<li>You can find out the number of elements from the getLength
*              	function.</li>
*				<li>You can get the value at any specific element using the
*              	getElement function.</li>
*				<li>You can sort the list in integer ascending order using the
*				sort function.</li>
*			</ol>
*
*<center>
*
*	Below is the UML class diagram:
*
*  |IntegerList					 |
*  |-----------------------------|
*  |-int *list					 |
*  |-int length					 |
*  |							 |
*  |+push(value:int):void		 |
*  |+pop():int					 |
*  |+pushEnd(value:int):void	 |
*  |+popEnd():int				 |
*  |+getLength():int			 |
*  |+getElement(element:int):int |
*  |+sort():void                 |
*  <b>Source of UML: Provided by instructor, Marc Sosnick-Perez.</b>
*  </center>
*/

#ifndef __INTEGERLISTLINKED__H__
#define __INTEGERLISTLINKED__H__
#include "Node.h"

class IntegerListLinked
{
private:
	Node<int>* head;
	int length;
public:
	IntegerListLinked();
	~IntegerListLinked();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void sort();
};

#endif
