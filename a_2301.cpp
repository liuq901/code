#include <cstdio>
inline int sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
int K;
double ans,P,lower,upper,T;
void work(int dep,double L,double R,double p)
{
    if (sign(R-lower)<0 || sign(L-upper)>0)
        return;
    if (sign(L-lower)>=0 && sign(R-upper)<=0)
    {
        ans+=p;
        return;
    }
    double H=(L+R)/2;
    if (dep==K+1)
    {
        if (sign(H-lower)>=0 && sign(H-upper)<=0)
            ans+=p;
        return;
    }
    if (sign(T-H)>=0)
    {
        work(dep+1,H,R,p*(1-P));
        work(dep+1,L,H,p*P);
    }
    else
    {
        work(dep+1,H,R,p*P);
        work(dep+1,L,H,p*(1-P));
    }
}
int main()
{
    double L,R,E;
    scanf("%d%lf%lf%lf%lf%lf",&K,&L,&R,&P,&E,&T);
    lower=T-E;
    upper=T+E;
    work(1,L,R,1);
    printf("%.10f\n",ans);
    return(0);
}

