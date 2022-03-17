#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

string path = "data.txt";

int N = 0;
int count_line;
struct teacher
{
    int department;
    string fio[3];
    int status;
};

int string_to_int(string str)
{
    int result;
    istringstream iss(str, istringstream::in);
    iss >> result;
    return result;
}

void Input_file(teacher*& massive)
{
    fstream datainput;
    datainput.open(path, ios::out);
    for (int i = 0; i < N; i++)
    {
        datainput << massive[i].department << endl << massive[i].fio[0] << endl << massive[i].fio[1] << endl << massive[i].fio[2] << endl << massive[i].status << endl;
    }
    datainput.close();
}
void load_from_file(teacher*& massive)
{
    int index = 0;
    fstream datainput;
    datainput.open(path, ios::in);
    for (int j = 0; j < count_line - 1;)
    {
        j = j + 5;
        for (int i = 0; i < 5; i++)
        {
            switch (i)
            {
            case 0:
            {
                string line;
                getline(datainput, line);
                massive[index].department = string_to_int(line);
                break;
            }
            case 1:
            {
                string line;
                getline(datainput, line);
                massive[index].fio[0] = line;
                break;
            }
            case 2:
            {
                string line;
                getline(datainput, line);
                massive[index].fio[1] = line;
                break;
            }
            case 3:
            {
                string line;
                getline(datainput, line);
                massive[index].fio[2] = line;
                break;
            }
            case 4:
            {
                string line;
                getline(datainput, line);
                massive[index].status = string_to_int(line);
                break;
            }
            }
        }
        index++;
    }
    datainput.close();
}

void Value_N(int& N) {
    fstream read;
    read.open(path, ios::in);
    int count = 1;
    string per;
    while (read.peek() != EOF) {
        getline(read, per);
        ++count;
        if (count % 5 == 0)
        {
            ++N;
        }
    }
    count_line = count;
}

void add(teacher*& massive, int& N)
{
    cout << "Pleace input departament" << endl;
    cin >> massive[N].department;
    cout << "Pleace input fio" << endl;
    cin >> massive[N].fio[0] >> massive[N].fio[1] >> massive[N].fio[2];
    cout << "Pleace input status" << endl;
    cin >> massive[N].status;
    N++;
}

void Print(teacher*& massive, int& N)
{
    for (int i = 0; i < N; i++)
    {
        cout << "Departament" << " " << massive[i].department << endl;
        cout << "Fio" << " " << massive[i].fio[0] << " " << massive[i].fio[1] << " " << massive[i].fio[2] << endl;
        cout << "Status" << " " << massive[i].status << endl;
        cout << "######################################" << endl;
    }
}

void find_teacher(teacher*& massive, int& N)
{
    cout << "Please input fio" << endl;
    string name_f;
    string sureaname_f;
    string otch_f;
    cin >> name_f >> sureaname_f >> otch_f;
    for (int i = 0; i < N; i++)
    {
        if (name_f == massive[i].fio[0])
        {
            if (sureaname_f == massive[i].fio[1])
            {
                if (otch_f == massive[i].fio[2])
                {
                    cout << "This teacher has found !" << endl;
                    cout << "Name :" << massive[i].fio[0] << endl;
                    cout << "Surename :" << massive[i].fio[1] << endl;
                    cout << "Otchestvo :" << massive[i].fio[2] << endl;
                    cout << "Department :" << massive[i].department << endl;
                    cout << "Status :" << massive[i].status << endl;


                }

            }

        }
        else
        {
            cout << "Teacher has not found" << endl;
            system("pause");
            system("cls");
        }

    }
    system("pause");
    system("cls");

}

void fillter_find(teacher*& massive, int& N)
{
    cout << "Input number status" << endl;
    int number;
    cin >> number;
    int val = 0;
    for (int i = 0; i < N; i++)
    {
        if (massive[i].status == number)
        {
            cout << "This teacher has found !" << endl;
            cout << "Name :" << massive[i].fio[0] << endl;
            cout << "Surename :" << massive[i].fio[1] << endl;
            cout << "Otchestvo :" << massive[i].fio[2] << endl;
            cout << "Department :" << massive[i].department << endl;
            cout << "Status :" << massive[i].status << endl;
            cout << "##################################" << endl;
            val++;
        }
        else
        {
            if (val == 0)
            {
                cout << "This status empty" << endl;
            }


        }

    }
    system("pause");
    system("cls");

}

void sorty(teacher*& massive, int& N, teacher& temp, teacher*& massive_temp)
{
    for (int i = 0; i < N; i++)
    {
        massive_temp[i].fio[0] = massive[i].fio[0];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            if (massive_temp[i].fio[0] < massive_temp[j].fio[0])
            {
                temp.fio[0] = massive_temp[i].fio[0];
                massive_temp[i].fio[0] = massive_temp[j].fio[0];
                massive_temp[j].fio[0] = temp.fio[0];

            }

        }

    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (massive_temp[i].fio[0] == massive[j].fio[0])
            {
                massive_temp[i].department = massive[j].department;
                massive_temp[i].status = massive[j].status;
                massive_temp[i].fio[1] = massive[j].fio[1];
                massive_temp[i].fio[2] = massive[j].fio[2];
            }
        }

    }
    cout << "Sort" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Departament" << " " << massive_temp[i].department << endl;
        cout << "Fio" << " " << massive_temp[i].fio[0] << " " << massive_temp[i].fio[1] << " " << massive_temp[i].fio[2] << endl;
        cout << "Status" << " " << massive_temp[i].status << endl;
        cout << "######################################" << endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    Value_N(N);
    teacher* massive = new teacher[1000000];
    teacher* massive_temp = new teacher[1000000];
    teacher temp;
    int solution = 999999;
    load_from_file(massive);
    while (solution != 10)
    {
        cout << "1--Add new information about teacher" << endl;
        cout << "2--Print informaiton about teacher" << endl;
        cout << "3--Find  teacher by fio" << endl;
        cout << "4--Find teacher(s) by status" << endl;
        cout << "5-- Filter teachers" << endl;
        cout << "6--Exit" << endl;
        cout << "Please input your solution" << endl;
        cin >> solution;
        switch (solution)
        {
        case 1:
        {
            add(massive, N);
            cout << "Complete" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            Print(massive, N);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            find_teacher(massive, N);
            break;

        }
        case 4:
        {
            fillter_find(massive, N);

            break;
        }
        case 5:
        {
            sorty(massive, N, temp, massive_temp);
        }
        case 6:
        {
            Input_file(massive);
            return 0;
        }
        }

    }
    return 0;
}