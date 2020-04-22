#ifndef NOD_AVL_H
#define NOD_AVL_H
#include "Nod.h"

class Nod_AVL: public Nod
{
private:
    int echilibru;
    Nod_AVL* st;
    Nod_AVL* dr;
    int inaltime();
    Nod_AVL* rotireDreapta(Nod_AVL*);
    Nod_AVL* rotireStanga(Nod_AVL*);
    Nod_AVL* succesor();
    Nod_AVL* echilibrare(Nod_AVL*);

protected:
public:
    Nod_AVL();
    Nod_AVL(int , Nod_AVL*, Nod_AVL*);
    Nod_AVL(const Nod_AVL&);
    ~Nod_AVL();

    Nod_AVL* insert( Nod_AVL*, int );
    Nod_AVL* erase(Nod_AVL*, int );

    friend ostream& preordine(ostream &out, Nod_AVL* r);
    friend ostream& inordine(ostream &out, Nod_AVL* r);
    friend ostream& postordine(ostream &out, Nod_AVL* r);

    void preordineEchilibru();
    void inordineEchilibru();
    void postordineEchilibru();

    Nod_AVL* getSt();
    Nod_AVL* getDr();
    int getInfo();
};

#endif // NOD_AVL_H
