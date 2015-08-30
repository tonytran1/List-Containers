/**
* \mainpage
*		<h3>
*			File Name: IntegerList.h <br>
*		</h3>
*
*		<p>
*			This program is Vector implementation of an Integer List.
*
*			The program features <b>seven operations:</b>
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
*  |+sort():void				 |
*  </center>
*/

#ifndef __INTEGERLISTVECTOR__H__
#define __INTEGERLISTVECTOR__H__
#include <vector>
using namespace std;

class IntegerListVector
{
private:
	vector<int> *list;
	int length;
public:
	IntegerListVector();
	~IntegerListVector();
	void push(int value);
	int pop();
	void pushEnd(int value);
	int popEnd();
	int getLength();
	int getElement(int element);
	void sort();
};

#endif
