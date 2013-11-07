#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>
using namespace std;
int a[1010][1010];
char s[100];
void read(int &x)
{
    scanf("%s",s);
    int len=strlen(s);
    bool flag=false,nega=false;
    x=0;
    int p=0;
    for (int i=0;i<len;i++)
    {
        if (s[i]=='-')
            nega=true;
        if (s[i]=='.')
            flag=true;
        if (flag && isdigit(s[i]))
        {
            x=x*10+s[i]-'0';
            p++;
        }
    }
    while (p<3)
    {
        x*=10;
        p++;
    }
    if (nega && x!=0)
        x=1000-x;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        read(x);
        read(y);
        a[x][y]++;
    }
    int ans1;
    double ans2;
    ans1=0;
    for (int i=0;i<1000;i++)
        for (int j=0;j<1000;j++)
        {
            int p=min(i,1000-i),q=min(j,1000-j);
            double dist=sqrt(double(p*p+q*q));
            if (a[i][j]>ans1 || a[i][j]==ans1 && dist<ans2)
                ans1=a[i][j],ans2=dist;
        }
    printf("%d %.10f\n",ans1,ans2/1000.0);
    return(0);
}

