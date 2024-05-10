#include <iostream>

using namespace std;

int zakonczenie, karta, dobrana, suma, sumaD, kartyD, randomowe, przegrane, wygrane, remisy, opcja1;
int tab[52]={2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11};

int Diler();

int statystyka(){
    cout<<"Twoje dotychczasowe wygrane: "<<wygrane<<". Twoje dotychczasowe przegrane: "<<przegrane<<". Remisy: "<<remisy<<".\n";
    return 0;
}

int wygrana(){
    cout<<"Brawo! Wygrales z wynikiem "<<suma<<". Wynik Dilera: "<<sumaD<<"\n";
    wygrane++;
    statystyka();
    return 0;
}

int przegrana(){
    cout<<"Przegrales! Twoj wynik to "<<suma<<". Wynik Dilera: "<<sumaD<<"\n";
    przegrane++;
    statystyka();
    return 0;
}

int remis(){
    cout<<"Remis! Twoj wynik to "<<suma<<". Wynik Dilera: "<<sumaD<<"\n";
    remisy++;
    statystyka();
    return 0;
}

int dobieranie(){
    do{
    karta=rand() % randomowe;
    dobrana=tab[karta];
    tab[karta]=0;
    suma=suma+dobrana;
    }while(dobrana==0);
    
    if(suma>=21){
        if(suma==21){
            wygrana();
            return 0;
        }
        else{
            przegrana();
            return 0;
        }
    }
    
      cout<<"Dobrana karta to "<<dobrana<<". Twoj obecny wynik: "<<suma<<". Czy chcesz dobrac kolejna karte? Tak-wpisz 1 Nie-wpisz 2: ";
      cin>>opcja1;
      if(opcja1==1){
          dobieranie();
      }
      else{
          Diler();
          return 1;
      }
}

int Diler(){
    do{
        do{
            karta=rand() % randomowe;
            dobrana=tab[karta];
            tab[karta]=0;
            sumaD=sumaD+dobrana;
        }while(dobrana==0);
    
        kartyD++;
        if(sumaD>=21){
            if(sumaD==21){
                przegrana();
                return 0;
            }
            else{
                wygrana();
                return 0;
            }
        }
    }while(kartyD<3);
    
    if(sumaD>21){
        wygrana();
        return 0;
    }
    if(suma>sumaD){
        wygrana();
        return 0;
    }
    if(suma==sumaD){
        remis();
        return 0;
    }
    else{
        przegrana();
        return 0;
    }
    
}

int main()
{
    cout<<"Gra w BlackJacka\n";
    przegrane=0;
    wygrane=0;
    remisy=0;
    randomowe=51;
    
    do{
    int tab[52]={2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11};
    karta=rand() % randomowe;
    dobrana=tab[karta];
    tab[karta]=0;
    suma=dobrana;
    sumaD=0;
    karta=0;
    
    cout<<"Dobrana karta to "<<dobrana<<". Twoj obecny wynik: "<<suma<<". Czy chcesz dobrac kolejna karte? Tak-wpisz 1 Nie-wpisz 2: ";
    cin>>opcja1;
    if(opcja1==1){
        dobieranie();
    }
    else{
        Diler();
    }
    
    cout<<"Czy chcesz grac dalej? Tak-wpisz 1 Nie-wpisz 2: ";
    cin>>zakonczenie;
    }
    while(zakonczenie==1);
}

