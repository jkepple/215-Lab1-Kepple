#pragma once
//starting the ABag.h file on 2/2/2026. Building the body of the skeleton left in bagADT.h

#include "bagADT.h"
#include <iostream>
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
	int items = 0; //index starting at 0
public:
	ABag() : storedItems(new T[10]) {} ///constructor of array storedItems; can now hold 10 of T objects

	~ABag() override = default; //destructor

	int bagCapacity() const override {return capacity;}
	int numItems() const override {return items;}

	//Functions
	bool addItem(const T& item) override {
		if (items >= capacity) { ///returns false if no more room in array
			return false;
		}
		storedItems[items] = item; ///otherwise add item to storedItems, increase int items by 1
		items++;
		return true;
	}

	bool operator+=(const T& addend) override {
		return addItem(addend);  // delegate to addItem
	}

	void emptyBag() override {
		items = 0;  // resets the count
	}

	bool removeItem(T& item) override {
		for (int i = 0, i < items; i++) {//iterates through array
			if (storedItem[i] == item) {///check if i == caller's referenced 'item' to remove
				item = storedItem[i];///copy value to item
				for (int k = i; k < items - 1; k++) {///for loop to overwrite caller's 'item', shifting the rest, decreasing the size
					storedItems[k] = storedItems[k+1];
				}
				--items;///decrease size counter
				return true;
			}
		}
		return false;
	}

	bool removeTop(T& returnValue) override {
		if (items == 0) {///same check as addItem
			return false;
		}
		returnValue = storedItems[items-1]; ///when true, grabs the top value, deletes item
		--items;
		return true;
	}

	bool find(T& returnValue) const override {
		for (int i = 0; i < items; i++) {
			if (storedItems[i] == returnValue) {
				returnValue = storedItems[i];
				return true;
			}
		}
		return false;
	}

	bool inspectTop(T& item) const override {
		if (items == 0) {///same check as addItem
			return false;
		}
		
		item = storedItems[items - 1]; ///when true, removes top element to caller to 'peek' at the top of the array
		return true;
	}
	
};