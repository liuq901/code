#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define SIZE(X) (int(X.size()))
using namespace std;
const double PI=acos(-1.0);
const double eps=1e-8;
inline int Sign(double x)
{
    return(x<-eps?-1:x>eps);
}
inline double Sqrt(double x)
{
    return(x<0?0:sqrt(x));
}
struct point
{
    double x,y,z;
    point()
    {
        x=y=z=0;
    }
    point(double x,double y,double z):x(x),y(y),z(z){}
    bool operator <(const point &p) const
    {
        return(x<p.x || x==p.x && y<p.y || x==p.x && y==p.y && z<p.z);
    }
    bool operator ==(const point &p) const
    {
        return(Sign(x-p.x)==0 && Sign(y-p.y)==0 && Sign(z-p.z)==0);
    }
    point operator +(const point &p) const
    {
        return(point(x+p.x,y+p.y,z+p.z));
    }
    point operator -(const point &p) const
    {
        return(point(x-p.x,y-p.y,z-p.z));
    }
    point operator *(const double k) const
    {
        return(point(x*k,y*k,z*k));
    }
    point operator /(const double k) const
    {
        return(point(x/k,y/k,z/k));
    }
    point cross(const point &p) const
    {
        return(point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x));
    }
    double dot(const point &p) const
    {
        return(x*p.x+y*p.y+z*p.z);
    }
    double norm()
    {
        return(dot(*this));
    }
    double length()
    {
        return(Sqrt(norm()));
    }
    void Input()
    {
        scanf("%lf%lf%lf",&x,&y,&z);
    }
    void Output()
    {
        printf("%.10f %.10f %.10f\n",x,y,z);
    }
};
int mark[310][310];
point info[310];
int n,cnt;
double mix(const point &a,const point &b,const point &c)
{
    return(a.dot(b.cross(c)));
}
double area(int a,int b,int c)
{
    return(((info[b]-info[a]).cross(info[c]-info[a])).length());
}
double volume(int a,int b,int c,int d)
{
    return(mix(info[b]-info[a],info[c]-info[a],info[d]-info[a]));
}
struct Face
{
    int a,b,c;
    Face(){}
    Face(int a,int b,int c):a(a),b(b),c(c){}
    int &operator [](int k)
    {
        if (k==0)
            return(a);
        if (k==1)
            return(b);
        return(c);
    }
};
vector <Face> face;
inline void insert(int a,int b,int c)
{
    face.push_back(Face(a,b,c));
}
void add(int v)
{
    vector <Face> tmp;
    int a,b,c;
    cnt++;
    for (int i=0;i<SIZE(face);i++)
    {
        a=face[i][0];
        b=face[i][1];
        c=face[i][2];
        if (Sign(volume(v,a,b,c))<0)
            mark[a][b]=mark[b][a]=mark[b][c]=mark[c][b]=mark[c][a]=mark[a][c]=cnt;
        else
            tmp.push_back(face[i]);
    }
    face=tmp;
    for (int i=0;i<SIZE(tmp);i++)
    {
        a=face[i][0];
        b=face[i][1];
        c=face[i][2];
        if (mark[a][b]==cnt)
            insert(b,a,v);
        if (mark[b][c]==cnt)
            insert(c,b,v);
        if (mark[c][a]==cnt)
            insert(a,c,v);
    }
}
int Find()
{
    for (int i=2;i<n;i++)
    {
        point ndir=(info[0]-info[i]).cross(info[1]-info[i]);
        if (ndir==point())
            continue;
        swap(info[i],info[2]);
        for (int j=i+1;j<n;j++)
            if (Sign(volume(0,1,2,j))!=0)
            {
                swap(info[j],info[3]);
                insert(0,1,2);
                insert(0,2,1);
                return(1);
            }
    }
    return(0);
}
int main()
{
    for (;scanf("%d",&n)==1;)
    {
        for (int i=0;i<n;i++)
            info[i].Input();
        sort(info,info+n);
        n=unique(info,info+n)-info;
        face.clear();
        random_shuffle(info,info+n);
        if (Find())
        {
            memset(mark,0,sizeof(mark));
            cnt=0;
            for (int i=3;i<n;i++)
                add(i);
            vector <point> Ndir;
            for (int i=0;i<SIZE(face);i++)
            {
                point p=(info[face[i][0]]-info[face[i][1]]).cross(info[face[i][2]]-info[face[i][1]]);
                p=p/p.length();
                Ndir.push_back(p);
            }
            sort(Ndir.begin(),Ndir.end());
            int ans=unique(Ndir.begin(),Ndir.end())-Ndir.begin();
            printf("%d\n",ans);
        }
        else
            printf("1\n");
    }
    return(0);
}

