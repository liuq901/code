#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;
bool use[40];
char buf[1000000];
int n,m,len,a[510],b[510];
int get(char ch)
{
    if (isdigit(ch))
        return(ch-'0');
    return(ch-'A'+10);
}
void divide()
{
    int x=0;
    for (int i=len;i;i--)
    {
        x=x*10+b[i];
        b[i]=x/m;
        x%=m;
    }
    a[++n]=x;
    while (len>1 && b[len]==0)
        len--;
}
int f[510][40],pre[510][40];
char to(int x)
{
    if (x<10)
        return(x+'0');
    return(x-10+'A');
}
string ans;
void print(int x,int y)
{
    if (x==0 && y==0)
        return;
    print(x-1,(y+pre[x][y]-a[x])/m);
    ans+=to(pre[x][y]);
}
int main()
{
    freopen("digits.in","r",stdin);
    freopen("digits.out","w",stdout);
    scanf("%d%s",&m,buf);
    len=strlen(buf);
    for (int i=0;i<len;i++)
        use[get(buf[i])]=true;
    scanf("%s",buf+1);
    len=strlen(buf+1);
    for (int i=1;i<=len;i++)
        b[i]=buf[i]-'0';
    reverse(b+1,b+len+1);
    while (1)
    {
        divide();
        if (len==1 && b[1]==0)
            break;
    }
    reverse(a+1,a+n+1);
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=38;j++)
        {
            if (f[i-1][j]==0)
                continue;
            int left=j*m+a[i];
            for (int k=0;k<=36;k++)
            {
                if (!use[k] || left<k || left-k>=39)
                    continue;
                f[i][left-k]=min(2,f[i][left-k]+f[i-1][j]);
                pre[i][left-k]=k;
            }
        }
    if (f[n][0]==0)
        printf("Impossible\n");
    else
    {
        printf("%s\n",f[n][0]==1?"Unique":"Ambiguous");
        print(n,0);
        int p=ans.size()-1;
        for (int i=0;i<ans.size();i++)
            if (ans[i]!='0')
            {
                p=i;
                break;
            }
        printf("%s\n",ans.substr(p).c_str());
    }
    return(0);
}

