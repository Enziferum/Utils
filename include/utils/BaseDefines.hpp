#pragma once
#include <memory>


#define S_PTR(Name) using Ptr = std::shared_ptr<Name>;
#define U_PTR(Name) using Ptr = std::unique_ptr<Name>;

#define BIND_CLASS_FN(fn)[this](auto&&... args) -> decltype(auto) { \
	return this -> fn(std::forward<decltype(args)>(args)...);      \
}

#define BIND_CLASS_EMP_FN(fn)[this]() { \
	return this -> fn();      \
}