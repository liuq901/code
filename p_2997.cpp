#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int c[1010],f[10010][30];
char s[10010];
int main()
{
    c[1000]=1;
    c[600]=2;
    c[500]=3;
    c[400]=4;
    c[300]=5;
    c[200]=6;
    c[100]=7;
    c[60]=8;
    c[50]=9;
    c[40]=10;
    c[30]=11;
    c[20]=12;
    c[10]=13;
    c[6]=14;
    c[5]=15;
    c[4]=16;
    c[3]=17;
    c[2]=18;
    c[1]=19;
    while (gets(s+1))
    {
        int n=strlen(s+1),now1,now2,now3,ans;
        if (n==0)
            break;
        now1=now2=now3=ans=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=19;j++)
                f[i][j]=f[i-1][j];
            if (s[i]=='m')
            {
                f[i][c[1000]]=max(f[i][c[1000]],now1+1000);
                f[i][c[400]]=max(f[i][c[400]],f[i-1][c[100]]+800);
            }
            if (s[i]=='d')
            {
                f[i][c[500]]=max(f[i][c[500]],now1+500);
                f[i][c[400]]=max(f[i][c[400]],f[i-1][c[100]]+300);
            }
            if (s[i]=='c')
            {
                f[i][c[100]]=max(f[i][c[100]],now1+100);
                f[i][c[600]]=max(f[i][c[600]],f[i-1][c[500]]+100);
                f[i][c[200]]=max(f[i][c[200]],max(f[i-1][c[100]],f[i-1][c[600]])+100);
                f[i][c[300]]=max(f[i][c[300]],f[i-1][c[200]]+100);
                f[i][c[40]]=max(f[i][c[40]],f[i-1][c[10]]+80);
            }
            if (s[i]=='l')
            {
                f[i][c[50]]=max(f[i][c[50]],now2+50);
                f[i][c[40]]=max(f[i][c[40]],f[i-1][c[10]]+30);
            }
            if (s[i]=='x')
            {
                f[i][c[10]]=max(f[i][c[10]],now2+10);
                f[i][c[60]]=max(f[i][c[60]],f[i-1][c[50]]+10);
                f[i][c[20]]=max(f[i][c[20]],max(f[i-1][c[10]],f[i-1][c[60]])+10);
                f[i][c[30]]=max(f[i][c[30]],f[i-1][c[20]]+10);
                f[i][c[4]]=max(f[i][c[4]],f[i-1][c[1]]+8);
            }
            if (s[i]=='v')
            {
                f[i][c[5]]=max(f[i][c[5]],now3+5);
                f[i][c[4]]=max(f[i][c[4]],f[i-1][c[1]]+3);
            }
            if (s[i]=='i')
            {
                f[i][c[1]]=max(f[i][c[1]],now3+1);
                f[i][c[6]]=max(f[i][c[6]],f[i-1][c[5]]+1);
                f[i][c[2]]=max(f[i][c[2]],max(f[i-1][c[1]],f[i-1][c[6]])+1);
                f[i][c[3]]=max(f[i][c[3]],f[i-1][c[2]]+1);
            }
            for (int j=1;j<=19;j++)
            {
                if (j==1)
                    now1=max(now1,f[i][j]);
                if (j<=7)
                    now2=max(now2,f[i][j]);
                if (j<=13)
                    now3=max(now3,f[i][j]);
                ans=max(ans,f[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return(0);
}

