#include <cstdio>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair <string,int> data;
bool cmp(const data &a,const data &b)
{
    return(a.second>b.second || a.second==b.second && a.first<b.first);
}
data a[110];
char buf[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%s%d",buf,&x);
        a[i]=make_pair(buf,x);
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++)
    {
        if (a[i].second<60)
            break;
        printf("%s %d\n",a[i].first.c_str(),a[i].second);
    }
    return(0);
}

