#include <iostream> 
using namespace std; 
  
class Student { 
private: 
    int _id;
    int _english; 
    int _math; 
  
public: 
    Student(int id, int e, int m) 
    { 
        _id = id;
        _english = e; 
        _math = m; 
    } 
    int getID() { return _id; }
    int getEnglish() { return _english; }
    int getMath() { return _math; }
    
    friend ostream& operator<<(ostream& os, Student& student)
    {
        os<<student._id<<" "<<student._english<<" "<<student._math;
        return os;
    }

    friend istream& operator>>(istream& is, Student& student)
    {
        is >> student._id;
        is >> student._english;
        is >> student._math;
        return is;
    }
    
    Student& operator= (const Student& s)
    {
        _english = s._english;
        _math = s._math;
        return *this;
    }
}; 
  
// DO NOT MODIFY ANYTHING BELOW, MAY RESULT WITH FAILED HOMEWORK
int main() 
{ 
    int id1, id2, e1, e2, m1, m2, variant;
    cin >> id1 >> e1 >> m1 >> id2 >> e2 >> m2 >> variant;
    Student s1(id1, e1, m1), s2(id2, e2, m2);
    if (variant == 1)
    {
        s1 = s2;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 2)
    {
        s1 = s1;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 3)
    {
        cin >> s1;
        cout << s1.getID()<< " " << s1.getEnglish() << " " << s1.getMath();
    }
    else if (variant == 4)
    {
        cout << s1;
    }
    else
    {
        return 1;
    }
    return 0; 
}