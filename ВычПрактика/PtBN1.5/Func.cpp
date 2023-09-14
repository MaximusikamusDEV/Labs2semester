#include "Func.h"

void CalcArg(double& x, double t, double s)
{
	double cosec = cos(pow(x, 1 / 3));

	x = (pow(x, 2)) / (log(pow(x, t) + pow(cosec, 2))) * s;
}

double Integral(double n, double a, double b, double t, double s, void (*func)(double&, double, double))
{
	double cnt = 0;

	double x;

	double h = (b - a) / n;

	for (int i = 1; i <= n; i++)
	{
		x = a + i * h;

		func(x, t, s);

		cnt += x;
	}


	return (cnt * h);
}

void Ans(double s1, double s2, double ds, double a, double b, double t1, double t2, double dt)
{
	double eps = 0.000001;
	int k_iter;
	bool check = false;

	double n = 1;
	double res = 0;
	double resapp = 0;
	double tmp = t1;


	while (s1 <= s2)
	{
		while (t1 <= t2)
		{
			k_iter = 0;

			n = 1;
			res = 0;
		    resapp = 0;

			res = Integral(n, a, b, t1, s1, CalcArg);

			while (abs(resapp - res) > eps)
			{
				resapp = res;

				

				n *=  2;

				k_iter++;

				res = Integral(n, a, b, t1, s1, CalcArg);
                
			}

			Outer(res, s1, t1, k_iter, check);

			check = true;

			t1 += dt;
		}


		t1 = tmp;
		s1 += ds;

	}

}

void Outer(double res, double s, double t, double k_iter, bool check)
{
	if (check == false)
	{
		cout << "s \t" << "t \t" << "Int \t" << "k_iter \t" << endl;
	}
	
	cout << setprecision(3) << s << "\t" << t << "\t" << res << "\t" << k_iter << "\t" << endl;
}

void Enter(double& a, double& b, double& ds, double& s1, double& s2, double& dt, double& t1, double& t2)
{
	ifstream file;

	file.open("Input.txt");

	file >> a;
	file >> b;
	file >> ds;
	file >> s1;
	file >> s2;
	file >> dt;
	file >> t1;
	file >> t2;

	file.close();

}