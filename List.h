/**
* \mainpage
*		<h3>
*			File Name: List.h <br>
*		</h3>
*
*		<p>
*			This program is a Linked List implementation of an template List.
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
*			</ol>
*
*<center>
*
*	Below is the UML class diagram:
*
*  |IntegerList					 |
*  |-----------------------------|
*  |-Node<T> *head				 |
*  |-int length					 |
*  |							 |
*  |+push(value:T):void		     |
*  |+pop():T					 |
*  |+pushEnd(value:T):void	     |
*  |+popEnd():T				     |
*  |+getLength():int			 |
*  |+getElement(element:int):T   |
*  <b>Source of UML: Provided by instructor, Marc Sosnick-Perez.</b>
*  </center>
*/

#ifndef __LIST__H__
#define __LIST__H__
#include "Node.h"
using namespace std;

template <class T>
class List{
private:
	Node<T>* head;
	int length;
public:
	List();
	~List();
	void push(T value);
	T pop();
	void pushEnd(T value);
	T popEnd();
	int getLength();
	T getElement(int element);
};

#include "List.hxx"

#endif
