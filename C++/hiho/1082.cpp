#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
using namespace std;

int main()
{
    string s,sa;
    string a="marshtomp";
    while(getline(cin,s))
    {
        int i,j,l=s.size(),k,flag;
        sa="";
        int ll = a.size();
        for(i = 0; i < l; i++)
        {
            for(j = 0; j < ll; j++)
                if(i + j > l || tolower(s[i+j]) != a[j]){
                	printf("%c",s[i]);
                	break;
				}
                    
                if(j == ll)
                {
                    printf("fjxmlhx");
                    i += ll - 1;
                }
                    
        }
        printf("\n");
    }
    return 0;
}

