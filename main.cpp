//
//  main.cpp
//  PowerOptions
//
//  Created by Loic Tudela on 05/05/2015.
//  Copyright (c) 2015 Loic Tudela. All rights reserved.
//

#include <iostream>
#include "functions.h"

const double Cap = 3;

int main(int argc, const char * argv[]) {
    double S = 0;
    double X = 0;
    double T = 0;
    double r = 0;
    double b = 0;
    double sigma = 0;
    double i = 0;
    int CallorPut = 0;
    cout << "Quelle valeur pour l'indice du stock ?" << endl;
    scanf("%lf",&S);
    cout << "Quelle valeur pour le strike ?" << endl;
    scanf("%lf",&X);
    cout << "Quelle valeur pour la maturité ?" << endl;
    scanf("%lf",&T);
    cout << "Quelle valeur pour le taux d'intérêt sans risque ?" << endl;
    scanf("%lf",&r);
    cout << "Quelle valeur pour b ?" << endl;
    scanf("%lf",&b);
    cout << "Quelle valeur pour la volatilité ?" << endl;
    scanf("%lf",&sigma);
    cout << "Quelle valeur pour la puissance ?" << endl;
    scanf("%lf",&i);
    cout << "Tapez 0 pour un call, 1 pour un put" << endl;
    scanf("%d",&CallorPut);
    double resultat = powered(CallorPut,S,X,T,r,b,sigma,i);
    cout << "L'option vaut " << resultat << endl;
    system("PAUSE");
    return 0;
}
