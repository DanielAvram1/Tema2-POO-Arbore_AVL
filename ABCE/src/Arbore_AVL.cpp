#include "Arbore_AVL.h"
using namespace std;
#include "exceptionIntruder.h"
#include "exceptionNotFound.h"
Arbore_AVL::Arbore_AVL()
{
    this->rad = NULL;
}

Arbore_AVL::Arbore_AVL(Nod_AVL* rad): rad(rad){}

Arbore_AVL::Arbore_AVL(const Arbore_AVL& other){
    this->rad = new Nod_AVL(*(other.rad));
}

Arbore_AVL::~Arbore_AVL()
{
    delete this->rad;
}

Arbore_AVL Arbore_AVL::operator = (Arbore_AVL other){
    this->rad = new Nod_AVL(*(other.rad));
    return *this;
}

void Arbore_AVL::insert(int val)  {
    try{
        exceptionIntruder ex;

        if(this->find(val))
            throw ex;

        if(this->rad != NULL){
            Nod_AVL* temp;
            this->rad = temp->insert( this->rad,val);
        }
        else {

            this->rad = new Nod_AVL(val, NULL, NULL);
        }
    }catch(exception& e){
        cout << e.what();
    }
}

void Arbore_AVL::erase(int val)  {
    try{
        exceptionNotFound ex;
        if(!(this->find(val))){
            throw ex;
        }
        this->rad = this->rad->erase(this->rad, val);
    }catch(exception& e){
        cout<<e.what();
    }
}

bool Arbore_AVL::find(int val){
    Nod_AVL* curr;
    curr = this->rad;

    while(curr!=NULL){
        if(curr->getInfo() == val){
            return 1;
        }
        if(val < curr->getInfo()){
            curr = curr->getSt();
            continue;
        }
        if(val > curr->getInfo()){
            curr = curr->getDr();
            continue;
        }
    }

    return 0;

}

void Arbore_AVL::afisareEchilibru(){
    cout<<"Echilibru:\n";
    cout<<"Preordine:(";
    this->rad->preordineEchilibru();
    cout<<")\n";
    cout<<"Inordine:(";
    this->rad->inordineEchilibru();
    cout<<")\n";
    cout<<"Postordine:(";
    this->rad->postordineEchilibru();
    cout<<")\n";

}


ostream &operator <<(ostream &out, Arbore_AVL &arb){
    /*if(*(abc.radacina) == NULL){
        out<<"Arbore gol\n";
        return out;
    }*/

    ///pentru afisare, folosim functiile friend recursive din Nod
    out<<"Preordine:(";
    preordine(out, arb.rad);
    out<<")\n";
    out<<"Inordine:(";
    inordine(out, arb.rad);
    out<<")\n";
    out<<"Postordine:(";
    postordine(out, arb.rad);
    out<<")\n";
    return out;

}

///supraincararea operatorului de citire >>. se citeste mai intai un n, urmat de n numere care sunt inserate pe rand in arbore
istream &operator>>(istream &in, Arbore_AVL &arb){
    ///mai intai, stergem arborele precedent
    delete arb.rad;
    arb.rad = NULL;
    int n;
    in>>n;
    while(n--){
        int a;
        in>>a;
        arb.insert(a);
    }
    return in;
}

