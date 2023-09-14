#include "Func.h"

string ToPol(string exp)
{
	string PolExp;
	stack<char> Y;
	string ch;
	
	int prior = -1;

	for (unsigned int i = 0; i < exp.size(); i++)
	{
		
		prior = -1;
		CheckPrior(prior, exp[i]);

		if (prior == -1 && exp[i] != ')')
		{
			PolExp += exp[i];
		}
		else
			if (exp[i] == ')')
			{
				while (Y.top() != '(')
				{
					PolExp += Y.top();
					Y.pop();
				}
				Y.pop();
			}
			else 
				if (prior == 1)
				  Y.push(exp[i]);
				else
				{

					if (Y.empty())
						Y.push(exp[i]);
					else
					{
					    int tmpprior = -1;
						CheckPrior(tmpprior, Y.top());

						if (prior > tmpprior)
							Y.push(exp[i]);
						else
						{
							while (!Y.empty())
							{
								if (tmpprior < prior)
									break;
								PolExp += Y.top();
								Y.pop();
								if (!Y.empty() && Y.top() != '(')
									CheckPrior(tmpprior, Y.top());
								else
									tmpprior = -2;
							} 

							Y.push(exp[i]);
						}
					}

				}
	}

	
	while (!Y.empty())
	{
		PolExp += Y.top();
		Y.pop();
	}



	return PolExp;
}

void CheckPrior(int& prior, char exp)
{
	string pr1 = "(";
	string pr0 = "=";
	string pr2 = "+-";
	string pr3 = "*/%";

	if (pr0.find(exp, 0) < 5)
		prior = 0;
	else
		if (pr1.find(exp, 0) < 5)
			prior = 1;
		else
			if (pr2.find(exp, 0) < 5)
				prior = 2;
			else
				if (pr3.find(exp, 0) < 5)
					prior = 3;
}

void Calc(string st, int& ans)
{
	stringstream cont;
	vector<int> nums;
	int size = 0;

	for (int i = 0; i < st.size(); i++)
	{
		char t;
		t = st[i];
		int num = -1;
		CheckPrior(num, t);

		if (num == -1)
		{
			size++;
			cont.clear();
			cont << t;
			cont >> num;
			nums.push_back(num);
		}
	}

	bool flag = 0;
	
	while (true)
	{
		flag = 0;

		for (unsigned int i = 0; i < st.size(); i++)
		{
			char t;
			t = st[i];
			int num = -1;
			CheckPrior(num, t);
			if (num != -1)
			{
				flag = 1;
				if (t == '-')
					nums[i - 1] = nums[i - 2] - nums[i - 1];
				else
					if (t == '+')
						nums[i - 1] = nums[i - 1] + nums[i - 2];
					else
						if (t == '/')
							nums[i - 1] = nums[i - 2] / nums[i - 1];
						else
							if (t == '*')
								nums[i - 1] = nums[i - 2] * nums[i - 1];
							else
								if (t == '%')
									nums[i - 1] = nums[i - 2] % nums[i - 1];

				nums.erase(nums.begin() + i - 2);
				st.erase(i - 1, 2);
				cout << endl << endl;


				break;
			}
		}

		if (flag == 0)
			break;

	}

	ans = nums[0];
	
}