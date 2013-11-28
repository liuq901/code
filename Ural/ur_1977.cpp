#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int mm=550;
struct data
{
    bool empty;
    int n,len,now;
    double first,delta,sum,a[mm/2];
    double &operator [](int x)
    {
        return(a[x]);
    }
};
data a[mm*2];
int m,N,P,b[mm*2][mm/2],op[100010][4];
vector <int> X;
void build()
{
    int n=X.size()-1;
    for (int i=0;i<n;i++)
    {
        b[i/m][i%m]=X[i+1]-X[i];
        a[i/m].len+=b[i/m][i%m];
        a[i/m].n++;
    }
}
inline int get(int x)
{
    return(lower_bound(X.begin(),X.end(),x)-X.begin());
}
inline double calc(double first,double last,int num)
{
    return((first+last)*num/2);
}
void update(int id,int t)
{
    if (a[id].empty)
    {
        for (int i=0;i<a[id].n;i++)
            a[id][i]=0;
        a[id].empty=false;
    }
    a[id].sum=0;
    double first=a[id].first,delta=a[id].delta;
    for (int i=0;i<a[id].n;i++)
    {
        double last=first+delta*(b[id][i]-1);
        a[id][i]+=calc(first,last,b[id][i])+double(P)*(t-a[id].now)*b[id][i];
        a[id].sum+=a[id][i];
        first+=delta*b[id][i];
    }
    a[id].first=a[id].delta=0;
    a[id].now=t;
}
void insert(int L,int R,double first,double delta,int t)
{
    int lid=L/m,rid=R/m,lpos=L%m,rpos=R%m;
    if (lid==rid)
    {
        update(lid,t);
        for (int i=lpos;i<rpos;i++)
        {
            double last=first+delta*(b[lid][i]-1);
            double value=calc(first,last,b[lid][i]);
            a[lid][i]+=value;
            a[lid].sum+=value;
            first+=delta*b[lid][i];
        }
        return;
    }
    update(lid,t);
    for (int i=lpos;i<a[lid].n;i++)
    {
        double last=first+delta*(b[lid][i]-1);
        double value=calc(first,last,b[lid][i]);
        a[lid][i]+=value;
        a[lid].sum+=value;
        first+=delta*b[lid][i];
    }
    for (int i=lid+1;i<rid;i++)
    {
        a[i].first+=first;
        a[i].delta+=delta;
        first+=delta*a[i].len;
    }
    update(rid,t);
    for (int i=0;i<rpos;i++)
    {
        double last=first+delta*(b[rid][i]-1);
        double value=calc(first,last,b[rid][i]);
        a[rid][i]+=value;
        a[rid].sum+=value;
        first+=delta*b[rid][i];
    }
}
double query(int L,int R,int t)
{
    int lid=L/m,rid=R/m,lpos=L%m,rpos=R%m;
    double ans=0;
    if (lid==rid)
    {
        update(lid,t);
        for (int i=lpos;i<rpos;i++)
        {
            ans+=a[lid][i];
            a[lid].sum-=a[lid][i];
            a[lid][i]=0;
        }
        return(ans);
    }
    update(lid,t);
    for (int i=lpos;i<a[lid].n;i++)
    {
        ans+=a[lid][i];
        a[lid].sum-=a[lid][i];
        a[lid][i]=0;
    }
    for (int i=lid+1;i<rid;i++)
    {
        double last=a[i].first+a[i].delta*(a[i].len-1);
        ans+=a[i].sum+calc(a[i].first,last,a[i].len)+double(P)*a[i].len*(t-a[i].now);
        a[i].sum=a[i].first=a[i].delta=0;
        a[i].now=t;
        a[i].empty=true;
    }
    update(rid,t);
    for (int i=0;i<rpos;i++)
    {
        ans+=a[rid][i];
        a[rid].sum-=a[rid][i];
        a[rid][i]=0;
    }
    return(ans);
}
int main()
{
    scanf("%d%d",&N,&P);
    int Q;
    scanf("%d",&Q);
    for (int i=1;i<=Q;i++)
    {
        char buf[10];
        scanf("%d%s%d%d",&op[i][1],buf,&op[i][2],&op[i][3]);
        op[i][0]=buf[0]=='s';
        if (op[i][0]==0)
        {
            X.push_back(op[i][2]-op[i][3]+1);
            X.push_back(op[i][2]);
            X.push_back(op[i][2]+op[i][3]);
        }
        else
        {
            X.push_back(op[i][2]);
            X.push_back(op[i][3]+1);
        }
    }
    X.push_back(N+1);
    sort(X.begin(),X.end());
    X.erase(unique(X.begin(),X.end()),X.end());
    m=max(1,int(sqrt(double(X.size())))/2);
    //printf("%d %d\n",X.size(),m);
    build();
    double ans=0;
    for (int i=1;i<=Q;i++)
    {
        int t=op[i][1];
        if (op[i][0]==0)
        {
            if (fabs(ans)<1e-8)
                continue;
            int mid=op[i][2],d=op[i][3];
            int l=get(mid-d+1),r=get(mid+d);
            mid=get(mid);
            double sum=calc(1,d,d)+calc(1,d-1,d-1);
            double delta=ans/sum;
            insert(l,mid,delta,delta,t);
            insert(mid,r,delta*d,-delta,t);
            ans=0;
        }
        else
        {
            int l=get(op[i][2]),r=get(op[i][3]+1);
            ans+=query(l,r,t);
            printf("%.10f\n",ans);
        }
    }
    return(0);
}

