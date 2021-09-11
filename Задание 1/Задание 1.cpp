#include <iostream>
#include <string>
using namespace std;
int allvariant = 2;

int variant(string s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); i++) sum += int(s[i]);
	return (sum % allvariant + 1);
}
int main()
{
	cout << "Enter your Name and Surname\n>>";
	string name, sname;
	cin >> name >> sname;
	cout << "Your variant is " << variant(sname);
}