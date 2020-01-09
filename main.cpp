#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;

bool readWeightMatrix(vector<vector<double>> &); //функция считывания матрицы весов из файла
bool matrixProd(const vector<vector<double>> &, const vector<double> &, vector<double> &); //функция вычисления произведения марицы на вектор (реализация изменения x в этой функции)

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<vector<double>> w; //w - матрица весов

    vector<double> x = {1, -1, -1, -1}; //вектор координат
    vector<double> p;

    double k = 0.05; //шаг

    if(!readWeightMatrix(w))
    {
        cout << "Error";
        return -1;
    }

    matrixProd(w, x, p);

    /*vector<int> wtemp = {0, 1, 2, 3, 4, 5};
    int arraytemp[6] = {0, 1, 2, 3, 4, 5};
    int  *c = arraytemp + 1 * 2;


    vector<int>::iterator i = wtemp.begin() + 1 * 2;

    cout << *c << endl;
    cout << *i << endl;*/





    system("pause");
    return 0;
}

//считывание матрицы весов из файла

bool readWeightMatrix(vector<vector<double>> &fw)
{
    ifstream in("D:\\University\\DW\\DW\\debug\\weights.csv");

    if(in)
    {
        cout << "Open file: success" << endl << endl;

        string line, field;
        vector<double> v; //вектор для одной считанной строки

        while (getline(in, line))
        {
            v.clear();
            stringstream ss(line);

            while (getline(ss, field, ';'))  //разбить считанную строку по ;
                v.push_back(stod(field));

            fw.push_back(v); //добавление вектора считанной строки в матрицу весов
        }

        //вывод считанной матрицы весов
        for (size_t i = 0; i < fw.size(); ++i)
        {
            for (size_t j = 0; j < fw[i].size(); j++)
                cout << fw[i][j] << " ";
            cout << "\n";
        }

        in.close();
        return true;
    } else
    {
        cout << "Open file: error!" << endl;
        return false;
    }
}

bool matrixProd(const vector<vector<double>> &fw, const vector<double> &fx, vector<double> &fp){
    vector<double> px;
    for (size_t j = 0; j < fw[0].size(); j++)
    {
        cout << j << endl;
        px.push_back(0);
        for (size_t k = 0; k < fx.size(); k++)
            px[j] += fx[k] * fw[k][j];

     }

    //вывод вектора px

    for (size_t j = 0; j < fp.size(); j++)
        cout << px[j] << " ";
}


