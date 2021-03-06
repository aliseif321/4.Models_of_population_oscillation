/************************************************************************************************/
/*** Topic: Kuramoto model with Runge-Kutta 4th Order Method for 500 nodes in fully connection***/
/***   network with cupling                                                                   ***/
/*** Version Release 17.12 rev 11256                                                Ali-Seif  ***/
/*** Date: 5/13/2021                                                                           ***/
/*** Code implemented in Microsoft Visual Studio Enterprise 2019 C++ compiler                 ***/
/*** MSI: PX60 6QD/ DDR4                                                                      ***/
/*** Run under a Intel® Core™ i7-6700HQ CPU @ 2.60GHz × 64 based processor with 16 GB RAM     ***/
/************************************************************************************************/
#include <iostream>                                                             //import library for cout and endl and etc.
#include"Kuramoto.h"                                                            //import library Kuramoto
using namespace std;                                                            //using standard 
int main() {                                                                    //
    clock_t t = clock();                                                        //time start record
    const string address_matrix = "fully50";                                    //name matrix file
    const int size_matrix = 500;                                                //number of node size of matrix clom and row
    const double dt = 0.01;                                                     //step lenth
    const double t_final = 20;                                                  //time final
    double coupling = 0;                                                        //stringh cupling
    ofstream syncrony("syncrony.txt", ios::out | ios::trunc);                   //create file .txt for save sync volt
    Kuramoto kR(size_matrix, dt, t_final, coupling, address_matrix);            //call class and input initial variable
    kR.matrix_fully();                                                          //run initial cundition
    kR.theta_rider();                                                           //read random between 0 to 2pi normal
    kR.Omega_rider();                                                           //read random between 0 to 1 ufiform
    for (kR.coupling = 0; kR.coupling < 6.1; kR.coupling += 0.1) {              //foor loop cont coupling
        kR.theta_rider();                                                       //read random between 0 to 2pi normal
        kR.Run();                                                               //run kuramato model
        syncrony << kR.coupling << "\t" << kR.syncer << endl;                   //print time and sync in .txt
        cout << kR.coupling << "\t" << kR.syncer << endl;                       //type time and sync in .txt
    }                                                                           //
    syncrony.close();                                                           //close file .txt
    cout << "\nTime taken by program is :\t" << ((double)clock() - t) / CLOCKS_PER_SEC << " sec\nfinish\n";//calculate time run
    return 0;                                                                   //run program was correct
}
