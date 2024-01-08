#include <iostream>
#include <string>
#include <vector>
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

    public:
        Teacher(string NewSubject) { this->subject = NewSubject; }
        void giveGrade(Student& student, int grade){
            student.assignGrade(grade);
        }

        string getSubject(){
            return this->subject;
        }
};

int main()
{
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

    t1.giveGrade(s1, 5);
    t1.giveGrade(s2, 4);
    t1.giveGrade(s3, 2);

    t1.giveGrade(s1, 3);
    t1.giveGrade(s2, 3);
    t1.giveGrade(s3, 3);

    t3.giveGrade(s1, 2);
    t3.giveGrade(s2, 2);
    t3.giveGrade(s3, 2);

    cout << (s1.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s2.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s3.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    
    cout << t1.getSubject() << endl;
    cout << t2.getSubject() << endl;
    cout << t3.getSubject() << endl;

    return 0;
}
