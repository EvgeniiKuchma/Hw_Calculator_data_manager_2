#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <utility>
#include "Calculator.h"
#include "Data_manager.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    //Calculator<int, double> val(4, 0.25);
    //std::cout << "Result Sum = " << val.getSum() << "\n";
    //std::cout << "================\n";
    //std::cout << "Result Div = " << val.getDiv() << "\n";
    //std::cout << "================\n";
    //std::cout << "Result Sub = " << val.getSub() << "\n";
    //std::cout << "================\n";
    //std::cout << "Result Mul = " << val.getMul() << "\n";

    Data_manager < std::string> r;
    r.setInsert(1, "array");
    r.setInsert(2, "variable");
    r.setInsert(3, "zara");
    r.setInsert(4, "barret");
    r.setInsert(2, "CarrOt");
    r.setShowData();
    std::cout << "==========\n";
    r.setDelete(2);
    r.setDelete(7);
    std::cout << "==========\n";
    r.setShowData();
    std::cout << "==========\n";
    r.setModif(1, "true");
    r.setModif(7, "true");
    std::cout << "==========\n";
    r.setShowData();
    std::cout << "==========\n";
    r.setFind(1);
    std::cout << "==========\n";
    r.setFind(7);
    std::cout << "==========\n";
    std::cout << r.getDataOutput(1) << '\n';
    std::cout << r.getDataOutput(3) << '\n';
    std::cout << r.getDataOutput(4) << '\n';
    std::cout << "==========\n";
    std::cout << r.getDataOutput(2) << '\n';
    std::cout << "==========\n";
    std::cout << r.mostPopularKeyToFind();
    return 0;
}