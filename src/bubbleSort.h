#ifndef SRC_BUBBLESORT_H_
#define SRC_BUBBLESORT_H_

#include <iostream>
#include<vector>

using namespace std;

template <class Comparable>
void bubbleSort(vector<Comparable> &v)
{
	for(unsigned int j=v.size()-1; j>0; j--)
	{
		bool troca=false;
		for(unsigned int i = 0; i<j; i++)
			if(v[i+1] < v[i]) {
				swap(v[i],v[i+1]);
				troca = true;
			}
		if (!troca) return;
	}
}

#endif /* SRC_BUBBLESORT_H_ */
