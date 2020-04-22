#ifndef EXCEPTIONINTRUDER_H
#define EXCEPTIONINTRUDER_H
#include<exception>
using namespace std;

class exceptionIntruder: public exception {
    virtual const char* what() const throw();
};

#endif // EXCEPTIONINTRUDER_H
