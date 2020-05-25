#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>

using namespace std;

class Subject
{
protected:
	string _SubName;
	int _Hakjum;
	string _Grade;
	float _GPA;

private:
	void InPutValue(int &);
	void InPutValue(string &);

public:
	void Initialize();
	void Initialize(string subn, int hak, string grad);
	void InPutData();
	void PrintData() const;
	void CalcGPA();
	float GetGPA();
};

#endif