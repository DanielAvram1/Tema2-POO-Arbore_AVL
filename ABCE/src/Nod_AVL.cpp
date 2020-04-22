#include "Nod_AVL.h"
#include<algorithm>
using namespace std;

Nod_AVL::Nod_AVL(): Nod() {
    echilibru = 0;
}

Nod_AVL::Nod_AVL(int info, Nod_AVL* st, Nod_AVL* dr): Nod(info, NULL, NULL) {
    this->st = NULL;
    this->dr = NULL;
    this->inal = max(this->st->inaltime(), this->dr->inaltime()) + 1;
    this->echilibru = 0;
}

Nod_AVL::Nod_AVL(const Nod_AVL& other){

    if(other.st != NULL){
        this->st = new Nod_AVL(*(other.st));
    }else this->st = NULL;
    if(other.dr != NULL){
        this->dr = new Nod_AVL(*(other.dr));
    }else this->dr = NULL;
    this->info = other.info;
    this->inal = other.inal;
    this->echilibru = other.echilibru;
}

Nod_AVL::~Nod_AVL(){
   // cout<<this->info<<" distrus\n";
    if(st != NULL)
        delete st;

    if(dr!= NULL)
        delete dr;
}

int Nod_AVL::inaltime(){
    if(this == NULL)
        return 0;
    return this->inal;
}

Nod_AVL* Nod_AVL::rotireStanga(Nod_AVL* radacina){
    Nod_AVL* radacinaNoua = radacina->dr;
    radacina->dr = radacinaNoua->st;
    radacinaNoua->st = radacina;

    radacina->inal = max(radacina->st->inaltime(), radacina->dr->inaltime()) + 1;
    radacinaNoua->inal = max(radacinaNoua->st->inaltime(), radacinaNoua->dr->inaltime()) + 1;
    radacina->echilibru = radacina->st->inaltime() - radacina->dr->inaltime();
    return radacinaNoua;
}

Nod_AVL* Nod_AVL::rotireDreapta(Nod_AVL* radacina) {
    Nod_AVL* radacinaNoua = radacina->st;
    radacina->st = radacinaNoua->dr;
    radacinaNoua->dr = radacina;

    radacina->inal = max(radacina->st->inaltime(), radacina->dr->inaltime()) + 1;
    radacinaNoua->inal = max(radacinaNoua->st->inaltime(), radacinaNoua->dr->inaltime()) + 1;
    radacina->echilibru = radacina->st->inaltime() - radacina->dr->inaltime();
    return radacinaNoua;
}

Nod_AVL* Nod_AVL::echilibrare(Nod_AVL* radacina){

    radacina->inal = max(radacina->st->inaltime(), radacina->dr->inaltime()) + 1;

    radacina->echilibru = radacina->st->inaltime() - radacina->dr->inaltime();

    if(radacina->echilibru > 1){       ///fiul stang e mai greu
        if(radacina->st->echilibru >=0) { ///fiul stang a fiului stang e mai greu
            radacina = radacina->rotireDreapta(radacina); ///rotim radacina in dreapta
        }
        else {                                        ///daca fiul drept al fiului stang e mai greu
            radacina->st = radacina->st->rotireStanga(radacina->st);  ///rotim fiul stang in stanga
            radacina = radacina->rotireDreapta(radacina);         ///rotim radacina in drepta
        }

    }
    if(radacina->echilibru < -1){       ///fiul drept e mai greu
        if(radacina->dr->echilibru <=0) { ///fiul drept a fiului drept e mai greu
            radacina = radacina->rotireStanga(radacina); ///rotim radacina in stanga
        }
        else {                                        ///daca fiul stang al fiului drept e mai greu
            radacina->dr = radacina->dr->rotireDreapta(radacina->dr);  ///rotim fiul drept in dreapta
            radacina = radacina->rotireStanga(radacina);         ///rotim radacina in drepta
        }
    }
    radacina->inal = max(radacina->st->inaltime(), radacina->dr->inaltime()) + 1;

    radacina->echilibru = radacina->st->inaltime() - radacina->dr->inaltime();
    return radacina;
}

Nod_AVL* Nod_AVL::insert(Nod_AVL* radacina, int val) {
    if(val == radacina->info){
        return radacina;
    }
    if(val < radacina->info){
        if(radacina->st != NULL){
            radacina->st = radacina->st->insert(radacina->st, val);
        }
        else {
            radacina->st = new Nod_AVL(val, NULL, NULL);
        }
    }
    if(val > radacina->info){
        if(radacina->dr != NULL){
            radacina->dr = radacina->dr->insert(radacina->dr, val);
        }
        else {
            radacina->dr = new Nod_AVL(val, NULL, NULL);
        }
    }

    radacina = radacina->echilibrare(radacina);

    return radacina;


}

Nod_AVL* Nod_AVL::succesor(){
    Nod_AVL* temp = this;
    while(temp->st != NULL)
        temp = temp->st;
    return temp;
}

Nod_AVL* Nod_AVL::erase(Nod_AVL* radacina, int val){

    if(radacina == NULL)
        return radacina;

    if(val < radacina->info){
        radacina->st = radacina->st->erase(radacina->st,val);
    }
    else if(val > radacina->info){
        radacina->dr = radacina->dr->erase(radacina->dr, val);
    }
    else {  /// am gasit nodul

        if(radacina->st == NULL || radacina->dr == NULL){ ///daca are cel mult un copil
            Nod_AVL* temp = radacina->st ? radacina->st: radacina->dr;

            if(temp == NULL) {  ///nu are nici un copil
                delete radacina;
                return NULL;
            }
            else {
                radacina = temp;
                delete temp;

            }
        }
        else {  ///are doi copii
            Nod_AVL* temp = radacina->dr->succesor();
            radacina->info = temp->info;

            radacina->dr = radacina->dr->erase(radacina->dr, temp->info);
        }
    }

    if(radacina == NULL)
        return radacina;

    radacina =radacina->echilibrare(radacina);

    return radacina;
}

ostream &preordine(ostream &out, Nod_AVL* r){
    if(r){
        out<<r->info<<' ';
        preordine(out,r->st);
        preordine(out,r->dr);
    }
    return out;

}

ostream& inordine(ostream &out,Nod_AVL* r){
    if(r){

        inordine(out,r->st);
        out<<r->info<<' ';
        inordine(out,r->dr);
    }
    return out;

}

ostream& postordine(ostream &out, Nod_AVL* r){
    if(r){
        postordine(out,r->st);
        postordine(out,r->dr);
        out<<r->info<<' ';
    }
    return out;
}

void Nod_AVL::preordineEchilibru(){
    if(this != NULL){
        cout<<this->echilibru<<' ';
        this->st->preordineEchilibru();
        this->dr->preordineEchilibru();
    }
    return;

}

void Nod_AVL::inordineEchilibru(){
    if(this != NULL){

        this->st->inordineEchilibru();
        cout<<this->echilibru<<' ';
        this->dr->inordineEchilibru();
    }
    return;

}

void Nod_AVL::postordineEchilibru(){
    if(this != NULL){
        this->st->postordineEchilibru();
        this->dr->postordineEchilibru();
        cout<<this->echilibru<<' ';
    }
    return;
}

Nod_AVL* Nod_AVL::getSt(){
    return st;
}
Nod_AVL* Nod_AVL::getDr(){
    return dr;
}

int Nod_AVL::getInfo(){
    return info;
}
