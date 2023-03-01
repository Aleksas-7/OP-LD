#ifndef MYLIB_H
#define MYLIB_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include <sstream>

using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::left;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;
using std::sort;
using std::accumulate;
using std::ifstream;
using std::stringstream;
using std::swap;
using std::ofstream;

struct studentas {
  string vardas, pavarde;
  vector<int> paz;
  int egz;
};

// func.cpp:
int random_to_int(int to);
double rask_studento_galutini_vid(vector<int> paz, int egz);
double rask_studento_galutine_med(vector<int> paz, int egz);
int duok_man_int(int from, int to);
char duok_man_char(char a, char b, char c);
int partition(vector<studentas> *ptr, int low, int high);
void quickSort(vector<studentas> *ptr, int low, int high);
void spausd_v0_1(vector<studentas> *st);

// failai.cpp:
void nuskaityk(string f_pav, vector<studentas> *ptr);
void spausd_v0_2(vector<studentas> *ptr);

// stud.cpp:
studentas sukurk_atsitiktinai (int kiek_nd);
studentas pildik(int kiek_nd);
void spausdink_stud(vector<studentas> *st);

#endif