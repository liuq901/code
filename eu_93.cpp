#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
struct fraction
{
    int x,y;
    fraction(){}
    fraction(int _x,int _y=1):x(_x),y(_y)
    {
        int p=__gcd(abs(x),abs(y));
        x/=p,y/=p;
        if (y<0)
            x*=-1,y*=-1;
    }
    bool zero() const
    {
        return(x==0);
    }
};
inline fraction operator +(const fraction &a,const fraction &b)
{
    return(fraction(a.x*b.y+a.y*b.x,a.y*b.y));
}
inline fraction operator -(const fraction &a,const fraction &b)
{
    return(fraction(a.x*b.y-a.y*b.x,a.y*b.y));
}
inline fraction operator *(const fraction &a,const fraction &b)
{
    return(fraction(a.x*b.x,a.y*b.y));
}
inline fraction operator /(const fraction &a,const fraction &b)
{
    return(fraction(a.x*b.y,a.y*b.x));
}
vector <int> ans;
void calc(const vector <fraction> &a)
{
    if (a.size()==1)
    {
        if (a[0].y==1 && a[0].x>0)
            ans.push_back(a[0].x);
        return;
    }
    for (int i=0;i<a.size();i++)
        for (int j=i+1;j<a.size();j++)
        {
            vector <fraction> b=a;
            b.erase(b.begin()+j);
            b[i]=a[i]+a[j];
            calc(b);
            b[i]=a[i]-a[j];
            calc(b);
            b[i]=a[j]-a[i];
            calc(b);
            b[i]=a[i]*a[j];
            calc(b);
            if (!a[j].zero())
            {
                b[i]=a[i]/a[j];
                calc(b);
            }
            if (!a[i].zero())
            {
                b[i]=a[j]/a[i];
                calc(b);
            }
        }
}
int main()
{
    int ma=0,final;
    for (int i=1;i<10;i++)
        for (int j=i+1;j<10;j++)
            for (int k=j+1;k<10;k++)
                for (int l=k+1;l<10;l++)
                {
                    ans.clear();
                    vector <fraction> a;
                    a.push_back(i);
                    a.push_back(j);
                    a.push_back(k);
                    a.push_back(l);
                    calc(a);
                    sort(ans.begin(),ans.end());
                    ans.erase(unique(ans.begin(),ans.end()),ans.end());
                    int now=ans.size();
                    for (int p=0;p<ans.size();p++)
                        if (ans[p]!=p+1)
                        {
                            now=p;
                            break;
                        }
                    if (now>ma)
                    {
                        ma=now;
                        final=i*1000+j*100+k*10+l;
                    }
                }
    printf("%d\n",final);
    return(0);
}

