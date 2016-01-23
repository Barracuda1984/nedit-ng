
#ifndef MEMORY_20140103_H_
#define MEMORY_20140103_H_

#include <cstddef>
#include <memory>
#include <type_traits>
#include <utility>

namespace memory {

template <class T> struct _Unique_if {
	typedef std::unique_ptr<T> _Single_object;
};

template <class T> struct _Unique_if<T[]> {
	typedef std::unique_ptr<T[]> _Unknown_bound;
};

template <class T, size_t N> struct _Unique_if<T[N]> {
	typedef void _Known_bound;
};

//------------------------------------------------------------------------------
// Name: make_unique
// Desc: this will create a std::unique_ptr, this function is considered an
//       oversight by the standards commity and will be in C++14
//------------------------------------------------------------------------------
template <class T, class... Args>
typename _Unique_if<T>::_Single_object make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

//------------------------------------------------------------------------------
// Name: make_unique
// Desc: this will create a std::unique_ptr, this function is considered an
//       oversight by the standards commity and will be in C++14
//------------------------------------------------------------------------------
template <class T>
typename _Unique_if<T>::_Unknown_bound make_unique(size_t n) {
	typedef typename std::remove_extent<T>::type U;
	return std::unique_ptr<T>(new U[n]());
}

template<class T, class... Args>
typename _Unique_if<T>::_Known_bound make_unique(Args&&...) = delete;

}

#endif
