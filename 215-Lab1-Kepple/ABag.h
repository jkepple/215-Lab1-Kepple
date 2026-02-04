#pragma once
//starting the ABag.h file on 2/2/2026. Building the body of the skeleton left in bagADT.h

#include "bagADT.h"
#include <stdlib.h>
#include <memory> //for smart pointers

//addItemm and +=, use the add function is the same as +=
//+= can call addItem

//pointer arrays= std::unique_ptr<E[]> bag creates the array.....then bag=std::unique_ptr<E[]> name (size); <---use in constructor....++ on a pointer moves the pointer to the next location in memory

template <class T>
class ABag : public Bag<T> ///inherits bagADT
{
private: 
	std::unique_ptr<T[]> storedItems; //declaration of array, smart ptr used for managing memory automatically, deletion of it too
	int capacity = 10; //size declared per test
	int used = 0; //index starting at 0
public:
	ABag() : storedItems(new T[10]) {} ///constructor of array storedItems; can now hold 10 of T objects

	~ABag() override = default; //destructor

	int bagCapacity() const override { return capacity; }
	int numItems() const override { return used; }

	//Functions
	bool addItem(const T& item) override {
		if (used >= capacity) return false;
		storedItems[used] = item;
		++used;
		return true;
	}

	bool operator+=(const T& addend) override {
		return addItem(addend);  // delegate to addItem
	}

	void emptyBag() override {
		used = 0;  // resets the count
	}

	// Stub functions for later build
	bool removeItem(T& item) override {
		return false;  // Stub: not found
	}

	bool removeTop(T& returnValue) override {
		return false;  // Stub: empty
	}

	bool find(T& returnValue) const override {
		return false;  // Stub: not found
	}

	bool inspectTop(T& item) const override {
		return false;  // Stub: empty
	}
	
};