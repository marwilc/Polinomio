/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   polinomio.h
 * Author: marwilc
 *
 * Created on 11 de abril de 2016, 09:16 AM
 */

#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include "list.h"
#include "monomio.h"

using namespace std;

template <class T>
class Polinomio: public List <T>
{
    public:
        void suma(Polinomio<T> &p1, Polinomio<T> &p2);
        void Multiplicacion(Polinomio<T> &p1, Polinomio<T> &p2);
        void imprimir();
};

template <class T>
void Polinomio<T>::imprimir()
{
    int i;
    Monomio m1;
    
    for(i=1;i<=this->length();i++)
    {
        m1=this->consult(i);
        m1.imprimir();
    }
}

template <class T>
void Polinomio<T>::suma(Polinomio<T> &p1,Polinomio<T> &p2)
{
    Polinomio<T> Rx;
    Monomio mono1, mono2, mono3;
    int i=1,j=1,cont=1;
    
    while(i<=p1.length() || j<=p2.length())
    {
        mono1=p1.consult(i);
        mono2=p2.consult(j);
        
        if(mono1.obtExp()>mono2.obtExp()|| (i<=p1.length() && j>p2.length()))
        {
            this->insert(mono1,cont++);
            i++;
        }
        else if(mono1.obtExp()<mono2.obtExp() || (i>p1.length() && j<=p2.length()))
        {       
            this->insert(mono2,cont++);
            j++;
        }
        else
        {
            mono3.modCoef(mono1.obtCoef()+mono2.obtCoef());
            if(mono3.obtCoef()!=0)
            {
                mono3.modExp(mono1.obtExp());
                this->insert(mono3,cont++);
            }
            i++;
            j++;
        }
        //cont++;
    }
    //return Rx;
}

template <class T>
void Polinomio<T>::Multiplicacion(Polinomio<T>& p1, Polinomio<T>& p2)
{
    Polinomio<T> Rx;
    Monomio m1, m2, m3;
    int i;
    
    m1=p2.consult(1);
    for(i=1;i<=p1.length();i++)
    {
        m2=p1.consult(i);
        m3.modCoef(m2.obtCoef()*m1.obtCoef());
        m3.modExp(m2.obtExp()+m1.obtExp());
        this->insert(m3,i);
    }
    //return(Rx);
    
}
#endif /* POLINOMIO_H */

