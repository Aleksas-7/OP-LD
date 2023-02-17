// Ivesties tikrinimas (duok_man_int - char funkcija):
// https://www.itcodar.com/c-plus-1/how-to-do-input-validation-in-c-with-cin.html

// Rikiavimas (bubble sort):
// https://www.geeksforgeeks.org/cpp-program-for-bubble-sort/

// Jau po vectoriu darymo nebetaisiu sio failo.

#include "Mylib.h"

struct studentas {
  string vardas, pavarde;
  int *paz;
  int egz;
};

int random_to_int(int to) {
  return rand() % to + 1;
}

void bubbleSort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
      }
    }
  }
}

int duok_man_int(int from, int to) {
  int ats;
  while (true) {
    cin >> ats;
    if (cin) {
      if (ats >= from && ats <= to) {
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

double rask_studento_galutini_vid(int paz[], int n_paz, int egz, int kiek_nd) {
  double vid = 0;
  for (int x = 0; x < kiek_nd; x++) {
    vid += paz[x];
  }
  return (0.4 * (vid / kiek_nd)) + (0.6 * egz);
}

double rask_studento_galutine_med (int arr[], int n_paz, int egz, int kiek_nd){
  double vid;
  bubbleSort(arr, kiek_nd);

  if (kiek_nd % 2 == 0) {
    // Lyginio sk mediana
    int vi = kiek_nd / 2;
    vid = (1.0 * arr[vi] + arr[vi - 1]) / 2;
  } else {
    // Nelyginio sk mediana
    vid = arr[(kiek_nd - 1) / 2];
  }
  return (0.4 * vid) + (0.6 * egz);
}

void pildik(studentas &temp, int kiek_nd) {
  // Vardas, Pavarde -----------------------------------------
  cout << "Iveskite vardą ir pavardę." << endl;
  cin >> temp.vardas >> temp.pavarde;

  // Namu darbu vertinimai------------------------------------
  int mas[kiek_nd];
  cout << "Iveskite " << kiek_nd << " pažymius." << endl;

  int sk = 0;
  while (sk < kiek_nd && cin >> mas[sk]) {
    sk++;
    if (mas[sk - 1] < 0 || mas[sk - 1] > 10) {
      sk--;
      cout << " Netaisyklinga ivestis int[0, 10]: " << endl;
    }
  }
  cin.clear();
  cin.ignore(100, '\n');

  if (sk < kiek_nd - 1) {
    for (int j = sk; j < kiek_nd; j++)
      mas[j] = 0;
  }
  
  temp.paz = new int[kiek_nd];
  for (int i = 0; i < kiek_nd; i++) {
    temp.paz[i] = mas[i];
  }

  // Egzamino vertinimai----------------------------------------
  cout << "Iveskite egzamino rezultatą." << endl;
  temp.egz = duok_man_int(0, 10);
}

void pildik_atsitiktinai (studentas &temp, int kiek_nd){
  // Vardas, Pavarde -----------------------------------------
  temp.vardas = "Vardas";
  temp.pavarde = "Pavarde";

  // Namu darbu vertinimai------------------------------------
  temp.paz = new int[kiek_nd];
  for (int i = 0; i < kiek_nd; i++) {
    temp.paz[i] = random_to_int(10);
  }

  // Egzamino vertinimai----------------------------------------
  temp.egz = random_to_int(10);
  
}

void spausd_v0_1(studentas st[], int kiek_st, int kiek_nd) {
  cout << "Jei norite matyti" << endl;
  cout << "vidurkius, iveskite v" << endl;
  cout << "medianas, iveskite m" << endl;
  char pasirinkimas = duok_man_char('v', 'm');

  cout << endl << "Pavardė" << setw(10) << "Vardas";
  if (pasirinkimas == 'v') {
    cout << setw(20) << "Galutinis(vid.)" << endl;
  } else if (pasirinkimas == 'm') {
    cout << setw(20) << "Galutinis(Med.)" << endl;
  }

  cout << "--------------------------------------" << endl;
  // Skaičiuojama studentu info
  for (int i = 0; i < kiek_st; i++) {
    
    double galutinis;
    int *arr = new int[kiek_nd];
    for (int j = 0; j < kiek_nd; j++) {
      arr[j] = st[i].paz[j];
    }

    // Susirandu Galutini vidurki rez:

    if (pasirinkimas == 'v') {
      galutinis = rask_studento_galutini_vid(arr, kiek_nd, st[i].egz, kiek_nd);
    } else {
      galutinis = rask_studento_galutine_med(arr, kiek_nd, st[i].egz, kiek_nd);
    }
    delete [] arr;
    cout << st[i].pavarde << setw(10) << st[i].vardas;
    cout << setw(18) << setprecision(3) << galutinis << endl;
  }
}

int main() {

  studentas *mas;
  int kiek_studentu = 1;

  mas = new studentas[kiek_studentu];

  cout << "Iveskite studento namų darbų skaičių: ";
  int kiek_nd = duok_man_int(1, 20);

  cout << endl << "Ar norite vesti pažimius atsitiktinai?" << endl;
  cout << "Jei taip, iveskite t" << endl;
  cout << "Jei ne, iveskite n" << endl;
  bool atsitiktinai = false;
  if (duok_man_char('t', 'n') == 't') {
    atsitiktinai = true;
  }

  do {
    if (atsitiktinai) {
      pildik_atsitiktinai(mas[kiek_studentu - 1], kiek_nd);
    } else {
      pildik(mas[kiek_studentu - 1], kiek_nd);
    }

    studentas *temp = new studentas[kiek_studentu];
    copy(mas, mas + kiek_studentu, temp);
    delete[] mas;
    kiek_studentu++;
    mas = new studentas[kiek_studentu];
    copy(temp, temp + kiek_studentu - 1, mas);
    delete[] temp;
    
    cout << "Irašyti dar vieną studentą, iveskite a" << endl;
    cout << "Baigti studentų irašymą, iveskite n" << endl;

  } while (duok_man_char('a', 'n') == 'a');
  kiek_studentu--;

  spausd_v0_1(mas, kiek_studentu, kiek_nd);
  delete[] mas;
}
