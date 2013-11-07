#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int mod=2011;
char a[30][100];
int inv[mod];
int power(int x,int y)
{
    int ret=1;
    for (int i=1;i<=y;i++)
        ret=ret*x%mod;
    return(ret);
}
bool empty(int x1,int y1,int x2,int y2)
{
    for (int i=x1;i<=x2;i++)
        for (int j=y1;j<=y2;j++)
            if (a[i][j]!='.')
                return(false);
    return(true);
}
bool before(char ch)
{
    return(ch==' ' || ch=='+' || ch=='-' || ch=='*' || ch=='(' || ch=='!');
}
int calc(int x1,int y1,int x2,int y2)
{
    while (empty(x1,y1,x2,y1))
        y1++;
    while (empty(x1,y2,x2,y2))
        y2--;
    while (empty(x1,y1,x1,y2))
        x1++;
    while (empty(x2,y1,x2,y2))
        x2--;
    if (x1==x2 && y1==y2)
        return(a[x1][y1]-'0');
    int base;
    for (int i=x1;i<=x2;i++)
        if (a[i][y1]!='.')
        {
            base=i;
            break;
        }
    char last=' ';
    for (int i=y1;i<=y2;i++)
    {
        if (a[base][i]=='-')
        {
            if (i>y1 && a[base][i-1]=='~' || i<y2 && a[base][i+1]=='-')
                a[base][i]='~';
            if (a[base][i]=='-' && before(last))
                a[base][i]='!';
        }
        if (a[base][i]!='.')
            last=a[base][i];
    }
    int k1,k2,now;
    k1=k2=-1;
    now=0;
    for (int i=y2;i>=y1;i--)
    {
        if (a[base][i]==')')
            now++;
        if (a[base][i]=='(')
            now--;
        if (now==0 && (a[base][i]=='+' || a[base][i]=='-') && k1==-1)
            k1=i;
        if (now==0 && a[base][i]=='*' && k2==-1)
            k2=i;
    }
    if (k1!=-1)
    {
        int x=calc(x1,y1,x2,k1-1),y=calc(x1,k1+1,x2,y2);
        int ans=(a[base][k1]=='+'?x+y:x-y)%mod;
        if (ans<0)
            ans+=mod;
        return(ans);
    }
    if (k2!=-1)
        return(calc(x1,y1,x2,k2-1)*calc(x1,k2+1,x2,y2)%mod);
    if (a[base][y1]=='(' && a[base][y2]==')')
        return(calc(x1,y1+1,x2,y2-1));
    if (a[base][y1]=='!')
        return((mod-calc(x1,y1+1,x2,y2))%mod);
    if (a[base][y2]=='.')
        return(power(calc(x1,y1,x2,y2-1),a[base-1][y2]-'0'));
    return(calc(x1,y1,base-1,y2)*inv[calc(base+1,y1,x2,y2)]%mod);
}
int main()
{
    for (int i=1;i<mod;i++)
        inv[i]=power(i,mod-2);
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int m=strlen(a[1]+1);
        cout<<calc(1,1,n,m)<<endl;
    }
    return(0);
}

