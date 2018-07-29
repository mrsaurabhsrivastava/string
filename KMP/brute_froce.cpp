#include<iostream>
#include<vector>

using namespace std;

vector<int> gFindPattern(string& xText, string& xPattern) 
{
	vector<int> lResult;
	for (int i = 0; i < xText.size()-xPattern.size()+1; i++) 
	{
		if (xText[i] == xPattern[0])	
		{
			// Can start pattern matching 
			int j = i+1;
			bool lMatched = true;
			for (int k = 1; k < xPattern.size(); k++) 
			{
				if (xText[j] != xPattern[k])
				{
					lMatched = false;
					break;
				}
				j++;
			}
			if (lMatched) 
			{
				lResult.push_back(i);
			}
		}
	}
	return lResult;
}

int main () 
{
	string lText;
	string lPattern;
	cin>>lText>>lPattern;
	vector<int> lIndexes = gFindPattern(lText, lPattern);
	for (auto v:lIndexes) 
		cout<<v<<" ";	
}
