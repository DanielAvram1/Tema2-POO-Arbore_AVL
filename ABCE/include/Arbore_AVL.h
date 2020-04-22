#ifndef ARBORE_AVL_H
#define ARBORE_AVL_H
#include "Arbore.h"
#include "Nod_AVL.h"
#include <iostream>
using namespace std;

class Arbore_AVL: public Arbore
{
private:
    Nod_AVL* rad;
public:
    Arbore_AVL();
    Arbore_AVL(Nod_AVL*);
    Arbore_AVL(const Arbore_AVL&);
    ~Arbore_AVL();
    friend ostream &operator <<(ostream &out, Arbore_AVL &arb);
    friend istream &operator>>(istream &in, Arbore_AVL &arb);
    Arbore_AVL operator =(Arbore_AVL);
    void afisareEchilibru();
    virtual void insert(int);
    virtual void erase(int);
    virtual bool find(int);


};

#endif // ARBORE_AVL_H
