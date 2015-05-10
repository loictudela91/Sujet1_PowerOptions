//
//  functions.h
//  PowerOptions
//
//  Created by Loic Tudela on 05/05/2015.
//  Copyright (c) 2015 Loic Tudela. All rights reserved.
//

#ifndef PowerOptions_functions_h
#define PowerOptions_functions_h

/*
const double S = 100;
const double X = 100;
const double T = 0.5;
const double r = 0.1;
const double b = 0.07;
const double sigma = 0.2;
const double i = 2;
*/

#include <string>
using namespace std;

const double p = 0.2316419;
const double b1 = 0.319381530;
const double b2 = - 0.356563782;
const double b3 = 1.781477937;
const double b4 = - 1.821255978;
const double b5 = 1.330274429;

const double Pi = 3.1415926;

double factorielle(double);
double combin(double,double);
double fdrgauss(double);
double powercontracts(double,double,double,double,double,double,double);
double standardpower(int,double,double,double,double,double,double,double);
double cappedpower(int,double,double,double,double,double,double,double,double);
double powered(int,double,double,double,double,double,double,double);

#endif
