#include <cstdio>
#include <cctype>
#include <utility>
#include <algorithm>
using namespace std;
pair <int,int> a[3000010];
int ans[1000010];
void read(int &x)
{
    char ch;
    while (1)
    {
        ch=getchar();
        if (ch=='-' || isdigit(ch))
            break;
    }
    bool nega=false;
    int &ret=x;
    if (ch=='-')
        nega=true;
    else
        ret=ch-'0';
    while (1)
    {
        ch=getchar();
        if (!isdigit(ch))
            break;
        ret=ret*10+ch-'0';
    }
}
int main()
{
    int n,Q;
    read(n);
    read(Q);
    for (int i=1;i<=n;i++)
    {
        int x;
        read(x);
        a[i]=make_pair(x,0);
    }
    for (int i=1;i<=Q;i++)
    {
        int x,y;
        read(x);
        read(y);
        a[i+n]=make_pair(x,-i);
        a[i+n+Q]=make_pair(y,i);
    }
    sort(a+1,a+n+2*Q+1);
    int cnt=0;
    for (int i=1;i<=n+2*Q;i++)
        if (a[i].second<0)
            ans[-a[i].second]-=cnt;
        else if (a[i].second==0)
            cnt++;
        else
            ans[a[i].second]+=cnt;
    for (int i=1;i<=Q;i++)
        if (ans[i]==0)
            printf("The candies are too short\n");
        else
            printf("%d\n",ans[i]);
    return(0);
}

