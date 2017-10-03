#include <iostream>
using namespace std;
void get(int &a,unsigned int &k)
{
	k=1;
	k = k <<= a;
	k = k >>= 1;
}

int main()
{
	int a = 0;
	int b = 4;
	a + b;
	return 0;
}