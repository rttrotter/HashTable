#include "htable.h"

#define N1 10  // num of decimal digits
#define N2 26  // num of upper-case letters

// Hash function, you may NOT modify this function
int HT::hash(const string &s) {
  int n = (N2 * N1) * (s[0] - 'A') + N1 * (s[1] - 'A') + (s[2] - '0');

  return n % hsize;
}



/****************************************************
Name: Tyler Trotter
id: z1802019
Class: cis 340
assignment 9
I certify that this is my own work with the exception of the 
code provided by NIU

****************************************************/
// You will complete the code below ...
/********************************************
mysort(entry *, entry)
output: bool
Purpose Lambda function for sort in the ptable
*********************************************/
bool mySort(Entry *i, Entry *j)
{
	return(i->key < j->key);
};
//constructor
HT::HT(const unsigned &hs)
{
	hsize = hs;//define our size
	hTable.resize(hs); //establish our hash table according to the input size
}
//deconstructor
HT::~HT() 
{
	while(hTable.size() != 0)//while our table still has things in it
	{
		while(hTable.back().size() != 0)//while our list has things in it
			hTable.back().pop_back();//pop all the things in the list
		hTable.pop_back();//pop the list
	}
	while(pTable.size() != 0)//clear the pointer table
	{
		pTable.pop_back();
	}
}
/**********************************************
Void insert(const Entry&)
Purpose: to insert a new entry into our hash table
if an entry doesn't already exist 

***********************************************/
void HT::insert(const Entry &e) 
{
	int h = hash(e.key); //pull our key from the hash function
	bool found = false;//trigger for next if statement
	for(Entry data : hTable[h])
	{
		if(e.key == data.key)
		{
			cout << " Error: Entry exists" << endl;
			found = true;
			break;
		}
	}
	if(!found)
	{
		cout << " Hash Index: " << h << endl;
		hTable[h].push_front(e); // add Entry to our hash table
		pTable.push_back(&(hTable[h].back())); // add our pointer that points to entry. 
		
	}
	
}
/**************************************************
Search(const String &)
Purpose: to find if the given key with the provided string
is in our hash table


***************************************************/
void HT::search(const string &s) 
{
	int h = hash(s); //hash the string
	bool error = true;// if it's not found this will remain true
	for(Entry e : hTable[h])//iterate through the list found at the key's hash value
	{
		if(e.key == s)
		{
			cout << " Found: key: " << e.key << "num: " << e.num << ", desc: " << e.desc << endl;
			error = false;
		}
	}
	if(error)
	{
		cout << " Error, no entry found" << endl;
	}
	
}
/***************************************************
hTable_Print

purpose: Print out from first list, to last list in the hash table
***************************************************/
void HT::hTable_print() 
{
	for(list<Entry> l : hTable)//iterate through the hash table
	{
		for(Entry e : l)//iterate through the lists in the hash table
		{
			cout << e.key << ", " << e.num << ", " << e.desc << endl;
			
		}
	}
}

/*******************************************
ptable_print
Purpose: Prints out all of the entries in order
by their key.

*******************************************/
void HT::pTable_print() 
{
	sort(pTable.begin(), pTable.end(), mySort);//uses our lambda function from earlier to sort the pointers
	for(Entry *e : pTable)// iterate through the table and print out the entries
	{
			cout << e->key << ", " << e->num << ", " << e->desc   << endl;
	}
}

