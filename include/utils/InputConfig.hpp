#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>

#include "Enum.hpp"
#include "Result.hpp"


namespace utils {

	DECLARE_ENUM(ConfigError, FileException)

	struct Value {
		template<typename T>
		T as() const;

		std::string m_value;
	};

	template<typename Key>
	class InputConfig {
	public:
		using InputConfigPair = std::pair<Key, std::string>;

		bool hasValue(Key key) const { return (m_values.find(key) != m_values.end()); }

		void setValue(const InputConfigPair& key_value) { m_values[key_value.first] = Value{ key_value.second }; }
		Value getValue(const Key& value) const { return m_values.at(value); }
	private:
		std::unordered_map<Key, Value> m_values;
	};

	template<typename Key>
	struct key_formatter;

	template<typename Key>
	Result<ConfigError> read_config(InputConfig<Key>& config, const std::string& config_path) {
		const std::unordered_map<std::string, Key> types = key_formatter<Key>::makeTypes();

		constexpr auto split = [](const std::string& str, char sep) ->	std::pair < std::string, std::string > {
			auto found = str.find(sep);
			return { str.substr(0, found), str.substr(found + 1, str.size() - found) };
		};

		try {
			/// TODO(a.raag): simple bad cases checking
			std::ifstream input(config_path);
			for (std::string line; getline(input, line); )
			{
				auto [type, value] = split(line, ':');

				std::string clear_path;
				int index = 0;
				while (value[index] == ' ')
					++index;
				clear_path = value.substr(index, value.size() - index);

				config.setValue( std::make_pair(types.at(type), clear_path));
			}
			input.close();
		}
		catch (...) {
			return ConfigError::FileException;
		}

		return std::nullopt;
	}

} // namespace utils