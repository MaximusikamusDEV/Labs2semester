#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void Outer(double s, double x, double fx, int k_iter, bool fl);
double FindF(double x);
double FindFx(double x);
void FindX(double& x, double& f, double& fx, double (*funcF)(double), double (*funcFx)(double));
void NewtonFunc(int, int);

void NewtonFunc(double a, double b, double sl, double sr, double ds);
void FindX(double& x, double& f, double& fx, double (*funcF)(double, double), double (*funcFx)(double, double), double s);
double FindFx(double x, double s);
double FindF(double x, double s);