#ifndef ARBORE_H
#define ARBORE_H


class Arbore
{
private:
protected:
public:
    virtual void insert(int) = 0;
    virtual void erase(int) = 0;
    virtual bool find(int) = 0;

};

#endif // ARBORE_H
