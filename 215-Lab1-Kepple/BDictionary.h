#pragma once
//indexs and sorting, KV pairs come into play
//starting the BDictionary.h file on 2/2/2026. Building the body of the skeleton left in dictionaryADT.h
#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"

template <class K, class V>
class BDictionary : public Dictionary<K, V> ///inheritance from dictionaryADT
{
private:
	ABag<KVpair<K, V>> theBag; //Bag of KVpair objects to store the dictionary entries, "has-a" relationship

public:
	///constructor and destructor
	BDictionary() {}
	~BDictionary() override = default;

	///function implementations
	void clear() override {
		theBag.emptyBag();
	}

	bool insert(const K& k, const V& v) override { ///inserts a new KVpair into the bag
		KVpair<K, V> newPair(k, v); ///create a new KVpair object with the given key and value
		KVpair<K, V> searchPair(k, V{}); ///take this pair and see if it already exists in the bag
		//the V{} is a default value for V, since we only care about the key for searching, based on my observation of the test.cpp
		if (theBag.find(searchPair)) { 
			return false; ///if found, no duplicate allowed, so return false
		}
		
		return theBag.addItem(newPair); ///add if not found
	}

	bool remove(const K& k, V& rtnVal) override {
		KVpair<K, V> searchPair(k, V{}); ///only care about the key like insert is programmed like

		if (theBag.removeItem(searchPair)) { ///if found and removed
			rtnVal = searchPair.value(); ///update rtnVal with the value from the found pair
			return true;
		}

		return false; ///if record not found, then return false; DIFFERENT than removeAny in this way only
	}

	bool removeAny(V& rtnVal) override {
		KVpair<K, V> removedPair;

		if (theBag.removeTop(removedPair)) {
			rtnVal = removedPair.value();
			return true;
		}
		return false;
	}

	bool search(const K& k, V& rtnVal) const override {
		KVpair<K, V> searchPair(k, V{});

		if (theBag.find(searchPair)) {// find updates searchPair if match
			rtnVal = searchPair.value();          
			return true;
		}

		return false;
	}

	int size() const override {
		return theBag.numItems();
	}
};
