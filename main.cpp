#include <iostream>
#include "base64.h"
#include <fstream>

int main() {
    using namespace std;
    string line;
    string test_input;
    std::vector<BYTE> myData;

    ifstream instream("../flag.jpeg", ios::in | ios::binary);
    ofstream outstream("../encoded_result.jpeg");

    if (instream.is_open()) {
        while (getline(instream, line)) {
            test_input += line;
            test_input += '\n';
            for (auto c : line) {
                myData.push_back(c);
            }
            myData.push_back('\n');
        }
    } else {
        cout << "File not opened\n";
    }

    std::string encodedData = base64_encode(&myData[0], myData.size());
    outstream << encodedData;
    outstream.close();
    instream.close();

    ifstream iinstream("../encoded_result.jpeg", ios::in | ios::binary);
    ofstream ooutstream("../result.jpeg");

    std::string temp_decodedString;
    if (iinstream.is_open()) {
        while (getline(iinstream, line)) {
            temp_decodedString += line;
        }
    } else {
        cout << "File not opened\n";
    }

    std::vector<BYTE> decodedData = base64_decode(temp_decodedString);

    std::string decodedString;
    for (auto c : decodedData) {
        decodedString += c;
    }

    ooutstream << decodedString;

//    ofstream test_input01("FILE_1.txt");
//    ofstream test_input02("FILE_2.txt");

//    for (auto s : decodedString){
//        test_input01 << "0X" << std::hex << std::setfill('0') << std::setw(2) << s << " " ;
//    }
//    for (auto s : test_input){
//        test_input02 << "0X" << std::hex << std::setfill('0') << std::setw(2) << s << " " ;
//    }
//    test_input01.close();
//    test_input02.close();


//    instream.close();
//    outstream.close();

    if (decodedString.size() != test_input.size()) {
        cout << "Size mismatch" << endl;
    }

    if(decodedString.compare(test_input)){
        cout << "There is a difference between them";
    }else{
        cout << "There is NO difference between them";
    }


    return 0;
}
