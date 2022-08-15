/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-zacharie.lawson
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <exception>
#include <string>

namespace indie {
    class IndieException : public std::exception {
        public:
        IndieException(const std::string &message): _message(message) {};
        ~IndieException() {};
        const char *what() const noexcept {
            return ("IndieException: " + _message).c_str();
        }

        private:
            std::string _message;
    };
}
#endif /* !EXCEPTION_HPP_ */
