#include <cstdio>
#include <cstring>
char key[1010],s[100010];
int main()
{
    while (1)
    {
        scanf("%s",key);
        if (key[0]=='0')
            break;
        scanf("%s",s);
        int n=strlen(key),m=strlen(s),t=0;
        for (int i=0;i<m;i++)
        {
            int x=key[t]-'A'+1,y=s[i]-'A';
            y+=x;
            if (y>=26)
                y-=26;
            printf("%c",y+'A');
            t++;
            if (t==n)
                t=0;
        }
        printf("\n");
    }
    return(0);
}
