#include <cstdio>
#include <algorithm>
using namespace std;
const double eps=1e-8;
FILE *in,*out;
double a[3010],h[3010],r[3010],R[3010];
double sign(double x)
{
    return(x<-eps?-1:x>eps);
}
double get(int i,double now)
{
    double H=r[i]*h[i]/(R[i]-r[i]);
    return(now*(H+h[i])/R[i]-H);
}
int main()
{
    in=fopen("input.txt","r");
    out=fopen("output.txt","w");
    int n;
    fscanf(in,"%d",&n);
    for (int i=1;i<=n;i++)
        fscanf(in,"%lf%lf%lf",&h[i],&r[i],&R[i]);
    for (int i=1;i<=n;i++)
    {
        a[i]=0;
        for (int j=1;j<i;j++)
        {
            if (sign(r[i]-R[j])>=0)
            {
                a[i]=max(a[i],a[j]+h[j]);
                continue;
            }
            a[i]=max(a[i],a[j]);
            if (sign(r[i]-r[j])>0)
            {
                double H=get(j,r[i]);
                a[i]=max(a[i],a[j]+H);
            }
            if (sign(R[i]-R[j])>0)
            {
                double H=get(i,R[j]);
                a[i]=max(a[i],a[j]+h[j]-H);
            }
            double H=get(j,R[i]);
            if (sign(H-h[j])<=0)
                a[i]=max(a[i],a[j]+H-h[i]);
        }
    }
    double ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,a[i]+h[i]);
    fprintf(out,"%.10f\n",ans);
    fclose(in),fclose(out);
    return(0);
}

