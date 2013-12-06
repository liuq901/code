#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
char buf[1000000];
int main()
{
    int ans=0;
    while (scanf("%s",buf)==1)
    {
        string a=buf,b=a;
        reverse(b.begin(),b.end());
        ans+=a==b;
    }
    printf("%d\n",ans);
    return(0);
}

