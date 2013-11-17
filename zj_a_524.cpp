#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        string s;
        for (int i=n;i;i--)
            s+=char(i+'0');
        while (1)
        {
            printf("%s\n",s.c_str());
            if (!prev_permutation(s.begin(),s.end()))
                break;
        }
    }
    return(0);
}

