#include <cstdio>
#include <cstdlib>
struct chess
{
    int now,a[8][8];
    void in()
    {
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
                scanf("%d",&a[i][j]);
    }
    int sign(int x)
    {
        return(x<0?-1:x>0);
    }
    bool empty(int x1,int y1,int x2,int y2)
    {
        int dx=sign(x2-x1),dy=sign(y2-y1);
        for (int i=x1+dx,j=y1+dy;i!=x2 || j!=y2;i+=dx,j+=dy)
            if (a[i][j]!=0)
                return(false);
        return(true);
    }
    bool straight(int x1,int y1,int x2,int y2)
    {
        if (x1!=x2 && y1!=y2)
            return(false);
        return(empty(x1,y1,x2,y2));
    }
    bool diagonal(int x1,int y1,int x2,int y2)
    {
        if (x1+y1!=x2+y2 && x1-y1!=x2-y2)
            return(false);
        return(empty(x1,y1,x2,y2));
    }
    bool whitePawn(int x1,int y1,int x2,int y2)
    {
        if (x1==6 && x2==4 && y1==y2 && a[4][y1]==0 && a[5][y1]==0)
            return(true);
        if (sign(a[x2][y2])==-1 && x1-1==x2 && abs(y1-y2)==1)
            return(true);
        return(x1-1==x2 && y1==y2 && a[x2][y2]==0);
    }
    bool blackPawn(int x1,int y1,int x2,int y2)
    {
        if (x1==1 && x2==3 && y1==y2 && a[3][y1]==0 && a[2][y1]==0)
            return(true);
        if (sign(a[x2][y2])==1 && x1+1==x2 && abs(y1-y2)==1)
            return(true);
        return(x1+1==x2 && y1==y2 && a[x2][y2]==0);
    }
    bool legal(int x1,int y1,int x2,int y2)
    {
        int kind=abs(a[x1][y1]);
        if (kind==6)
            return(abs(x1-x2)<=1 && abs(y1-y2)<=1);
        else if (kind==5)
            return(straight(x1,y1,x2,y2) || diagonal(x1,y1,x2,y2));
        else if (kind==4)
            return(straight(x1,y1,x2,y2));
        else if (kind==3)
            return(diagonal(x1,y1,x2,y2));
        else if (kind==2)
            return(abs(x1-x2)==1 && abs(y1-y2)==2 || abs(x1-x2)==2 && abs(y1-y2)==1);
        else if (sign(a[x1][y1])==1)
            return(whitePawn(x1,y1,x2,y2));
        else
            return(blackPawn(x1,y1,x2,y2));
    }
    bool illegal(int x1,int y1,int x2,int y2)
    {
        if (sign(a[x1][y1])!=now || x1==x2 && y1==y2 || sign(a[x2][y2])==now)
            return(true);
        int tmp=a[x2][y2];
        a[x2][y2]=a[x1][y1];
        a[x1][y1]=0;
        bool flag=check();
        a[x1][y1]=a[x2][y2];
        a[x2][y2]=tmp;
        return(flag || !legal(x1,y1,x2,y2));
    }
    bool check()
    {
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
            {
                if (abs(a[i][j])!=6 || sign(a[i][j])!=now)
                    continue;
                for (int x=0;x<8;x++)
                    for (int y=0;y<8;y++)
                        if (sign(a[x][y])==-now && legal(x,y,i,j))
                            return(true);
            }
        return(false);
    }
    bool stalemate()
    {
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
            {
                if (sign(a[i][j])!=now)
                    continue;
                for (int x=0;x<8;x++)
                    for (int y=0;y<8;y++)
                        if (!illegal(i,j,x,y))
                            return(false);
            }
        return(true);
    }
    bool move(int x1,int y1,int x2,int y2)
    {
        if (illegal(x1,y1,x2,y2))
        {
            printf("Incorrect\n");
            return(false);
        }
        a[x2][y2]=a[x1][y1];
        a[x1][y1]=0;
        now*=-1;
        bool f1=check(),f2=stalemate();
        if (f1 && f2)
        {
            printf("Mate\n");
            return(false);
        }
        if (f1)
        {
            printf("Check\n");
            return(true);
        }
        if (f2)
        {
            printf("Draw\n");
            return(false);
        }
        printf("Correct\n");
        return(true);
    }
    void print()
    {
        for (int i=0;i<8;i++)
            for (int j=0;j<8;j++)
                printf("%d%c",a[i][j],j==7?'\n':' ');
    }
};
chess a;
int main()
{
    a.in();
    int n;
    char buf[10];
    scanf("%d%s",&n,buf);
    a.now=buf[0]=='W'?1:-1;
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        if (!a.move('8'-buf[1],buf[0]-'a','8'-buf[4],buf[3]-'a'))
            break;
    }
    printf("\n");
    a.print();
    return(0);
}

