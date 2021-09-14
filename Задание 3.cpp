#include <iostream>
using namespace std;

class FooString {
private:
    int val;
    char* buf;
    string s1;
public:
    FooString(char* tbuf) {
        int i = 0;
        while (tbuf[i] != 0)
            i++;
        val = i;
        buf = new char[val];
        buf = tbuf;
    };
    ~FooString() {
    };
    void add(FooString& str) {
        int valCopy = getVal() + str.getVal();
        char* bufCopy = new char[valCopy];
        for (int i = 0; i < getVal(); i++) { 
            bufCopy[i] = outputMasI(i);
        }
        for (int i = getVal(); i <= valCopy; i++) { 
            bufCopy[i] = str.outputMasI(i - getVal());
        }
        val = valCopy;
        buf = new char[val];
        buf = bufCopy;
    }
    void show() {
        for (int i = 0; i < val; i++)
            cout << buf[i];
        cout << endl;
    }
    int outputMasI(int i) {
        if ((i >= 0) && (i <= val)) {
            return buf[i];
        }
    }
    void setVal(int newVal) {
        val = newVal;
    }
    int getVal() {
        return val;
    }
};
int test(char* a, char* b, char* otvet) {
    bool exit = true;
    FooString sl(a);
    FooString slNew(b);
    sl.add(slNew);
    FooString t1(otvet);
    for (int i = 0; i <= t1.getVal(); i++) {
        if (sl.outputMasI(i) != t1.outputMasI(i))
            return -1;
    }
    return 0;
}
int main() {
    char test1_a[50] = "a";
    char test1_b[50] = "a";
    char test1_otvet[50] = "aa";
    if (test(test1_a, test1_b, test1_otvet) == 0) {
        cout << "TEST 1 COMPLETE" << endl;
    }
    else {
        cout << "TEST 1 FAIL" << endl;
    }
    char test2_a[50] = "abba";
    char test2_b[50] = "bom";
    char test2_otvet[50] = "abbabom";
    if (test(test2_a, test2_b, test2_otvet) == 0) {
        cout << "TEST 2 COMPLETE" << endl;
    }
    else {
        cout << "TEST 2 FAIL" << endl;
    }
    char test3_a[50] = "awrgst";
    char test3_b[50] = "awrgst";
    char test3_otvet[50] = "awrgstawrgst";
    if (test(test3_a, test3_b, test3_otvet) == 0) {
        cout << "TEST 3 COMPLETE" << endl;
    }
    else {
        cout << "TEST 3 FAIL" << endl;
    }
    char test4_a[50] = "qwerty";
    char test4_b[50] = "a";
    char test4_otvet[50] = "qwerty";
    if (test(test4_a, test4_b, test4_otvet) == -1) {
        cout << "TEST 4 COMPLETE" << endl;
    }
    else {
        cout << "TEST 4 FAIL" << endl;
    }
    char test5_a[50] = "a";
    char test5_b[50] = "qwerty";
    char test5_otvet[50] = "qwerty";
    if (test(test5_a, test5_b, test5_otvet) == -1) {
        cout << "TEST 5 COMPLETE" << endl;
    }
    else {
        cout << "TEST 5 FAIL" << endl;
    }
    return 0;
}