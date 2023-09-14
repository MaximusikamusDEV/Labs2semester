#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct Stud;
void Find(Stud*& BSU, Stud* pv);
void AddToFile();
void Add(Stud*& BSU, char Sname[], char Name[], char birthdate[], double ball, int course, int group);
void Read(Stud*& BSU);
void Output(Stud* BSU);
void CourseDel(Stud*& BSU);
void Delete(Stud*& BSU, int course);