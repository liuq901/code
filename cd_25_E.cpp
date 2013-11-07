#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
string s[10];
char buf[100010];
int next[100010],ret[100010];
void extended_KMP(const string &a,const string &b)
{
    int i,j,k,m=a.size(),n=b.size();
    for (j=0;j+1<n && a[j]==a[j+1];j++);
    next[1]=j;
    k=1;
    for (i=2;i<m;i++)
    {
        int len=k+next[k],l=next[i-k];
        if (l<len-i)
            next[i]=l;
        else
        {
            for (j=max(0,len-i);i+j<m && a[j]==a[i+j];j++);
            next[i]=j;
            k=i;
        }
    }
    for (j=0;j<n && j<m && a[j]==b[j];j++);
    ret[0]=j;
    k=0;
    for (i=1;i<n;i++)
    {
        int len=k+ret[k],l=next[i-k];
        if (l<len-i)
            ret[i]=l;
        else
        {
            for (j=max(0,len-i);j<m && i+j<n && a[j]==b[i+j];j++);
            ret[i]=j;
            k=i;
        }
    }
}
int get(const string &a,const string &b)
{
    extended_KMP(b,a);
    for (int i=0;i<a.size();i++)
        if (ret[i]==b.size())
            return(b.size());
    for (int i=b.size()-1;i>=0;i--)
    {
        int p=a.size()-i-1;
        if (p<0)
            continue;
        if (ret[p]==a.size()-p)
            return(i+1);
    }
    return(0);
}
int work(const string &a,const string &b,const string &c)
{
    int p=get(a,b);
    string tmp=a+b.substr(p);
    return(tmp.size()+c.size()-get(tmp,c));
}
int main()
{
    for (int i=1;i<=3;i++)
    {
        scanf("%s",buf);
        s[i]=buf;
    }
    int p[10]={0,1,2,3},ans=1<<30;
    while (1)
    {
        ans=min(ans,work(s[p[1]],s[p[2]],s[p[3]]));
        if (!next_permutation(p+1,p+4))
            break;
    }
    printf("%d\n",ans);
    return(0);
}

