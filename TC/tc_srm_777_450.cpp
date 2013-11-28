#include <cstring>
#include <vector>
#include <string>
using namespace std;
struct P8XMatrixRecovery
{
    int n,m,b[40];
    bool f[40],a[40][40];
    vector <string> solve(vector <string> rows,vector <string> columns)
    {
        n=rows.size(),m=columns.size();
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                if (rows[i][j]!='?')
                    continue;
                rows[i][j]='0';
                memset(a,0,sizeof(a));
                for (int k=0;k<m;k++)
                    for (int l=0;l<m;l++)
                        if (check(rows,columns,k,l))
                            a[k][l]=true;
                if (!hungary())
                    rows[i][j]='1';
            }
        return(rows);
    }
    bool check(const vector <string> &row,const vector <string> &col,int x,int y)
    {
        for (int i=0;i<n;i++)
        {
            char p=row[i][x],q=col[y][i];
            if (p!=q && p!='?' && q!='?')
                return(false);
        }
        return(true);
    }
    bool hungary()
    {
        memset(b,-1,sizeof(b));
        for (int i=0;i<m;i++)
        {
            memset(f,0,sizeof(f));
            if (!find(i))
                return(false);
        }
        return(true);
    }
    bool find(int x)
    {
        if (x==-1)
            return(true);
        for (int i=0;i<m;i++)
        {
            if (!a[x][i] || f[i])
                continue;
            f[i]=true;
            if (find(b[i]))
            {
                b[i]=x;
                return(true);
            }
        }
        return(false);
    }
};
int main(){}

