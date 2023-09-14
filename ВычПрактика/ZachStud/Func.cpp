#include "Func.h"

struct Stud
{
	char Sname[100];
	char Name[100];
	char birthdate[100];
	double ball;
	int course;
	int group;
	Stud* next;
};

void Delete(Stud*& BSU, int course)
{
	Stud* head = BSU;
	Stud* pv = BSU;
	
	while (pv->course == course)
	{
		BSU = BSU->next;
		delete pv;
		pv = BSU;
		head = pv;

	}
	
	if (BSU->next)
		BSU = BSU->next;

	while (BSU)
	{
		if (BSU && BSU->course == course)
		{
			pv->next = BSU->next;
			delete BSU;
			BSU = pv->next;
		}
		else
		{
			pv = pv->next;
			BSU = BSU->next;
		}
	}

	BSU = head;
}

void CourseDel(Stud*& BSU)
{
	int n;
	cout << "Write a course which you want to delete: ";
		cin >> n;
	Delete(BSU, n);

	cout << "If you want to delete it from file then type 1: ";
		bool fl;
		cin >> fl;

		if (fl == 1)
		{

			char Sname[100];
			char Name[100];
			char birthdate[100];
			double ball;
			int course;
			int group;
			fstream file1;
			ofstream file2;
			file1.open("Input.json");
			file2.open("temp.json");

			while (true)
			{
				if (file1.eof())
					break;
				file1 >> Sname;
				file1 >> Name;
				file1 >> birthdate;
				file1 >> ball;
				file1 >> course;
				file1 >> group;

				if (course != n)
				{
					file2 << Sname;
					file2 << " ";
					file2 << Name;
					file2 << " ";
					file2 << birthdate;
					file2 << " ";
					file2 << ball;
					file2 << " ";
					file2 << course;
					file2 << " ";
					file2 << group;
					file2 << endl;
				}
			}
			file1.close();
			file2.close();

			ofstream filein;
			fstream file;

			filein.open("Input.json");
			file.open("temp.json");
			while (true)
			{
				if (file.eof())
					break;
				file >> Sname;
				file >> Name;
				file >> birthdate;
				file >> ball;
				file >> course;
				file >> group;
				if (file.eof())
					break;
					filein << Sname;
					filein << " ";
					filein << Name;
					filein << " ";
					filein << birthdate;
					filein << " ";
					filein << ball;
					filein << " ";
					filein << course;
					filein << " ";
					filein << group;
					//filein << " ";
					filein << endl;
			}

			file.close();
			filein.close();

		}


}

void AddToFile()
{
	bool fl = true;
	bool kos = false;
	char Sname[100];
	char Name[100];
	char birthdate[100];
	double ball;
	int course;
	int group;
	ofstream file;

	while (true)
	{
		cout << "If you want to add person to list then write 1 else write 0: ";
		cin >> fl;

		if (fl == false)
			break;

		cin >> Sname;
		cin >> Name;
		cin >> birthdate;
		cin >> ball;
		cin >> course;
		cin >> group;
		file.open("Input.json", ios::app);
		if (kos == true)
		file << endl << Sname << " " << Name << " " << birthdate << " " << ball << " " << course << " " << group << endl;
		else
			file << Sname << " " << Name << " " << birthdate << " " << ball << " " << course << " " << group << endl;
		file.close();
		kos = true;
	}
}

void Find(Stud*& BSU, Stud* pv)
{
	Stud* head = BSU;
	Stud* ppv = BSU;
	BSU = BSU->next;
	while (BSU && BSU->Sname[0] < pv->Sname[0])
	{
		BSU = BSU->next;
		ppv = ppv->next;
	}

	ppv->next = pv;
	if(BSU)
	pv->next = BSU;
	BSU = head;
}

void Add(Stud*& BSU, char Sname[], char Name[], char birthdate[], double ball, int course, int group)
{
	Stud* pv = BSU;
	Stud* new_el = new Stud;

	new_el->ball = ball;
	new_el->course = course;
	new_el->group = group;

	for (int i = 0; i < 100; i++)
	{
		new_el->birthdate[i] = birthdate[i];
		new_el->Name[i] = Name[i];
		new_el->Sname[i] = Sname[i];
	}

	new_el->next = NULL;

	if (!BSU)
	{
		BSU = new_el;
		//cout << Sname << " ";
	}
	else
	{
		if (new_el->Sname[0] < BSU->Sname[0])
		{
			new_el->next = BSU;
			BSU = new_el;
			//cout << Sname << " ";
		}
		else
		{
			Find(BSU, new_el);
			BSU = pv;
		}
	   
		//BSU = pv;
	}


}

void Read(Stud*& BSU)
{
	fstream file;
	
	char Sname[100];
	char Name[100];
	char birthdate[100];
	double ball;
	int course;
	int group;

	file.open("ListStud.txt");

	bool fl = false;

	while (true)
	{
			if (file.eof())
				break;
			file >> Sname;
			file >> Name;
			file >> birthdate;
			file >> ball;
			file >> course;
			file >> group;
			if (file.eof())
				break;

			//cout << Sname << " ";
			Add(BSU, Sname, Name, birthdate, ball, course, group);
			//Output(BSU);
	}

	file.close();
}

void Output(Stud* BSU)
{
	//BSU = BSU->next;
	while (BSU)
	{
	 cout << BSU->Sname << " " << BSU->Name << " " << BSU->birthdate << " " << BSU->ball << " " << BSU->course << " " << BSU->group << endl;
	 BSU = BSU->next;
	}
}