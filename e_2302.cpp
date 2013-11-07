#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,string> a[100010];
char s[100000];
int main()
{
    int x,n=0;
    while (scanf("%s%d",s,&x)==2)
        a[++n]=make_pair(x,s);
    sort(a+1,a+n+1);
    for (int i=2;i<=n;i++)
        if (a[i].first-a[i-1].first<=2)
        {
            printf("%s %s\n",a[i-1].second.c_str(),a[i].second.c_str());
            i++;
        }
    return(0);
}

