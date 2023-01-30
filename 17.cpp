#include<iostream>
#include<fstream>
using namespace std;
ifstream finj ("judet.in");
ifstream fino ("oras.in");
struct judet
{
    char nume_judet[256];
    int cod_judet;
} j[101];
struct oras
{
    int cod_oras;
    int cod_judet;
    char nume_oras[256];
    int nr_locuitori;
    int suprafata;
} o[101];
int main()
{
    int n,m,l[101],s[101];
    finj>>n;
    fino>>m;
    for(int i=1; i<=n; i++)
    {

        finj>>j[i].nume_judet;
        finj>>j[i].cod_judet;
    }
    for(int i=1; i<=m; i++)
    {
        fino>>o[i].cod_oras>>o[i].cod_judet;
        fino>>o[i].nume_oras;
        fino>>o[i].nr_locuitori>>o[i].suprafata;
    }
    for(int i=1; i<=n; i++)
    {
        cout<<j[i].nume_judet<<" "<<j[i].cod_judet<<endl;
    }
    cout<<endl;
    for(int i=1; i<=m; i++)
    {
        cout<<o[i].cod_oras<<" "<<o[i].cod_judet<<" "<<o[i].nume_oras<<" "<<o[i].nr_locuitori<<" "<<o[i].suprafata<<endl;
    }
    cout<<endl;
    for(int i=1; i<=m; i++)
        for(int k=1; k<=n; k++)
        {
            if(o[i].cod_judet==j[k].cod_judet)
                cout<<j[k].nume_judet<<" "<<o[i].nr_locuitori<<" "<<o[i].suprafata<<endl;
        }
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        s[i]=0;
        l[i]=0;
        for(int k=1; k<=m; k++)
            if(j[i].cod_judet==o[k].cod_judet)
            {
                l[i]=l[i]+o[k].nr_locuitori;
                s[i]=s[i]+o[k].suprafata;

            }
    }
        for(int i=1; i<=n; i++)
            cout<<j[i].cod_judet<<" "<<l[i]<<" "<<s[i]<<endl;

    return 0;
}
