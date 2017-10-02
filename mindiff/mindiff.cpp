#include <iostream>
#include <algorithm>  //min() --> http://www.cplusplus.com/reference/algorithm/min/
#include <stdlib.h>  //abs(),rand(),srand() -->http://www.cplusplus.com/reference/cstdlib/abs/  http://www.cplusplus.com/reference/cstdlib/rand/ 
#include <time.h>
#include <vector>
#include <stdio.h>
#include <limits.h> // datatype max,min values http://www.cplusplus.com/reference/climits/

using namespace std;


//O(n^2)
int bruteforce(vector<int> L,vector<int> M){
	
	int min=INT_MAX;

	for(int i=0;i<L.size();++i){
		for(int j=0;j<M.size();++j)
			min=std::min(min,abs(L[i]-M[j]));
	}

	return min;
}

//consecutive elements have least difference,hence sort A and B find consecutive elements accross two arrays
//O(nlogn) = O(nogn)+O(nlogn)+2*n

int mindiff(vector<int> L,vector<int> M){

	int min=INT_MAX;
	
	//O(nlogn)
	sort(L.begin(),L.end());
	
	//O(nlogn)
	sort(M.begin(),M.end());

	int i=0;
	int j=0;

	while(i<L.size()&&j<M.size()){

		min=std::min(min,abs(L[i]-M[j]));

		if(L[i]==M[j]){
			++i;
			++j;
		}else if(L[i]<M[j]){
			++i;
		}else{
			++j;
		}

	}

	return min;
}

int main(){

	srand(time(NULL));
	vector<int> A,B;

	int size_a,size_b;
	
	cout<<"Find minimum distance between elements from two arrays"<<endl;
	cout<<"Enter size for array A and B"<<endl;

	cin>>size_a>>size_b;


	//stores random values in vector ranges from 1 to 10;
	for(int i=0;i<size_a;++i)
		A.push_back(rand()%10+1);

	for(int i=0;i<size_b;++i)
		B.push_back(rand()%100+1);


	//print vector values
	for(int i=0;i<size_a;++i)
		cout<<A[i]<<" ";

	cout<<endl;

	for(int i=0;i<size_b;++i)
		cout<<B[i]<<" ";



	cout<<"Choose number from below appraches"<<endl;
	cout<<"1. bruteforce approach -- O(n2)"<<endl;
	cout<<"2. consecutive elements have least difference,hence sort A and B find consecutive elements accross two arrays -- O(nlogn)"<<endl;

	int choose;
	cin>>choose;

	switch(choose){
		case 1:
			cout<<bruteforce(A,B)<<endl;
		break;
		case 2:
			cout<<mindiff(A,B)<<endl;
		break;
		default:
			cout<<"choose numbers in range,please run application again"<<endl;
	}
}
