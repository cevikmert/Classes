#pragma once
using namespace std;
class Node
{
private:
	int data;
	Node* next;
public:
	//friend ostream& operator<<(ostream& os, const Node& input);
	Node();
	Node(int in_data);
	int getData() const;
	Node* getNext() const;
	void setData(int in_data);
	void setNext(Node* in_next);
};

class List
{
private:
	int size;
	Node* head;
	Node* last;
public:
	List();
	void add(const Node& input);
	void add(const Node* input);
	void del(Node& input);
	List& operator+=(const Node& input);
	List& operator-=(const Node& input);
	int& operator[](int i);
	const int& operator[](int i) const;
	//void del(Node* input);
};