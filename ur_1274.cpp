#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
typedef long long ll;
struct data
{
    ll a,b;
    data(){}
    data(ll a,ll b):a(a),b(b){}
    data(char *s)
    {
        int len=strlen(s);
        bool flag=true;
        if (s[0]=='-')
        {
            flag=false;
            s[0]=' ';
        }
        for (int i=0;i<len;i++)
            if (s[i]=='/')
                s[i]=' ';
        stringstream sin(s);
        ll x,p[10];
        int n=0;
        while (sin>>x)
            p[++n]=x;
        if (n==1)
            a=p[1],b=1;
        else if (n==2)
            a=p[1],b=p[2];
        else
            a=p[2]+p[1]*p[3],b=p[3];
        if (!flag)
            a=-a;
    }
    ll gcd(ll a,ll b)
    {
        return(b?gcd(b,a%b):a);
    }
    void print()
    {
        if (b<0)
            a=-a,b=-b;
        ll c=gcd(llabs(a),b);
        a/=c,b/=c;
        if (a<0)
        {
            printf("-");
            a=llabs(a);
        }
        if (a==0)
        {
            printf("0\n");
            return;
        }
        if (a/b>0)
            printf("%lld",a/b);
        if (a%b!=0)
        {
            if (a/b>0)
                printf(" ");
            printf("%lld/%lld\n",a%b,b);
        }
    }
};
data operator +(data a,data b)
{
    return(data(a.a*b.b+a.b*b.a,a.b*b.b));
}
data operator -(data a,data b)
{
    return(data(a.a*b.b-a.b*b.a,a.b*b.b));
}
data operator *(data a,data b)
{
    return(data(a.a*b.a,a.b*b.b));
}
data operator /(data a,data b)
{
    return(data(a.a*b.b,a.b*b.a));
}
char s1[100],s2[100],s3[100];
int main()
{
    gets(s1),gets(s2),gets(s3);
    data a=s1,b=s3,c;
    switch (s2[0])
    {
    case '+':
        c=a+b;
        break;
    case '-':
        c=a-b;
        break;
    case '*':
        c=a*b;
        break;
    case '/':
        c=a/b;
        break;
    }
    c.print();
    return(0);
}

