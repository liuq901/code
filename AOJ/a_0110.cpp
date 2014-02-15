#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
char s1[10000],s2[10000],s3[10000];
bool check(string &a,string &b,string &c)
{
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    int n=max(a.size(),b.size()),t=0;
    for (int i=0;i<n;i++)
    {
        int x=i<a.size()?a[i]-'0':0;
        int y=i<b.size()?b[i]-'0':0;
        int z=(x+y+t)%10;
        t=(x+y+t)/10;
        if (i>=c.size() || c[i]!=z+'0')
            return(false);
    }
    return(t==0 && n==c.size() || t!=0 && n==c.size()-1 && c[n]==t+'0');
}
int main()
{
    while (scanf(" %[0-9X]+%[0-9X]=%[0-9X]",s1,s2,s3)==3)
    {
        bool zero=false;
        if (strlen(s1)>1 && s1[0]=='X')
            zero=true;
        if (strlen(s2)>1 && s2[0]=='X')
            zero=true;
        if (strlen(s3)>1 && s3[0]=='X')
            zero=true;
        int ans=-1;
        for (int i=zero;i<10;i++)
        {
            string t1=s1,t2=s2,t3=s3;
            replace(t1.begin(),t1.end(),'X',char(i+'0'));
            replace(t2.begin(),t2.end(),'X',char(i+'0'));
            replace(t3.begin(),t3.end(),'X',char(i+'0'));
            if (check(t1,t2,t3))
            {
                ans=i;
                break;
            }
        }
        if (ans==-1)
            printf("NA\n");
        else
            printf("%d\n",ans);
    }
    return(0);
}

