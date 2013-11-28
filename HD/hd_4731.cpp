#include <cstdio>
#include <cstring>
const char c[][10]={"","a","ab","aab","aabb","aaaba","aaabab","aaababb","aaababbb"};
const char a[]="babbaababbaa";
char ans[100010];
void work(int n)
{
    if (n<=8)
    {
        int len=strlen(c[n]);
        for (int i=0;i<len;i++)
            ans[i]=c[n][i];
        return;
    }
    for (int i=0;i<4;i++)
        ans[i]='a';
    for (int i=4;i<n;i+=12)
        for (int j=0;j<12;j++)
            if (i+j<n)
                ans[i+j]=a[j];
    int p=(n-4)%12;
    if (p==1 || p==7)
        ans[n-1]='a';
    else if (p==2 || p==8)
        ans[n-2]='a';
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        if (m==1)
            for (int i=0;i<n;i++)
                ans[i]='a';
        else if (m==2)
            work(n);
        else
            for (int i=0;i<n;i+=3)
                for (int j=0;j<3;j++)
                    if (i+j<n)
                        ans[i+j]='a'+j;
        ans[n]='\0';
        static int id=0;
        printf("Case #%d: %s\n",++id,ans);
    }
    return(0);
}

