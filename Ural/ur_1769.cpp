#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1000010];
char buf[100010];
int main()
{
    scanf("%s",buf);
    int len=strlen(buf),n=0;
    for (int i=0;i<len;i++)
    {
        int x=0;
        for (int j=0;j<9;j++)
        {
            if (i+j==len)
                break;
            x=x*10+buf[i+j]-'0';
            a[n++]=x;
        }
    }
    a[n++]=0;
    a[n++]=1<<30;
    sort(a,a+n);
    for (int i=1;i<n;i++)
        if (a[i-1]+1<a[i])
        {
            printf("%d\n",a[i-1]+1);
            break;
        }
    return(0);
}

