//
//  functions.cpp
//  PowerOptions
//
//  Created by Loic Tudela on 05/05/2015.
//  Copyright (c) 2015 Loic Tudela. All rights reserved.
//

#include <stdio.h>
#include "functions.h"
#include "math.h"


double factorielle(double n)
{
    if (n<=1)
    {
        return 1;
    }
    else
    {
        double p = 1;
        double res = 1;
        while (p<=n-1)
        {
            res = res*(res+1);
            p=p+1;
        }
        return res;
    }
}

double combin(double i, double j)
{
    double res1 = factorielle(i);
    double res2 = factorielle(j);
    double res3 = factorielle(i-j);
    return (res1+0.0)/(res2*res3);
}

double fdrgauss(double x)
{
    double t = 1.0/(1.0 + p*x);
    return 1 - exp(-x*x/2)*(b1*t + b2*pow(t,2) + b3*pow(t,3) + b4*pow(t,4) + b5*pow(t,5))/sqrt(2*Pi);
}

double powercontracts(double S,double X,double T,double r,double b,double sigma,double i)
{
    double fact = (S+0.0)/X;
    double a = b - (pow(sigma,2)+0.0)/2;
    double res1 = a*i - r + (pow(i,2)*pow(sigma,2)+0.0)/2;
    return pow(fact,i)*exp(res1*T);
}

double standardpower(int CallorPut, double S,double X,double T,double r,double b,double sigma, double i)
{
    double res1 = log(S) - (log(X)+0.0)/i;
    double res2 = b + ((2*i-1)*pow(sigma,2)+0.0)/2;
    double d1 = (res1 + T*res2+0.0)/(sigma*sqrt(T));
    double d2 = d1 - i*sigma*sqrt(T);
    double res3 = (i-1)*(r + (i*pow(sigma,2))/2);
    double res4 = i*(r-b);
    if (CallorPut==0)
    {
    return pow(S,i)*exp((res3-res4)*T)*fdrgauss(d1) - X*exp(-r*T)*fdrgauss(d2);
    }
    if (CallorPut==1)
    {
        return X*exp(-r*T)*fdrgauss(- d2) - pow(S,i)*exp((res3-res4)*T)*fdrgauss(- d1);
    }
    else
    {
        return 0;
    }
}

double cappedpower(int CallorPut,double C,double S,double X,double T,double r,double b,double sigma,double i)
{
    double res1 = log(S) - (log(X)+0.0)/i;
    double res2 = b + ((2*i-1)*pow(sigma,2)+0.0)/2;
    double e1 = (res1 + T*res2+0.0)/(sigma*sqrt(T));
    double e2 = e1 - i*sigma*sqrt(T);
    double res4 = b + ((2*i-1)*pow(sigma,2)+0.0)/2;
    double res5 = (i-1)*(r + (i*pow(sigma,2))/2);
    double res6 = i*(r-b);
    if (CallorPut==0)
    {
    double res3 = log(S) - (log(X+C)+0.0)/i;
    double e3 = (res3 + T*res4+0.0)/(sigma*sqrt(T));
    double e4 = e3 - i*sigma*sqrt(T);
    double res7 = pow(S,i)*exp((res5-res6)*T)*(fdrgauss(e1)-fdrgauss(e3));
    double res8 = exp(-r*T)*(X*fdrgauss(e2)-((X+C)*fdrgauss(e4)));
    return res7-res8;
    }
    if (CallorPut==1)
    {
        double res32 = log(S) - (log(X-C)+0.0)/i;
        double e3 = (res32 + T*res4+0.0)/(sigma*sqrt(T));
        double e4 = e3 - i*sigma*sqrt(T);
        double res8 = exp(-r*T)*(X*fdrgauss(-e2)-((X-C)*fdrgauss(-e4)));
        double res7 = pow(S,i)*exp((res5-res6)*T)*(fdrgauss(-e1)-fdrgauss(-e3));
        return res8-res7;
    }
    else
    {
        return 0;
    }
}

double powered(int CallorPut,double S,double X,double T,double r,double b,double sigma,double i)
{
    if (CallorPut==0)
    {
    double sum = 0;
    double d1;
    for (int j=0; j<=i; j=j+1)
    {
        d1 = (log(S/X) + (b + (i-j-0.5)*pow(sigma,2))*T) / (sigma*sqrt(T));
        sum = sum + combin(i,j)*pow(S,i-j)*pow(-X,j)*exp((i-j-1)*(r+(i-j)*pow(sigma,2)/2)*T - (i-j)*(r-b)*T)*fdrgauss(d1);
    }
    return sum;
    }
    if (CallorPut==1)
    {
        double sum = 0;
        double d1;
        for (int j=0; j<=i; j=j+1)
        {
            d1 = (log(S/X) + (b + (i-j-0.5)*pow(sigma,2))*T) / (sigma*sqrt(T));
            sum = sum + combin(i,j)*pow(-S,i-j)*pow(X,j)*exp((i-j-1)*(r+(i-j)*pow(sigma,2)/2)*T - (i-j)*(r-b)*T)*fdrgauss(-d1);
        }
        return sum;
    }
    else
    {
        return 0;
    }
}
