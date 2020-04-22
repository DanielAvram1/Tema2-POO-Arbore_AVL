#ifndef ABC_H
#define ABC_H
#include "Arbore.h"
#include<iostream>
#include "Nod.h"

class ABC: public Arbore
{
private:
    Nod* radacina;
public:
    ABC();
    ABC(Nod*);
    ABC(const ABC&);
    ~ABC();
    void afisare_frunze();
    ABC operator +(int a);
    ABC operator =(ABC a);
    friend ostream &operator <<(ostream &out, ABC &arb);
    friend istream &operator>>(istream &in, ABC &arb);
    int inaltime();
    virtual void insert(int);
    virtual void erase(int);
    virtual bool find(int);


};

#endif // ABC_H
