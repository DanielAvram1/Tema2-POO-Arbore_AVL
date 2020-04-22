#include "exceptionNotFound.h"

const char* exceptionNotFound::what()const throw() {
    return "Eroare, incercati sa stergeti un element care nu exista in Arbore\n";
}

