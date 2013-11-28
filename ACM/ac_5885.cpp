#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <map>
using namespace std;
const int maxn=100010;
map <string,pair <int,int> > M;
void KMP(int n,int *s,int *next)
{
    next[0]=0;
    int now=0;
    next[1]=0;
    for (int i=2;i<=n;i++)
    {
        while (now && s[now+1]!=s[i])
            now=next[now];
        if (s[now+1]==s[i])
            now++;
        next[i]=now;
    }
}
int l1,l2,n,K,cycle[110],key[110],next[110],w1[110],w2[110],s[maxn];
char buf[maxn];
void init(int &len,int *a)
{
    scanf("%s",buf);
    len=strlen(buf);
    for (int i=1;i<=len;i++)
        a[i]=buf[i-1]-'A';
}
string ans;
bool check(pair <int,int> p,int i)
{
    return(p.first+l1<=i || p.second-l2>=i);
}
int work(int l1,int *w1,bool first)
{
    int tot=0;
    for (int i=1;i<=n-l1+1;i++)
    {
        for (int j=1;j<=l1;j++)
        {
            key[j]=s[i+j-1]-w1[j];
            if (key[j]<=0)
                key[j]+=26;
        }
        KMP(l1,key,next);
        int num=0;
        for (int pp=l1;pp;pp=next[pp])
        {
            int p=l1-pp;
            if (p==0)
                continue;
            cycle[++num]=p;
        }
        cycle[++num]=l1;
        for (int j=1;j<=num;j++)
        {
            int p=cycle[j];
            bool flag=true;
            for (int k=1;k<j;k++)
                if (p%cycle[k]==0)
                {
                    flag=false;
                    break;
                }
            if (p>K || !flag)
                break;
            int t;
            if (p==1)
                t=1;
            else
            {
                t=i%p;
                if (t>1)
                    t=p+2-t;
                else
                    t=2-t;
            }
            string tmp;
            for (int j=1;j<=p;j++)
            {
                tmp+=key[t]+'A'-1;
                t++;
                if (t>p)
                    t=1;
            }
            if (first)
                if (!M.count(tmp))
                    M[tmp]=make_pair(i,i);
                else
                    M[tmp].second=i;
            else
                if (M.count(tmp) && check(M[tmp],i))
                    if (tot==0)
                    {
                        tot=1;
                        ans=tmp;
                    }
                    else if (ans!=tmp)
                    {
                        tot=2;
                        goto out;
                    }
        }
    }
out:
    return(tot);
}
void print(int n,string ans)
{
    int t=0;
    for (int i=1;i<=n;i++)
    {
        int p=ans[t++]-'A'+1;
        if (t==ans.size())
            t=0;
        char ch=s[i]+'A'-p;
        if (ch<'A')
            ch+=26;
        printf("%c",ch);
    }
    printf("\n");
}
int main()
{
    while (1)
    {
        scanf("%d",&K);
        if (K==0)
            break;
        init(l1,w1);
        init(l2,w2);
        init(n,s);
        M.clear();
        work(l1,w1,true);
        int tot=work(l2,w2,false);
        if (tot==0)
            printf("impossible\n");
        else if (tot==2)
            printf("ambiguous\n");
        else
            print(n,ans);
    }
    return(0);
}

