#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
#define N  5 
  
bool pPilihL1dariL(int pilih[2*N][N], int p, int l, int l1) 
{ 
    for (int i = 0; i < N; i++) 
    {  
        if (pilih[p][i] == l1) 
            return true; 
  
        if (pilih[p][i] == l) 
           return false; 
    } 
} 
  
void stabil(int pilih[2*N][N]) 
{ 

    int pPasangan[N]; 
  

    bool lKosong[N]; 
  
    memset(pPasangan, -1, sizeof(pPasangan)); 
    memset(lKosong, false, sizeof(lKosong)); 
    int freecount = N; 
  
    while (freecount > 0) 
    { 
        int l; 
        for (l = 0; l < N; l++) 
            if (lKosong[l] == false) 
                break; 
  

        for (int i = 0; i < N && lKosong[l] == false; i++) 
        { 
            int p = pilih[l][i]; 
  

            if (pPasangan[p-N] == -1) 
            { 
                pPasangan[p-N] = l; 
                lKosong[l] = true; 
                freecount--; 
            } 
  
            else   
            { 
                int l1 = pPasangan[p-N]; 
  

                if (pPilihL1dariL(pilih, p, l, l1) == false) 
                { 
                    pPasangan[p-N] = l; 
                    lKosong[l] = true; 
                    lKosong[l1] = false; 
                } 
            } 
        } 
    }
  
  
    cout << "Cewe   Cowo" << endl;
 string namco;
 string namce;
    for (int i = 0; i < N; i++) 
 {
  if(i<N){
   if(pPasangan[i]==0)
    namco="Victor";
   if(pPasangan[i]==1)
    namco="Wyatt";
   if(pPasangan[i]==2)
    namco="Xavier";
   if(pPasangan[i]==3)
    namco="Yancey";
   if(pPasangan[i]==4)
    namco="Zeus";
   if(i==0)
    namce="Amy";
   if(i==1)
    namce="Bertha";
   if(i==2)
    namce="Clare";
   if(i==3)
    namce="Diane";
   if(i==4)
    namce="Erika";
  }

       cout << " " << namce << "\t" << namco << endl;
 }
}  
int main() 
{ 
    int pilih[2*N][N] = { {6,5,8,9,7},
        {8,6,5,7,9},
        {6,9,7,8,5},
        {5,8,7,6,9},
        {6,8,5,9,7},
        {4,0,1,3,2},
        {2,1,3,0,4},
        {1,2,3,4,0},
        {0,4,3,2,1},
        {3,1,4,2,0} 
    }; 
    stabil(pilih); 
  
    return 0; 
}