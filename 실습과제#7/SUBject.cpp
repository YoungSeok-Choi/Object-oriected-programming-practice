#include "Student.h"


	/*
	privates
	*/
	void Subject::InPutValue(string & temp)
	{
		getline(cin, temp);
	}

	void Subject::InPutValue(int & i)
	{
		int temp;
		cin >> temp;
		i = temp;
	}
	

	/*
	publics
	*/
	void  Subject::InPutData()
	{
		string sub, grade;
		int hakjum;

		cout << "교과목명 : ";
		InPutValue(sub);
		cout << "과목학점수 : ";
		InPutValue(hakjum);
		cin.ignore();
		cout << "과목등급(A+ ~ F) : ";
		InPutValue(grade);
		Subject::Initialize(sub, hakjum, grade);
		CalcGPA();
		cout << "\n\n";
	}

	void  Subject::PrintData() const
	{
		cout << _SubName << "\t\t" << _Hakjum << "\t\t" << _Grade << "\t\t" << _GPA;
	}

	void  Subject::CalcGPA()
	{
		string gde[20] = { "A+", "a+", "A0", "a0", "B+",
					 "b+", "B0", "b0", "C+", "c+",
				   "C0", "c0", "D+", "d+","D0",
				  "d0", "F","f" };

		if (gde[0] == Subject::_Grade || gde[1] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 4.5;

		else if (gde[2] == Subject::_Grade || gde[3] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 4.0;

		else if (gde[4] == Subject::_Grade || gde[5] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 3.5;

		else if (gde[6] == Subject::_Grade || gde[7] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 3.0;

		else if (gde[8] == Subject::_Grade || gde[9] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 2.5;

		else if (gde[10] == Subject::_Grade || gde[11] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 2.0;

		else if (gde[12] == Subject::_Grade || gde[13] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 1.5;

		else if (gde[14] == Subject::_Grade || gde[15] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 1.0;

		else if (gde[16] == Subject::_Grade || gde[17] == Subject::_Grade)
			Subject::_GPA = Subject::_Hakjum * 0.0;

		else
		{
			cout << "성적이 아닌 정보를 입력하였으므로 프로그램을 종료합니다. 다시 실행하여 올바른값을 넣어주세요\n";
			exit(1);
		}
	}

	float Subject::GetGPA()
	{
		return _GPA;
	}
    
	void Subject::Initialize(string subn, int hak, string grad)
	{
		Subject::_SubName = subn;
		Subject::_Hakjum = hak;
		Subject::_Grade = grad;
	}

	void Subject::Initialize()
	{
		string Dfault = "국어";
		int hak = 3;
		string grade = "A0";

		Subject::_SubName = Dfault;
		Subject::_Hakjum = hak;
		Subject::_Grade = grade;
	}

