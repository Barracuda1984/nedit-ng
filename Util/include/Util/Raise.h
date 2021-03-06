
#ifndef UTIL_RAISE_H_
#define UTIL_RAISE_H_

#include <utility>

template <class E, class ... Args>
constexpr void
#ifdef __GNUC__
__attribute__(( noinline, cold, noreturn ))
#elif defined(_MSC_VER)
__declspec(noreturn)
#endif
Raise(Args && ...args) {
	throw E{std::forward<Args>(args)...};
}

#endif
