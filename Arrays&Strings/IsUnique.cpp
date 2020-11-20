/*
*
* dertermine string has all unique characters.
* what if you cannot use additional data structure.
*
*/

#include <iostream>
#include <string>

bool HasUniqueCharacters(const string& s) {

	bool bOk = true;


	char count[256];

	memset(count, 0, 256);

	for (auto c : s)
	{
		if (1 == count[c])
		{
			count[c]++;
			return false;
		}

		count[c]++;

	}

	return bOk;
}



int main()
{

	cout << "Goutham "			<< (HasUniqueCharacters("Goutham")		? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "Bb "				<< (HasUniqueCharacters("Bb")			? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "Bada "				<< (HasUniqueCharacters("Bada")			? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "@#%^ "				<< (HasUniqueCharacters("@#%^")			? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "!!12 "				<< (HasUniqueCharacters("!!12")			? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "123456789 "		<< (HasUniqueCharacters("123456789")	? "has Unique Characters" : "doesn't have Unique Characters") << endl;
	cout << "9686146849 "		<< (HasUniqueCharacters("9686146849")	? "has Unique Characters" : "doesn't have Unique Characters") << endl;

	return 0;
}