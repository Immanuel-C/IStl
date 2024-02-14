#pragma once

#include "../_IStlCore.hpp"

namespace IStl {
	/// Users should not create this object.
	struct Null_T {
		/**
		* Saftey struct is used to make creating this struct harder.
		* Similer to std::optional's implementation on the msvc c++ compiler (std::optional::_Tag).
		*/
		struct _Saftey {};
		ISTL_CONSTEXPR20 explicit Null_T(_Saftey) {}
	};

	/// Used to set IStl::NullableReference and IStl::Nullable to null.
	ISTL_CONSTEXPR20 Null_T null{ Null_T::_Saftey{} };
}

