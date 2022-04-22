#include <vector>
#include <list>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <map>
#include <numeric>

void read_from_file(std::vector<double>& vd, std::string file){
    std::ifstream ifs(file);

    for(double d; ifs >> d;)
        vd.push_back(d);
}

class Less_than{
    double v;
public:
    Less_than(double d) : v{d} {}

    bool operator()(double val){return val < v;}
};

template<typename T>
void v_print(const std::vector<T>& vec){
    for(double val : vec)
        std::cout << val << '\n';
    std::cout << '\n';
}

int main(){

    //1.
    std::vector<double> vd;

    read_from_file(vd, "data2.txt");

    //2.
    std::cout << "VD vector elements:\n";
    v_print(vd);

    //3.
    std::vector<int> vi(vd.size());
    std::copy(vd.begin(), vd.end(), vi.begin());

    //4.
    std::cout << "\nVD+VI vector elements:\n";
    for (int i = 0; i < vd.size(); ++i)
        std::cout << vd[i] << '\t' << vi[i] << '\n';

    //5.
    double vd_sum = 0;
    for(double d : vd)
        vd_sum += d;

    std::cout << "\nSum of vd: " << vd_sum << '\n';

    //6.
    double vi_sum = 0;
    for(double d : vi)
        vi_sum += d;

    std::cout << "\nDifference of vd and vi is: " << std::abs(vi_sum-vd_sum) << '\n';
    
    //7.
    std::reverse(vd.begin(), vd.end());
    std::cout << "VD vector elements:\n";
    v_print(vd);

    //8.
    double vd_mean = vd_sum / vd.size();
    std::cout << "The mean of vd is: " << vd_mean << '\n';

    //9.
    std::vector<double> vd2(vd.size());
    std::copy_if(vd.begin(), vd.end(), vd2.begin(), Less_than(vd_mean));
    std::cout << "VD2 vector elements:\n";
    v_print(vd2);

    //10.
    std::sort(vd.begin(), vd.end());
    std::cout << "VD vector elements:\n";
    v_print(vd);

    return 0;
}