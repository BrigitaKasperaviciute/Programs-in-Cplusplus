#include <iostream>
#include <string>
#include <fstream>

using namespace std;
const char duomenys[]="rezultatai.txt";
const char duomenys1[]="namekai.txt";
const char rezultatai[]="StartoSarasas.txt";
const char cmax=100;
struct rungtiesrez
{
    int nr;
    int task;
};
struct namekaii
{
    string slap;
    string vard;
    int nr;
    string pav;
    string komandupav;
    int sum;
};
struct starto_sar
{
    string slap;
    string vard;
    int nr;
    string pav;
    int task;
    int startoh;
    int startomin;
};
void skaitymas(rungtiesrez a[],namekaii b[],starto_sar c[], int &dal_sk);
void laikas(rungtiesrez a[],starto_sar c[], int dal_sk);
void geriausia_komanda(rungtiesrez a[],namekaii b[], int dal_sk, int &daugtask,string &pavdgstask);
void spausdinimas(starto_sar c[], int dal_sk,int daugtask,string pavdgstask);
int main()
{
    int dal_sk,daugtask;
    string pavdgstask;
    rungtiesrez a[cmax];
    namekaii b[cmax];
    starto_sar c[cmax];
    skaitymas(a,b,c, dal_sk);
    laikas(a,c, dal_sk);
    geriausia_komanda(a,b, dal_sk,daugtask,pavdgstask);
    for(int i=0; i<dal_sk-1; i++)
    {
        for(int j=i+1; j<dal_sk; j++)
        {
            if(b[i].nr>b[j].nr)
            {
                swap(b[i].slap,b[j].slap);
                swap(b[i].vard,b[j].vard);
                swap(b[i].nr,b[j].nr);
                swap(b[i].pav,b[j].pav);
            }
        }
    }
    for(int i=0; i<dal_sk; i++)
    {
        c[i].slap=b[i].slap;
        c[i].vard=b[i].vard;
        c[i].pav=b[i].pav;
    }
    spausdinimas(c, dal_sk,daugtask,pavdgstask);
    return 0;
}
void skaitymas(rungtiesrez a[],namekaii b[],starto_sar c[], int &dal_sk)
{
    ifstream fd;
    fd.open(duomenys);
    fd>>dal_sk;
    for(int i=0; i<dal_sk; i++)
    {
        fd>>a[i].nr>>a[i].task;
        c[i].nr=a[i].nr;
        c[i].task=a[i].task;
    }
    fd.close();
    fd.open(duomenys1);
    for(int i=0; i<dal_sk; i++)
    {
        fd>>b[i].slap>>b[i].vard>>b[i].nr>>b[i].pav;
    }
    fd.close();
}
void laikas(rungtiesrez a[],starto_sar c[], int dal_sk)
{
    c[0].startoh=00;
    c[0].startomin=00;
    for(int i=1; i<dal_sk; i++)
    {
        if(a[0].task-a[i].task<=60)
        {

            c[i].startomin=c[0].startomin+a[0].task-a[i].task;
        }
        else
        {
            c[i].startoh= c[0].startoh+(a[0].task-a[i].task)/60;
            c[i].startomin=c[0].startomin+(a[0].task-a[i].task)%60;
        }
    }
}
void geriausia_komanda(rungtiesrez a[],namekaii b[], int dal_sk, int &daugtask, string &pavdgstask)
{
    bool komanda=true;
    int m=0;
    for(int i=0; i<dal_sk; i++)
    {
        b[i].sum=0;
        for(int j=0; j<m; j++)
        {
            if(b[i].pav==b[j].komandupav)
            {
                komanda=false;
            }
        }
        if(komanda)
        {
            b[m].komandupav=b[i].pav;
            m++;
        }
        komanda=true;
    }
    for(int i=0; i<dal_sk; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(b[i].pav==b[j].komandupav)
            {
                b[j].sum+=a[i].task;
            }
        }
    }
    int  dgs=b[0].sum;
    for(int j=1; j<m; j++)
    {
        if(dgs<b[j].sum)
        {
            dgs=b[j].sum;
            pavdgstask=b[j].komandupav;
        }
        daugtask=dgs;
    }
}
void spausdinimas(starto_sar c[], int dal_sk,int daugtask,string pavdgstask)
{
    ofstream fr(rezultatai);
    for(int i=0; i<dal_sk; i++)
    {
        fr<<c[i].slap<<" "<<c[i].vard<<" "<<c[i].nr<<" "<<c[i].pav<<" "<<c[i].task<<" ";
        if(c[i].startoh<10)
        {
            fr<<"0";
        }
        fr<<c[i].startoh<<":";
        if(c[i].startomin<10)
        {
            fr<<"0";
        }
        fr<<c[i].startomin<<endl;
    }
    fr.close();
}
