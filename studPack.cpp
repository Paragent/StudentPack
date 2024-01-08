#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Student{
    private:
        string firstName;
        string lastName;
        vector<int> grades;
    public:
        Student(string NewfirstName, string NewlastName)
        {
            firstName = NewfirstName;
            lastName = NewlastName;
        }
        string getfirstName() { return firstName; }
        vector<int> getgrades() { return grades; }
        void assignGrade(int NewGrade) { grades.push_back(NewGrade); }
        bool isExcellentStudent()
        {
            float average;
            for(int i = 0; i < grades.size(); i++) average += grades[i];
            average /= (grades.size());

            if(average >= 4.5) return true; else return false;
        }
};

class Teacher
{
    private:
        string subject;
        bool mood;

    public:
        Teacher(string NewSubject) : subject(NewSubject)
    {
        mood = (rand() % 2 == 0);
    }

    void giveGrade(Student& student)
    {
        int randomGrade = 0;

        if (mood && student.isExcellentStudent())
        {
            randomGrade = 5;
        }
        else if (!mood && student.isExcellentStudent())
        {
            randomGrade = (rand() % 2 == 0) ? 4 : 5;
        }
        else if (mood && !student.isExcellentStudent())
        {
            randomGrade = 4;
        }
        else if (!mood && !student.isExcellentStudent())
        {
            randomGrade = (rand() % 2 == 0) ? 2 : 3;
        }

        student.assignGrade(randomGrade);
    }

        string getSubject(){
            return this->subject;
        }
};

int main()
{
    srand(time(0));

    Teacher t1("OOP");
    Teacher t2("Math");
    Teacher t3("English");

    Student s1("Alex", "Mercer");
    Student s2("James", "Franko");
    Student s3("Peter", "Parker");

    s1.assignGrade(3);
    s1.assignGrade(2);
    s1.assignGrade(5);

    s2.assignGrade(5);
    s2.assignGrade(4);
    s2.assignGrade(5);

    s3.assignGrade(4);
    s3.assignGrade(4);
    s3.assignGrade(4);

    t1.giveGrade(s1);
    t1.giveGrade(s2);
    t1.giveGrade(s3);

    t1.giveGrade(s1);
    t1.giveGrade(s2);
    t1.giveGrade(s3);

    t3.giveGrade(s1);
    t3.giveGrade(s2);
    t3.giveGrade(s3);

    cout << (s1.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s2.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s3.isExcellentStudent()?"Excellent":"Not excellent") << endl;

    cout << t1.getSubject() << endl;
    cout << t2.getSubject() << endl;
    cout << t3.getSubject() << endl;

    return 0;
}
