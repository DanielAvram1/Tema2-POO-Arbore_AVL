#ifndef EXCEPTIONNOTFOUND_H
#define EXCEPTIONNOTFOUND_H
#include<exception>
using namespace std;

class exceptionNotFound: public exception {
    virtual const char* what() const throw();
};

#endif // EXCEPTIONINTRUDER_H
