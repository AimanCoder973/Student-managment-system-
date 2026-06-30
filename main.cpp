#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    float marks;

public:
    void addStudent()
    {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void displayStudent()
    {
        cout << "\n--------------------";
        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\n--------------------";
    }

    int getRollNo()
    {
        return rollNo;
    }

    void updateStudent()
    {
        cin.ignore();
        cout << "\nEnter New Name: ";
        getline(cin, name);

        cout << "Enter New Marks: ";
        cin >> marks;

        cout << "\nStudent Updated Successfully!\n";
    }
};

int main()
{
    vector<Student> students;
    int choice, roll;
    bool found;

    do
    {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            Student s;
            s.addStudent();
            students.push_back(s);
            cout << "\nStudent Added Successfully!";
            break;
        }

        case 2:
        {
            if(students.empty())
            {
                cout << "\nNo Student Found!";
            }
            else
            {
                for(auto &s : students)
                {
                    s.displayStudent();
                }
            }
            break;
        }

        case 3:
        {
            found = false;
            cout << "\nEnter Roll Number: ";
            cin >> roll;

            for(auto &s : students)
            {
                if(s.getRollNo() == roll)
                {
                    s.displayStudent();
                    found = true;
                }
            }

            if(!found)
                cout << "\nStudent Not Found!";
            break;
        }

        case 4:
        {
            found = false;
            cout << "\nEnter Roll Number to Update: ";
            cin >> roll;

            for(auto &s : students)
            {
                if(s.getRollNo() == roll)
                {
                    s.updateStudent();
                    found = true;
                }
            }

            if(!found)
                cout << "\nStudent Not Found!";
            break;
        }

        case 5:
            cout << "\nThank You!";
            break;

        default:
            cout << "\nInvalid Choice!";
        }

    } while(choice != 5);

    return 0;
}
