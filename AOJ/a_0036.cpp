#include <cstdio>
#include <vector>
#include <utility>
#include <map>
using namespace std;
char a[10][10];
map <vector <pair <int,int> >,char> ans;
void init()
{
    for (int i=0;i<7;i++)
    {
        vector <pair <int,int> > b;
        b.push_back(make_pair(0,0));
        switch (i)
        {
        case 0:
        case 2:
        case 4:
        case 6:
            b.push_back(make_pair(0,1));
            break;
        case 1:
        case 5:
            b.push_back(make_pair(1,0));
            break;
        case 3:
            b.push_back(make_pair(1,-1));
            break;
        }
        switch (i)
        {
        case 0:
        case 3:
            b.push_back(make_pair(1,0));
            break;
        case 1:
            b.push_back(make_pair(2,0));
            break;
        case 2:
            b.push_back(make_pair(0,2));
            break;
        case 4:
        case 5:
            b.push_back(make_pair(1,1));
            break;
        case 6:
            b.push_back(make_pair(1,-1));
            break;
        }
        switch (i)
        {
        case 0:
            b.push_back(make_pair(1,1));
            break;
        case 1:
            b.push_back(make_pair(3,0));
            break;
        case 2:
            b.push_back(make_pair(0,3));
            break;
        case 3:
            b.push_back(make_pair(2,-1));
            break;
        case 4:
            b.push_back(make_pair(1,2));
            break;
        case 5:
            b.push_back(make_pair(2,1));
            break;
        case 6:
            b.push_back(make_pair(1,0));
            break;
        }
        ans[b]='A'+i;
    }
}
int main()
{
    init();
    while (scanf("%s",a[1]+1)==1)
    {
        for (int i=2;i<=8;i++)
            scanf("%s",a[i]+1);
        int x0,y0;
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
                if (a[i][j]=='1')
                {
                    x0=i,y0=j;
                    goto out;
                }
out:
        vector <pair <int,int> > b;
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
                if (a[i][j]=='1')
                    b.push_back(make_pair(i-x0,j-y0));
        printf("%c\n",ans[b]);
    }
    return(0);
}

