#include <cstdio>
#include <cctype>
#include <vector>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
struct card
{
    char now;
    card(){}
    card(char l,char k)
    {
        int level,kind;
        if (isdigit(l))
            level=l-'0';
        else if (l=='A')
            level=1;
        else if (l=='T')
            level=10;
        else if (l=='J')
            level=11;
        else if (l=='Q')
            level=12;
        else if (l=='K')
            level=13;
        if (k=='s')
            kind=0;
        else if (k=='h')
            kind=1;
        else if (k=='c')
            kind=2;
        else if (k=='d')
            kind=3;
        now=level*4+kind;
    }
    int level() const
    {
        return(now>>2);
    }
    int kind() const
    {
        return(now&3);
    }
};
vector <card *> all[10];
bool operator <(card a,card b)
{
    if (a.level()!=b.level())
        return(a.level()<b.level());
    return(a.kind()<b.kind());
}
inline bool operator ==(card a,card b)
{
    return(a.level()==b.level() && a.kind()==b.kind());
}
int bitcount(int x)
{
    int ret=0;
    while (x)
    {
        ret+=x&1;
        x>>=1;
    }
    return(ret);
}
ll C(int a,int b)
{
    int ret=1;
    for (int i=1;i<=b;i++)
        ret*=a-i+1;
    for (int i=1;i<=b;i++)
        ret/=i;
    return(ret);
}
bool isflush(const vector <card> &a)
{
    int kind=a[0].kind();
    for (int i=1;i<5;i++)
        if (a[i].kind()!=kind)
            return(false);
    return(true);
}
int isstraight(vector <card> a)
{
    sort(a.begin(),a.end());
    if (a[0].level()==1 && a[1].level()==10 && a[2].level()==11 && a[3].level()==12 && a[4].level()==13)
        return(2);
    for (int i=1;i<5;i++)
        if (a[i].level()!=a[i-1].level()+1)
            return(0);
    return(1);
}
int getkind(const vector <card> &a)
{
    bool flush=isflush(a);
    int straight=isstraight(a);
    if (flush && straight==2)
        return(9);
    if (flush && straight==1)
        return(8);
    if (flush)
        return(5);
    if (straight)
        return(4);
    int f[20]={0};
    for (int i=0;i<5;i++)
        f[a[i].level()]++;
    int c[5]={0};
    for (int i=1;i<=13;i++)
        c[f[i]]++;
    if (c[4]==1)
        return(7);
    if (c[3]==1 && c[2]==1)
        return(6);
    if (c[3]==1)
        return(3);
    if (c[2]==2)
        return(2);
    if (c[2]==1)
        return(1);
    return(0);
}
vector <card> lq,now;
int tot;
void work()
{
    int t=getkind(now);
    tot++;
    if (t==0)
        return;
    sort(now.begin(),now.end());
    card *p=new(card[5]);
    for (int i=0;i<5;i++)
        p[i]=now[i];
    all[t].push_back(p);
}
void dfs(int dep,int pos)
{
    if (dep==6)
    {
        work();
        return;
    }
    for (int i=pos;i<lq.size();i++)
    {
        now.push_back(lq[i]);
        dfs(dep+1,i+1);
        now.pop_back();
    }
}
void init()
{
    for (int i=1;i<=13;i++)
        for (int j=0;j<4;j++)
        {
            card t;
            t.now=i*4+j;
            lq.push_back(t);
        }
    dfs(1,0);
}
int v[10],len[10];
card **p[10];
int main()
{
    tot=0;
    init();
    int T;
    scanf("%d",&T);
    for (int i=1;i<=9;i++)
    {
        len[i]=all[i].size();
        p[i]=new(card *[len[i]]);
        for (int j=0;j<len[i];j++)
            p[i][j]=all[i][j];
        all[i].clear();
    }
    while (T--)
    {
        for (int i=1;i<=9;i++)
            scanf("%d",&v[i]);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            char s[10];
            lq.clear();
            for (int i=0;i<5;i++)
            {
                scanf("%s",s);
                lq.push_back(card(s[0],s[1]));
            }
            int f[40]={0};
            for (int i=1;i<=9;i++)
                for (int j=0;j<len[i];j++)
                {
                    int state=0;
                    for (int k=0;k<5;k++)
                        for (int q=0;q<5;q++)
                            if (lq[k]==p[i][j][q])
                            {
                                state|=1<<k;
                                break;
                            }
                    f[state]+=v[i];
                }
            double ans=0;
            for (int i=0;i<32;i++)
            {
                double now=double(f[i])/(C(47,5-bitcount(i)));
                ans=max(ans,now);
            }
            printf("%.10f\n",ans);
        }
    }
    return(0);
}

