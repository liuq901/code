#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;
typedef long long ll;
const int inf=1000000000;
const char error[]="ERROR";
int n,tot,s[1010],a[100010];
char buf[1000];
bool all,flag;
int divide(int x,int y)
{
    int ret=abs(x)/abs(y);
    if (x<0 && y>0 || x>0 && y<0)
        ret=-ret;
    return(ret);
}
int mod(int x,int y)
{
    int ret=abs(x)%abs(y);
    if (x<0)
        ret=-ret;
    return(ret);
}
void push(int x)
{
    if (x<-inf || x>inf)
    {
        flag=false;
        return;
    }
    s[++tot]=x;
}
int pop()
{
    if (tot==0)
    {
        all=true;
        return(0);
    }
    return(s[tot--]);
}
void work(int first)
{
    s[tot=1]=first;
    flag=true;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        if (a[i]>=0)
        {
            push(a[i]);
            continue;
        }
        if (a[i]>=-3)
            x=pop();
        else
        {
            y=pop();
            x=pop();
        }
        if (all)
        {
            printf("%s\n",error);
            return;
        }
        if (a[i]==-2)
            push(-x);
        else if (a[i]==-3)
        {
            push(x);
            push(x);
        }
        else if (a[i]==-4)
        {
            push(y);
            push(x);
        }
        else if (a[i]==-5)
            push(x+y);
        else if (a[i]==-6)
            push(x-y);
        else if (a[i]==-7)
        {
            ll p=ll(x)*y;
            if (p>inf || p<-inf)
            {
                printf("%s\n",error);
                return;
            }
            push(x*y);
        }
        else if (a[i]<=-8)
        {
            if (y==0)
            {
                printf("%s\n",error);
                return;
            }
            if (a[i]==-8)
                push(divide(x,y));
            else
                push(mod(x,y));
        }
        if (!flag)
        {
            printf("%s\n",error);
            return;
        }
    }
    if (tot!=1)
    {
        all=true;
        printf("%s\n",error);
        return;
    }
    printf("%d\n",s[1]);
}
int main()
{
    while (1)
    {
        n=0;
        while (1)
        {
            scanf("%s",buf);
            string s=buf;
            if (s=="QUIT")
                goto out;
            if (s=="END")
                break;
            n++;
            if (s=="NUM")
                scanf("%d",&a[n]);
            else if (s=="POP")
                a[n]=-1;
            else if (s=="INV")
                a[n]=-2;
            else if (s=="DUP")
                a[n]=-3;
            else if (s=="SWP")
                a[n]=-4;
            else if (s=="ADD")
                a[n]=-5;
            else if (s=="SUB")
                a[n]=-6;
            else if (s=="MUL")
                a[n]=-7;
            else if (s=="DIV")
                a[n]=-8;
            else if (s=="MOD")
                a[n]=-9;
        }
        int K;
        scanf("%d",&K);
        all=false;
        for (int i=1;i<=K;i++)
        {
            int x;
            scanf("%d",&x);
            work(x);
        }
        printf("\n");
    }
out:
    return(0);
}

