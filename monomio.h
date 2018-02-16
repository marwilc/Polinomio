/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   monomio.h
 * Author: marwilc
 *
 * Created on 11 de abril de 2016, 08:32 AM
 */

#ifndef MONOMIO_H
#define MONOMIO_H
#include <iostream>

using namespace std;

//template <class T>
class Monomio
{
    private: 
        float coef;
        int exp;
        //Node <T>* mon;
        
    public:
        //constructores
        Monomio ();
        Monomio (const float &c, const int &e);
        
        //consultores
        float obtCoef()const{return this->coef;}
        int obtExp()const{return this->exp;}
        void imprimir(){cout<<coef<<" ",cout<<exp<<" ";}
        
        //modificadores
        void modCoef(const float &c){this->coef=c;}
        void modExp(const int &e){this->exp=e;}
};

Monomio::Monomio()
{
    this->coef=0;
    this->exp=0;
    //this->mon=NULL;
}

Monomio::Monomio(const float& c, const int& e)
{
    this->coef=c;
    this->exp=e;
    //this->mon=NULL;
}


#endif /* MONOMIO_H */

