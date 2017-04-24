#pragma once
#include "stdafx.h"

template <typename Node, typename T>
class Iterator
{
private:
	Node * node;
public:
   Iterator(Node* _ptr) :node(_ptr) {}
   Iterator& operator ++ () {
	   if (node != NULL)
		   node = node->next;
	   return *this;
   }
   Iterator& operator -- () {
	   if (node != NULL)
		   node = node->prev;
	   return *this;
   }
   T& operator*() {
	   return node->data;
   }
   Node* operator&() {
	   return node;
   }
   bool operator == (Iterator<Node,T> _ptr) {
	   return (node == &_ptr);
   }
   bool operator != (Iterator<Node,T> _ptr) {
	   return (node != &_ptr);
   }

  /* bool operator <= (Iterator<Node, T> _ptr) {
	   return (node <= &_ptr);
   }*/
};

