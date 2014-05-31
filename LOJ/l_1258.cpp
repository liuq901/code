#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[1000010],b[1000010];
int next[1000010],ret[1000010];
void extKMP(char a[],char b[],int m,int n,int next[],int ret[])
{
    int i,j,k;
    for (j=0;j+1<m && a[j]==a[j+1];j++);
    next[1]=j;
    k=1;
    for (i=2;i<m;i++)
    {
        int len=k+next[k],l=next[i-k];
        if (l<len-i)
            next[i]=l;
        else
        {
            for (j=max(0,len-i);i+j<m && a[j]==a[i+j];j++);
            next[i]=j;
            k=i;
        }
    }
    for (j=0;j<n && j<m && a[j]==b[j];j++);
    ret[0]=j;
    k=0;
    for (i=1;i<n;i++)
    {
        int len=k+ret[k],l=next[i-k];
        if (l<len-i)
            ret[i]=l;
        else
        {
            for (j=max(0,len-i);j<m && i+j<n && a[j]==b[i+j];j++);
            ret[i]=j;
            k=i;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a);
        memcpy(b,a,sizeof(a));
        int n=strlen(a);
        reverse(b,b+n);
        extKMP(b,a,n,n,next,ret);
        int ans=1<<30;
        for (int i=0;i<n;i++)
            if (ret[i]==n-i)
                ans=min(ans,i);
        static int id=0;
        printf("Case %d: %d\n",++id,ans+n);
    }
    return(0);
}

