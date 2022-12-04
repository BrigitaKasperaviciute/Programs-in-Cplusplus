#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
const char duomenys [] = "valiuta.txt";
const char rezultatai [] = "rezultatai.txt";
const int cmax=100;
struct valiutos
{
    string V;
    int E;
    int CT;
};
void skaitymas (valiutos a[], int &n,int &ver_e,int &ver_c);
void Gido_surinkti_pinigai (valiutos a[], int n, int &Eur, int &ct);
void Val_keitimas (valiutos a[], int n, int Eur, int ct,int &Eur1, int &ct1,  int ver_e, int ver_c);
void Rasymas (valiutos a[], int n,int Eur, int ct,int Eur1, int ct1, int ver_e, int ver_c);
int main()
{
    valiutos a[cmax];
    int n,Eur, ct,ver_e,ver_c,Eur1, ct1;
    skaitymas (a,n,ver_e,ver_c);
    Gido_surinkti_pinigai ( a,n, Eur, ct);
    Val_keitimas( a,n, Eur, ct,Eur1, ct1,ver_e,ver_c);
    Rasymas (a,n,Eur, ct,Eur1, ct1,ver_e,ver_c);
    return 0;
}
void skaitymas (valiutos a[], int &n,int &ver_e,int &ver_c)
{
    ifstream fd(duomenys);
    char vardas[16];
    fd>>n;
    fd.ignore(80,'\n');
    for(int i=0; i<n; i++)
    {
        fd.get(vardas,16);
        a[i].V=vardas;
        fd>>a[i].E>>a[i].CT;
        fd.ignore(80,'\n');
    }
    fd>>ver_e>>ver_c;
    fd.close();
}
void Gido_surinkti_pinigai (valiutos a[], int n, int &Eur, int &ct)
{
    int e=0;
    int c=0;
    for(int i=0; i<n; i++)
    {
        e+=a[i].E;
        c+=a[i].CT;
        while(c>=100)
        {
            e++;
            c-=100;
        }
    }
    Eur=e;
    ct = c;

}
void Val_keitimas (valiutos a[], int n,int Eur, int ct, int &Eur1, int &ct1, int ver_e, int ver_c)
{
    Eur1=Eur*(ver_e);
    ct1=Eur*ver_c+ct*0.01*ver_c+ct*0.01*100*ver_e;
    while(ct1>=100)
    {
        Eur1+=ct1/100;
        ct1-=(ct1/100)*100;
    }
}
void Rasymas (valiutos a[], int n,int Eur, int ct,int Eur1, int ct1, int ver_e, int ver_c)
{
    ofstream fr(rezultatai);
    fr<<"Gidas surinko: "<<Eur<<" "<<ct<<endl;
    fr<<"Gidas gavo: "<<Eur1<<" "<<ct1<<endl;
for(int i=0;i<=40;i++)
{
    fr<<"-";
}
fr<<endl;
fr<<setw(16)<<left<<"Vardas"<<setw(12)<<left<<"Turi"<<setw(8)<<left<<"Gavo"<<endl;

for(int i=0;i<=40;i++)
{
    fr<<"-";
}
fr<<endl;
for(int i=0;i<n;i++)
{
    fr<<setw(16)<<left<<a[i].V<<setw(4)<<left<<a[i].E<<setw(8)<<left<<a[i].CT;
    Eur=a[i].E;
    ct=a[i].CT;
        Val_keitimas( a,n, Eur, ct,Eur1, ct1,ver_e,ver_c);
    fr<<setw(5)<<left<<Eur1<<setw(5)<<left<<ct1<<endl;
}
for(int i=0;i<=40;i++)
{
    fr<<"-";
}
fr<<endl;
}
