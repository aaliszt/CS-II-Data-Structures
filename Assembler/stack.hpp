// Aaron Liszt
// CS23001
// stack.hpp
// Description: Template defenition for a dynamic stack
// CLASS INV: TOS -> A -> B -> ... -> 0

#include <new>

#ifndef STACK_HPP
#define STACK_HPP

#include "node.hpp"
#include <cassert>

template<typename T>
class Stack{
public:
	Stack(): tos(0){};
	~Stack();
	Stack(Stack<T>&&);
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	Stack<T>& operator=(Stack<T>&&);	

	void swap(Stack<T>&);
	bool isEmpty() const{ return tos == 0; }
	bool isFull() const;
	T pop();
	void push(const T&);
private:
	node<T> *tos;

};

// FUNCTION DEFENITIONS

// POP
// REQUIRES: Stack cannot be empty
// ENSURES: tos is removed, and new tos is set
template<typename T>
T Stack<T>::pop(){
	assert(tos != 0);    // Check stack isn't empty
	T result = tos->data;
	node<T> *temp = tos; // Keep track of old tos to de-allocate(avoid mem-leak)
	tos = tos->next; 
	delete temp;          
	return result;
}

// PUSH
// REQUIRES: tos -> A -> B -> ... -> 0
// ENSURES: tos -> x -> A -> B -> ... -> 0
template<typename T>
void Stack<T>::push(const T& x){
	assert(!isFull());
	node<T> *temp = new node<T>(x);
	temp->next = tos;    // Make temp's next point to tos 
	tos = temp;          // temp is the new tos
}

// DESTRUCTOR
// REQUIRES:
// ENSURES: All memony in the stack is de-allocated
template<typename T>
Stack<T>:: ~Stack(){
	node<T> *temp;
	while(tos != 0){ // While we are not at the bottom of the stack
		temp = tos;
		tos = tos->next;
		delete temp;
	}
}

// COPY CONSTRUCTOR
// REQUIRES:
// ENSURES: temp is an exact copy of actual
template<typename T>
Stack<T>::Stack(const Stack<T>& actual){
	node<T> *temp = actual.tos, *bottom = 0;
	tos = 0;
	while(temp != 0){
		if(tos == 0){				// If we are at the tos
			tos = new node<T>(temp->data);
			bottom = tos;
		}
		else{  // If we have more than one node
			bottom->next = new node<T>(temp->data);
			bottom = bottom->next; 
		}
		temp = temp->next; // Increment temp
	}
}

// ASSIGNMENT OPERATOR
// REQUIRES:
// ENSURES: rhs is copied to this
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs){
	if(tos == rhs.tos)     // If stacks are the same return 
		return *this;
 
	node<T> *temp;
	while(tos != 0){      // Deallocate everything in this
		temp = tos;
		tos = tos->next;
		delete temp;
	}

	temp = rhs.tos;
	node<T> *bottom = 0;
	while(temp != 0){     // Copy rhs to this
		if(tos == 0){
			tos = new node<T>(temp->data);
			bottom = tos;
		}
		else{
			bottom->next = new node<T>(temp->data);
			bottom = bottom->next;
		}
		temp = temp->next;
	}
	return *this;
}

// SWAP
// REQUIRES:
// ENSURES: this = rhs, rhs = temp(this)
template<typename T>
void Stack<T>::swap(Stack<T> & rhs){
	node<T> *temp = tos;
	tos = rhs.tos;
	rhs.tos = temp;
}

// MOVE ASSIGNMENT
// REQUIRES:
// ENSURES: this = rhs, rhs = this
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T>&& rhs){
	swap(rhs);
	return *this;
}

// MOVE CONSTRUCTOR
// REQUIRES:
// ENSURES:
template<typename T>
Stack<T>::Stack(Stack<T>&& actual){
	tos = actual.tos;
	actual.tos = 0;
}

// ISFULL
// REQUIRES:
// ENSURES: returns true if stack is full, false otherwise
template<typename T>
bool Stack<T>::isFull()const{
	node<T> *temp = new(std::nothrow)node<T>();
	if(temp != 0){      // If there was enough memory for one more node object
		delete temp;
		return false;
	}
	else		    // No memory left
		return true;
}

#endif
