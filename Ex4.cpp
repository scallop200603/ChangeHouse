#include <iostream>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

struct Student
{
    int ID;
    string name;
    string Class;
    Student(int _ID, string _name, string _Class)
    {
        ID = _ID;
        name = _name;
        Class = _Class;
    }
    Student(){
        ID = 0;
        name = "";
        Class = "";
    }
};
struct Node
{
    Student student;
    Node* next;
    Node(int id, string name, string Class, Node* _next)
    {
        student.ID = id;
        student.name = name;
        student.Class = Class;
        next = _next;
    }
    Node(){
        student = Student(0, "", "");
        next = nullptr;
    }
};
struct ClassList
{
    Node* head;
    ClassList(Node* _head)
    {
        head = _head;
    }
    ClassList(){
        head = nullptr;
    }
    void deleting(int id);
    void deleteHead();
    Node* insert(int id, string name, string Class);
    void print();
    void infor(int id);
};
string getItem(string input);

int getIDFromInsert(string input);

string getNameFromInsert(string input);

string getClassFromInsert(string input);

int getIDFromDelete(string input);

int getIDFromInfor(string input);

int main()
{
    ClassList list;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if(getItem(s) == "Insert")
        {
            int id = getIDFromInsert(s);
            string name = getNameFromInsert(s);
            string Class = getClassFromInsert(s);
            list.insert(id, name, Class);
        }
        else if(getItem(s) == "Delete")
        {
            int id = getIDFromDelete(s);
            list.deleting(id);
        }
        else if(getItem(s) == "Infor")
        {
            int id = getIDFromInfor(s);
            list.infor(id);
        }
    }
    return 0;
}
void ClassList::infor(int id)
{
    Node* temp;
    int count = 0;
    for(Node* p = head; p != nullptr; p = p->next)
    {
        if(p->student.ID == id)
        {
            temp = p;
            count++;
        }
    }
    if(count != 0) cout << temp->student.name << "," << temp->student.Class << endl;
    else cout << "NA,NA" << endl;
}
void ClassList::deleting(int id)
{
    if(id == head->student.ID) deleteHead();
    else
    {
        Node* temp;
        for(Node* p = head; p != nullptr; p = p->next)
        {
            if(p->student.ID == id)
            {
                temp = p;
                break;
            }
        }
        Node* p = head;
        while(p->next != temp)
        {
            p = p->next;
        }
        p->next = temp->next;
        delete temp;
    }
}
void ClassList::deleteHead()
{
    Node* p = head;
    head = head->next;
    delete p;
}
Node* ClassList::insert(int id, string name, string Class)
{
    Node* newStudent = new Node(id, name, Class, nullptr);
    if(head == nullptr) head = newStudent;
    else
    {
        Node* p = head;
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = newStudent;
    }
    return newStudent;
}
void ClassList::print()
{
    if(head == nullptr) cout << "Empty list" << endl;
    else
    {
        Node* p = head;
        while(p != nullptr)
        {
            cout << p->student.ID << " " << p->student.name << " " << p->student.Class << endl;
            p = p->next;
        }
    }
    cout << endl;
}
string getItem(string input)
{
    string s = "";
    int i = 0;
    while(input[i] != '(')
    {
        s += input[i];
        i++;
    }
    return s;
}
int getIDFromInsert(string input)
{
    string s = "";
    int i = 7;
    while(input[i] != ',')
    {
        s += input[i];
        i++;
    }
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0') * pow(10, s.length() - i - 1);
    }
    return sum;
}
string getNameFromInsert(string input)
{
    string s = "";
    int i = 9;// need to update this later
    while(input[i] != ',')
    {
        s += input[i];
        i++;
    }
    return s;
}
string getClassFromInsert(string input)
{
    int start = -1;
    int end = -1;
    for(int i = 0; i < input.length(); i++)
    {
        if(input[i - 1] == ',') start = i;
        if(input[i + 1] == ')') end = i;
    }
    string s = input.substr(start, end - start + 1);
    return s;
}
int getIDFromDelete(string input)
{
    string s = "";
    int i = 7;
    while(input[i] != ')')
    {
        s += input[i];
        i++;
    }
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0') * pow(10, s.length() - 1 - i);
    }
    return sum;
}
int getIDFromInfor(string input)
{
    string s = "";
    int i = 6;
    while(input[i] != ')')
    {
        s += input[i];
        i++;
    }
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        sum += (s[i] - '0') * pow(10, s.length() - 1 - i);
    }
    return sum;
}
