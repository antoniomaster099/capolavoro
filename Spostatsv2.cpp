
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
class canzoni {
private:
    int ncantanti;
    int nascoltati;
public:
    canzoni(){}

void carica(vector <canzoni>& c){
        int settimane;
        cout << "Su quante settimane vuoi lavorare? ";
        cin >> settimane;
        c.resize(settimane);
        
        for(int i = 0; i < c.size(); i++){
            cout << "metti il " << i + 1 << " numero di cantanti e poi degli ascolti fatti: ";
            cin >> c[i].ncantanti >> c[i].nascoltati;
        }
        
        
        salvaDatiGrezzi(c);
    }

  
    void salvaDatiGrezzi(vector <canzoni>& c){
        ofstream scrivi("musica.txt"); 
        for(int i = 0; i < c.size(); i++){
            scrivi << c[i].ncantanti << " " << c[i].nascoltati << "\n";
        }
        scrivi.close();
    }

   
    void leggiDaFile(vector <canzoni>& c){
        ifstream leggi("musica.txt");
        if(!leggi) {
            cout << "[Avviso] File musica.txt non trovato. Verrà considerato come vuoto.\n";
            return;
        }
        canzoni temp;
       
        while(leggi >> temp.ncantanti >> temp.nascoltati){
            c.push_back(temp);
        }
        leggi.close();
    }
   

friend int totalcantanti(vector <canzoni>& c);
friend int totalascolti(vector <canzoni>& c);
friend float mediacantanti(vector <canzoni>& c);
friend float mediaascolti(vector <canzoni>& c);
friend void nuovaset(vector <canzoni>& c);
};
void casi(int s,float m, float min, float tc, float ta,vector <canzoni>& cv);
void salva(vector <canzoni>& c, float m, float min, float tc, float ta);
void visualizza(vector <canzoni>& c, float m, float min, float tc, float ta);



int main(){
    float m,min,tc,ta;
    vector <canzoni> cv;
    canzoni c;
    int s;
    cout<<" \n PROGRAMMA FATTO DA ANTONIO SALDUCCO \n in questo programma si vuole calcolare la media dei cantanti, la media degli ascolti, il totale dei cantanti e  degli ascolti in un certo numero di settimane \n";
    cout<<" se vuoi caricare una settimana nuova ( consigliato se si hanno gia i dati ) premi 1, altrimenti premi 0( consigliato se è la prima volta ) \n";
    cin>>s;
    if(s==1){
        nuovaset(cv);
    }
    else if(s==0){
    c.carica(cv);
    }
    cout<<" cosa vuoi vedere? \n 1) media dei cantanti \n 2) media degli ascolti \n 3) totale dei cantanti \n 4) totale degli ascolti\n 5) visualizza \n 0) tutto \n";
    cin>>s;
    casi(s,m,min,tc,ta,cv);
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
    float media=contac/c.size();
    return media;
}

float mediaascolti(vector <canzoni>& c){
    int contam=totalascolti(c);
    float media=contam/c.size();
    return media;
}

void salva(vector <canzoni>& c, float m, float min, float tc, float ta){
    ofstream salva;
    salva.open("musica.txt",ios::app); 
    salva<<" la media dei cantanti è "<<m<<" \n"<<" la media degli ascolti è "<<min<<" \n"<<" il totale dei cantanti è "<<tc<<" \n"<<" il totale degli ascolti è "<<ta<<" \n";
    salva.close();
    
}

void visualizza(vector <canzoni>& c, float m, float min, float tc, float ta){
    ifstream leggi("musica.txt"); 
    if(!leggi) return;
    string line;
    cout << "\n--- CONTENUTO FILE REPORT ---\n";
    while(getline(leggi, line)){
        cout << line << "\n"; 
    }
    leggi.close();
}
void nuovaset(vector <canzoni>& c){
    canzoni gestore;
  
    gestore.leggiDaFile(c);
    cout << "Dati storici caricati dal file. Settimane precedenti trovate: " << c.size() << "\n";

    int nc, na;
    cout << "inserisci il numero di cantanti e di ascolti della nuova settimana: ";
    cin >> nc >> na;
    
    canzoni nuova;
    nuova.ncantanti = nc;
    nuova.nascoltati = na;
    
c.push_back(nuova);
    
    gestore.salvaDatiGrezzi(c);
}
void casi(int s,float m, float min, float tc, float ta,vector <canzoni>& cv){
    
    switch(s){
        case 1:
            m=mediacantanti(cv);
            cout<<" la media dei cantanti è "<<m<<" \n";
            break;
        case 2:
            min=mediaascolti(cv);
            cout<<" la media degli ascolti è "<<min<<" \n";
            break;
        case 3:
            tc=totalcantanti(cv);
            cout<<" il totale dei cantanti è "<<tc<<" \n";
            break;
        case 4:
            ta=totalascolti(cv);
            cout<<" il totale degli ascolti è "<<ta<<" \n";
            break;
        case 0:
    m=mediacantanti(cv);
    min=mediaascolti(cv);
    tc=totalcantanti(cv);
    ta=totalascolti(cv);
    salva(cv,m,min,tc,ta);
    visualizza(cv,m,min,tc,ta);
    break;
    }
    

}
