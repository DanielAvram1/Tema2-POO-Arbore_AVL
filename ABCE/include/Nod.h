#ifndef NOD_H
#define NOD_H
#include <iostream>
using namespace std;
class Nod
{
private:

protected:
    int info;
    Nod* st;
    Nod* dr;
    int inal;
public:
    friend class ABC;
    friend class Arbore_AVL;
    Nod();
    Nod(int info, Nod* st, Nod* dr);
    Nod(const Nod&);
    ~Nod();

    friend ostream& preordine(ostream &out, Nod* r);
    friend ostream& inordine(ostream &out, Nod* r);
    friend ostream& postordine(ostream &out, Nod* r);

    Nod* getSt();
    Nod* getDr();
    int getInfo();

};

#endif // NOD_H
