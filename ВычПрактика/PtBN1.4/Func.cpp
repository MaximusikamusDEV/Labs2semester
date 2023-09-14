#include "Func.h"

void Outer(double s, double x, double fx, int k_iter, bool fl)
{
	if (fl == true)
	{
		cout << "S\t" << "X\t" << "F(x)\t" << "K_ITER\t" << endl;	
	}

	cout << setprecision(3) << s << "\t" << x << "\t" << fx << "\t" << k_iter << "\t" << endl;

}

double FindF(double x)
{
	double f = pow((x - 1), 2) - 3;
	return f;
}

double FindFx(double x)
{
	double fx = 2*(x-1);
	return fx;
}

void FindX(double& x, double& f, double &fx, double (*funcF)(double), double (*funcFx)(double))
{
	f = funcF(x);
	fx = funcFx(x);
	x = x - f / fx;
}

void NewtonFunc(int a, int b)
{
	double f = 1;
	double fx = 2;
	int k_iter = 0;
	double x = b;
	bool fl = true;

	while (abs(f) > 0.000001)
	{
			FindX(x, f, fx, FindF, FindFx);

			fx = f;


			k_iter++;

		f = FindF(x);

	}
		Outer(0, x, fx, k_iter, fl);
}

double FindF(double x, double s)
{
	double f = pow(x,2) - sin(5*pow(x, s));
	return f;
}

double FindFx(double x, double s)
{
	double fx = 2*x - 5*s*pow(x, s-1)*sin(5*pow(x, s));
	return fx;
}

void FindX(double& x, double& f, double& fx, double (*funcF)(double, double), double (*funcFx)(double, double), double s)
{
	f = funcF(x, s);
	fx = funcFx(x, s);

	x = x - f / fx;
}

void NewtonFunc(double a, double b, double sl, double sr, double ds)
{
	double f;
	double fx;
	int k_iter = 0;
	double x;
	bool fl = true;

	while (sl <= sr)
	{
		k_iter = 0;
		x = b;
		f = 1;
		fx = 1;

		while (abs(f) > 0.000001)
		{
			FindX(x, f, fx, FindF, FindFx, sl);

			fx = f;

			k_iter++;

			f = FindF(x, sl);
		}


		Outer(sl, x, fx, k_iter, fl);
		fl = false;
		sl += ds;

	}
}
