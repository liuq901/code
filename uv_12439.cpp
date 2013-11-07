#include <cstdio>
#include <string>
using namespace std;
const string M[]={"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
int month(const string &s)
{
    for (int i=1;i<=12;i++)
        if (s.substr(0,3)==M[i])
            return(i);
}
void getdate(int &m,int &d,int &y)
{
    char s[100];
    scanf("%s",s);
    m=month(s);
    scanf("%d%*c%d",&d,&y);
}
bool leap(int x)
{
    if (x%400==0)
        return(true);
    if (x%100==0)
        return(false);
    return(x%4==0);
}
int get(int l,int r,int p)
{
    while (l%p!=0)
        l++;
    if (l>r)
        return(0);
    int t=r-l+1;
    return(t/p+(t%p!=0));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m1,d1,y1,m2,d2,y2;
        getdate(m1,d1,y1);
        getdate(m2,d2,y2);
        int ans=0;
        if (y1==y2)
            ans+=leap(y1) && m1<=2 && (m2>2 || m2==2 && d2==29);
        else
        {
            ans+=leap(y1) && m1<=2;
            ans+=leap(y2) && (m2>2 || m2==2 && d2==29);
            y1++,y2--;
            ans+=get(y1,y2,4)-get(y1,y2,100)+get(y1,y2,400);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

