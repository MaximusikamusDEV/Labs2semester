#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;

void Outer(double res, double s, double t, double k_iter, bool check);
void Ans(double s1, double s2, double ds, double a, double b, double t1, double t2, double dt);
double Integral(double n, double a, double b, double t, double s, void (*func)(double&, double, double));
void CalcArg(double& x, double t, double s);
void Enter(double& a, double& b, double& ds, double& s1, double& s2, double& dt, double& t1, double& t2);