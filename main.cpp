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

bool matrixProd(const vector<vector<double>> &fw, const vector<double> &fx, vector<double> &fp)
{
    vector<double> ps;
    vector<int> p;
    vector<double> tempx = {1, -1, -1, -1};
    double k = 0.05;

    ofstream out("D:\\University\\DW\\DW\\debug\\ps.txt");

    for (double x3 = -1; x3 <= 1; x3 += k)
    {
        for (double x2 = -1; x2 <= 1; x2 += k)
        {
            out << endl;
            for (double x1 = -1; x1 <= 1 + k / 2.; x1 += k)
            {
                tempx[1] = x1;
                tempx[2] = x2;
                tempx[3] = x3;
                ps.clear();
                for (size_t j = 0; j < fw[0].size(); j++)
                {
                    ps.push_back(0);
                    for (size_t l = 0; l < tempx.size(); l++)
                        ps[j] += tempx[l] * fw[l][j];

                 }

                //вывод вектора x
                for (size_t j = 0; j < tempx.size(); j++)
                    out << tempx[j] << " ";
                out << "| ";

                //расчет вектора p
                p.clear();
                for (size_t j = 0; j < ps.size(); j++){
                    p.push_back( static_cast<int>(round(tanh(ps[j]))));
                    out << p[j] << " ";
                }

                out << endl;
            }
        }
    }
    cout << "End" << endl;
    out.close();

}


