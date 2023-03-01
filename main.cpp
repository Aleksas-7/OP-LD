#include "Mylib.h"

int main() {

  int kiek_studentu = 1;

  vector<studentas> st;
  vector<studentas> *ptr;
  ptr = &st;
  
  bool nustoti = false;
  // - - - - - - - - - - - - - - - - - - - - - - - - - - - -

  cout << "Pasirinkite duomenų ivedimo būdą: " << endl;
  cout << "Jei norite suvesti failus iš duomenų failo: iveskite f" << endl;
  cout << "Jei norite patys suvesti duomenis consolėje: iveskite p" << endl;
  cout << "Jei norite sukurti atsitiktinius duomenis: iveskite a" << endl;

  char pasirinkimas = duok_man_char('f', 'p', 'a');

  if (pasirinkimas == 'f') {
    st.reserve(1000000);
    cout << "Iveskite failo pavadinima: " << endl;
    string failo_pav;
    cin >> failo_pav;

    try{
      nuskaityk(failo_pav, ptr);
      spausd_v0_2(ptr);
    }
    catch (std::exception &e){cout << "Atsitiko problema su failo nuskaitymu: " << e.what() << endl;}
    //spausdink_stud(ptr);
    
  }

  if (pasirinkimas == 'p') {
    cout << "Kiek namų darbų turės studentai: " << endl;
    int kiek_nd = duok_man_int(1, 20);

    do {
        st.push_back(pildik(kiek_nd));
        cout << " - Irašyti dar vieną studentą, iveskite a" << endl;
        cout << "Baigti studentų irašymą, iveskite n" << endl;
      } while (duok_man_char('a', 'n', '.') == 'a');

    spausd_v0_1(ptr);
  }

  if (pasirinkimas == 'a'){

    cout << "Kiek namų darbų turės studentai: " << endl;
    int kiek_nd = duok_man_int(1, 20);

    cout << "Kiek atsitiktinių studentu norite sukurti?" << endl;
    int kiek = duok_man_int(1, 10000);
    for (int i = 0 ; i < kiek ; i++){st.push_back(sukurk_atsitiktinai(kiek_nd));}
    spausd_v0_1(ptr);
  }
  st.clear();
  //spausdink_stud(ptr);
  //cout << "Ptr testing: " << (*ptr)[0].vardas;
}
