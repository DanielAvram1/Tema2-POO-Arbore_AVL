#include <iostream>
#include "Arbore_AVL.h"
#include "ABC.h"
#include <exception>
using namespace std;

int main()
{
    ///Testare ABC

    ABC abc;
    abc.insert(3);
    abc.insert(5);
    cout<<abc;
    abc.erase(3);
    cout<<abc;
    cin>>abc;
    cout<<abc;
    ABC abc2(abc);
    abc2.insert(4);
    cout<<abc<<'\n';
    cout<<abc2;
    abc2 = abc;
    abc2.insert(1000);
    cout<<abc<<'\n';
    cout<<abc2<<'\n';


    ///Testare Arbore_AVL
    /*
    Arbore_AVL abce;
    abce.insert(3);
    abce.insert(5);
    cout<<abce;
    abce.afisareEchilibru();
    abce.insert(7);
    abce.insert(8);
    cout<<abce;
    abce.afisareEchilibru();
    abce.erase(3);
    cout<<abce;
    abce.afisareEchilibru();
    cin>>abce;
    cout<<abce<<'\n';
    Arbore_AVL abce2(abce);
    cout<<abce2<<'\n';
    abce2.insert(100);
    cout<<abce2<<'\n';
    cout<<abce<<'\n';
    abce2 = abce;
    abce2.insert(1000);
    cout<<abce<<'\n';
    cout<<abce2<<'\n';
    */

    ///Testarea exceptiilor
    /*
        ///Sterg un element din ABC care nu exista
    ABC abc;
    abc.insert(4);
    abc.erase(3);
        ///Sterg un element din Arbore_AVL care nu exista
    Arbore_AVL abce;
    abce.erase(6);
        ///Inserez un element care deja exista in Arbore_AVL
    abce.insert(4);
    abce.insert(4);
    */

    return 0;

}
