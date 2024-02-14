#pragma once

#include <cassert>

#if ISTL_CXX_VERSION >= ISTL_CXX17
	#define ISTL_NODISCARD [[nodiscard]]
#endif // ISTL_CXX_VERSION >= ISTL_CXX17

#if ISTL_CXX_VERSION >= ISTL_CXX11
	#define ISTL_NORETURN [[noreturn]] 
#else // ISTL_CXX_VERSION >= ISTL_CXX11
	#ifdef __GNUC__
		#define ISTL_NORETURN __attribute__((noreturn))
		#define ISTL_NODISCARD __attribute__((warn_unused_result))
	#elif __MINGW32__
		#define ISTL_NORETURN __attribute__((noreturn))
		#define ISTL_NODISCARD __attribute__((warn_unused_result))
	#elif __clang__
		#define ISTL_NORETURN __attribute__((noreturn))
		#define ISTL_NODISCARD __attribute__((warn_unused_result))
	#elif _MSC_VER
		#define ISTL_NORETURN __declspec(noreturn)
		#define ISTL_NODISCARD _Check_return_ 
	#endif
#endif // ISTL_CXX_VERSION >= ISTL_CXX11

#ifdef ISTL_CXX_VERSION >= ISTL_CXX20
	#define ISTL_CONSTEXPR20 constexpr
#else // ISTL_CXX_VERSION >= ISTL_CXX20
	#define ISTL_CONSTEXPR20 const
#endif // ISTL_CXX_VERSION >= ISTL_CXX20

#define ISTL_ASSERT(condition, msg) assert((condition) && msg)
#define ISTL_STATIC_ASSERT(condition, msg) static_assert((condition), msg)