#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char duomenys[]="U1.txt";
const char rezultatai[]="U1rez.txt";
const int cmax=100;
struct skaiciai
{
    int k[6];
    char v[6];
};
void konvertacija(int c[], int d[], int e[],skaiciai t[],int a, int b);
int main()
{
    int a,b,w=0;
    skaiciai t[cmax];
    int c[cmax],d[cmax],e[cmax];
    ifstream fd(duomenys);
    fd>>a>>b;
    for(int i=0; i<a*b; i++)
    {
        fd>>c[i]>>d[i]>>e[i];
    }
    fd.close();
    konvertacija(c,d,e,t,a, b);
    ofstream fr (rezultatai);
    for(int i=0; i<a*b; i++)
    {
        for(int h=0; h<6; h++)
        {
            fr<<t[i].v[h];
        }
        w++;
          if(w!=b)
        {
            fr<<";";
        }
        if(w==b)
        {
            fr<<endl;
            w=0;
        }
    }
    fr.close();
    return 0;
}
void konvertacija(int c[], int d[], int e[],skaiciai t[],int a, int b)
{
    int h;
    for(int i=0; i<a*b; i++)
    {
        h=0;
        t[i].k[h]=c[i]/16;
        h++;
        t[i].k[h]=c[i]%16;
        h++;
        t[i].k[h]=d[i]/16;
        h++;
        t[i].k[h]=d[i]%16;
        h++;
        t[i].k[h]=e[i]/16;
        h++;
        t[i].k[h]=e[i]%16;
        h++;
    }
    char elementai[16]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    for(int j=0; j<a*b; j++)
    {
        for(int y=0; y<6; y++)
        {
            for(int i=0; i<=15; i++)
            {
                if(i==t[j].k[y])
                {
                    t[j].v[y]=elementai[i];
                }
            }
        }
    }

}
