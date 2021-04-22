#include "list.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include <string>
using namespace std;

Node::Node()
{
	data = 0;
	next = NULL;
}

Node::Node(int in_data)
{
	data = in_data;
	next = NULL;
}

int Node::getData() const
{
	return data;
}

Node* Node::getNext() const
{
	return next;
}

void Node::setData(int in_data)
{
	data = in_data;
}

void Node::setNext(Node* in_next)
{
	next = in_next;
}

//ostream& operator<<(ostream &os, const Node &input)
//{
//	os << input.getData() << "\n";
//	return os;
//}


List::List()
{
	head = NULL;
	last = NULL;
	size = 0;
}

void List::add(const Node& input)
{
	if (head == NULL)
	{
		head = (Node*)&input;
		size++;
		last = head;
		return;
	}
	else {
		Node* traverse = head;
		Node* tail = NULL;
		while (traverse)
		{
			tail = traverse;
			traverse = traverse->getNext();
		}
		tail->setNext((Node*)&input);
		size++;
		last = tail->getNext();
	}
	return;
}

void List::add(const Node* input)
{
	if (head == NULL)
	{
		head = (Node*)input;
		size++;
		last = head;
		return;
	}
	else {
		Node* traverse = head;
		Node* tail = NULL;
		while (traverse)
		{
			tail = traverse;
			traverse = traverse->getNext();
		}
		tail->setNext((Node*)input);
		size++;
		last = tail->getNext();
	}
	return;
}

void List::del(Node& input)
{
	Node* to_del = &input;
	if (head == NULL)
	{
		cerr << "NO NODE" << endl;
		return;
	}
	else {
		if (size == 1 || head->getNext() == NULL)
		{
			if (head == to_del)
			{
				size--;
				head = NULL;
				last = NULL;
			}
			else {
				cerr << "NO NODE" << endl;
				return;
			}
		}
		else {
			Node* traverse = head;
			Node* tail = head;
			while (traverse != to_del && tail)
			{
				tail = traverse;
				traverse = traverse->getNext();
			}
			if (traverse)
			{
				Node* tmp = traverse->getNext();
				tail->setNext(tmp);
				size--;
			}
			else {
				cerr << "NO NODE" << endl;
				return;
			}
		}
	}
}

List& List::operator+=(const Node& input)
{
	this->add(input);
	return *this;
}

List& List::operator-=(const Node& input)
{
	this->del((Node&)input);
	return *this;
}

int& List::operator[](int i)
{
	int k = 0;
	Node* traverse = head;
	while (traverse && k != i)
	{
		traverse = traverse->getNext();
		k++;
	}
	if (traverse)
	{
		int c = traverse->getData();
		return c;
	}
	else {
		cerr << "OUT OF INDEX" << endl;
		int m = last->getData();
		return m;
	}
}

const int& List::operator[](int i) const
{
	int k = 0;
	assert(i >= 0 && i < size);
	Node* traverse = head;
	while (traverse && k != i)
	{
		traverse = traverse->getNext();
	}
	if (traverse)
	{
		int c = traverse->getData();
		return c;
	}
	else {
		cerr << "OUT OF INDEX" << endl;
		int m = last->getData();
		return m;
	}
}

