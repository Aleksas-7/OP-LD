#include "Mylib.h"

bool compareByGalutinis(const studentas &a, const studentas &b)
{
    return a.galutinis < b.galutinis;
}

int main() {
  
  vector<studentas> st;
  char pasirinkimas;

  std::vector<studentas> v;
  std::cout << v.max_size();

  do {

    cout << "\nJei norite: " << endl;
    cout << "  suvesti studentus iš duomenų failo: iveskite f" << endl;
    cout << "  išvesti studentus i out.txt faila: iveskite i" << endl;
    cout << "  patys suvesti studentus consolėje: iveskite k" << endl;
    cout << "  sukurti atsitiktini studentu kieki: iveskite a" << endl;

    cout << "Versijos v0_4 func: " << endl;
    cout << "  sukurti atsitiktinių studentų failą, iveskite s" << endl;
    cout << "  padalinti studentu failą į galvočiu ir nuskriaustuku failus, iveskite p" << endl;

    cout << endl;
    cout << "  išeiti iš programos, iveskite n" << endl;

    pasirinkimas = duok_man_chara();

    if (pasirinkimas == 'f') 
    {
    cout << "Iveskite failo pavadinima: " << endl;
    string failo_pav;
    cin >> failo_pav;

    try{
      nuskaityk(st, failo_pav);

      for (auto &s : st){s.galutinis = rask_studento_galutini_vid(s.paz, s.egz);}
      sort(st.begin(), (st.end()), compareByGalutinis);

    }
    catch (std::exception &e){cout << "Atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
    }

    if (pasirinkimas == 'i')
    {
      spausd_v0_2(st);
      cout << "studentai atspausdinti i faila out.txt" << endl;
    }

    if (pasirinkimas == 'k') 
    {
    cout << "Kiek namų darbų turės studentai: " << endl;
    int kiek_nd = duok_man_int(1, 20);

    do {
      st.push_back(pildik(kiek_nd));
      cout << " - Irašyti dar vieną studentą, iveskite a" << endl;
      cout << "Baigti studentų irašymą, iveskite n" << endl;
    } while (duok_man_char('a', 'n', '.') == 'a');

    spausd_v0_1(st);
    }

    if (pasirinkimas == 'a')
    {
      cout << "Kiek namų darbų turės studentai: " << endl;
      int kiek_nd = duok_man_int(1, 20);
      
      cout << "Kiek atsitiktinių studentu norite sukurti?" << endl;
      int kiek = duok_man_int(1, 10000);
      prikurk_studentu(st, kiek, kiek_nd);
      spausd_v0_1(st);
    }
      
    if (pasirinkimas == 's')
    {
      cout << "Kiek namų darbų turės studentai: " << endl;
      int kiek_nd = duok_man_int(1, 20);

      cout << "Kiek studentu turėtu būti šiame faile?: " << endl;
      int kiek_st = duok_man_int(1, 10000000);

      auto p1 = std::chrono::high_resolution_clock::now();
      sukurk_v0_4(kiek_st, kiek_nd);
      auto p2 = std::chrono::high_resolution_clock::now();
      cout << "Failo, dydzio: " << kiek_st << " kurimas, užtruko " 
      << std::chrono::duration_cast<std::chrono::milliseconds>(p2-p1).count() << " milliseconds\n";
    }

    if (pasirinkimas == 'p')
    {
      string f_name;
      
      cout << "Iveskite studentų failo pavadinimą: " << endl;
      cin >> f_name;
      cout << "Kiek studentu šiame faile?" << endl;
      int stud_kiek = duok_man_int(1, 10000000);

      try {
        auto a1 = std::chrono::high_resolution_clock::now();

        auto t1 = std::chrono::high_resolution_clock::now();
        nuskaityk(st, f_name);
        auto t2 = std::chrono::high_resolution_clock::now();
        cout << "Failo nuskaitytas per " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
        

        for (auto &s : st){s.galutinis = rask_studento_galutini_vid(s.paz, s.egz);}

        

        auto t11 = std::chrono::high_resolution_clock::now();
        sort(st.begin(), (st.end()), compareByGalutinis);
        auto t12 = std::chrono::high_resolution_clock::now();
        cout << "Failo surikiuotas per " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(t12-t11).count() << " milliseconds\n";


        auto t21 = std::chrono::high_resolution_clock::now();
        studentu_padalinimas(st, stud_kiek);
        auto t22 = std::chrono::high_resolution_clock::now();
        cout << "Studentai padalinti per " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(t22-t21).count() << " milliseconds\n";

        auto a2 = std::chrono::high_resolution_clock::now();
        cout << "Visas studentu skirstymas užtruko " 
        << std::chrono::duration_cast<std::chrono::milliseconds>(a2-a1).count() << " milliseconds\n";

      }
      catch (std::exception &e){cout << "atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
    }

  } while (pasirinkimas != 'n');

  st.clear();
}