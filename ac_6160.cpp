#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;
const int inf=262626260;
struct state
{
    int a,b;
    char ch;
    state(int a,int b):a(a),b(b){}
};
inline ll Abs(ll x)
{
    return(x<0?-x:x);
}
vector <state> way,now;
int X,ans,a[10];
bool use[10];
void dfs()
{
    for (int i=1;i<=6;i++)
    {
        if (use[i])
            continue;
        if (abs(a[i]-X)<abs(ans-X) || abs(a[i]-X)==abs(ans-X) && now.size()<way.size())
            ans=a[i],way=now;
        if (ans==X)
            return;
        for (int j=i+1;j<=6;j++)
        {
            if (use[j])
                continue;
            now.push_back(state(a[i],a[j]));
            int temp=a[i];
            use[j]=true;
            now.back().ch='+';
            a[i]=temp+a[j];
            dfs();
            if (ans==X)
                return;
            if (temp>=a[j])
            {
                now.back().ch='-';
                a[i]=temp-a[j];
                dfs();
                if (ans==X)
                    return;
            }
            if (Abs(ll(temp)*a[j])<=inf)
            {
                now.back().ch='*';
                a[i]=temp*a[j];
                dfs();
                if (ans==X)
                    return;
            }
            if (a[j]!=0 && temp%a[j]==0)
            {
                now.back().ch='/';
                a[i]=temp/a[j];
                dfs();
                if (ans==X)
                    return;
            }
            swap(now.back().a,now.back().b);
            if (a[j]>=temp)
            {
                now.back().ch='-';
                a[i]=a[j]-temp;
                dfs();
                if (ans==X)
                    return;
            }
            if (temp!=0 && a[j]%temp==0)
            {
                now.back().ch='/';
                a[i]=a[j]/temp;
                dfs();
                if (ans==X)
                    return;
            }
            use[j]=false;
            a[i]=temp;
            now.pop_back();
        }
    }
}
int calc(int x,char ch,int y)
{
    if (ch=='+')
        return(x+y);
    if (ch=='-')
        return(x-y);
    return(ch=='*'?x*y:x/y);
}
void print()
{
    printf("Target: %d\n",X);
    for (int i=0;i<way.size();i++)
        printf("%d %c %d = %d\n",way[i].a,way[i].ch,way[i].b,calc(way[i].a,way[i].ch,way[i].b));
    printf("Best approx: %d\n\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=6;i++)
        {
            scanf("%d",&a[i]);
            use[i]=false;
        }
        scanf("%d",&X);
        ans=a[1];
        way.clear();
        now.clear();
        dfs();
        print();
    }
    return(0);
}

