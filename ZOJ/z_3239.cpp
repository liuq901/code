#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <string>
using namespace std;
typedef unsigned long long ull;
const int lq=1813,mod=10007,Maxlen=12;
vector <int> f[Maxlen][mod];
vector <string> b,a[10010];
char buf[100000];
int p;
ull c[100];
inline ull get(char ch)
{
    if (isalpha(ch))
        return(c[ch-'a']);
    if (isdigit(ch))
        return(c[ch-'0'+26]);
    return(c[36]);
}
void gethash(const vector <string> &a,int pos)
{
    ull x=0;
    for (int i=0;i<a.size();i++)
    {
        ull t=get(a[i][0]);
        x+=t;
    }
    f[a.size()-1][x%mod].push_back(pos);
}
bool check(const vector <string> &b,int t)
{
    for (int i=0;i<b.size();i++)
    {
        if (b[i].size()>a[t][i].size())
            return(false);
        for (int j=0;j<b[i].size();j++)
            if (b[i][j]!=a[t][i][j])
                return(false);
    }
    return(true);
}
int getans(const vector <string> &a)
{
    int sum=0;
    ull x=0;
    for (int i=0;i<a.size();i++)
    {
        ull t=get(a[i][0]);
        x+=t;
    }
    int hash=x%mod;
    for (int i=0;i<f[a.size()-1][hash].size();i++)
        if (check(a,f[a.size()-1][hash][i]))
        {
            sum++;
            p=f[a.size()-1][hash][i];
        }
    return(sum);
}
int main()
{
    c[0]=1;
    for (int i=1;i<37;i++)
        c[i]=c[i-1]*lq;
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<Maxlen;i++)
            for (int j=0;j<mod;j++)
                f[i][j].clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%s",buf);
            int len=strlen(buf);
            a[i].clear();
            string tmp;
            for (int j=1;j<len;j++)
            {
                if (buf[j]=='/')
                {
                    a[i].push_back(tmp);
                    tmp="";
                    continue;
                }
                tmp+=buf[j];
            }
            a[i].push_back(tmp);
            gethash(a[i],i);
        }
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%s",buf);
            b.clear();
            int len=strlen(buf);
            string tmp;
            for (int i=1;i<len;i++)
            {
                if (buf[i]=='/')
                {
                    b.push_back(tmp);
                    tmp="";
                    continue;
                }
                tmp+=buf[i];
            }
            b.push_back(tmp);
            int t=getans(b);
            if (t==1)
            {
                for (int i=0;i<a[p].size();i++)
                    printf("/%s",a[p][i].c_str());
                printf("\n");
            }
            else
                printf("%d\n",t);
        }
    }
    return(0);
}

