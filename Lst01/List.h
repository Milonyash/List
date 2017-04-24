#pragma once
#include "stdafx.h"
#include "Iterator.h"

template <typename T>
class List
{
	struct Node {
		Node *prev;
		Node *next;
		T data;
	};
private:
	Node *head;
	Node *tail;
	int count;
public:
	typedef Iterator<Node,T> iterator;
	List() :head(NULL), tail(NULL), count(0) {}
	~List() {
		this->clear();
	}
	void Add(T x) {
		Node *temp = new Node;
		temp->next = NULL;
		temp->data = x;
		if (head != NULL)
		{
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
			count++;
		}
		else
		{
			temp->prev = NULL;
			head = tail = temp;
			count++;
		}
	}
	void Delete(int Number) {
		
		if (Number == 0)
		{
			Node* temp = head;
			head->next->prev = NULL;
			head = head->next;
			delete temp;
			count -= 1;
		}
		if (Number == count - 1)
		{
			Node* temp = tail;
			tail->prev->next = NULL;
			tail = tail->prev;
			delete temp;
			count -= 1;
		}
		if (Number>0 && Number<count - 1)
		{
			Node* temp = head;
			for (int i = 0; i<Number; i++)
			{
				temp = temp->next;
			}
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			count -= 1;
		}
	}

	iterator begin()
	{
		return iterator(head);
	}

	iterator end()
	{
		return nullptr;
	}

	void clear() {
		while (head)
		{
			tail = head->next;
			delete head;
			head = tail;
		}
		count = 0;
	}

};

