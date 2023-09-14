#include "Func.h"

struct List
{
	char Sname[100];
	char Name[100];
	int age;
	char gender[1];
	double ball;
	int course;
};

void AddToFile()
{
	List stud;
	
	cin >> stud.Sname >> stud.Name >> stud.age >> stud.gender >> stud.ball >> stud.course;
	
	ofstream file;
	file.open("ListStud.txt", ios_base::app);

//	file << 

	file << stud.Sname << " " << stud.Name << " " << stud.age << " " << stud.gender << " " << stud.ball << " " << stud.course << endl;
	
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


	List stud;

	file.open("ListStud.txt");
	ofile.open("Answer.bin");

	bool fl = false;

	while (true)
	{
			if (file.eof())
				break;
			
			file >> stud.Sname;
			file >> stud.Name;
			file >> stud.age;
			file >> stud.gender;
			file >> stud.ball;
			file >> stud.course;
			
			if (file.eof())
				break;

			if (stud.course == n)
			{
				ofile.write((char*)&stud, sizeof(List));
				//ofile << Sname << " " << Name << " " << age << " " << gender << " " << ball << " " << course << endl;
			}


			
	}

	ofile.close();
	file.close();
}

void OutputFromFile()
{
	fstream file;

	List stud;

	file.open("Answer.bin");

	bool fl = false;
	while (true)
	{
		if (file.eof())
			break;

		file.read((char*)&stud, sizeof(List));

		if (file.eof())
			break;

		cout << stud.Sname << " " << stud.Name << " " << stud.age << " " << stud.gender << " " << stud.ball << " " << stud.course << endl;

	}

	file.close();
}