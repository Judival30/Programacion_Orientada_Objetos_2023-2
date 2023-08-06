#ifndef Huesped_H
#define Huesped_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Huesped
{
private:
    string nombre;
    int tel;
    int dinero;

public:
    Huesped();
    Huesped(string &n, int t);
    void setDinero(int n);
    void setTel(int n);
    string getName();
    int getTel();
    int getDinero();
};

#endif