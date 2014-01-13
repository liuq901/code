#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string a[40],b[40];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char buf[10];
        scanf("%s",buf);
        a[i]=b[i]=buf;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=n;j>i;j--)
            if (a[j][1]<a[j-1][1])
                swap(a[j],a[j-1]);
        int k=i;
        for (int j=i;j<=n;j++)
            if (b[j][1]<b[k][1])
                k=j;
        swap(b[i],b[k]);
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i])
        {
            flag=false;
            break;
        }
    for (int i=1;i<=n;i++)
        printf("%s%c",a[i].c_str(),i==n?'\n':' ');
    printf("Stable\n");
    for (int i=1;i<=n;i++)
        printf("%s%c",b[i].c_str(),i==n?'\n':' ');
    printf("%s\n",flag?"Stable":"Not stable");
    return(0);
}

