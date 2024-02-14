#pragma once

#include <cassert>

#if ISTL_CXX_VERSION >= ISTL_CXX17
	#define ISTL_NODISCARD [[nodiscard]]
#else // ISTL_CXX_VERSION >= ISTL_CXX17 
	#define ISTL_NODISCARD 
#endif // ISTL_CXX_VERSION >= ISTL_CXX17

#if ISTL_CXX_VERSION >= ISTL_CXX11
	#define ISTL_NORETURN [[noreturn]] 
#else // ISTL_CXX_VERSION >= ISTL_CXX11
	#define ISTL_NORETURN 
#endif // ISTL_CXX_VERSION >= ISTL_CXX11

#ifdef ISTL_CXX_VERSION >= ISTL_CXX20
	#define ISTL_CONSTEXPR20 constexpr
#else // ISTL_CXX_VERSION >= ISTL_CXX20
	#define ISTL_CONSTEXPR20 const
#endif // ISTL_CXX_VERSION >= ISTL_CXX20

#define ISTL_ASSERT(condition, msg) assert((condition) && msg)
#define ISTL_STATIC_ASSERT(condition, msg) static_assert((condition), msg)