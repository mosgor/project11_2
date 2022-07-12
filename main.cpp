#include <iostream>
#include <string>

std::string first_part(std::string str){
    std::string library = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.!#$%&'*+-/=?^_`{|}~";
}

std::string second_part(std::string str){
    std::string library = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-.";
}

bool isValid(std::string email){

}

int main() {
    std::cout << "Is your email valid?" << std::endl;
    std::cout << "Input your email: ";
    std::string email;
    std::cin >> email;
    std::cout << isValid(email);
    return 0;
}
