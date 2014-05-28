#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
char buf[100];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        string s,t;
        s=t=buf;
        reverse(s.begin(),s.end());
        static int id=0;
        printf("Case %d: %s\n",++id,s==t?"Yes":"No");
    }
    return(0);
}

