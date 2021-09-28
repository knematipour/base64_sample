#include <iostream>
#include "base64.h"
#include <fstream>

int main() {
    using namespace std;
    string line;
    std::vector<BYTE> myData;

    ifstream instream("../flag.jpeg", ios::in | ios::binary);
    ofstream outstream("../result.jpeg");

    if (instream.is_open()) {
        while (getline(instream, line)) {

            for ( auto c : line){
                myData.push_back(c);
            }
            myData.push_back('\n');
        }
    } else {
        cout << "File not opened\n";
    }

    std::string encodedData = base64_encode(&myData[0], myData.size());
    std::vector<BYTE> decodedData = base64_decode(encodedData);

    std::string decodedString;
    for (auto c : decodedData){
            decodedString += c;
    }

    outstream << decodedString;

    instream.close();
    outstream.close();

    return 0;
}
