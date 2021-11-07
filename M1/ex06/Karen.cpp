#include "Karen.hpp"
#include <iostream>
#include <string>

const std::string Karen::_msg[4] = {"DEBUG", "HELLO", "WARNING", "ERROR"};
const Karen::funPtr Karen::_fun_array[5] = {&Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error, &Karen::_no_msg};

Karen::Karen(void) {
    return ;
}

Karen::~Karen(void) {
    return ;
}

void Karen::_debug(void) const {
    std::cout << "I love to get extra bacon for my "
    "7XL-double-cheese-triple-pickle-special-ketchup burger. "
    "I just love it!" << std::endl;
}

void Karen::_info(void) const {
    std::cout << "I cannot believe adding extra "
    "bacon cost more money. You don’t put enough! "
    "If you did I would not have to ask for it!" << std::endl;
}

void Karen::_warning(void) const {
    std::cout << "I think I deserve to have some extra bacon for free. "
    "I’ve been coming here for years and you just "
    "started working here last month." << std::endl;
}

void Karen::_error(void) const {
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void Karen::_no_msg(void) const {
    return ;
}

void Karen::complain(std::string level) const {
    unsigned int i;

    for (i=0;i<sizeof(this->_msg)/sizeof(*this->_msg);i++) {
        if (level.compare(this->_msg[i]) == 0)
            break ;
    }
    (this->*_fun_array[i])();
}

void Karen::complain_filter(std::string level) const {
    unsigned int i;

    for (i=0;i<sizeof(this->_msg)/sizeof(*this->_msg);i++) {
        if (level.compare(this->_msg[i]) == 0)
            break ;
    }
    if (i == sizeof(this->_msg)/sizeof(*this->_msg)) {
        std::cout << "[Probably complaining about insignificant problems ]" << std::endl;
        return ;
    }
    for (unsigned j = i;j < sizeof(this->_msg)/sizeof(*this->_msg);j++) {
        std::cout << "[" << this->_msg[j] << "]" << std::endl;
        (this->*_fun_array[j])();
        std::cout << std::endl;
    }
}
