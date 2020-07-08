#pragma once
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray {
private:
	T* t_array;

	unsigned int currentElements;
	unsigned int maxElements;
	void resizeArray();
	void copy(const DynamicArray<T>& copyArray);

public:
	DynamicArray();
	DynamicArray(unsigned int size);
	~DynamicArray();
	DynamicArray(const DynamicArray<T>& copyArray);

	DynamicArray& operator= (const DynamicArray<T>& copyArray);
	const T& operator[](const unsigned int position) const;
	T& operator[](const unsigned int position);

	void clear();
	void create(unsigned int size = 10);
	unsigned int getSize() const;

	void empty();
	bool isEmpty();

	void pushAt(unsigned int position, const T& new_t);
	void push(const T& new_t);
	void erase(const unsigned int position);
};


template<typename T>
void DynamicArray<T>::pushAt(unsigned int position, const T& new_t) {
	if (currentElements == maxElements)
		resizeArray();
	currentElements++;
	for (unsigned int i = currentElements-1; i > position; i--) {
		t_array[i] = t_array[i - 1];
	}
	t_array[position] = new_t;
}

template<typename T>
void DynamicArray<T>::erase(const unsigned int position) {
	if (position >= currentElements)
		return;
	for (unsigned int i = position; i < currentElements - 1; i++)
		t_array[i] = t_array[i+1];
	currentElements--;
}

template<typename T>
const T& DynamicArray<T>::operator[](const unsigned int position) const {
	return t_array[position];
}

template<typename T>
T& DynamicArray<T>::operator[](const unsigned int position) {
	return t_array[position];
}

template<typename T>
unsigned int DynamicArray<T>::getSize() const {
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
	if (this != &copyArray) {
		copy(copyArray);
	}
}

template<typename T>
void DynamicArray<T>::resizeArray() {
	maxElements *= 1.5;
	T* buffer = new T[maxElements];
	for (unsigned int i = 0; i < currentElements; i++)
		buffer[i] = t_array[i];
	delete[] t_array;
	t_array = buffer;
}

template<typename T>
inline void DynamicArray<T>::copy(const DynamicArray<T>& copyArray) {
	create(copyArray.maxElements);
	currentElements = copyArray.currentElements;
	for (unsigned int i = 0; i < currentElements; i++)
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
void DynamicArray<T>::create(unsigned int size) {
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
DynamicArray<T>::DynamicArray(unsigned int size) {
	create(size);
}

template<typename T>
void DynamicArray<T>::empty() {
	currentElements = 0;
}