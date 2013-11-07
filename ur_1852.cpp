#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
class cube
{
    int A[60];
public:
    cube()
    {
        for (int i=1;i<=54;i++)
            A[i]=i;
    }
    int gcd(int a,int b)
    {
        return(b?gcd(b,a%b):a);
    }
    void rotate(int a,int b,int c,int d,bool rev)
    {
        int t;
        if (rev)
            t=A[a],A[a]=A[b],A[b]=A[c],A[c]=A[d],A[d]=t;
        else
            t=A[d],A[d]=A[c],A[c]=A[b],A[b]=A[a],A[a]=t;
    }
    void U(bool rev)
    {
        rotate(1,19,28,46,rev);
        rotate(2,20,29,47,rev);
        rotate(3,21,30,48,rev);
        rotate(16,18,12,10,rev);
        rotate(17,15,11,13,rev);
    }
    void D(bool rev)
    {
        rotate(7,52,34,25,rev);
        rotate(8,53,35,26,rev);
        rotate(9,54,36,27,rev);
        rotate(40,44,42,38,rev);
        rotate(37,43,45,39,rev);
    }
    void L(bool rev)
    {
        rotate(1,10,36,37,rev);
        rotate(4,13,33,40,rev);
        rotate(7,16,30,43,rev);
        rotate(46,52,54,48,rev);
        rotate(47,49,53,51,rev);
    }
    void R(bool rev)
    {
        rotate(3,39,34,12,rev);
        rotate(6,42,31,15,rev);
        rotate(9,45,28,18,rev);
        rotate(19,25,27,21,rev);
        rotate(20,22,26,24,rev);
    }
    void F(bool rev)
    {
        rotate(16,54,39,19,rev);
        rotate(17,51,38,22,rev);
        rotate(18,48,37,25,rev);
        rotate(1,7,9,3,rev);
        rotate(2,4,8,6,rev);
    }
    void B(bool rev)
    {
        rotate(12,27,43,46,rev);
        rotate(11,24,44,49,rev);
        rotate(10,21,45,52,rev);
        rotate(28,34,36,30,rev);
        rotate(29,31,35,33,rev);
    }
    int calc()
    {
        bool vis[60]={0};
        int ans=1;
        for (int i=1;i<=54;i++)
        {
            if (vis[i])
                continue;
            int cnt=0;
            for (int j=i;!vis[j];j=A[j])
            {
                cnt++;
                vis[j]=true;
            }
            ans=ans/gcd(ans,cnt)*cnt;
        }
        return(ans);
    }
};
char buf[100010];
int main()
{
    cube a;
    scanf("%s",buf);
    int len=strlen(buf);
    for (int i=0;i<len;i++)
    {
        bool rev=islower(buf[i]);
        buf[i]=toupper(buf[i]);
        if (buf[i]=='U')
            a.U(rev);
        else if (buf[i]=='D')
            a.D(rev);
        else if (buf[i]=='L')
            a.L(rev);
        else if (buf[i]=='R')
            a.R(rev);
        else if (buf[i]=='F')
            a.F(rev);
        else if (buf[i]=='B')
            a.B(rev);
    }
    printf("%d\n",a.calc()-1);
    return(0);
}

