#include<iostream>
#include<vector>

using namespace std;

int getAns(vector<int> v, int m, int k){
	if (v.size()-m>k-1)
		return -1;
	else{
		for(int i=0;i<m;i++){
		for(int j=0;j<=v.size();j++){
		v[j]=v[j]^v[j+1];
		}
		v.pop_back();
		}
		return v[k];
	}
	
	
}

int main(){
	int a[]= {1,2,3,4,5,6,7,8,9,10};
	cout<<min(a[10],9);
	
}
