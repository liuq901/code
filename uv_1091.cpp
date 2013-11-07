#include <cstdio>
#include <cstring>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const double eps=1e-8;
const int N=160;
const string badcode="bad code",badC="bad C",badK="bad K";
int n,m,start,a[N],b[N],code[N];
int sign(double x)
{
    return(x<-eps?-1:x>eps);
}
bool get()
{
    int mi=*min_element(a+1,a+n+1);
    int ma=*max_element(a+1,a+n+1);
    double lower=0,upper=1e10;
    for (int i=1;i<=n;i++)
        if (a[i]-mi<ma-a[i])
        {
            lower=max(lower,a[i]/1.05);
            upper=min(upper,a[i]/0.95);
            a[i]=0;
        }
        else
        {
            lower=max(lower,a[i]/2.1);
            upper=min(upper,a[i]/1.9);
            a[i]=1;
        }
    return(sign(upper-lower)>=0);
}
int calc(int id)
{
    int ret=0;
    for (int i=id;i<=id+4;i++)
        ret=ret*2+a[i];
    return(ret);
}
string decode()
{
    if (b[0]!=start || b[m-1]!=start)
        return(badcode);
    int n=m-4;
    for (int i=1;i<=n+2;i++)
    {
        if (code[b[i]]==-1)
            return(badcode);
        b[i]=code[b[i]];
    }
    int C=0,K=0;
    for (int i=1;i<=n;i++)
        C+=((n-i)%10+1)*b[i];
    C%=11;
    if (C!=b[n+1])
        return(badC);
    for (int i=1;i<=n+1;i++)
        K+=((n-i+1)%9+1)*b[i];
    K%=11;
    if (K!=b[n+2])
        return(badK);
    string ret;
    for (int i=1;i<=n;i++)
        if (b[i]==10)
            ret+='-';
        else
            ret+=b[i]+'0';
    return(ret);
}
string work()
{
    if (n<29 || (n+1)%6!=0)
        return(badcode);
    if (!get())
        return(badcode);
    for (int T=0;T<=1;T++)
    {
        m=0;
        bool flag=true;
        for (int i=1;i<=n;i+=6)
        {
            b[m++]=calc(i);
            if (a[i+5]!=0)
            {
                flag=false;
                break;
            }
        }
        if (b[0]==start && flag)
            return(decode());
        reverse(a+1,a+n+1);
    }
    return(badcode);
}
int main()
{
    start=6;
    memset(code,-1,sizeof(code));
    code[1]=0;
    code[17]=1;
    code[9]=2;
    code[24]=3;
    code[5]=4;
    code[20]=5;
    code[12]=6;
    code[3]=7;
    code[18]=8;
    code[16]=9;
    code[4]=10;
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        static int id=0;
        printf("Case %d: %s\n",++id,work().c_str());
    }
    return(0);
}

