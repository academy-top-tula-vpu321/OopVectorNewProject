#include <iostream>
#include <vector>

using namespace std;

class Vector
{
    int* array;
    int size;
public:
    Vector(int size = 0) : size{ size }
    {
        array = new int[size];
    }

    int GetItem(int index)
    {
        return array[index];
    }

    int Size()
    {
        return size;
    }

    void SetItem(int index, int value)
    {
        array[index] = value;
    }

    int& operator[](int index)
    {
        return array[index];
    }
};

class User
{
    string name;
    string email;
    string address;
public:
    string& Name()
    {
        return name;
    }

    string& operator[](string key)
    {
        if (key == "name")
            return name;
        if (key == "email")
            return email;
        if (key == "address")
            return address;
    }

    friend ostream& operator<<(ostream& out, const User& user)
    {
        out << user.name << " " << user.address << " " << user.email;
        return out;
    }
};

class Accumulator
{
    int counter{};
public:
    int operator()(int number)
    {
        return counter += number;
    }

    void Reset() { counter = 0; }

    int Value() { return counter; }
};

class Matrix
{
    int** data;
    int rows;
    int cols;
public:
    Matrix(int rows, int cols) : rows{ rows }, cols{ cols }
    {
        data = new int* [rows];
        for (int i = 0; i < rows; i++)
            data[i] = new int[cols];
    }

    int& operator()(int row, int col)
    {
        return data[row][col];
    }

    int Rows() { return rows; }
    int Cols() { return cols; }

    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
};

class StringCompare
{
public:
    bool operator()(string s1, string s2)
    {
        //return s1 < s2;

        return s1.length() < s2.length();
    }
};

void Sort(vector<string>& v, StringCompare compare)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for(int j = v.size() - 1; j > i; j--)
            if (compare(v[j], v[j - 1]))
            {
                string temp = v[j];
                v[j] = v[j - 1];
                v[j - 1] = temp;
            }
    }

}

int Sum(int a, int b) { return a + b; }
int Mult(int a, int b) { return a * b; }
int Calc(int a, int b, int(*operation)(int, int))
{
    return operation(a, b);
}




int main()
{
    /*
    Vector v1(5);
    for (int i = 0; i < v1.Size(); i++)
        v1.SetItem(i, (i + 1) * 10);

    for (int i = 0; i < v1.Size(); i++)
        //std::cout << v1.GetItem(i) << " ";
        std::cout << v1[i] << " ";
    std::cout << "\n";

    v1[2] = 100;

    for (int i = 0; i < v1.Size(); i++)
        std::cout << v1[i] << " ";

    std::cout << "\n";

    User user;
    user["name"] = "Bob";
    user["address"] = "Tula";
    user["email"] = "bobby@mail.ru";

    user.Name() = "Tom";
    cout << user.Name() << "\n";

    cout << user << "\n";
    */

    /*cout << Calc(10, 20, Sum) << "\n";
    cout << Calc(10, 20, Mult) << "\n";

    cout << Sum << "\n";

    Accumulator acc;
    cout << acc(10) << "\n";
    cout << acc(20) << "\n";
    cout << acc.Value() << "\n";

    Matrix m(3, 4);
    for (int r = 0; r < m.Rows(); r++)
        for (int c = 0; c < m.Cols(); c++)
            m(r, c) = (r + 1) * 10 + (c + 1);

    for (int r = 0; r < m.Rows(); r++)
    {
        for (int c = 0; c < m.Cols(); c++)
            cout << m(r, c) << " ";
        cout << "\n";
    }*/
    
    vector<string> vstr;
    vstr.push_back("hello");
    vstr.push_back("international");
    vstr.push_back("abraabra");
    vstr.push_back("zero");

    StringCompare scomp;

    Sort(vstr, scomp);
    for (int i = 0; i < vstr.size(); i++)
        cout << vstr[i] << "\n";
}
