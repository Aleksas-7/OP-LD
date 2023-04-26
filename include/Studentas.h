#include <string>
#include <vector>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iomanip>


#include "../include/RandInt.h"

using std::string;
using std::vector;
using std::sort;
using std::stringstream;
using std::setw;
using std::left;



class Studentas {

private:

    std::string vardas;
    std::string pavarde;
    int egz;
    double galutinis_vid;
    double galutine_med;
    std::vector<int> paz;

public:
    Studentas(){
        vardas = "";
        pavarde = "";
        egz = 0;
        paz.resize(1);
        paz.at(0) = 0;
    }
    Studentas(std::string v, std::string p, std::vector<int> &pa, int e){
        vardas = v;
        pavarde = p;
        egz = e;
        copy(pa.begin(), pa.end(), std::back_inserter(paz));
    }

    inline std::string duok_var () const {return vardas;}
    inline std::string duok_pav () const {return pavarde;}

    inline double duok_vid() const {return galutinis_vid;}
    inline double duok_med() const {return galutine_med;}

    void rask_galutinis_vid(){
        double vidurkis = std::accumulate(paz.begin(), paz.end(), 0);
        vidurkis /= paz.size();
        galutinis_vid = (0.4 * vidurkis) + (0.6 * egz);
    }

    void rask_galutine_med(){
        double g;
        std::sort(paz.begin(), paz.end());

        if (paz.size() % 2 == 0) {
            // Lyginio sk mediana
            g = (1.0 * paz.at(paz.size() / 2) + paz.at((paz.size() / 2) - 1)) / 2.0;
        } 
        else {
            // Nelyginio sk mediana
            g = paz.at((paz.size() - 1) / 2);
        }
        galutine_med = (0.4 * g) + (0.6 * egz);
    }

    stringstream duok_info_line (){
        stringstream ss;
        ss << "\n" << left << setw(15) << duok_var() << setw(15) << duok_pav();
        for (auto &p : paz){
            ss << left << setw(5) << p;
        }
        ss << left << setw(5) << egz;
        return ss;
    }

    stringstream duok_galut_line (){
        stringstream ss;
        ss << "\n" << left << setw(15) << duok_var() << setw(15) << duok_pav();

        ss << left << setw(5) << duok_vid();
        return ss;
    }

};





