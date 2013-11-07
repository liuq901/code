#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
int c[50][50];
map <int,int> f[50][50];
char s[50];
int main()
{
    while (1)
    {
        int L,N;
        scanf("%d%d",&L,&N);
        if (L==0 && N==0)
            break;
        scanf("%s",s+1);
        int len=strlen(s+1);
        for (int i=0;i<=len;i++)
            for (int j=0;j<=L-N;j++)
                f[i][j].clear();
        for (int i=1;i<=len;i++)
        {
            if (s[i]=='0')
                continue;
            c[i][i]=1;
            for (int j=i+1;j<=len;j++)
                if (j-i>25)
                    c[i][j]=L+10;
                else
                    c[i][j]=c[i][j-1]*2+s[j]-'0';
        }
        f[0][0][0]=1;
        for (int i=0;i<len;i++)
            for (int j=0;j<=L-N;j++)
                for (map <int,int>::iterator k=f[i][j].begin();k!=f[i][j].end();k++)
                {
                    int x=k->first,value=k->second;
                    if (s[i+1]=='0' && j<L-N)
                        f[i+1][j+1][x]=min(200,value+f[i+1][j+1][x]);
                    if (s[i+1]=='1')
                        for (int l=i+1;l<=len;l++)
                        {
                            if (l<len && s[l+1]=='1' || l==i+2 && s[l]=='0')
                                continue;
                            if (l==i+2 && s[l]=='1')
                                f[l][j][x+2]=min(200,value+f[l][j][x+2]);
                            if (x+c[i+1][l]>N)
                                break;
                            f[l][j][x+c[i+1][l]]=min(200,value+f[l][j][x+c[i+1][l]]);
                        }
                }
        static int id=0;
        printf("Case #%d: ",++id);
        int ans=f[len][L-N][N];
        if (ans==1)
            printf("YES\n");
        else if (ans==0)
            printf("NO\n");
        else
            printf("NOT UNIQUE\n");
    }
    return(0);
}

