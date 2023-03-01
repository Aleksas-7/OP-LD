#include "Mylib.h"

void nuskaityk(string f_pav, vector<studentas> *ptr){

  std::stringstream buffer;
  ifstream fin (f_pav);
  if (!fin.is_open()){
    throw std::runtime_error("Tokio failo neradau.");
  }
  buffer << fin.rdbuf();
  fin.close();

  string line;
  int nd_sk = 0;

  getline(buffer, line);

  stringstream ss (line);
  string part;

  while (ss >> part){
    nd_sk++;
  }
  nd_sk -= 3;
  if (nd_sk == 0){
    throw std::runtime_error("Studentai irase neturi namu darbu informacijos.");
  }
  // Susiskaiciavome namu darbu sk is pirmines eil.
  studentas temp;

  while(buffer){
    if(!buffer.eof()){
      getline(buffer, line);
      // Sudalinti eile i jos komponentus:

      stringstream ss (line);
      ss >> temp.vardas;
      ss >> temp.pavarde;

      int t;
      for (int i = 0 ; i < nd_sk ; i++){
        ss >> t;
        temp.paz.push_back(t);
      }
      ss >> temp.egz;
      (*ptr).push_back(temp);
      temp.paz.clear();
      
    }
    else {break;}
    
  }
  (*ptr).pop_back();
  cout << "Studentu failas nuskaitytas" << endl;
}

void spausd_v0_2(vector<studentas> *ptr){

  quickSort(ptr, 0, (*ptr).size()-1);
  cout << "Studentai isrikiuoti" << endl;
  
  std::ostringstream ss;
  string f_name;
  

  ofstream fout("out.txt");
  
  fout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis(Vid.) / " << setw(25) << "Galutine(Med.)" << "\n";
  fout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
  string outputas;
  for (auto &st : (*ptr)){
    ss << left << setw(15) << st.vardas  << setw(15) << st.pavarde;
    ss << left << setw(20) << rask_studento_galutini_vid(st.paz, st.egz);
    ss << left << setw(20) << rask_studento_galutine_med(st.paz, st.egz);
    ss << " \n";
    outputas += ss.str();
    ss.str("");
  }
  fout << outputas;
  fout.close();
  cout << "Studentai israsyti i faila out.txt" << endl;
}
























