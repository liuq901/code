#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
int a[10];
vector <pair <ll,int> > ans;
int get(ll x)
{
    int ret=0;
    while (x)
    {
        ret++;
        x/=10;
    }
    return(ret);
}
void print(ll n,int len,int pos=0)
{
    if (n==-1)
    {
        for (int i=1;i<=len;i++)
            printf("-");
        printf("\n");
        return;
    }
    int space=len-pos-get(n);
    for (int i=1;i<=space;i++)
        printf(" ");
    cout<<n<<endl;
}
int ten[10];
int main()
{
    ten[0]=1;
    for (int i=1;i<10;i++)
        ten[i]=ten[i-1]*10;
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        int tot=0;
        for (int i=m;i;i/=10)
            a[++tot]=i%10;
        int now=1,pos=0;
        ll sum=0;
        ans.clear();
        for (int i=1;i<=tot;i++)
            if (a[i]==0)
                now*=10;
            else
            {
                now*=a[i];
                sum+=ll(now)*n*ten[pos];
                ans.push_back(make_pair(ll(now)*n,pos));
                now=1;
                pos=i;
            }
        static int id=0;
        printf("Problem %d\n",++id);
        int len=get(sum);
        print(n,len);
        print(m,len);
        print(-1,len);
        for (int i=0;i<ans.size();i++)
            print(ans[i].first,len,ans[i].second);
        if (ans.size()>1)
        {
            print(-1,len);
            print(sum,len);
        }
    }
    return(0);
}

