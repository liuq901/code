#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
pair <char,int> a[100010],b[100010];
int c[100010];
int work(int p,int r)
{
    int x=a[r].second,i=p-1;
    for (int j=p;j<r;j++)
        if (a[j].second<=x)
            swap(a[++i],a[j]);
    swap(a[++i],a[r]);
    return(i);
}
void sort(int p,int r)
{
    if (p<r)
    {
        int q=work(p,r);
        sort(p,q-1);
        sort(q+1,r);
    }
}
inline bool cmp(int x,int y)
{
    return(b[x].second<b[y].second || b[x].second==b[y].second && x<y);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char s[10];
        int x;
        scanf("%s%d",s,&x);
        b[i]=a[i]=make_pair(s[0],x);
        c[i]=i;
    }
    sort(1,n);
    sort(c+1,c+n+1,cmp);
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (a[i]!=b[c[i]])
        {
            flag=false;
            break;
        }
    printf("%s\n",flag?"Stable":"Not stable");
    for (int i=1;i<=n;i++)
        printf("%c %d\n",a[i].first,a[i].second);
    return(0);
}

