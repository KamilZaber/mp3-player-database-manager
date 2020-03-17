#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
struct przedmiot{
    string firma;
    string model;
    string pamiec;
    string cena;
    void wyswietl();
};

int zapisz[300];  
      
void przedmiot::wyswietl(){
cout<<firma;
for(int i=0;i<16-firma.size();i++)cout<<" ";
cout<<model;
for(int i=0;i<16-model.size();i++)cout<<" ";
cout<<pamiec;
for(int i=0;i<16-pamiec.size();i++)cout<<" ";
cout<<cena;
for(int i=0;i<16-cena.size();i++)cout<<" ";
cout<<endl;
}
przedmiot baza[300];
void wczytywanie(){
    string linia;
    ifstream mp3 ("mp3.txt");
    int dlugosc;
    int ilosc=0;
    while(getline(mp3,linia)) {                                   
        int licznik=0;                                          
        string zapas[4]={"","","",""};
        dlugosc=linia.size();
        for(int i=0;i<dlugosc;i++) {                                   
            if(linia[i]=='*'){                                           
                licznik++;                                               
                i++;
            }
            
            zapas[licznik]=zapas[licznik]+linia[i];
        }                                                              
        baza[ilosc].firma=zapas[0];                                   
        baza[ilosc].model=zapas[1];                                      
        baza[ilosc].pamiec=zapas[2];
        baza[ilosc].cena=zapas[3];
        ilosc++;
    }

    mp3.close();
}
void zapiszPlik() {
    fopen("mp3.txt","w");
    ofstream mp3("mp3.txt", ios_base::trunc);                                     
    for(int i=0;i<300;i++) {
        if(baza[i].firma!= "")
        mp3<<baza[i].firma<<'*'<<baza[i].model<<'*'<<baza[i].pamiec<<'*'<<baza[i].cena<<endl;                
    }
    mp3.close();
}
void edytuj(string firma,string model,string pamiec,string cena,int jaki) {
    if(firma!="nie")baza[jaki].firma=firma;
    if(model!="nie")baza[jaki].model=model;
    if(pamiec!="nie")baza[jaki].pamiec=pamiec;
    if(cena!="nie")baza[jaki].cena=cena;
}
void dodaj(string firma,string model,string pamiec,string cena) {
    int jaki;
    for(int i=0;i<300;i++){                                     
        if(baza[i].firma=="") {
            jaki=i;
            break;
        }
    }
    baza[jaki].firma=firma;                                     
    baza[jaki].model=model;
    baza[jaki].pamiec=pamiec;
    baza[jaki].cena=cena;
}
void usun(int jaki) {
    baza[jaki].firma="";
    baza[jaki].model="";
    baza[jaki].pamiec="";
    baza[jaki].cena="";
}
void wyszukaj(string text) {
    int licznik=1;
    cout<<"  Firma:          Model:          Pamiec:         Cena:"<<endl;
    for(int i=0;i<300;i++) {                                                                                    
        if(baza[i].firma==text || baza[i].model==text|| baza[i].cena==text||baza[i].pamiec==text) {    
            cout<<licznik<<".";                                                                        
            baza[i].wyswietl();                                                                        
            licznik++;
        }


    }
}
void lista(){
    int licznik=1;
    cout<<"  Modele w bazie:"<<endl<<endl;
    cout<<"  Firma:          Model:          Pamiec:         Cena:"<<endl<<endl;
    for(int i=0;i<300;i++) {
        if(baza[i].firma!="") {                                                                  
            cout<<licznik<<".";
            baza[i].wyswietl();                                                                              
            zapisz[licznik]=i;
            licznik++;
        }
    }
    cout<<endl;
}
void Akcja() {
    cout<<"--------------------------------------------------------------------------------";
    cout<<"BAZA ODTWARZACZY MP3"<<endl<<"Kamil Zaber"<<endl;
    cout<<"--------------------------------------------------------------------------------";
    cout<<endl;
    cout<<"Aby zapisac liste wpisz: zapisz"<<endl;
    cout<<"Aby dodac element wpisz: dodaj"<<endl;
    cout<<"Aby usunac element wpisz: usun"<<endl;
    cout<<"Aby wyszukac element wpisz: szukaj"<<endl;
    cout<<"Aby zedytowac element wpisz: edytuj"<<endl;
    cout<<"Aby wyczyscic okno wpisz: czysc"<<endl;
    cout<<"Aby wyjsc wpisz: exit"<<endl;
    cout<<endl;
    cout<<"--------------------------------------------------------------------------------";
}
int main()
{
    int liczba;
    bool flaga=false;
    string potwierdz;
    string text;
    string firma,model,pamiec,cena;
    
    wczytywanie();
    Akcja();                                                                                 
    lista();
    
    while(cin>>text) {
    if(text=="zapisz"){
        cout<<"Czy napewno chcesz zapisac?"<<endl<<"t-tak"<<endl<<"n-nie"<<endl;
        cin>>potwierdz;
        if(potwierdz=="t") {
            zapiszPlik();
            flaga=true;
        }
        system("cls");                                                                        
        Akcja();
        lista();
        if(flaga) {
           cout<<"Baza zostala zapisana w pliku."<<endl;
           flaga=false;
        }
    }
        else if(text=="dodaj") {
            cin.ignore();
            cout<<"Podaj nazwe firmy: ";
            getline(cin,firma);
            cout<<"Podaj model: ";
            getline(cin,model);
            cout<<"Podaj pamiec: ";
            getline(cin,pamiec);
            cout<<"Podaj cene: ";
            getline(cin,cena);
            cout<<"Czy napewno chcesz dodac nowy wpis?"<<endl<<"t-tak"<<endl<<"n-nie"<<endl;
            cin>>potwierdz;
            if(potwierdz=="t") {
                dodaj(firma,model,pamiec,cena);
                flaga=true;
            }
            system("cls");
            Akcja();
            lista();
            if(flaga){
                cout<<"Do bazy zostal dodany nowy wpis."<<endl;
                flaga=false;
            }


            }
            else if(text=="usun"){
                 cout<<"Podaj numer do usuniecia:"<<endl;
                 cin>>liczba;
                 cout<<"Czy napewno chcesz usunac wpis?"<<endl<<"t-tak"<<endl<<"n-nie"<<endl;
                 cin>>potwierdz;
                 if(potwierdz=="t") {
                 usun(zapisz[liczba]);
                 flaga=true;
                 }
                 system("cls");
                 Akcja();
                 lista();
                 if(flaga){
                    cout<<"Z bazy zostal usuniety wpis."<<endl;
                    flaga=false;
                 }
                 }
                 else  if(text=="szukaj"){
                       cin.ignore();
                       cout<<"Wpisz szukana fraze:"<<endl;
                       getline(cin,text);
                       wyszukaj(text);

                       }
                       else  if(text=="czysc"){
                            system("cls");
                            Akcja();
                            lista();
                       }
                          else if(text=="edytuj"){
                                cout<<"Podaj numer do edycji:"<<endl;
                                cin>>liczba;
                                cout<<"Jezeli nie chcesz zmieniac akutalnej pozycji wpisz: nie."<<endl;
                                cin.ignore();
                                cout<<"Podaj nazwe firmy: ";
                                getline(cin,firma);
                                cout<<"Podaj model: ";
                                getline(cin,model);
                                cout<<"Podaj pamiec: ";
                                getline(cin,pamiec);
                                cout<<"Podaj cene: ";
                                getline(cin,cena);
                                cout<<"Czy napewno chcesz zedytowac ten wpis?"<<endl<<"t-tak"<<endl<<"n-nie"<<endl;
                                cin>>potwierdz;
                                if(potwierdz=="t") {
                                edytuj(firma,model,pamiec,cena,zapisz[liczba]);
                                flaga=true;
                                }
                                 if(flaga){
                                      cout<<"Wpis zostal zedytowany."<<endl;
                                      flaga=false;
                               }
                            system("cls");
                            Akcja();
                            lista();
                          }
                                else if(text=="exit") return 0;



    }
}
