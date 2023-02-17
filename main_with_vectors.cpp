// Ivesties tikrinimas:
// https://www.itcodar.com/c-plus-1/how-to-do-input-validation-in-c-with-cin.html

#include "Mylib.h"

struct studentas {
  string vardas, pavarde;
  vector<int> paz;
  int egz;
};

int random_to_int(int to) {
  return rand() % to + 1;
}

double rask_studento_galutini_vid(vector<int> paz, int egz) {
  double vidurkis = accumulate(paz.begin(), paz.end(), 0);
  vidurkis /= paz.size();
  return (0.4 * vidurkis) + (0.6 * egz);
}

double rask_studento_galutine_med(vector<int> paz, int egz) {
  double galutinis;
  sort(paz.begin(), paz.end());

  if (paz.size() % 2 == 0) {
    // Lyginio sk mediana
    galutinis = (1.0 * paz[paz.size() / 2] + paz[(paz.size() / 2) - 1]);
  } else {
    // Nelyginio sk mediana
    galutinis = paz[(paz.size() - 1) / 2];
  }
  return (0.4 * galutinis) + (0.6 * egz);
}

int duok_man_int(int from, int to) {
  int ats;
  while (true) {
    if (cin >> ats) {
      if (ats >= from && ats < to) {
        return ats;
      }
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
    } else {
      cout << "Iveskite skaičių nuo ";
      cout << from << " iki " << to << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
}

char duok_man_char(char a = '`', char b = '`') {
  char ats;
  while (true) {
    if (cin >> ats) {
      if ((ats == a || ats == b) && (ats != '`')) {
        return ats;
      }
      cout << "Ivestis turi būti " << a << " arba " << b << endl;
    } else {
      cout << "Ivestis turi būti " << a << " arba " << b << endl;
      cin.clear();
      cin.ignore(50, '\n');
    }
  }
  return ats;
}

studentas pildik(int kiek_nd) {
  studentas temp;
  // Vardas, Pavarde -----------------------------------------
  cout << "Iveskite vardą ir pavardę." << endl;
  cin >> temp.vardas >> temp.pavarde;

  // Namu darbu vertinimai------------------------------------ !!!!!!
  cout << "Iveskite " << kiek_nd << " pažymius." << endl;
  if (kiek_nd > 1) {
    int sk = 0, iv;
    while (sk < kiek_nd && cin >> iv) {
      sk++;
      temp.paz.push_back(iv);
      if (temp.paz[sk - 1] < 0 || temp.paz[sk - 1] > 10) {
        sk--;
        temp.paz.pop_back();
        cout << " Netaisyklinga ivestis int[0, 10]: " << endl;
      }
    }
    cin.clear();
    cin.ignore(100, '\n');

    if (sk < kiek_nd - 1) {
      for (int j = sk; j < kiek_nd; j++)
        temp.paz[j] = 0;
    }
  } else if (kiek_nd == 1) {
    temp.paz.push_back(duok_man_int(0, 10));
  }

  // Egzamino vertinimai----------------------------------------
  cout << "Iveskite egzamino rezultatą." << endl;
  temp.egz = duok_man_int(0, 10);
  return temp;
}

studentas pildik_atsitiktinai(int kiek_nd) {
  studentas temp;
  // Vardas, Pavarde -----------------------------------------
  temp.vardas = "Vardas";
  temp.pavarde = "Pavarde";

  // Namu darbu vertinimai------------------------------------
  for (int i = 0; i < kiek_nd; i++)
    temp.paz.push_back(random_to_int(10));

  // Egzamino vertinimai--------------------------------------
  temp.egz = random_to_int(10);
  return temp;
}

void spausd_v0_1(vector<studentas> st) {
  cout << " | Jei norite matyti" << endl;
  cout << "vidurkius, iveskite v" << endl;
  cout << "medianas, iveskite m" << endl;
  char pasirinkimas = duok_man_char('v', 'm');

  cout << endl << "Pavardė" << setw(10) << "Vardas";
  if (pasirinkimas == 'v') {
    cout << setw(20) << "Galutinis(Vid.)" << endl;
  } else {
    cout << setw(20) << "Galutinis(Med.)" << endl;
  }

  cout << "--------------------------------------" << endl;
  // Skaičiuojama studentu info
  double galutinis;

  // Eiti per visus studentus:
  for (int nr = 0; nr < st.size(); nr++) {

    // Susirandu Galutini vidurki rez: (jei pasi == 'v')
    if (pasirinkimas == 'v') {
      galutinis = rask_studento_galutini_vid(st[nr].paz, st[nr].egz);
    }
    else {
      galutinis = rask_studento_galutine_med(st[nr].paz, st[nr].egz);
    }

    cout << st[nr].pavarde << setw(10) << st[nr].vardas;
    cout << setw(18) << setprecision(3) << galutinis << endl;
  }
}

void spausdink_stud(vector<studentas> st) {
  for (int i = 0; i < st.size(); i++) {
    cout << st[i].vardas << " " << st[i].pavarde << " ";
    for (int p = 0; p < st[i].paz.size(); p++) {
      cout << st[i].paz[p] << " ";
    }
    cout << ": " << st[i].egz << endl;
  }
}

int main() {

  int kiek_studentu = 1;
  vector<studentas> st;

  cout << "Iveskite studento namų darbų skaičių: ";
  int kiek_nd = duok_man_int(1, 20);
  cout << endl;

  cout << "Ar norite vesti pažimius atsitiktinai?" << endl;
  cout << "Jei taip, iveskite t" << endl;
  cout << "Jei ne, iveskite n" << endl;
  bool atsitiktinai = false;
  if (duok_man_char('t', 'n') == 't') {
    atsitiktinai = true;
  }

  do {
    if (atsitiktinai) {
      st.push_back(pildik_atsitiktinai(kiek_nd));
    } else {
      st.push_back(pildik(kiek_nd));
    }

    cout << " | Irašyti dar vieną studentą, iveskite a" << endl;
    cout << "Baigti studentų irašymą, iveskite n" << endl;

  } while (duok_man_char('a', 'n') == 'a');

  // spausdink_stud(st);

  spausd_v0_1(st);
}
