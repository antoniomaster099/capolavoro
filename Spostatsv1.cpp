
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
class canzoni {
private:
    int ncantanti;
    int nascoltati;
public:
    canzoni(){}

    void carica(vector <canzoni>& c){
        int settimane;
        cout<<" su quante settimane vuoi lavorare? ";
        cin>>settimane;
        c.resize(settimane);
        
        for( int i=0; i<c.size();i++){
            cout<<"metti il "<<i+1<<"  numero di cantanti e poi degli ascolti fatti ";
            cin>>c[i].ncantanti>>c[i].nascoltati;
    }
   
}
friend int totalcantanti(vector <canzoni>& c);
friend int totalascolti(vector <canzoni>& c);
friend float mediacantanti(vector <canzoni>& c);
friend float mediaascolti(vector <canzoni>& c);
};
void casi(int s,vector <canzoni>& cv);
void salva(vector <canzoni>& c, float m, float min, float tc, float ta);
void visualizza(vector <canzoni>& c, float m, float min, float tc, float ta);



int main(){
    float m,min,tc,ta;
    vector <canzoni> cv;
    canzoni c;
    int s;
    cout<<" in questo programma si vuole calcolare la media dei cantanti, la media degli ascolti, il totale dei cantanti e  degli ascolti in un certo numero di settimane \n";
    c.carica(cv);
    cout<<" cosa vuoi vedere? \n 1) media dei cantanti \n 2) media degli ascolti \n 3) totale dei cantanti \n 4) totale degli ascolti\n 0) tutto \n";
    cin>>s;
    casi(s,cv);
}



int totalcantanti(vector <canzoni>& c){
    int conta=0;
    for( int i=0; i<c.size();i++){
        conta+=c[i].ncantanti;
    }
    return conta;
}

int totalascolti(vector <canzoni>& c){
    int conta=0;
    for( int i=0; i<c.size();i++){
       conta+=c[i].nascoltati;
    }
    return conta;
}

float mediacantanti(vector <canzoni>& c){
    int contac=totalcantanti(c);
    float media=(float)contac/c.size();
    return media;
}

float mediaascolti(vector <canzoni>& c){
    int contam=totalascolti(c);
    float media=(float)contam/c.size();
    return media;
}

void salva(vector <canzoni>& c, float m, float min, float tc, float ta){
    ofstream salva;
    salva.open("musica.txt",ios::app); 
    salva<<" la media dei cantanti è "<<round(m)<<" \n"<<" la media degli ascolti è "<<round(min)<<" \n"<<" il totale dei cantanti è "<<tc<<" \n"<<" il totale degli ascolti è "<<ta<<" \n";
    salva.close();
    
}

void visualizza(vector <canzoni>& c, float m, float min, float tc, float ta){
ifstream leggi("musica.txt"); // Semplice apertura in lettura
string riga;
if (leggi.is_open()) {
while (getline(leggi, riga)) {
cout << riga << endl; // Stampa quello che c'è DAVVERO nel file
}
leggi.close();
} else {
cout << "Errore: impossibile aprire il file! \n";
}
}

void casi(int s,vector <canzoni>& cv){
    float m,min,tc,ta;
    m=mediacantanti(cv);
    min=mediaascolti(cv);
    tc=totalcantanti(cv);
    ta=totalascolti(cv);
    switch(s){
        case 1:
            cout<<" la media dei cantanti è "<<round(m)<<" \n";
           break;
        case 2:
            cout<<" la media degli ascolti è "<<round(min)<<" \n";
            break;
        case 3:
            
            cout<<" il totale dei cantanti è "<<tc<<" \n";
            break;
        case 4:
    
            cout<<" il totale degli ascolti è "<<ta<<" \n";
            break;
        case 0:
    visualizza(cv,m,min,tc,ta);
    break;
}
salva(cv,m,min,tc,ta);
    

}
