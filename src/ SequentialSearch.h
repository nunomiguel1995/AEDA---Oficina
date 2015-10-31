#ifndef SRC__SEQUENTIALSEARCH_H_
#define SRC__SEQUENTIALSEARCH_H_

#include <iostream>
#include <vector>

using namespace std;

int SequentialSearch(const vector<int> &v, int x)
{
for (unsigned int i = 0; i < v.size(); i++)
if (v[i] == x)
return i; // encontrou
return -1; // não encontrou
}

#endif /* SRC__SEQUENTIALSEARCH_H_ */
