#include<iostream>
#include<vector>

using namespace std;

void gBuildLPS(string& xPattern, vector<int>& xLPS) 
{
	xLPS.resize(xPattern.size(), 0);
	int i = 0, j =1;
	while(j < xPattern.size()) 
	{
		if (xPattern[i] == xPattern[j]) 
		{
			i++;
			xLPS[j] = i;
			j++;
		}
		else 
		{
			// Mismatch 
			if (i > 0) 
			{
				i = xLPS[i-1];
			}
			else 
			{
				xLPS[j] = 0;
				j++;
			}
		}
	}
	return;
}

vector<int> gFindPattern(string& xText, string& xPattern) 
{
	vector<int> lResult;
	vector<int> lLPS;
	gBuildLPS(xPattern, lLPS);
	int i = 0, j = 0;
	bool lPatternMachingStart = false;
	int lStartOfPatternMatching = -1;
	while (i < xText.size()) 
	{
		if (xText[i] == xPattern[j]) 
		{
			if (!lPatternMachingStart) 
			{
				lStartOfPatternMatching = i;
				lPatternMachingStart = true;
			}
			if (j == xPattern.size()-1) 
			{
				lResult.push_back(lStartOfPatternMatching) ;
				j = lLPS[xPattern.size()-1];
				if (j > 0)
				{
					lStartOfPatternMatching = i -j + 1;
					lPatternMachingStart = true;	
				}	
				else 
				{
					lPatternMachingStart = false;
					j = 0;
					lStartOfPatternMatching = -1;
				}
			}
			else 
				j++;
			i++;
		}
		else
		{
			if (lPatternMachingStart) 
			{
				j = lLPS[j-1];
				if (j > 0) 
				{
					// ALready some pattern matched 
					lStartOfPatternMatching = i -j + 1;
					lPatternMachingStart = true;
				}
				else 
				{
					lPatternMachingStart = false;
					lStartOfPatternMatching = -1;
					i++;
				}
			}
			else 
				i++;
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
