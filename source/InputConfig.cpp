#include "utils/InputConfig.hpp"

namespace utils {

	template<>
	std::string Value::as() const {
		return m_value;
	}

	template<>
	bool Value::as() const {
		return m_value == "true" ? true : false;
	}

	template<>
	float Value::as() const {
		return std::stof(m_value);
	}

	template<>
	int Value::as() const {
		return std::stoi(m_value);
	}


} // namespace utils