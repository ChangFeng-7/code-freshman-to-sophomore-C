#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string id;
    string name;
public:
    Person(string id, string name) {
        this->id = id;
        this->name = name;
    }
};
class Student : public Person {
private:
    string major;
    int score;
public:
    Student(string id, string name, string major, int score);
    friend ostream& operator <<(ostream &out, Student &s);
};
/* 请在这里填写答案 */
Student::Student(string id, string name, string major, int score):Person(id,name){
    this->id=id;
    this->name=name;
    this->major=major;
    this->score=score;
}
ostream& operator <<(ostream &out, Student &s) {
    out << "ID：" << s.id
        << " 姓名：" << s.name
        << " 专业：" << s.major
        << " 成绩：" << s.score;
    return out;
}
int main() {
    Student a("ypc202101", "胡莘涵", "电子信息专业", 95);
    cout << a << endl;
    return 0;
}
//不知道为什么中文会输出乱码
