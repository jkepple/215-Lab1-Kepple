// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.
// Modified 04/24/2025 -- Prof Sipantzi
// Modified 11/10/2025 -- Prof Sipantzi

#pragma once

// The Dictionary abstract class.
template <class K, class V>
class  Dictionary {
public:
	Dictionary() {}          // Default constructor
	virtual ~Dictionary() {} // Base destructor

	// Reinitialize dictionary
	virtual void clear() = 0;

	// Insert a record
	// k: The key for the record being inserted.
	// e: The value for the record being inserted.
	// Return true if insert is successful and false otherwise
	virtual bool insert(const K& k, const V& v) = 0;

	// Looks for a record using the key and if found does the following:
	// - updates the V& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	virtual bool remove(const K& k, V& rtnVal) = 0;

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the V& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	virtual bool removeAny(V& rtnVal) = 0;

	// Looks for a record using the key and if found does the following:
	// - updates the V& rtnVal
	// - returns true
	// If the record is not found the function returns false.
	virtual bool search(const K& k, V& rtnVal) const = 0;

	// Return the number of records in the dictionary.
	virtual int size() const = 0;
	  
	// do not make any changes to this file or you will not get
	// any credit for your work -- Prof Sipantzi (09/30/2022)

};

