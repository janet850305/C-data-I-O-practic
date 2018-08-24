#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main() {

    string str;
    ifstream ifile;
        //This array is used to deposit the data importing from csv
    int data[100][11];
    double avsd[100][2];
    //宣告一個浮點數陣列以儲存平均和標準差
    //You can change the filename to open the specific data
    string filename="Problem1_TestData.csv";

    ifile.open(filename);

    if (ifile)
    {

        int c = 0;
        while (getline (ifile,str)){
            stringstream ss(str);
            string temp;
            // ss → 每一行資料轉成串流
            int sum=0;
            for(int i=0;i<11;i++){
                getline(ss,temp,',');
                //atoi is used to transform string to int
                data[c][i]=atoi(temp.c_str());
                    cout<<temp<<"\t";
                    sum+=data[c][i];
                //sum儲存該列每一欄相加的值
                }
            double avg=sum/11.0;
            cout<<avg<<"\t";
                avsd[c][0]=avg;
                //avg為平均，且將avsd陣列第一欄作為平均數儲存的位置


                double Sq=0;
                for(int i=0;i<11;i++){
                    double q=pow((data[c][i]-avg),2);
                    Sq+=q;
            }
                double Sd=sqrt(Sq/11);
                avsd[c][1]=Sd;
               cout<<Sd<<"\t";
                  //Sq為sum of square，q為暫存每一欄平方的值，Sd為標準差
                cout<<"\n";

                c++;
        }
        cout << "Finish reading data" << endl;
        //Now, you can start to use the data array to complete this problem
    }
    else
    {
        cout << "Error" <<endl;
    }


    ifile.close();

    ofstream file;

       file.open("Problem_testdatanew.csv",ios::in);

    if (file.is_open())
    {

        for(int c=0;c<100;c++){
        string str="";
            for(int i=0;i<11;i++){
            stringstream tempp;
            tempp<<data[c][i];
            str+=tempp.str()+",";
                }
            for(int k=0;k<2;k++){
                stringstream tempp;
                tempp<<avsd[c][k];
                str+=tempp.str()+",";
            }
            file<<str<<"\n";

    }


                   cout << "Finish reading data" << endl;

    }
    else
    {
        cout << "Error" <<endl;
    }
     file.close();

    return 0;
}

