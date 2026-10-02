#include <iostream>
#include <string>
using namespace std;

class Teacher
{
public:
    void teach()
    {
        cout << "Teaching students" << endl;
    }
};

class Sportman
{
};

class Student : virtual public Teacher, virtual public Sportman
{
};

int main()
{
    Student s;

    s.teach();

    return 0;
}