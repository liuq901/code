#include <cstdio>
#include <algorithm>
using namespace std;
int a[110],b[110],p[110];
char s[110][1000];
bool cmp(int x,int y)
{
    return(a[x]<a[y] || a[x]==a[y] && b[x]<b[y]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%s%s",s[i],s[0]);
        if (s[0][0]=='r')
            a[i]=0;
        else if (s[0][0]=='w' || s[0][0]=='c' && s[0][1]=='h')
            a[i]=1;
        else if (s[0][0]=='m')
            a[i]=2;
        else
            a[i]=3;
        b[i]=p[i]=i;
    }
    sort(p+1,p+n+1,cmp);
    for (int i=1;i<=n;i++)
        printf("%s\n",s[p[i]]);
    return(0);
}

