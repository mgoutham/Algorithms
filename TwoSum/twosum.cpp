#include <iostream>
#include <stdlib.h> //rand(),srand() --> http://www.cplusplus.com/reference/cstdlib/rand/ 
#include <vector>
#include <algorithm> //sort(),binary_search() --> http://www.cplusplus.com/reference/algorithm/sort/   http://www.cplusplus.com/reference/algorithm/binary_search/
#include <time.h>
#include <unordered_set> // http://www.cplusplus.com/reference/unordered_set/unordered_set/

using namespace std;

//all the pairs of array are added up to check with key value
//O(n2)
bool bruteforce(vector<int>L,int k){

	for(int i=0;i<L.size();++i){
		for(int j =i+1;j<L.size();++j){
			int temp = L.at(i)+L.at(j);
			if(temp==k)
				return true;
		}
	}

	return false;

}


//get key=search-A[i] and search for key in array.
//O(nlogn)

bool sortArraySearchforDifferencevalue(vector<int>L,int k){

	//sort array 
	//O(nlogn)
	sort(L.begin(),L.end());

	//O(nlogn)
	for(int i=0;i<L.size();i++){
		int temp = k - L.at(i);
		if(binary_search(L.begin()+i+1,L.end(),temp)){
			return true;
		}
	}
	return false;
}


//using hash_set data structure o(n)

bool hashSetApproach(vector<int>L,int k){

	unordered_set <int> set;
	unordered_set <int>::iterator set_it;

	for(int i=0;i<L.size();++i){

		int tmp = k - L.at(i);
		set_it = set.find(tmp);

		if(set_it == set.end())
			set.insert(L.at(i));
		else
			return true;
	}

	return false;
}

//Two pointer on sorted array
//0(n-2)

bool twoPointer(vector<int>L,int k){

	//sort array 
	//O(nlogn)
	sort(L.begin(),L.end());

	int i=0;
	int j= L.size()-1;
	
	while(i<j){
		
		if(k==L.at(i)+L.at(j))
			return true;
		else if (k>(L.at(i)+L.at(j)))
			++i;
		else
			--j;
	}

	return false;
	
}

int main(int argv,char *arg[])
{

	int sizeOfArray;
	int search;

	/* initialize random seed: */
	srand (time(NULL));

	cout<<"Enter Size of array for Two Sum Problem"<<endl;
	cin>>sizeOfArray;

	vector<int> v(sizeOfArray);

	//stores random values in vector ranges from 1 to 10;
	for(int i=0;i<v.size();i++){
		v[i]=rand()%10+1;
	}

	//print vector values
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;

	cout<<"Enter the search value"<<endl;
	cin>>search;
	
	cout<<"Choose number from below appraches"<<endl;
	cout<<"1. bruteforce approach O(n2)"<<endl;
	cout<<"2. search for difference value in sorted array O(nlogn)"<<endl;
	cout<<"3. hash set approach O(n)"<<endl;
	cout<<"4. two pointer O(n-2)"<<endl;

	int choose;
	cin>>choose;

	switch(choose){

		case 1:
			if(bruteforce(v,search))
				cout<<"success"<<endl;
			else
				cout<<"Not Success"<<endl;
		break;


		case 2:
			if(sortArraySearchforDifferencevalue(v,search))
				cout<<"success"<<endl;
			else
				cout<<"Not Success"<<endl;
		break;

		case 3:
			if(hashSetApproach(v,search))
				cout<<"success"<<endl;
			else
				cout<<"Not Success"<<endl;
		break;

		case 4:
			if(twoPointer(v,search))
				cout<<"sucess"<<endl;
			else
				cout<<"Not Success"<<endl;

		default:
			cout<<"choose number in range,please run application again"<<endl;

	}
	
	return 0;
}
