#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
bool prime[20];
int to[40330];
map <int,int> M;
void init()
{
    int a[8];
    for (int i=0;i<8;i++)
        a[i]=i+1;
    int cnt=0;
    while (1)
    {
        cnt++;
        int sum=0;
        for (int i=0;i<8;i++)
            sum=sum*10+a[i];
        M[sum]=cnt;
        to[cnt]=sum;
        if (!next_permutation(a,a+8))
            break;
    }
    prime[2]=prime[3]=prime[5]=prime[7]=prime[11]=prime[13]=prime[17]=prime[19]=true;
}
int vis[40330],d[40330];
bool sign[10];
queue <int> Q;
vector <int> get(int x)
{
    vector <int> ret(8);
    int tmp=to[x];
    for (int i=7;i>=0;i--)
    {
        ret[i]=tmp%10;
        tmp/=10;
    }
    return(ret);
}
int get(const vector <int> &a)
{
    int ret=0;
    for (int i=0;i<8;i++)
        ret=ret*10+a[i];
    return(M[ret]);
}
bool check(int x,int y)
{
    return(sign[x]!=sign[y] && prime[x+y]);
}
void update(int y,int x,int id)
{
    if (vis[y]!=id)
    {
        vis[y]=id;
        d[y]=d[x]+1;
        Q.push(y);
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        vector <int> a(8);
        for (int i=0;i<8;i++)
        {
            scanf("%d",&a[i]);
            sign[abs(a[i])]=a[i]<0;
            a[i]=abs(a[i]);
        }
        static int id=0;
        printf("Case %d: ",++id);
        int S=get(a);
        Q.push(S);
        vis[S]=id;
        d[S]=0;
        while (!Q.empty())
        {
            int x=Q.front();
            Q.pop();
            vector <int> a=get(x);
            for (int i=0;i<8;i++)
            {
                int y=a[i];
                a.erase(a.begin()+i);
                for (int j=0;j<7;j++)
                    if (check(a[j],y))
                    {
                        a.insert(a.begin()+j,y);
                        update(get(a),x,id);
                        swap(a[j],a[j+1]);
                        update(get(a),x,id);
                        a.erase(a.begin()+j+1);
                    }
                a.insert(a.begin()+i,y);
            }
        }
        if (vis[1]!=id)
            printf("-1\n");
        else
            printf("%d\n",d[1]);
    }
    return(0);
}

