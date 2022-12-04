#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const char duomenys[]="U2.txt";
const char rezultatai[]="U2rez.txt";
const int cmax=31;
struct slidininkai
{
    string info;
    int h,minut,s;
};
struct finisas
{
    string info;
    int h,minut,s;
    int slid_laikas;
};
void rikiavimas(finisas b[], int m);
void spausdinimas (finisas b[], int m);
int main()
{
    int n,m,d=0;
    slidininkai a[cmax];
    finisas b[cmax];
    ifstream fd(duomenys);
    char v[21];
    fd>>n;
    fd.ignore(80,'\n');
    for(int i=0; i<n; i++)
    {
        fd.get(v,21);
        a[i].info=v;
        fd>>a[i].h>>a[i].minut>>a[i].s;
        fd.ignore(80,'\n');

    }
    fd>>m;
    fd.ignore(80,'\n');
    for(int i=0; i<m; i++)
    {
        fd.get(v,21);
        b[i].info=v;
        fd>>b[i].h>>b[i].minut>>b[i].s;
        fd.ignore(80,'\n');
    }
    fd.close();
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(a[i].info==b[j].info)
            {
                b[j].slid_laikas=(b[j].h*3600+b[j].minut*60+b[j].s)-(a[i].h*3600+a[i].minut*60+a[i].s);
                b[j].h=b[j].slid_laikas/3600;
                b[j].slid_laikas-=b[j].slid_laikas/3600*3600;
                b[j].minut=b[j].slid_laikas/60;
                b[j].slid_laikas-=b[j].slid_laikas/60*60;
                b[j].s=b[j].slid_laikas;
            }
        }
    }
    rikiavimas(b,m);
    spausdinimas(b,m);
    return 0;
}

void spausdinimas(finisas b[], int m)
{
    ofstream fr (rezultatai);
    for(int j=0; j<m; j++)
    {
            fr<<b[j].info<<" "<<b[j].minut<<" "<<b[j].s<<endl;
    }
    fr.close();
}
void rikiavimas(finisas b[], int m)
{
    for(int j=0; j<m-1; j++)
    {
        for(int i=j+1; i<m; i++)
        {
            if(b[i].h*3600+b[i].minut*60+b[i].s<b[j].h*3600+b[j].minut*60+b[j].s)
            {
                swap(b[i].info,b[j].info);
                swap(b[i].minut,b[j].minut);
                swap(b[i].s,b[j].s);
            }

            if(b[i].h*3600+b[i].minut*60+b[i].s==b[j].h*3600+b[j].minut*60+b[j].s&&b[i].info<b[j].info)
            {
                swap(b[i].info,b[j].info);
                swap(b[i].minut,b[j].minut);
                swap(b[i].s,b[j].s);
            }
        }
    }
}
