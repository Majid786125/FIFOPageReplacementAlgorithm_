#include <iostream>
using namespace std;
void Print(int PL[],int FL[],int Fsize,int Psize)
{
    cout<<endl;
    cout<<"Current Frame is : ";
    for(int i=0;i<Fsize;i++)
    {
        cout<<FL[i];
        cout<<" ";
    }
    cout<<endl;
}
bool same(int P[],int size,int V)
{
    bool flag= false;
    for (int i = 0; i < size; ++i) {
        if(P[i]==V)
        {
            flag=true;
        }
    }
    return flag;
}

int Fault(int NP, int F)
{
    int count=0;
    int p;
    int PL[NP];
    int FL[F];
    int TFault=0;
    for(int i=0;i<NP;i++) {
        cout << "Enter Page Number : ";
        cin >> p;
        if (!same(FL, F, p)) {
            if (count < F) {
                FL[count] = p;
                count++;
                TFault++;
            } else {
                count = 0;
                FL[count] = p;
                count++;
                TFault++;

            }
        }
    }
    Print(PL,FL,F,NP);
    return TFault;
}


int main() {
    int NP,F;
    cout<<"Enter Number Of Pages : ";
    cin>>NP;
    cout<<"Enter Number of Frames : ";
    cin>>F;
    int TF= Fault(NP, F);
    cout<<"Total Numbe of Fault Pages : "<<TF;
    return 0;
}