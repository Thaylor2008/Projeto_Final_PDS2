#ifndef JOGOSTAB_H
#define JOGOSTAB_H
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
using namespace std;
class JogosTab{
    public:
    virtual void MostraTab () const = 0;
    virtual void TestaJogada() const =0;
    virtual ~Jogostab();
};
#endif