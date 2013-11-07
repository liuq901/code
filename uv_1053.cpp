#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
struct fact
{
    ll a,b;
    bool nega;
    fact(){}
    fact(int x):a(abs(x)),b(1),nega(x<0){}
    fact rev()
    {
        fact c=*this;
        c.nega=!c.nega;
        return(c);
    }
};
fact operator *(fact a,int b)
{
    fact c=a;
    c.a*=b;
    ll p=__gcd(c.a,c.b);
    c.a/=p,c.b/=p;
    return(c);
}
fact operator /(fact a,int b)
{
    fact c=a;
    c.b*=b;
    ll p=__gcd(c.a,c.b);
    c.a/=p,c.b/=p;
    return(c);
}
bool operator ==(fact a,fact b)
{
    return(a.a==b.a && a.b==b.b && a.nega==b.nega);
}
bool two;
int n,cnt,ans1,ans2,c[10],T[10],b[10];
string ansm,ansh,Minute,Hour,s[10];
fact minute,hour,R,r[10];
char name[10][10];
string get(const string &a)
{
    string ret;
    for (int i=0;i<a.size();i++)
        if (a[i]!='*' && a[i]!='-')
            ret+=a[i];
    return(ret);
}
void update(int num)
{
    ans1=cnt;
    ans2=num;
    ansm=Minute;
    ansh=Hour;
}
void getans(int num)
{
    if (cnt<ans1 || cnt==ans1 && num<ans2)
        update(num);
    if (cnt==ans1 && num==ans2)
    {
        string s,t;
        s=get(ansm)+get(ansh);
        t=get(Minute)+get(Hour);
        if (t<s)
            update(num);
    }
}
void dfs(int dep,bool flag)
{
    if (!flag && Minute!="")
    {
        if (Hour!="")
            getans(dep-1);
        else if (dep!=n+1)
        {
            for (int i=0;i<dep;i++)
            {
                b[dep]=b[i];
                s[dep]=s[b[dep]]+name[c[dep]];
                r[dep]=r[i];
                dfs(dep+1,true);
                if (i>0)
                {
                    cnt++;
                    b[dep]=dep;
                    s[dep]=s[i]+'-'+name[c[dep]];
                    r[dep]=(r[i]*T[c[i]]/T[c[dep]]).rev();
                    if (r[dep]==hour)
                        Hour=s[dep];
                    dfs(dep+1,true);
                    cnt--;
                    Hour="";
                }
            }
        }
        return;
    }
    if (flag && Hour!="")
    {
        getans(dep-1);
        return;
    }
    if (cnt>ans1 || cnt==ans1 && dep>ans2 || dep==n+1)
        return;
    b[dep]=b[dep-1];
    s[dep]=s[b[dep]]+name[c[dep]];
    r[dep]=r[dep-1];
    dfs(dep+1,flag);
    cnt++;
    b[dep]=dep;
    s[dep]=s[dep-1]+'-'+name[c[dep]];
    r[dep]=(r[dep-1]*T[c[dep-1]]/T[c[dep]]).rev();
    if (r[dep]==minute && Minute=="")
        Minute=s[dep];
    if (r[dep]==hour && Hour=="")
        Hour=s[dep];
    dfs(dep+1,flag);
    cnt--;
    if (r[dep]==minute && s[dep]==Minute)
        Minute="";
    if (r[dep]==hour && s[dep]==Hour)
        Hour="";
}
int main()
{
    minute=24,hour=2;
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        ans1=10000; 
        int tmp;
        scanf("%d",&tmp);
        R=tmp;
        for (int i=1;i<=n;i++)
        {
            scanf("%s%d",name[i],&T[i]);
            c[i]=i;
        }
        while (1)
        {
            r[0]=R;
            s[0]='*';
            b[0]=0;
            cnt=1;
            Minute=Hour="";
            if (R==minute)
                Minute=s[0];
            if (R==hour)
                Hour=s[0];
            dfs(1,false);
            if (!next_permutation(c+1,c+n+1))
                break;
        }
        static int id=0;
        if (id)
            printf("\n");
        printf("Trial %d",++id);
        if (ans1==10000)
            printf(" IS IMPOSSIBLE\n");
        else
        {
            printf("\n");
            printf("Minutes: %s\n",ansm.c_str());
            printf("Hours:   %s\n",ansh.c_str());
        }
    }
    return(0);
}

