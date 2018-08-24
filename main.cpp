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
    //�ŧi�@�ӯB�I�ư}�C�H�x�s�����M�зǮt
    //You can change the filename to open the specific data
    string filename="Problem1_TestData.csv";

    ifile.open(filename);

    if (ifile)
    {

        int c = 0;
        while (getline (ifile,str)){
            stringstream ss(str);
            string temp;
            // ss �� �C�@�����ন��y
            int sum=0;
            for(int i=0;i<11;i++){
                getline(ss,temp,',');
                //atoi is used to transform string to int
                data[c][i]=atoi(temp.c_str());
                    cout<<temp<<"\t";
                    sum+=data[c][i];
                //sum�x�s�ӦC�C�@��ۥ[����
                }
            double avg=sum/11.0;
            cout<<avg<<"\t";
                avsd[c][0]=avg;
                //avg�������A�B�Navsd�}�C�Ĥ@��@���������x�s����m


                double Sq=0;
                for(int i=0;i<11;i++){
                    double q=pow((data[c][i]-avg),2);
                    Sq+=q;
            }
                double Sd=sqrt(Sq/11);
                avsd[c][1]=Sd;
               cout<<Sd<<"\t";
                  //Sq��sum of square�Aq���Ȧs�C�@�業�誺�ȡASd���зǮt
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

