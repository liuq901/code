#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000000];
int main()
{
    while (1)
    {
        scanf("%s",s);
        int len=strlen(s);
        if (s[0]=='-' && len==1)
            break;
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int n;
            scanf("%d",&n);
            rotate(s,s+n,s+len);
        }
        printf("%s\n",s);
    }
    return(0);
}

