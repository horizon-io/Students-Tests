#include <iostream>
#include <numeric>
#include <cmath>
#include <sstream> // for splitting the IP to octets

using namespace std;

// START P1\ The Missing Letter
char theMissingLetter1(char letters[]) {

    char previous = letters[0];
    for (int i = 1; letters[i]; i++) {
        if (letters[i] - previous > 1) {
            return (char)(letters[i] - 1);
        }
        previous = letters[i];
    }

    throw "Not valid Input";
}

char theMissingLetter2(char input[]) {

    string letters(input);
    // because all we need is the count + 1
    int count = letters.length() + 1;

    int expectedSum = input[0] * count + ( /* The rule of summing the sequence */ (round(count)/2) * (count - 1));

    int actualSum = accumulate(letters.begin(), letters.end(), 0);

    return (char)(expectedSum - actualSum);
}
// END P1

/**********************************/

// START P2\ Create a Binary Calculator

int sumOfBinary(string first, string second) {

    // reverse both inputs
    reverse(first.begin(), first.end());
    reverse(second.begin(), second.end());

    int firstNumber = 0;
    int secondNumber = 0;

    for (int i = 0; first[i]; i++) {
        if (first[i] == '1') {
            firstNumber += pow(2, i);
        }
    }
    for (int i = 0; second[i]; i++) {
        if (second[i] == '1') {
            secondNumber += pow(2, i);
        }
    }

    return firstNumber + secondNumber;
}

// END P2

/**********************************/

// START P3\ Find Network and Broadcast of a network

 int* stringToOctetsArray(string input) {
    int octet1, octet2, octet3, octet4;
    char dotPlaceholder; // we don't want to store them

    istringstream s(input);

    // given 192.168.2.1
    s >> octet1          // 192
      >> dotPlaceholder  // .
      >> octet2          // 168
      >> dotPlaceholder  // .
      >> octet3          // 2
      >> dotPlaceholder  // .
      >> octet4;         // 1

    return new int[4] {octet4, octet3, octet2, octet1};
}

unsigned int octetArrayToNumber( int octets[]) {
    unsigned int number = 0;

    for (int i = 0; i < 4; i++) number += (octets[i] << (i * 8)); // Shift to left 0 then 8 then 16 then 24

    return number;
}

unsigned int stringIPtoNumber(string ip) {
    return octetArrayToNumber(stringToOctetsArray(ip));
}

string numberToIPString(unsigned int input) {
    string result = "";

    // reverse shift
    result += to_string ((input & 0xff000000) >> 24);
    result += ".";
    result += to_string ((input & 0x00ff0000) >> 16);
    result += ".";
    result += to_string ((input & 0x0000ff00) >> 8);
    result += ".";
    result += to_string ((input & 0x000000ff));

    return result;
}

struct IPInfo {
    string network;
    string broadcast;
};

IPInfo findIPInfo(string host, string subnet) {

    unsigned int hostAddress = stringIPtoNumber(host);
    unsigned int subnetAddress = stringIPtoNumber(subnet);

    return IPInfo
            {
                    .network = numberToIPString(hostAddress & subnetAddress),
                    .broadcast = numberToIPString(hostAddress | ~subnetAddress)
            };
}

IPInfo findIPInfo(string host, int cidr) {

    unsigned int hostAddress = stringIPtoNumber(host);
    unsigned int subnetAddress = 0xffffffff << (32 - cidr);

    return IPInfo
            {
                    .network = numberToIPString(hostAddress & subnetAddress),
                    .broadcast = numberToIPString(hostAddress | ~subnetAddress)
            };
}

// END P3

int main(int argc, const char * argv[]) {

    cout << "The Missing Letter: " << endl;

    cout << "['a','b', 'c', 'e'] -> " << theMissingLetter1(new char[4] {'a', 'b', 'c', 'e'}) << endl;
    cout << "['M', 'O', 'P', 'Q', 'R'] -> " << theMissingLetter2(new char[5] {'M', 'O', 'P', 'Q', 'R'}) << endl;


    cout << "**********************************" << endl;

    cout << "The Binary Calculator: " << endl;

    cout << " 1010 + 10 = " << sumOfBinary("1010", "10") << endl;
    cout << " 1000000 + 1000000 = " << sumOfBinary("1000000", "1000000") << endl;

    cout << "**********************************" << endl;

    cout << "The Network Address and the Subnet: " << endl;

    IPInfo info = findIPInfo("192.168.3.5", 26);
    cout << "(Host: 192.168.3.5, CIDR: 26)" << "=> (Network: " << info.network << ", Broadcast: " << info.broadcast << ")" << endl;

    info = findIPInfo("10.2.4.3", "255.255.128.0");
    cout << "(Host: 10.2.4.3, Subnet: 255.255.128.0)" << "=> (Network: " << info.network << ", Broadcast: " << info.broadcast << ")" << endl;

    return 0;
}
