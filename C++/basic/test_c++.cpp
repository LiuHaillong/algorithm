#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int a;
	for(int i=1;i<=5;i++){
		scanf("%d",&a);
		v.push_back(a);
	}
	for(int i=1;i<=v.size();i++){
		cout<<v[i-1]<<endl;
	}
	
	getchar();getchar();
	return 0;
}
