// #include <iostream>
// using namespace std;
// class student
// {
// private:
//     double dob;

// public:
// student(){ // constructor
//     cout<<"This is constructor which is intialise automatically:"<<endl;
// }
//     string name;
//     string sec;
//     int rollno;
//     void dob2(double n)
//     {
//         dob = n;
//     }
//     double getdob()
//     {
//         return dob;
//     }
// };

// int main()
// {
//     student st1;
//     st1.name = "aman";
//     st1.sec = "A";
//     st1.rollno = 37;
//     st1.dob2(140426);

//     cout<<st1.name<<endl;

//     return 0;
// }

// using parametrised constructor
#include <iostream>
using namespace std;
class student
{
private:
    double dob;

public:
    student()
    { // constructor
        cout << "This is constructor which is intialise automatically:" << endl;
    }
    student(string s, string sc, int roll, double dob2)
    {
        name = s;
        sec = sc;
        rollno = roll;
        dob = dob2;
    }

    string name;
    string sec;
    int rollno;
    void dob2(double n)
    {
        dob = n;
    }
    double getdob()
    {
        return dob;
    }
    void getinfo()
    {
        cout << name << endl;
        cout << sec << endl;
        cout << rollno << endl;
        cout << dob << endl;
    }
};

int main()
{
    student st1("aman", "A", 37, 140426);
    st1.getinfo();
    return 0;
}