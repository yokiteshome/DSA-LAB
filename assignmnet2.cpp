#include <iostream>
#include <string>
using namespace std;


struct Student{
    int id;
    double cgpa;
    string name;
} yordanos; //method one


template<class Type>
Type overload( Type x, Type y) {
    return x+y;
}


int overload( int x, int y){
    return x+y;
}


string overload( string x, string y) {
    return x+y;
}


double overload(double x, double y) {
    return (x+y)/2;
}

namespace yordi {
    int assignment(int age) {
        return age;
    }
}

namespace elshu {
    double assignment(double cgpa) {
        return cgpa;
    }
}


int main() {
    yordanos.id=489;
    yordanos.name="yordanos";
    yordanos.cgpa=4.0;

    cout<<"your id is: "<< yordanos.id<<endl;
    cout<<"your name is: "<<yordanos.name<<endl;
    cout<<"your cgpa is: "<<yordanos.cgpa<<endl;

    Student elshu; //method two

    cout<<"enter elshu's name: "<<endl;
    cin>>elshu.name;
    cout<<"elshu's name is: "<<elshu.name<<endl;
    cout<<"enter elshu's id: "<<endl;
    cin>>elshu.id;
    cout<<"elshu's id is: "<<elshu.id<<endl;
    cout<<"enter elshu's cgpa: "<<endl;
    cin>>elshu.cgpa;
    cout<<"elshu's cgpa is: "<<elshu.cgpa<<endl;

    int result= overload<int>(elshu.id,yordanos.id);
    double result2=overload<double>(elshu.cgpa,yordanos.cgpa);
    string result3=overload<string>("hello", " I'm shalom harloy");
    cout<<result<<endl;
    cout<<result2<<endl;
    cout<<result3<<endl;


    int age=20;
    // double gpa1,gpa2;


    // cout<<"What is the first semester's gpa?: "<<endl;
    // cin>>gpa1;
    // cout<<"What is the second semester's gpa?: "<<endl;
    // cin>>gpa2;
    // double cgpa= (gpa1+gpa2)/2;

    cout<<"yordi::assignment is: "<<yordi::assignment(age)<<endl;
    cout<<"elshu::assignment is: "<<elshu::assignment(elshu.cgpa)<<endl;
    return 0;

    return 0;
}
// }

// namespace yordi {
//     int assignment(int age) {
//         return age;
//     }
// }

// namespace elshu {
//     double assignment(double cgpa) {
//         return cgpa;
//     }
// }
//  int main() {
//     // int age=20;
    // double gpa1,gpa2;


    // cout<<"What is the first semester's gpa?: "<<endl;
    // cin>>gpa1;
    // cout<<"What is the second semester's gpa?: "<<endl;
    // cin>>gpa2;
    // double cgpa= (gpa1+gpa2)/2;

    // cout<<"yordi::assignment is: "<<yordi::assignment(age)<<endl;
    // cout<<"elshu::assignment is: "<<elshu::assignment(cgpa)<<endl;
    // return 0;
//  }



