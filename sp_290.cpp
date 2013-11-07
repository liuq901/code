#include <cstdio>
#include <cctype>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
const double error=1e-5,infi=100;
double a[10],x[10];
int n;
int sign(double x)
{
    return(x<-error?-1:x>error);
}
double f(double *a,int n,double x)
{
    double tmp=1,sum=0;
    for (int i=0;i<=n;i++)
    {
        sum+=a[i]*tmp;
        tmp*=x;
    }
    return(sum);
}
double binary(double l,double r,double *a,int n)
{
    int sl=sign(f(a,n,l)),sr=sign(f(a,n,r));
    if (sl==0)
        return(l);
    if (sr==0)
        return(r);
    if (sl*sr>0)
        return(infi);
    while (r-l>error)
    {
        double mid=(l+r)/2;
        int ss=sign(f(a,n,mid));
        if (ss==0)
            return(mid);
        if (ss*sl>0)
            l=mid;
        else
            r=mid;
    }
    return(l);
}
void solve(int n,double *a,double *x,int &nx)
{
    if (n==1)
    {
        x[1]=-a[0]/a[1];
        nx=1;
        return;
    }
    double da[10],dx[10];
    int ndx;
    for (int i=n;i;i--)
        da[i-1]=a[i]*i;
    solve(n-1,da,dx,ndx);
    nx=0;
    if (ndx==0)
    {
        double tmp=binary(-infi,infi,a,n);
        if (tmp<infi)
            x[++nx]=tmp;
        return;
    }
    double tmp=binary(-infi,dx[1],a,n);
    if (tmp<infi)
        x[++nx]=tmp;
    for (int i=1;i<=ndx-1;i++)
    {
        tmp=binary(dx[i],dx[i+1],a,n);
        if (tmp<infi)
            x[++nx]=tmp;
    }
    tmp=binary(dx[ndx],infi,a,n);
    if (tmp<infi)
        x[++nx]=tmp;
}
char s[310];
string S;
void init()
{
    for (int i=0;i<=6;i++)
        a[i]=0;
    S=s;
    string A[10];
    int l=0,t=0;
    for (int i=1;i<S.size();i++)
        if (S[i]=='+' || S[i]=='-')
        {
            A[++t]=S.substr(l,i-l);
            l=i;
        }
    A[++t]=S.substr(l);
    for (int i=1;i<=t;i++)
    {
        int k=A[i].size();
        for (int j=0;j<A[i].size();j++)
            if (A[i][j]=='x')
            {
                k=j;
                break;
            }
        int x=-1,y=-1;
        bool nega=false;
        for (int j=0;j<k;j++)
        {
            if (A[i][j]=='-')
                nega=true;
            if (isdigit(A[i][j]))
            {
                if (x==-1)
                    x=0;
                x=x*10+A[i][j]-'0';
            }
        }
        if (x==-1)
            x=1;
        if (nega)
            x=-x;
        for (int j=k+1;j<A[i].size();j++)
            if (isdigit(A[i][j]))
            {
                if (y==-1)
                    y=0;
                y=y*10+A[i][j]-'0';
            }
        if (y==-1)
            y=k==A[i].size()?0:1;
        a[y]+=x;
        n=max(n,y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        n=0;
        init();
        int nx;
        solve(n,a,x,nx);
        for (int i=1;i<=nx;i++)
            if (fabs(x[i])<error)
                x[i]=0;
        for (int i=1;i<=nx;i++)
            printf("%.2f%c",x[i],i==nx?'\n':' ');
        if (nx==0)
            printf("\n");
    }
    return(0);
}

