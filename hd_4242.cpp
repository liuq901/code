/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
class Main
{
    class Point
    {
        double x,y;
        Point(double _x,double _y)
        {
            x=_x;
            y=_y;
        }
        Point add(Point p)
        {
            return(new Point(x+p.x,y+p.y));
        }
        Point subtract(Point p)
        {
            return(new Point(x-p.x,y-p.y));
        }
        Point multiply(double t)
        {
            return(new Point(x*t,y*t));
        }
        Point divide(double t)
        {
            return(new Point(x/t,y/t));
        }
    }
    double det(Point a,Point b)
    {
        return(a.x*b.y-a.y*b.x);
    }
    double sqr(double x)
    {
        return(x*x);
    }
    double dist(Point a,Point b)
    {
        return(Math.sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
    }
    double area(Point a,Point b,Point c)
    {
        return(Math.abs(det(b.subtract(a),c.subtract(a)))/320.0);
    }
    Point mid(Point a,Point b)
    {
        return(a.add(b).divide(2.0));
    }
    Point intersect(Point a,Point b,Point c,Point d)
    {
        double s1=det(b.subtract(a),c.subtract(a));
        double s2=det(b.subtract(a),d.subtract(a));
        return(c.multiply(s2).subtract(d.multiply(s1)).divide(s2-s1));
    }
    void run() throws Exception
    {
        int T=nextInt();
        while (T-->0)
        {
            int id=nextInt();
            double a1=nextDouble(),a2=nextDouble(),a3=nextDouble(),a4=nextDouble(),a5=nextDouble();
            Point A=new Point(0,0),B=new Point(a1,0),C=new Point(a2,a3),D=new Point(a4,a5);
            Point a=intersect(A,mid(B,C),B,mid(C,D));
            Point b=intersect(B,mid(C,D),C,mid(A,D));
            Point c=intersect(C,mid(A,D),D,mid(A,B));
            Point d=intersect(D,mid(A,B),A,mid(B,C));
            double aA=area(A,B,a),aB=area(B,C,b),aC=area(C,D,c),aD=area(A,D,d),aE=area(a,b,c)+area(a,c,d);
            double len=dist(a,b)+dist(b,c)+dist(c,d)+dist(a,d);
            writer.println(String.format("%d %.3f %.3f %.3f %.3f %.3f %.0f",id,aA,aB,aC,aD,aE,Math.ceil(len*16.5)));
        }
        reader.close();
        writer.close();
    }
    double nextDouble() throws Exception
    {
        return(Double.parseDouble(next()));
    }
    public static void main(String args[]) throws Exception
    {
        (new Main()).run();
    }
    BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
    PrintWriter writer=new PrintWriter(System.out);
    StringTokenizer tokenizer=null;
    String next() throws Exception
    {
        for (;tokenizer==null || !tokenizer.hasMoreTokens();)
            tokenizer=new StringTokenizer(reader.readLine());
        return(tokenizer.nextToken());
    }
    int nextInt() throws Exception
    {
        return(Integer.parseInt(next()));
    }
}
*/
int main(){}

