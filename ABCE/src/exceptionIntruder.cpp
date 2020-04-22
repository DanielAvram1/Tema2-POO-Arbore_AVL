#include "exceptionIntruder.h"

const char* exceptionIntruder::what()const throw() {
    return "Eroare, incercati sa introduceti un element care deja exista in Arbore\n";
}
