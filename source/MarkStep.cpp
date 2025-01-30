#include <iostream>
#include <unordered_map>

#include <utils/MarkStep.hpp>
#include <utils/Util.hpp>


namespace utils {
    struct ScopeMarkStep {
        ScopeMarkStep() = default;
        ScopeMarkStep(const std::string& _message, const std::string& _key):
                message{_message}, key{_key} {}

        std::string message;
        std::string key;
        int callCount { 0 };
    };

    namespace {

        std::unordered_map<std::string, ScopeMarkStep> g_scopeMarkSteps;

    }

    void mark_step(const std::string& message, const std::string& file, int line) {
        std::cout << util::format_string("[MarkStep]: {0}: file: {1}, line: {2}",
                                         message, file, line) << std::endl;
    }


    ScopeMarkStep scope_mark_step(const std::string& message, const std::string& file, int line) {
        std::string uniqueKey = util::format_string("{0}:{1}", file, line);
        if(g_scopeMarkSteps.find(uniqueKey) == g_scopeMarkSteps.end()) {
            g_scopeMarkSteps[uniqueKey] = ScopeMarkStep();
        }

        return g_scopeMarkSteps[uniqueKey];
    }

} // namespace utils