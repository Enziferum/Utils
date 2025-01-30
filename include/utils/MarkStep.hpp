#pragma once
#include <string>

namespace utils {

    void mark_step(const std::string& message, const std::string& file, int line);

}

#define MARK_STEP(message) utils::mark_step(message, __FILE__, __LINE__);