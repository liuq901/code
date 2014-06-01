#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
bool use[26];
unsigned N,ret[50][50],x[50][50];
void multiply(unsigned a[][50],unsigned b[][50],unsigned c[][50])
{
    unsigned d[50][50]={0};
    for (int i=0;i<N;i++)
        for (int j=0;j<N;j++)
            for (int k=0;k<N;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
void power(int n)
{
    for (;n;n>>=1)
    {
        if (n&1)
            multiply(ret,x,ret);
        multiply(x,x,x);
    }
}
int calc(const string &s,const string &t)
{
    for (int i=0;i<=s.size();i++)
        if (s.substr(i)==t.substr(0,s.size()-i))
            return(s.size()-i);
}
void gen(string s)
{
    memset(x,0,sizeof(x));
    for (int i=0;i<s.size();i++)
        for (int j=0;j<26;j++)
        {
            if (!use[j])
                continue;
            int len=calc(s.substr(0,i)+char(j+'a'),s);
            if (len<s.size())
                x[i][len]++;
        }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        char s[60];
        scanf("%d%s",&n,s);
        memset(use,0,sizeof(use));
        int len=strlen(s);
        for (int i=0;i<len;i++)
            use[s[i]-'a']=true;
        scanf("%s",s);
        N=strlen(s);
        gen(s);
        memset(ret,0,sizeof(ret));
        for (int i=0;i<N;i++)
            ret[i][i]=1;
        power(n);
        unsigned ans=0;
        for (int i=0;i<N;i++)
            ans+=ret[0][i];
        static int id=0;
        printf("Case %d: %u\n",++id,ans);
    }
    return(0);
}

