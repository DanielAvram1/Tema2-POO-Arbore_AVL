#include "Nod.h"
using namespace std;

Nod::Nod() {
    info = 0;
    st = NULL;
    dr = NULL;
    inal = 1;
}

Nod::Nod(int info, Nod* st, Nod* dr) {
    this->info = info;
    this->st = st;
    this->dr = dr;
}

Nod::Nod(const Nod& other){

    if(other.st != NULL){
        this->st = new Nod(*(other.st));
    }else this->st = NULL;
    if(other.dr != NULL){
        this->dr = new Nod(*(other.dr));
    }else this->dr = NULL;
    this->info = other.info;
    this->inal = other.inal;
}

Nod::~Nod(){
    if(st != NULL)
        delete st;

    if(dr != NULL)
        delete dr;
}


ostream &preordine(ostream &out, Nod* r){
    if(r){
        out<<r->info<<' ';
        preordine(out,r->st);
        preordine(out,r->dr);
    }
    return out;

}

ostream& inordine(ostream &out,Nod* r){
    if(r){

        inordine(out,r->st);
        out<<r->info<<' ';
        inordine(out,r->dr);
    }
    return out;

}

ostream& postordine(ostream &out, Nod* r){
    if(r){
        postordine(out,r->st);
        postordine(out,r->dr);
        out<<r->info<<' ';
    }
    return out;
}

Nod* Nod::getSt(){
    return st;
}
Nod* Nod::getDr(){
    return dr;
}

int Nod::getInfo(){
    return info;
}

