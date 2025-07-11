#include <iostream>
using namespace std;
static int num = 1;
class Student {
private:
    int age;
    string name;
    int grade1;
    int grade2;
    int grade3;
    int ID;

public:
    Student() {
        cout << "Student " << num << endl;
        cout << "Enter your age: ";
        cin >> age;

        cout << "Enter your name: ";
        cin >> name;

        cout << "Enter your ID: ";
        cin >> ID;

        cout << "Enter the first subject grade: ";
        cin >> grade1;

        cout << "Enter the second subject grade: ";
        cin >> grade2;

        cout << "Enter the third subject grade: ";
        cin >> grade3;

        num++;
    }

    void print(Student ob1[], int size) {
        for (int x = 0; x < size; x++) {
            double Average = (ob1[x].grade1 + ob1[x].grade2 + ob1[x].grade3) / 3.0;
            cout << "\n--- Student " << x + 1 << " ---\n";
            cout << "Age: " << ob1[x].age << endl;
            cout << "Name: " << ob1[x].name << endl;
            cout << "ID: " << ob1[x].ID << endl;
            cout << "Grade 1: " << ob1[x].grade1 << endl;
            cout << "Grade 2: " << ob1[x].grade2 << endl;
            cout << "Grade 3: " << ob1[x].grade3 << endl;
            cout << "Average grades: " << Average << endl;
        }
    }

    void Excellencestudents(Student ob1[], int size) {
        cout << "\nStudents with excellent grades:\n";
        bool foundExcellent = false;
        for (int x = 0; x < size; x++) {
            double Average = (ob1[x].grade1 + ob1[x].grade2 + ob1[x].grade3) / 3.0;
            if (Average >= 90) {
                cout << "  " << ob1[x].name<<endl;
                foundExcellent = true;
            }
        }
        if (!foundExcellent) {
            cout << "No students with excellent grades.\n";
        }
    }

    void Search(Student ob1[], int size) {
        int codes;
        cout << "\nSearch engine (type 0 to exit)\n";
        do {
            cout << "\nEnter student ID to search: ";
            cin >> codes;
            if (codes == 0) break;

            bool found = false;
            for (int x = 0; x < size; x++) {
                double Average = (ob1[x].grade1 + ob1[x].grade2 + ob1[x].grade3) / 3.0;
                if (codes == ob1[x].ID) {
                    cout << "\nStudent found:\n";
                    cout << "Age: " << ob1[x].age << endl;
                    cout << "Name: " << ob1[x].name << endl;
                    cout << "ID: " << ob1[x].ID << endl;
                    cout << "Grade 1: " << ob1[x].grade1 << endl;
                    cout << "Grade 2: " << ob1[x].grade2 << endl;
                    cout << "Grade 3: " << ob1[x].grade3 << endl;
                    cout << "Average grades: " << Average << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "No student found with ID " << codes << endl;
            }

        } while (codes != 0);
    }
    void Delete (Student ob1[], int size)
    {
        int code ;
        do{
            cout<<"Enter the code of the student you want to delete : "<<endl;
            cin>>code ;
            if(code == 0 )break ;
            bool dalat  = false ;
            int indexToDelete = -1;
            for(int x = 0 ; x < size ; x++)
            {
                if(ob1[x].ID ==code )
                {
                    indexToDelete = x ;
                    dalat  = true;
                    break;
                }
            }
            if(dalat){
            for(int x = indexToDelete ; x < size ; x++)
            {
                ob1[x] = ob1[x + 1];
            }
            
            size--;
            cout << "\nStudent deleted successfully.\n";
            cout << "Remaining students:\n";
            
            for(int x = 0 ; x < size ; x++){
               cout << "Age: " << ob1[x].age << endl;
               cout << "Name: " << ob1[x].name << endl;
               cout << "ID: " << ob1[x].ID << endl;
               cout << "Grade 1: " << ob1[x].grade1 << endl;
               cout << "Grade 2: " << ob1[x].grade2 << endl;
               cout << "Grade 3: " << ob1[x].grade3 << endl;
             }
            }
          else
          cout << "❌ Student with ID " << code << " not found.\n";
          }while(true);
    }
    void Edit(Student ob1[], int size)
    {
        int IDI ;
        do{
        cout<<"Enter the code of the student whose data you want to modify : ";
        cin>>IDI;
        
        if(IDI == 0)break ;
        bool Verification = false ;
        for(int x = 0 ; x < size ; x++){
        if(IDI == ob1[x].ID){
            cout<<"age : ";
            cin>>ob1[x].age ;
            cout<<"ID : ";
            cin>>ob1[x].ID;
            cout<<"Grade 1 : ";
            cin>>ob1[x].grade1 ;
            cout<<"Grade2 : ";
            cin>>ob1[x].grade2 ;
            cout<<"Grade3 : ";
            cin>>ob1[x].grade3 ;
            Verification = true ;
           }
        }
        if(!Verification){
            cout<<"The code I wrote "<<IDI<<" Not registered ";
          }
        cout<<"Student data after modification ";
        for(int x = 0 ; x < size ; x++){
            double Average = (ob1[x].grade1 + ob1[x].grade2 + ob1[x].grade3) / 3.0;
            cout << "Age: " << ob1[x].age << endl;
            cout << "Name: " << ob1[x].name << endl;
            cout << "ID: " << ob1[x].ID << endl;
            cout << "Grade 1: " << ob1[x].grade1 << endl;
            cout << "Grade 2: " << ob1[x].grade2 << endl;
            cout << "Grade 3: " << ob1[x].grade3 << endl;
            cout << "Average grades: " << Average << endl;
          }
        }while(true);
    }
};

int main() {
    int size;
    cout << "Enter the number of students: ";
    cin >> size;

    Student* ob1 = new Student[size];

    ob1[0].print(ob1, size);
    ob1[0].Excellencestudents(ob1, size);
    ob1[0].Search(ob1, size);
    ob1[0].Delete(ob1, size);
    ob1[0].Edit(ob1, size);
    delete[] ob1; // تحرير الذاكرة
    return 0;
}