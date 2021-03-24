#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <climits>

class SmallVector {

private:
	int size;
	int capacity;
	int* arr;

public:
	SmallVector();
	SmallVector(int arr[], int size);
	SmallVector(const SmallVector &input);
	void push_back(int x);
	int pop_back();
	void reverse();
	SmallVector& operator+(const SmallVector &input);
	SmallVector& operator*(int x);
	void printVector();
	size_t size();
	int maxElement();
	int minElement();
};

int SmallVector::maxElement(){
	int max = INT_MIN;
	for(int i=0;i<size;i++){
		if(arr[i]>=max){
			max = arr[i];
		}
	}
	return max;
}

int SmallVector::minElement(){
	int min = INT_MAX;
	for(int i=0;i<size;i++){
		if(arr[i]<=min){
			min = arr[i];
		}
	}
	return min;
}

size_t SmallVector::size(){
	return const_cast<size_t>(this->size);
}
SmallVector& SmallVector::operator*(int x){
	for(int i=0;i<size;i++){
		arr[i]*=x;
	}
}

SmallVector& SmallVector::operator+(const SmallVector &input){
	int total_size = this->size+input.size;
	int total_capacity = this->capacity+input.capacity;
	int *ne = new int[total_size];
	memcpy(ne,this->arr,this->size*sizeof(int));
	memcpy((ne+this->size),input.arr,input.size*sizeof(int));
	arr = ne;
	this->size = total_size;
	this->capacity = total_capacity;
	return *(this);
}

void SmallVector::reverse() {
	int m = size;
	for (int i = 0; i < size/2; i++) {
		int k = arr[i];
		arr[i] = arr[m-i-1];
		arr[m - i - 1] = k;
	}

}

int SmallVector::pop_back() {
	if (size > 0) {
		int k = arr[size];
		int* ns = new int[size - 1];
		memcpy(ns, arr, (size - 1) * sizeof(int));
		arr = ns;
		size--;
		return k;
	}
	else {
		return INT_MIN;
	}
}
void SmallVector::printVector() {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

void SmallVector::push_back(int x) {
	if (capacity == size) {
		int* nk = new int[capacity * 2];
		memcpy(nk, arr, size*sizeof(int));
		arr = nk;
		capacity = capacity * 2;
		arr[size] = x;
		size++;
	} else {
		arr[size] = x;
		size++;
	}
}

SmallVector::SmallVector() {
	size = 0;
	capacity = 0;
	arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = 0;
	}
}

SmallVector::SmallVector(int input[], int size) {
	this->size = size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = input[i];
	}
	capacity = size;
}

SmallVector::SmallVector(const SmallVector& input) {
	this->size = input.size;
	this->capacity = input.capacity;
	this->arr = new int[size];
	memcpy(this->arr, input.arr, size * sizeof(int));
}
int main()
{
	int arr[10] = { 10,25,36,48,478,254,11,72,15,69 };
	SmallVector one(arr, 10);
	one.printVector();
	one.push_back(99);
	one.printVector();
	one.push_back(81);
	one.pop_back();
	one.printVector();
	int iks[10] = {1,1,1,1,1,1,1,1,1,1};
	SmallVector two(iks,10);
	SmallVector three = two+one;
	three = three*(-1);
	// one.reverse();
	std::cout << "\n";
	// one.printVector();
	// std::cout << "\n";
	three.printVector();
	return 0;
}