#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int n=strlen(s);
        sort(s,s+n);
        int x=atoi(s);
        reverse(s,s+n);
        printf("%d\n",atoi(s)-x);
    }
    return(0);
}

