#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char s[1000000];
double calc(int l,int r)
{
    if (s[l]!='(')
    {
        double ret;
        sscanf(s+l,"%lf",&ret);
        return(ret);
    }
    l++,r--;
    double p;
    sscanf(s+l,"%lf",&p);
    int now=0,k1,k2;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(')
            now++;
        if (s[i]==')')
            now--;
        if (now==0 && s[i]==' ')
        {
            k1=i;
            break;
        }
    }
    for (int i=r;i>=l;i--)
    {
        if (s[i]==')')
            now++;
        if (s[i]=='(')
            now--;
        if (now==0 && s[i]==' ')
        {
            k2=i;
            break;
        }
    }
    double x=calc(k1+1,k2-1),y=calc(k2+1,r);
    return(p*(x+y)+(1-p)*(x-y));
}
int main()
{
    while (1)
    {
        gets(s);
        int len=strlen(s);
        if (len==2 && s[0]=='(' && s[1]==')')
            break;
        printf("%.2f\n",calc(0,len-1));
    }
    return(0);
}

