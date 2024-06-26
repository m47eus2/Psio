#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

enum class TypRosliny { Owoc, Warzywo };

struct Roslina {
    TypRosliny typ;
    std::string nazwa;
};

using Koszyk = std::vector<Roslina>;


void dodaj_rosline(Roslina roslina, Koszyk &koszyk);
bool czy_jest_gruszka(const Koszyk &koszyk);
bool czy_same_owoce(const Koszyk &koszyk);
bool czy_same_warzywa(const Koszyk &koszyk);
bool co_najmniej_jedno_warzywo(const Koszyk &koszyk);
bool co_najmniej_jeden_owoc(const Koszyk &koszyk);
bool zadnego_owocu(const Koszyk &koszyk);
bool zadnego_warzywa(const Koszyk &koszyk);
int zlicz_owoce(const Koszyk &koszyk);
int zlicz_warzywa(const Koszyk &koszyk);
void usun_zaczynajace_sie_od(Koszyk &koszyk, char litera, TypRosliny typ);

// zad 8
std::ostream& operator<<(std::ostream &out, const Roslina &roslina) 
{
    if(roslina.typ == TypRosliny::Owoc) out<<"Owoc";
    else if(roslina.typ == TypRosliny::Warzywo) out<<"Warzywo";
    out<<", ";
    out<<roslina.nazwa;
    return out;
}
// zad 8
std::ostream& operator<<(std::ostream &out, const Koszyk &koszyk) 
{
    for(auto &i : koszyk)
    {
        if(i.typ == TypRosliny::Owoc) out<<"Owoc";
        if(i.typ == TypRosliny::Warzywo) out<<"Warzywo";
        out<<", ";
        out<<i.nazwa<<endl;
    }
    return out;
}


// PROSZE NIE MODYFIKOWAC FUNKCJI MAIN
int main()
{
    Koszyk koszyk;
    Roslina r;
    int zad;
    cin >> zad;
    switch(zad) 
    {
        case 7:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            cout<<koszyk[0].nazwa<<endl;
            break;
        case 8:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Rzodkiewka";
            dodaj_rosline(r, koszyk);
            cout<<r<<endl;
            cout<<koszyk<<endl;
            break;
        case 9:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            cout<<czy_jest_gruszka(koszyk)<<endl;
            r.nazwa = "Gruszka";
            dodaj_rosline(r, koszyk);
            cout<<czy_jest_gruszka(koszyk)<<endl;
        break;
        case 10:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Banan";
            dodaj_rosline(r, koszyk);
            cout<<czy_same_owoce(koszyk)<<endl;
            cout<<czy_same_warzywa(koszyk)<<endl;
            cout<<zadnego_owocu(koszyk)<<endl;
            cout<<zadnego_warzywa(koszyk)<<endl;
            cout<<co_najmniej_jedno_warzywo(koszyk)<<endl;
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Rzodkiewka";
            dodaj_rosline(r, koszyk);
            cout<<co_najmniej_jedno_warzywo(koszyk)<<endl;
            cout<<zadnego_warzywa(koszyk)<<endl;
        break;
        case 11:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Banan";
            dodaj_rosline(r, koszyk);
            cout<<zlicz_owoce(koszyk)<<endl;
            cout<<zlicz_warzywa(koszyk)<<endl;
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Mandarynka";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Chlebowiec";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Rzodkiewka";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Marchew";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Ziemniak";
            dodaj_rosline(r, koszyk);
            cout<<zlicz_owoce(koszyk)<<endl;
            cout<<zlicz_warzywa(koszyk)<<endl;
        break;
        case 12:
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Jablko";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Banan";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Mandarynka";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Chlebowiec";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Owoc;
            r.nazwa = "Mango";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Rzodkiewka";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Marchew";
            dodaj_rosline(r, koszyk);
            r.typ = TypRosliny::Warzywo;
            r.nazwa = "Ziemniak";
            dodaj_rosline(r, koszyk);
            usun_zaczynajace_sie_od(koszyk, 'M', TypRosliny::Owoc);
            cout<<koszyk;
        break;
    }
}
// PROSZE NIE MODYFIKOWAC FUNKCJI MAIN


// zad 7
void dodaj_rosline(Roslina roslina, Koszyk &koszyk)
{
    koszyk.emplace_back(roslina);
}

// zad 9
bool czy_jest_gruszka(const Koszyk &koszyk)
{
    if(find_if(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.nazwa == "Gruszka";}) != koszyk.end())
        return true;
    else
        return false;
}

// zad 10
bool czy_same_owoce(const Koszyk &koszyk)
{
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Owoc;});
}
bool czy_same_warzywa(const Koszyk &koszyk)
{
    return all_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Warzywo;});
}
bool co_najmniej_jedno_warzywo(const Koszyk &koszyk)
{
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ ==  TypRosliny::Warzywo;});
}
bool co_najmniej_jeden_owoc(const Koszyk &koszyk)
{
    return any_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Owoc;});
}
bool zadnego_owocu(const Koszyk &koszyk)
{
    return none_of(koszyk.begin(), koszyk.end(),[](const Roslina &roslina){return roslina.typ == TypRosliny::Owoc;});
}
bool zadnego_warzywa(const Koszyk &koszyk)
{
    return none_of(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Warzywo;});
}

// zad 11
int zlicz_owoce(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Owoc;});
}
int zlicz_warzywa(const Koszyk &koszyk)
{
    return count_if(koszyk.begin(), koszyk.end(), [](const Roslina &roslina){return roslina.typ == TypRosliny::Warzywo;});
}

// zad 12
void usun_zaczynajace_sie_od(Koszyk &koszyk, char litera, TypRosliny typ)
{
    koszyk.erase(remove_if(koszyk.begin(), koszyk.end(), [litera,typ](const Roslina &roslina) {return (roslina.nazwa[0] == litera)&&(roslina.typ==typ);}),koszyk.end());
}