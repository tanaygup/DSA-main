// every number is repeating 3 times except for one
// what we do is take to sum of bits at each position-> if bitsum is of form 3n
// then the unique number has unset bit at that position , If it is of form 
// 3n+1 then unique number is set See the image



#include<iostream>
#include<vector>
using namespace std;

void updateSum(vector<int> &sumArr,int x){

	//Extract all bits of X
	for(int i=0; i<32; i++){
		int ith_bit = x & (1<<i);
		if(ith_bit){
			sumArr[i]++;
		}
	}
}

int numFromBits(vector<int> sumArr){
	int num = 0;
	for(int i=0; i<32; i++){
		num += (sumArr[i] * (1<<i));
	}
	return num;
}

int uniqueNo3(vector<int> arr){
	vector<int> sumArr(32,0); //Fill Constructor
	for(int x : arr){
		updateSum(sumArr,x);
	}

	for(int i=0; i<32; i++){
		sumArr[i] = sumArr[i]%3;
	}
	//An Array of Bits (0 or 1)
	return numFromBits(sumArr);
}

int main(){
	vector<int> arr = {1,3,5,4,3,1,5,5,3,1};
	cout << uniqueNo3(arr);

	return 0;
}