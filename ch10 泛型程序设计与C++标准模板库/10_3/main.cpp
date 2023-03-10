#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using namespace std;
//InputIterator
template<class T,class IT,class OT>
void mySort(IT first, IT last, OT result)
{
	vector<T> s;
	for (; first != last; ++first)
	{
		s.push_back(*first);
	}

	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);
}
int main()
{

	double a[5] = { 1.1,2.2,3.3,4.5,5.8 };
	mySort<double>(a, a + 5, ostream_iterator<double>(cout, " "));
	cout << endl;

	mySort<int>(istream_iterator<int>(cin), istream_iterator<int>(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
