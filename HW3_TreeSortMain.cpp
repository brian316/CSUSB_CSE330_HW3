//BRIAN DUENAS
//5-30-17
// to be used for HW3
// CSE 330, Spring 2017, Kerstin Voigt, May 2017

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "HW3Set.h"
using namespace std;

template <class T>
void tree_sort(vector<T>&);

int main()
{

	vector<int> myvec;

	int k, next;
	cout << "How many items? ";
	cin >> k;
	cout << endl;
	for (int i = 1; i <= k; i++)
	{
		cout << "Number: ";
		cin >> next;
		//cout << endl;
		myvec.push_back(next);
	}
	cout << endl;

	cout << "Items in vector: " << endl;
	for (int i = 0; i < myvec.size(); i++)
		cout << myvec[i] << " ";
	cout << endl << endl;
	
	tree_sort(myvec);

	cout << "Items in sorted vector: " << endl;
	for (int i = 0; i < myvec.size(); i++)
		cout << myvec[i] << " ";
	cout << endl << endl;

	system("Pause");
}

template <class T>
void tree_sort(vector<T>& vec)
{
	Set<T> aset;
	
	// complete in HW3

	for (int i=0; i < vec.size(); i++)
		aset.insert(vec[i]);

	typename Set<T>::iterator itr;

	int i=0;
	for (itr = aset.begin(); itr != aset.end(); itr++){
		vec[i] = *itr;
		i++;
	}

	return;
}

