#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;
char a[30][500],ans[30][500];
int pos[30],bound[30],left[30][30],right[30][30],v[30][500];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        gets(a[0]);
        for (int i=1;i<=n;i++)
            gets(a[i]+1);
        int K=0,m=strlen(a[1]+1);
        memset(v,-1,sizeof(v));
        for (int i=1;i<=n;i++)
        {
            int t=0;
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]==' ')
                {
                    a[i][j]='.';
                    t++;
                    continue;
                }
                if (a[i][j]=='#')
                {
                    a[i][j]='A'+t;
                    v[i][j]=t;
                }
                if (a[i][j]=='0')
                {
                    a[i][j]='a'+t;
                    v[i][j]=t;
                }
            }
            K=max(K,t);
        }
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        for (int k=0;k<=K;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                    if (v[i][j]==k)
                    {
                        if (left[k][i]==0)
                            left[k][i]=j;
                        right[k][i]=j;
                    }
        for (int k=0;k<=K;k++)
        {
            left[k][0]=1<<30;
            for (int i=1;i<=n;i++)
            {
                if (left[k][i]==0)
                    continue;
                left[k][0]=min(left[k][0],left[k][i]);
            }
        }
        pos[0]=left[0][0];
        for (int i=1;i<=n;i++)
            bound[i]=right[0][i]==0?-50:right[0][i];
        for (int k=1;k<=K;k++)
        {
            int delta=1<<30;
            for (int i=1;i<=n;i++)
            {
                if (left[k][i]==0)
                    continue;
                delta=min(delta,left[k][i]-bound[i]-2);
            }
            pos[k]=left[k][0]-delta;
            for (int i=1;i<=n;i++)
            {
                if (left[k][i]==0)
                    continue;
                bound[i]=right[k][i]-delta;
            }
        }
        int begin=0;
        for (int k=0;k<=K;k++)
            begin=max(begin,-pos[k]);
        for (int k=0;k<=K;k++)
            pos[k]+=begin;
        int lower=1<<30,upper=0;
        memset(ans,'.',sizeof(ans));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (isupper(a[i][j]))
                {
                    int k=v[i][j];
                    int p=j-left[k][0]+pos[k];
                    upper=max(upper,p);
                    lower=min(lower,p);
                    ans[i][p]='#';
                }        
        static int id=0;
        printf("%d\n",++id);
        for (int i=1;i<=n;i++)
        {
            for (int j=lower;j<=upper;j++)
                printf("%c",ans[i][j]);
            printf("\n");
        }
    }
    return(0);
}

