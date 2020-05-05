#ifndef GAME_MOTOR_TGMERRORS_H
#define GAME_MOTOR_TGMERRORS_H

#include <exception>
#include <string>
#include <iostream>

class file_not_found_exception : public std::exception{
private:
    std::string message = "File not found";
public:
    file_not_found_exception() = default;
    explicit file_not_found_exception(const std::string& file_t){
        if(!file_t.empty()) message.append(":" + file_t);
    }
    const char *what() const noexcept override{
        return message.c_str();
    }
};


#endif //GAME_MOTOR_TGMERRORS_H
