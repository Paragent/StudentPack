#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Student {
private:
    string firstName;
    string lastName;
    vector<int> grades;

public:
    Student(string NewFirstName, string NewLastName)
        : firstName(NewFirstName), lastName(NewLastName) {}

    string getFirstName() const { return firstName; }
    vector<int> getGrades() const { return grades; }
    int getNumGrades() const { return grades.size(); }
    void assignGrade(int NewGrade) { grades.push_back(NewGrade); }
    bool isExcellentStudent() const
    {
        if (grades.empty()) {
            return false;
        }

        float average = 0;
        for (int i = 0; i < grades.size(); i++) average += grades[i];
        average /= grades.size();

        return (average >= 4.5);
    }
};

class Teacher {
protected:
    string subject;
    bool mood;
    int gradeCounter;

public:
    Teacher(string NewSubject)
        : subject(NewSubject), mood(rand() % 2 == 0), gradeCounter(0) {}

    virtual void giveGrade(Student& student)
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

        gradeCounter++;
        if (gradeCounter % 5 == 0) {
            mood = !mood;
        }
    }

    string getSubject() const { return subject; }
    bool getMood() const { return mood; }
};

class fiveTeacher : public Teacher {
public:
    fiveTeacher(string NewSubject)
        : Teacher(NewSubject) {}

    void giveGrade(Student& student) override
    {
        student.assignGrade(5);
    }
};

class twoTeacher : public Teacher {
public:
    twoTeacher(string NewSubject)
        : Teacher(NewSubject) {}

    void giveGrade(Student& student) override
    {
        student.assignGrade(2);
    }
};

class OftenChangingMoodTeacher : protected Teacher {
public:
    OftenChangingMoodTeacher(string NewSubject)
        : Teacher(NewSubject) {}

    void giveGrade(Student& student) override
    {
        student.assignGrade(5);
        gradeCounter++;
        if (gradeCounter % 3 == 0) {
            mood = !mood;
        }
    }
};

class RarelyChangingMoodTeacher : protected Teacher {
public:
    RarelyChangingMoodTeacher(string NewSubject)
        : Teacher(NewSubject) {}

    void giveGrade(Student& student) override
    {
        student.assignGrade(5);
        gradeCounter++;
        if (gradeCounter % 10 == 0) {
            mood = !mood;
        }
    }
};

class Lesson {
private:
    Teacher teacher;
    vector<Student> students;

public:
    Lesson(const Teacher& lessonTeacher)
        : teacher(lessonTeacher) {}

    void addStudent(const Student& student)
    {
        students.push_back(student);
    }

    void conductLesson()
    {
        for (Student& student : students)
        {
            teacher.giveGrade(student);
        }
    }

    Teacher getTeacher() const { return teacher; }
    vector<Student> getStudents() const { return students; }
};

int main()
{
    srand(time(0));

    fiveTeacher t1("OOP");
    Lesson l1(t1);

    Teacher t2("Math");
    Lesson l2(t2);

    twoTeacher t3("English");
    Lesson l3(t3);


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

    t2.giveGrade(s1);
    t2.giveGrade(s2);
    t2.giveGrade(s3);

    t3.giveGrade(s1);
    t3.giveGrade(s2);
    t3.giveGrade(s3);

    l1.addStudent(s1);
    l1.addStudent(s2);
    l1.addStudent(s3);

    l2.addStudent(s1);
    l2.addStudent(s2);
    l2.addStudent(s3);

    l3.addStudent(s1);
    l3.addStudent(s2);
    l3.addStudent(s3);

    cout << (s1.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s2.isExcellentStudent()?"Excellent":"Not excellent") << endl;
    cout << (s3.isExcellentStudent()?"Excellent":"Not excellent") << endl;

    cout << t1.getSubject() << endl;
    cout << t2.getSubject() << endl;
    cout << t3.getSubject() << endl;

    l1.conductLesson();
    l2.conductLesson();
    l3.conductLesson();


    for (const Student& stud : l3.getStudents())
    {
        cout << stud.getFirstName() << "'s grades: ";
        for (int i=0; i < stud.getNumGrades(); i++) {
            cout << stud.getGrades()[i] << " ";
        }
        cout << endl;
    }


    return 0;
}
