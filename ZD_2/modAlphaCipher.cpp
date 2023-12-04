#include "modAlphaCipher.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

string modAlphaCipher::decrypt(const std::string& cipher_stroka)              //расшифрование
{
    string s = getValidText(cipher_stroka);
    string ocs = s;
    int dlina, kolvostrok, pozitsiya, a; 
    dlina = s.size();
    kolvostrok = (dlina - 1) / kolvostolbov + 1;
    a = 0;
    for (int nomerstolba = kolvostolbov; nomerstolba > 0; nomerstolba--) { 
        for (int line_number = 0; line_number < kolvostrok; line_number++) { 
            pozitsiya = kolvostolbov * line_number + nomerstolba;
            if (pozitsiya - 1 < dlina) {
                ocs[pozitsiya - 1] = s[a];
                a++;
            }
        }
    }
    return ocs;
}
string modAlphaCipher::encrypt(const string& open_stroka)                     //зашифрование
{
    string s = getValidText(open_stroka);
    string ocs = s;
    int dlina, kolvostrok, pozitsiya, a; 
    dlina = s.size();
    kolvostrok = (dlina - 1) / kolvostolbov + 1; 
    a = 0;
    for (int nomerstolba = kolvostolbov; nomerstolba > 0; nomerstolba--) { 
        for (int line_number = 0; line_number < kolvostrok; line_number++) {
            pozitsiya = nomerstolba + kolvostolbov * line_number;
            if (pozitsiya-1 < dlina) {
                ocs[a] = open_stroka[pozitsiya-1];
                a++;
            }
        }
    }
    return ocs;
}

inline std::string modAlphaCipher::getValidText(const std::string & s)
{
    string tmp;
    for (auto c:s) {
        if (isalpha (c)) {
            if (islower (c))
                tmp.push_back(toupper(c));
                else
                    tmp.push_back(c);
    }
}

if (tmp.empty())
    throw cipher_error ("Empty open text");
    return tmp;
}