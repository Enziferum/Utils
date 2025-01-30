#pragma once
#include <string>
#include <optional>

#include "Enum.hpp"


namespace utils {

    template<typename T>
    class Result {
    public:
        Result() = default;
        ~Result() = default;

        Result(std::nullopt_t) {}
        Result(const T& data): m_result{ data } {}
        Result& operator=(std::nullopt_t data) {
            m_result = data;
            return *this;
        }

        Result& operator=(const T& data) {
            m_result = data;
            return *this;
        }

        // TODO(a.raag): result formatter
        std::string to_string() const {
            return ENUM2STR(*m_result);
        }

        T unpack() const {
            return m_result;
        }

        T operator*() const {
            return *m_result;
        }

        explicit operator bool() const noexcept {
            return m_result.has_value();
        }
    private:
        std::optional<T> m_result;
    };
} // namespace utils