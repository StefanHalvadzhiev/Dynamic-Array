#pragma once
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
	T* t_array;

	unsigned currentElements;
	unsigned maxElements;
	void resizeArray();
	void copy(const DynamicArray<T>& copyArray);

public:
	DynamicArray();
	DynamicArray(unsigned size);
	~DynamicArray();
	DynamicArray(const DynamicArray<T>& copyArray);

	DynamicArray<T>& operator= (const DynamicArray<T>& copyArray);
	const T& operator[](const unsigned position) const;
	T& operator[](const unsigned position);
	DynamicArray<T>& operator+= (const DynamicArray<T>& other);

	void swap(DynamicArray<T>& other);
	void clear();
	void create(unsigned size = 10);
	unsigned getSize() const;

	void empty();
	bool isEmpty();

	void pushAt(unsigned position, const T& new_t);
	void push(const T& new_t);
	void erase(const unsigned position);
};

template<typename T>
void DynamicArray<T>::swap(DynamicArray<T>& other){

}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator+= (const DynamicArray<T>& other) {
	unsigned size = other.getSize();
	for (unsigned i = 0; i < size; ++i)
		push(other[i]);
	return *this;
}

template<typename T>
DynamicArray<T> operator+ (const DynamicArray<T>& lhs, const DynamicArray<T>& rhs) {
	DynamicArray<T> temp = lhs;
	temp += rhs;
	return temp;
}

template<typename T>
void DynamicArray<T>::pushAt(unsigned position, const T& new_t) {
	if (currentElements == maxElements)
		resizeArray();
	currentElements++;
	for (unsigned i = currentElements-1; i > position; --i)
		t_array[i] = t_array[i - 1];
	
	t_array[position] = new_t;
}

template<typename T>
void DynamicArray<T>::erase(const unsigned position) {
	if (position >= currentElements)
		return;
	for (unsigned i = position; i < currentElements - 1; ++i)
		t_array[i] = t_array[i+1];
	currentElements--;
}

template<typename T>
const T& DynamicArray<T>::operator[](const unsigned position) const {
	return t_array[position];
}

template<typename T>
T& DynamicArray<T>::operator[](const unsigned position) {
	return t_array[position];
}

template<typename T>
unsigned DynamicArray<T>::getSize() const {
	return currentElements;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& copyArray) {
	if (this != &copyArray) {
		clear();
		copy(copyArray);
	}
	return *this;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& copyArray) {
	copy(copyArray);
}

template<typename T>
void DynamicArray<T>::resizeArray() {
	maxElements *= 1.5;
	T* buffer = new T[maxElements];
	for (unsigned i = 0; i < currentElements; ++i)
		buffer[i] = t_array[i];
	delete[] t_array;
	t_array = buffer;
}

template<typename T>
inline void DynamicArray<T>::copy(const DynamicArray<T>& copyArray) {
	create(copyArray.maxElements);
	currentElements = copyArray.currentElements;
	for (unsigned i = 0; i < currentElements; ++i)
		t_array[i] = copyArray.t_array[i];
}

template<typename T>
void DynamicArray<T>::push(const T& new_t) {
	if (currentElements == maxElements)
		resizeArray();
	t_array[currentElements] = new_t;
	currentElements++;
}

template<typename T>
bool DynamicArray<T>::isEmpty() {
	if (currentElements == 0)
		return true;
	return false;
}

template<typename T>
void DynamicArray<T>::clear() {
	if (t_array != nullptr) {
		delete[] t_array;
		t_array = nullptr;
	}
}

template<typename T>
void DynamicArray<T>::create(unsigned size) {
	t_array = new T[size];
	currentElements = 0;
	maxElements = size;
}

template<typename T>
DynamicArray<T>::DynamicArray() {
	create();
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	clear();
}

template<typename T>
DynamicArray<T>::DynamicArray(unsigned size) {
	create(size);
}

template<typename T>
void DynamicArray<T>::empty() {
	currentElements = 0;
}