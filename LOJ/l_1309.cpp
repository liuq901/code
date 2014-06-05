#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
inline pair <int,int> operator +(const pair <int,int> &a,const pair <int,int> &b)
{
    return(make_pair(a.first+b.first,a.second+b.second));
}
inline pair <int,int> operator -(const pair <int,int> &a,const pair <int,int> &b)
{
    return(make_pair(a.first-b.first,a.second-b.second));
}
inline pair <int,int> operator *(const pair <int,int> &a,const pair <int,int> &b)
{
    return(make_pair(a.first*b.second+b.first*a.second,a.second*b.second));
}
char s[110];
pair <int,int> calc(int l,int r)
{
    if (l==r && s[l]=='x')
        return(make_pair(1,0));
    int cnt=0;
    for (int i=r;i>=l;i--)
    {
        if (s[i]==')')
            cnt++;
        if (s[i]=='(')
            cnt--;
        if (cnt==0 && (s[i]=='+' || s[i]=='-'))
            return(s[i]=='+'?calc(l,i-1)+calc(i+1,r):calc(l,i-1)-calc(i+1,r));
    }
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            cnt++;
        if (s[i]==')')
            cnt--;
        if (cnt==0 && s[i]=='*')
            return(calc(l,i-1)*calc(i+1,r));
    }
    if (s[l]=='(' && s[r]==')')
        return(calc(l+1,r-1));
    int ret=0;
    for (int i=l;i<=r;i++)
        ret=ret*10+s[i]-'0';
    return(make_pair(0,ret));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int len=strlen(s),pos;
        for (int i=0;i<len;i++)
            if (s[i]=='=')
            {
                pos=i;
                break;
            }
        pair <int,int> ans=calc(0,pos-1)-calc(pos+1,len-1);
        static int id=0;
        printf("Case %d: ",++id);
        if (ans.first==0)
            printf("%s\n",ans.second==0?"infinitely many solutions":"no solution");
        else
        {
            int p=__gcd(ans.first,ans.second);
            ans.first/=p,ans.second/=-p;
            if (ans.first<0)
                ans.first*=-1,ans.second*=-1;
            if (ans.first==1)
                printf("%d\n",ans.second);
            else
                printf("%d/%d\n",ans.second,ans.first);
        }
    }
    return(0);
}

