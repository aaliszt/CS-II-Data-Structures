// Aaron Liszt
// CS23001
// node.hpp
// Description: Defenition for node object

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class node{
public:
	T data;
	node<T> *next;
	node(): next(0){};
	node(const T& x): data(x), next(0){};
};

#endif
