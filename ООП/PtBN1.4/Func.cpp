#include "Func.h"

void AddToFile()
{
	char Sname[100];
	char Name[100];
	int age;
	char gender;
	double ball;
	int course;

	cin >> Sname >> Name >> age >> gender >> ball >> course;
	
	ofstream file;
	file.open("ListStud.txt", ios_base::app);

	file << Sname << " " << Name << " " << age << " " << gender << " " << ball << " " << course << endl;
	
	file.close();
}

void Ask()
{
	bool fl = 0;
	while (true)
	{
		cout << "If you want to add student to list, press 1, or press 0 if you don't want: ";
		cin >> fl;
		if (fl == 0)
			break;
		if (fl == 1)
			AddToFile();
	}
}

void Ans()
{
	fstream file;
	ofstream ofile;
	int n;

	cout << "Write a course which you want to know: ";
	cin >> n;


	char Sname[100];
	char Name[100];
	char gender;
	double ball;
	int course;
	int age;

	file.open("ListStud.txt");
	ofile.open("Answer.txt");

	bool fl = false;

	while (true)
	{
			if (file.eof())
				break;
			
			file >> Sname;
			file >> Name;
			file >> age;
			file >> gender;
			file >> ball;
			file >> course;
			
			if (file.eof())
				break;

			if (course == n)
			{
				ofile << Sname << " " << Name << " " << age << " " << gender << " " << ball << " " << course << endl;
			}


			
	}

	file.close();
}

void OutputFromFile()
{
	fstream file;

	char Sname[100];
	char Name[100];
	char gender;
	double ball;
	int course;
	int age;

	file.open("ListStud.txt");

	bool fl = false;
	while (true)
	{
		if (file.eof())
			break;

		file >> Sname;
		file >> Name;
		file >> age;
		file >> gender;
		file >> ball;
		file >> course;

		if (file.eof())
			break;

		cout << Sname << " " << Name << " " << age << " " << gender << " " << ball << " " << course;

	}

	file.close();
}