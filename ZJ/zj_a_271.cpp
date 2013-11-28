#include <cstdio>
#include <cstring>
char s[100000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y,z,w,n,m,cnt=0;
        scanf("%d%d%d%d%d%d",&x,&y,&z,&w,&n,&m);
        gets(s),gets(s);
        char *now=strtok(s," ");
        while (now!=NULL)
        {
            m-=cnt*n;
            if (m<=0)
                break;
            int t;
            sscanf(now,"%d",&t);
            switch (t)
            {
            case 0:
                break;
            case 1:
                m+=x;
                break;
            case 2:
                m+=y;
                break;
            case 3:
                m-=z;
                break;
            case 4:
                m-=w;
                cnt++;
                break;
            }
            now=strtok(NULL," ");
        }
        if (m<=0)
            printf("bye~Rabbit\n");
        else
            printf("%dg\n",m);
    }
    return(0);
}

