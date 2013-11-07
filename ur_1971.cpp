#include <cstdio>
#include <cmath>
#include <string>
#include <map>
using namespace std;
map <string,int> M;
double a[100010];
char *getans(double now)
{
    double ans=-now;
    if (ans<log(10.0))
        return("Slideshow");
    else if (ans>=log(60.0))
        return("Perfect");
    else
        return("So-so");
}
int main()
{
    int n;
    scanf("%d",&n);
    double now=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        char buf[20];
        scanf("%s%d",buf,&x);
        M[buf]=i;
        a[i]=log(double(x));
        now+=a[i];
    }
    double W,H,P;
    scanf("%lf%lf%lf",&W,&H,&P);
    now+=log(W)+log(H)-log(P);
    printf("%s\n",getans(now));
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[20],buf[20];
        scanf("%s",op);
        if (string(op)=="Off")
        {
            scanf("%s",buf);
            int id=M[buf];
            now-=a[id];
        }
        else if (string(op)=="On")
        {
            scanf("%s",buf);
            int id=M[buf];
            now+=a[id];
        }
        else
        {
            double x,y;
            scanf("%lf%lf",&x,&y);
            now+=log(x)+log(y)-log(W)-log(H);
            W=x,H=y;
        }
        printf("%s\n",getans(now));
    }
    return(0);
}

