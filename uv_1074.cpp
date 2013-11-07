#include <cstdio>
#include <cstring>
const int C[16][3]={{1,7,7},{2,8,8},{3,9,9},{4,7,9},{4,9,7},{5,8,9},{5,9,8},{6,7,8},{6,8,7},{7,7,0},{7,0,7},{8,8,0},{8,0,8},{9,9,0},{9,0,9},{0,0,0}};
struct state
{
    double p[10];
    state()
    {
        clear();
    }
    void clear()
    {
        memset(p,0,sizeof(p));
    }
    double &operator [](int x)
    {
        return(p[x]);
    }
    double operator [](int x) const
    {
        return(p[x]);
    }
};
state operator +(const state &a,const state &b)
{
    state c;
    for (int i=0;i<10;i++)
        c[i]=a[i]+b[i];
    return(c);
}
state operator *(const state &a,double b)
{
    state c;
    for (int i=0;i<10;i++)
        c[i]=a[i]*b;
    return(c);
}
state operator *(const state &a,const state &b)
{
    state c;
    for (int i=0;i<16;i++)
    {
        int x=C[i][0],y=C[i][1],z=C[i][2];
        c[x]+=a[y]*b[z];
    }
    return(c);
}
double p[20];
state ans,a[20],b[30];
double power(double x,int n)
{
    double ret=1;
    for (int i=1;i<=n;i++)
        ret*=x;
    return(ret);
}
void intergrate(double x,int n,int value)
{
    for (int i=0;i<=n;i++)
    {
        double p=power(x,i+1)/(i+1)*value;
        ans=ans+b[i]*p;
    }
}
void solve(double c)
{
    double b[10],a[10][10];
    a[1][1]=2*ans[1],a[1][2]=ans[6],a[1][3]=ans[4],b[1]=-ans[7];
    a[2][1]=ans[6],a[2][2]=2*ans[2],a[2][3]=ans[5],b[2]=-ans[8];
    a[3][1]=ans[4],a[3][2]=ans[5],a[3][3]=2*ans[3],b[3]=-ans[9];
    for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
        {
            if (i==j)
                continue;
            double rate=a[j][i]/a[i][i];
            for (int k=1;k<=3;k++)
                a[j][k]-=rate*a[i][k];
            b[j]-=rate*b[i];
        }
    double a1,b1,a2,b2;
    a1=b[1]/a[1][1];
    a2=b[2]/a[2][2];
    b1=b[3]/a[3][3];
    b2=a1*c+b1-a2*c;
    static int id=0;
    printf("Case %d: %.3f %.3f %.3f %.3f\n",++id,a1,b1,a2,b2);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=n;i>=0;i--)
            scanf("%lf",&p[i]);
        double c;
        scanf("%lf",&c);
        for (int i=0;i<=n;i++)
        {
            a[i].clear();
            a[i][0]=p[i];
        }
        a[1][7]=-1;
        a[0][9]=-1;
        for (int i=0;i<=2*n;i++)
            b[i].clear();
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                b[i+j]=b[i+j]+a[i]*a[j];
        ans.clear();
        intergrate(c,2*n,1);
        intergrate(-1,2*n,-1);
        for (int i=0;i<=n;i++)
        {
            a[i].clear();
            a[i][0]=p[i];
        }
        a[1][8]=-1;
        a[0][7]=-c;
        a[0][8]=c;
        a[0][9]=-1;
        for (int i=0;i<=2*n;i++)
            b[i].clear();
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                b[i+j]=b[i+j]+a[i]*a[j];
        intergrate(1,2*n,1);
        intergrate(c,2*n,-1);
        solve(c);
    }
    return(0);
}

