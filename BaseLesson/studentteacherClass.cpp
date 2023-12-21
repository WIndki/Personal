#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string id; // 身份证号
    string name; // 姓名
    string gender; // 性别
    int age; // 年龄
    string major; // 专业
public:
    Person(string id, string name, string gender, int age, string major) {
        this->id = id;
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->major = major;
    }
};

class Student : public Person {
private:
    string student_id; // 学号
    int math_score; // 数学成绩
    int english_score; // 英语成绩
    int java_score; // Java程序设计成绩
public:
    Student(string id, string student_id, string name, string gender, int age, string major, int math_score, int english_score, int java_score) : Person(id, name, gender, age, major) {
        this->student_id = student_id;
        this->math_score = math_score;
        this->english_score = english_score;
        this->java_score = java_score;
    }
    void printInfo() {
        cout << "Student:" << id << " " << student_id << " " << name << " " << gender << " " << age << " " << major << " " << math_score << " " << english_score << " " << java_score << endl;
    }
};

class Teacher : public Person {
private:
    string teacher_id; // 教师号
    string title; // 职称
    int teaching_hours; // 授课时数
public:
    Teacher(string id, string teacher_id, string name, string gender, int age, string major, string title, int teaching_hours) : Person(id, name, gender, age, major) {
        this->teacher_id = teacher_id;
        this->title = title;
        this->teaching_hours = teaching_hours;
    }
    void printInfo() {
        cout << "Teacher:" << id << " " << teacher_id << " " << name << " " << gender << " " << age << " " << major << " " << title << " " << teaching_hours << endl;
    }
};

int main() {
    int type;
    while (cin >> type) {
        if (type == 1) {
            string id, student_id, name, gender, major;
            int age, math_score, english_score, java_score;
            cin >> id >> student_id >> name >> gender >> age >> major >> math_score >> english_score >> java_score;
            Student student(id, student_id, name, gender, age, major, math_score, english_score, java_score);
            student.printInfo();
        } else if (type == 2) {
            string id, teacher_id, name, gender, major, title;
            int age, teaching_hours;
            cin >> id >> teacher_id >> name >> gender >> age >> major >> title >> teaching_hours;
            Teacher teacher(id, teacher_id, name, gender, age, major, title, teaching_hours);
            teacher.printInfo();
        }
    }
    return 0;
}
