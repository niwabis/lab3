#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main() {
	int n = 0;
	int i, j, k, l, m, a, t;

	ifstream inFile("file.in", ios::in);//open file
	inFile >> n;//cin
	int arr[8];
	for (i = 0; i < n; ++i) {
		inFile >> arr[i];
		//cout << arr[i]<<endl;
	}
	vector<int> v(n);//vector

	for ( j = 1; j <= n; j++)
		v.at(j-1) = arr[j-1];


	for (k = 1; k < n; ++k) {
		t = v.at(k);
		l = k - 1;
		for (; l >= 0 && v.at(l) > t; l--)
			v.at(l + 1) = v.at(l);
		v.at(l + 1) = t;
	}

	for (m = 0; m < n; ++m)
		cout << v.at(m) << endl;

	int total = 0;
	for (a = 1; a <= 5; a++)
		total = total + v.at(n - a);
	cout << total << endl;


	return 0;
}
