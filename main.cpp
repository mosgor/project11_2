#include <iostream>
#include <string>

std::string first_part(std::string str){
    if (str[0] == '.' || str[0] == '@') return ".invalid";
    std::string library = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.!#$%&'*+-/=?^_`{|}~";
    int fPartLength = 0;
    for (int i = 0; i < str.length(); ++i) {
        bool rightSymbol;
        fPartLength++;
        if (str[i] == '.' && str[i - 1] == '.') return ".invalid";
        for (int j = 0; j < library.length(); ++j){
            if (str[i] != library[j]) rightSymbol = false;
            else {
                rightSymbol = true;
                break;
            }
        }
        if (!rightSymbol){
            if (str[i] == '@' && fPartLength >= 1 && fPartLength <= 64) return str.substr(0, i + 1);
            else return ".invalid";
        }
    }
    return ".invalid";
}

std::string second_part(std::string str){
    if (str[str.length() - 1] == '.') return "invalid.";
    str = str.substr(str.find('@') + 1, str.length() - first_part(str).length());
    std::string library = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";
    int sPartLength = 0;
    for (int i = 0; i < str.length(); ++i) {
        bool rightSymbol;
        sPartLength++;
        if (str[i] == '.' && str[i - 1] == '.') return "invalid.";
        for (int j = 0; j < library.length(); ++j){
            if (str[i] != library[j]) rightSymbol = false;
            else {
                rightSymbol = true;
                break;
            }
        }
        if (!rightSymbol || sPartLength < 1 || sPartLength > 63) return "invalid.";
    }
    return str;
}

std::string isValid(std::string email){
    if (first_part(email) == ".invalid" || second_part(email) == "invalid.") return "No\n";
    else return "Yes\n";
}

int main() {
    std::cout << "Is your email valid?" << std::endl;
    std::cout << "Input your email: ";
    std::string email;
    std::cin >> email;
    std::cout << isValid(email);
    return 0;
}