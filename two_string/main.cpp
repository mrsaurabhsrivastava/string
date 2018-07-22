//https://www.hackerrank.com/challenges/two-strings/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
//
#include<iostream>
#include<unordered_set>

using namespace std;

string twoStrings(string s1, string s2) 
{
	unordered_set<char> lSet;
	for (int i = 0; i < s1.size(); i++) 
		lSet.insert(s1[i]);
	
	for (int i = 0; i < s2.size(); i++) 
	{
		if (lSet.find(s2[i]) != lSet.end()) 
			return "YES";
	}
	return "NO";
}

int main () 
{
	string s1 = "hi";
	string s2 = "world";
	cout<<twoStrings(s1,s2);
	return 0;
}

