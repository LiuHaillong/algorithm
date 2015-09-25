#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string a;
string b;
//char a[101];
//char b[101];
bool StringContain(string &a,string &b)
{
    sort(a.begin(),a.end());
	sort(b.begin(),b.end());
    for(int pa=0,pb=0;pb<b.length();){
    	while((pa<a.length()) && a[pa]<b[pb] ) {
    		++pa;
		}
		if(pa>=a.length() || a[pa]>b[pb]){
			return false;			
		}
		++pb;
	}
	return true;
}

bool StringContain1(string &a,string &b)
{
   for(int i=0;i<b.size();i++){
   		int j;
		for(j=0;j<a.size() && b[i]!=a[j];j++);
	   	if(j>=a.size()){
	   		return false;
		}
   }
   return true;
}

int main(){
	while(true){
		cin>>a>>b;
		bool flag = StringContain(a,b);
		cout<<flag<<endl;	
	}
}

