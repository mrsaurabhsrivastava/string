//https://www.hackerrank.com/challenges/count-triplets-1/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=dictionaries-hashmaps

#include<iostream>
#include<vector>

using namespace std;

long countTriplets(vector<long> arr, long r) {

	vector<bool> lCanFormTripletArr(arr.size(), false);
	vector<long> lHowManyTripletCanForm(arr.size(), 0);
	
	for (int i = 0; i < arr.size(); i++) 
	{
		if (arr[i] % r == 0) 
		{
			long lLastGPElement = arr[i]/r;
			for (int j = i-1; j >= 0; j--) 
			{
				if (arr[j] == lLastGPElement) 
				{
					lCanFormTripletArr[i] = true;
					break;
				}
			}
		}
	}
	
	for (int i = 0; i < arr.size(); i++) 
	{
		if (lCanFormTripletArr[i]) 
		{
			long lLastGPElement = arr[i]/r;
			for (int j = i-1; j >=0; j--) 
			{
				if (lLastGPElement == arr[j] &&
				    lCanFormTripletArr[j] == true) 
				{
					if (lHowManyTripletCanForm[j] == 0) 
						lHowManyTripletCanForm[i] += 1;
					else 
						lHowManyTripletCanForm[i] += lHowManyTripletCanForm[j];
				}
				
			}
		}
	}
	long lTotalGp = 0;
	for (int i =0; i < lHowManyTripletCanForm.size(); i++) 
	{
		lTotalGp += lHowManyTripletCanForm[i];
	}	
	return lTotalGp;
}

int main() 
{
	vector<long> arr(100,1);
	int r = 1;
	cout<<countTriplets(arr, r)<<endl;
	return 0;
}
