#include <cstdio>
#include <cstring>
using namespace std;
char s1[100000],s2[100000],s3[100000];
bool forbid[17580];
int q[17580],d[17580];
inline int hash(char a,char b,char c)
{
    return((a-'a')*676+(b-'a')*26+c-'a');
}
inline void get(int x,char *s)
{
    for (int i=2;i>=0;i--)
    {
        s[i]=x%26+'a';
        x/=26;
    }
}
inline void inc(char &ch)
{
    ch=ch=='z'?'a':ch+1;
}
inline void dec(char &ch)
{
    ch=ch=='a'?'z':ch-1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%s%s%d",s1,s2,&n);
        int S=hash(s1[0],s1[1],s1[2]),T=hash(s2[0],s2[1],s2[2]);
        memset(forbid,0,sizeof(forbid));
        for (int i=1;i<=n;i++)
        {
            scanf("%s%s%s",s1,s2,s3);
            int l1=strlen(s1),l2=strlen(s2),l3=strlen(s3);
            for (int j=0;j<l1;j++)
                for (int k=0;k<l2;k++)
                    for (int l=0;l<l3;l++)
                        forbid[hash(s1[j],s2[k],s3[l])]=true;
        }
        memset(d,-1,sizeof(d));
        if (!forbid[S] && !forbid[T])
        {
            int l,r;
            q[l=r=1]=S;
            d[S]=0;
            while (l<=r)
            {
                int x=q[l++];
                char s[3];
                get(x,s);
                for (int i=0;i<3;i++)
                {
                    inc(s[i]);
                    int y=hash(s[0],s[1],s[2]);
                    dec(s[i]);
                    if (d[y]==-1 && !forbid[y])
                    {
                        d[y]=d[x]+1;
                        q[++r]=y;
                    }
                    dec(s[i]);
                    y=hash(s[0],s[1],s[2]);
                    if (d[y]==-1 && !forbid[y])
                    {
                        d[y]=d[x]+1;
                        q[++r]=y;
                    }
                    inc(s[i]);
                }
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,d[T]);
    }
    return(0);
}

