#include "Mylib.h"

studentas sukurk_atsitiktinai (int kiek_nd){
    int vard_k = 3;
    string vardai_m[3] = {"Singailas", "Odisejas", "Algintas"};
    string vardai_f[3] = {"Asta", "Alfreda", "Airine"};

    int pav_k = 3;
    string pav_m[3] = {"Alton", "Alsenas", "Jakaitis"};
    string pav_f[3] = {"Joteika", "Sousa", "Tenorio"};

    studentas temp;
    if (random_to_int(2) == 1){
        temp.vardas = vardai_m[random_to_int(vard_k)-1];
        temp.pavarde = pav_m[random_to_int(vard_k)-1];

        for (int i = 0; i < kiek_nd; i++){
            temp.paz.push_back(random_to_int(10));
        }
        temp.egz = random_to_int(10);
    }
    else{
        temp.vardas = vardai_f[random_to_int(vard_k)-1];
        temp.pavarde = pav_f[random_to_int(vard_k)-1];

        for (int i = 0; i < kiek_nd; i++){
            temp.paz.push_back(random_to_int(10));
        }
        temp.egz = random_to_int(10);
    }
    return temp;
}

studentas pildik(int kiek_nd) {
  studentas temp;
  // Vardas, Pavarde -----------------------------------------
  cout << "Iveskite vardą ir pavardę." << endl;
  cin >> temp.vardas >> temp.pavarde;

  // Namu darbu vertinimai------------------------------------
  cout << "Iveskite " << kiek_nd << " pažymius." << endl;
  if (kiek_nd > 1) {
    int sk = 0, iv;
    while (sk < kiek_nd && cin >> iv) {
      if (iv < 0 || iv > 10) {
        cout << " Netaisyklinga ivestis int[0, 10]: " << endl;
        continue;
      }
      else {
        sk++;
        temp.paz.push_back(iv);
      }
    }
    cin.clear();
    cin.ignore(100, '\n');

    if (sk < kiek_nd) {
      for (int j = sk; j < kiek_nd; j++)
        temp.paz.push_back(0);
    }
  } 
  else if (kiek_nd == 1) {
    temp.paz.push_back(duok_man_int(0, 10));
  }

  // Egzamino vertinimai----------------------------------------
  cout << "Iveskite egzamino rezultatą." << endl;
  temp.egz = duok_man_int(0, 10);
  return temp;
}

void spausdink_stud(vector<studentas> *st) {
  cout << "Pradedamas studentu israsymas i konsole: " << endl;
  for (auto &i : (*st)) {
    cout << i.vardas << " " << i.pavarde << " ";
    for (int p = 0; p < i.paz.size(); p++) {
      cout << i.paz.at(p) << " ";
    }
    cout << ": " << i.egz << endl;
  }
  cout << "Studentu israsymas yra baigtas..." << endl;
}


