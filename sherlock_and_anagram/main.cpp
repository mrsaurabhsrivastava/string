//https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps
//
#include <bits/stdc++.h>

#define TOTAL_CHAR 26
using namespace std;

struct trieNode
{
	trieNode* dChildChar[TOTAL_CHAR];
	int dCount;
	bool dEnd;
	trieNode() 
	{
		memset(dChildChar, 0, sizeof(trieNode*) * TOTAL_CHAR);
		dEnd = false;
		dCount = 0;
	}
};

// return true if inserted successfuly 
// return false if already insrted
bool gInsertNodeInTrie(trieNode* xRoot, string s) 
{
	bool lAlreadyInsrted = true;
	trieNode* lCurrNode = xRoot;
	int i = 0; 
	while(lCurrNode && i < s.size()) 
	{
		if (lCurrNode->dChildChar[s[i]-'a'] == NULL) 
		{
			lAlreadyInsrted = false;
			lCurrNode->dChildChar[s[i]-'a'] = new trieNode();
		}
		lCurrNode = lCurrNode->dChildChar[s[i]-'a'];
		i++;	
	}
	if (lAlreadyInsrted) 
	{
		// Check if end of already string and current inserted strings are same 
		if (lCurrNode->dEnd == false) 
		{
			lAlreadyInsrted = false;
		}
	}
	lCurrNode->dEnd = true;
	lCurrNode->dCount++;
	return !lAlreadyInsrted;
}

int gNc2(int n) 
{
	int lResult = 1;
	if (n == 1) 
		return 1;

	for (int i = n; i > (n-2); i--) 
		lResult *= i;
	return lResult/2;
}

int gNumAnagramAtCurrentNode(trieNode* xNode) 
{
	int lResult = 0;
	if (xNode && xNode->dEnd)
	{
		if (xNode->dCount > 1) 
			return gNc2(xNode->dCount); 
			
	} 
	return 0;
}

int gNumAnagram(trieNode* xRoot) 
{
	int lResult = 0;
	if (xRoot == NULL) 
		return lResult;

	lResult += gNumAnagramAtCurrentNode(xRoot);
	for (int i = 0 ; i < TOTAL_CHAR; i++) 
	{
		lResult+= gNumAnagram(xRoot->dChildChar[i]);
	}
	return lResult;
}
// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
	// Find all substring of s 
	// sort them and insert in trie 
	// if string found already inserted, means we got an anagram
	trieNode* lRoot = new trieNode();
	int lAnagram = 0;
	for (int i = 0 ; i < s.size(); i++) 
	{
		for (int j = 1; j <= s.size()-i; j++) 
		{
			string lSubStr = s.substr(i,j);// i = pos, j = length
			std::sort(lSubStr.begin(), lSubStr.end());
			//cout<<"sub str "<<lSubStr<<endl;	
			if (!gInsertNodeInTrie(lRoot, lSubStr)) 
			{
				lAnagram++;
			}
		}
	}
	return gNumAnagram(lRoot);	

}

int main () 
{
	string s;
	cin>>s;
	cout<<sherlockAndAnagrams(s);
	return 0;
}
