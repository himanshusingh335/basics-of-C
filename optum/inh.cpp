#include <iostream>
#include <string>
using namespace std;

class Kid
{
private:
    string name;
    string gender;

public:
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getGender()
    {
        return gender;
    }
    void setGender(string gender)
    {
        this->gender = gender;
    }

    Kid(string name, string gender)
    {
        this->name = name;
        this->gender = gender;
    }
};

class Student : public Kid
{
private:
    int regNo;

public:
    Student(int regNo, string name, string gender) : Kid(name, gender)
    {
        this->regNo = regNo;
    }
    Student();
};

int main()
{
    Student s(1, "himanshu", "M");
    cout << s.getName();
    cout << s.getGender();
}