#include <iostream>
using namespace std;

class Child
{
protected:
    string name;

public:
    string getName()
    {
        return name;
    }
    void setName(string name)
    {
        this->name = name;
    }
    Child(string name)
    {
        this->name = name;
    }
};

class Student : public Child
{
private:
    int marks;

public:
    int getMarks()
    {
        return marks;
    }
    void setMarks(int marks)
    {
        this->marks = marks;
    }
    Student(int marks, string name) : Child(name)
    {
        this->marks = marks;
    }
};

void editMarks(Student &s)
{
    s.setMarks(s.getMarks() + 1);
}

int main()
{
    Student s(49, "Himanshu");
    Student *b = &s;
    cout << s.getMarks() << " " << s.getName() << endl;
    editMarks(*b);
    cout << s.getMarks() << " " << s.getName() << endl;
    return 0;
}
