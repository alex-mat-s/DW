#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //w - матрица весов
    vector< vector<double> > w;

    ifstream in("D:\\University\\DW\\DW\\debug\\weights.csv");

    if(in){
        cout << "Open file: success" << endl;

        string line, field;
        vector<double> v; //вектор для одной считанной строки

        while (getline(in, line)){
            v.clear();
            stringstream ss(line);

            while (getline(ss, field, ';'))  //разбить считанную строку по ;
                v.push_back(stod(field));

            w.push_back(v); //добавление вектора считанной строки в матрицу весов
       }

        //вывод считанной матрицы весов
        for (size_t i = 0; i < w.size(); ++i) {
            for (size_t j = 0; j < w[i].size(); j++)
                cout << w[i][j] << " ";
            cout << "\n";
       }

        in.close();
    } else {
        cout << "Open file: error!" << endl;
        return -1;
    }






    //освобождение памяти
    /*for (int i = 0; i < wrow; i++)
        delete [] w[i];*/

    system("pause");
    return 0;
}
