#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
char op[100],buf[100000],a[80][80];
void draw(int x,int y,char ch)
{
    if (x<=0 || x>n || y<=0 || y>m)
        return;
    char &now=a[x][y];
    if (ch==' ')
    {
        now=' ';
        return;
    }
    if (ch==now || now=='*' || now=='+' && (ch=='-' || ch=='|') || now=='x' && (ch=='/' || ch=='\\'))
        return;
    if (now==' ')
        now=ch;
    else if (now=='|' && ch=='-' || now=='-' && ch=='|')
        now='+';
    else if (now=='/' && ch=='\\' || now=='\\' && ch=='/')
        now='x';
    else
        now='*';
}
void point(int x,int y)
{
    draw(x,y,'o');
}
void text(int x,int y,char *s)
{
    int len=strlen(s);
    for (int i=0;i<len;i++)
        draw(x+i,y,s[i]);
}
void line(int x1,int y1,int x2,int y2)
{
    if (x1>x2 || x1==x2 && y1>y2)
        swap(x1,x2),swap(y1,y2);
    if (x1==x2)
        for (int i=y1;i<=y2;i++)
            draw(x1,i,'|');
    else if (y1==y2)
        for (int i=x1;i<=x2;i++)
            draw(i,y1,'-');
    else if (y1<y2)
        for (int i=x1;i<=x2;i++)
            draw(i,y1+i-x1,'\\');
    else
        for (int i=x1;i<=x2;i++)
            draw(i,y1-i+x1,'/');
}
void clear(int x1,int y1,int x2,int y2)
{
    if (x1>x2)
        swap(x1,x2);
    if (y1>y2)
        swap(y1,y2);
    for (int i=x1;i<=x2;i++)
        for (int j=y1;j<=y2;j++)
            draw(i,j,' ');
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (!n && !m)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                a[i][j]=' ';
        while (1)
        {
            scanf("%s",op);
            if (op[0]=='P' && op[1]=='O')
            {
                int x,y;
                scanf("%d%d",&x,&y);
                point(x,y);
            }
            else if (op[0]=='T')
            {
                int x,y;
                scanf("%d%d%s",&x,&y,buf);
                text(x,y,buf);
            }
            else if (op[0]=='L')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                line(x1,y1,x2,y2);
            }
            else if (op[0]=='C')
            {
                int x1,y1,x2,y2;
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                clear(x1,y1,x2,y2);
            }
            else
                break;
        }
        printf("+");
        for (int i=1;i<=n;i++)
            printf("-");
        printf("+\n");
        for (int i=1;i<=m;i++)
        {
            printf("|");
            for (int j=1;j<=n;j++)
                printf("%c",a[j][i]);
            printf("|\n");
        }
        printf("+");
        for (int i=1;i<=n;i++)
            printf("-");
        printf("+\n\n");
    }
    return(0);
}

