#pragma once
#include <string>
#include <stdexcept>

namespace utils {
    struct base_exception : public std::runtime_error {
        base_exception(const std::string& msg, const std::string& file, int line) : std::runtime_error(msg) {
            m_realMessage = file + ':' + std::to_string(line) + ' ' + msg;
        }
        ~base_exception() override = default;

        [[nodiscard]]
        const char* what() const noexcept override {
            return m_realMessage.c_str();
        }
    private:
        std::string m_realMessage;
    };

} // namespace utils

#define COMMON_EXCEPTION(message) throw utils::base_exception{message, __FILE__, __LINE__}