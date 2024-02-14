#pragma once

#include "../_IStlCore.hpp"
#include "IStlNullable.hpp"

#include <type_traits>

namespace IStl {
	/**
	* A class that owns that value T and allows any type to be set to IStl::null.
	*
	* To set references to IStl::null see IStl::NullableReference
	* 
	* @tparam T the type of data this class holds.
	*/
	template<typename T>
	class Nullable {
	public:
		/**
		* Constructs the class with value.
		*/
		ISTL_CONSTEXPR20 Nullable(T val) noexcept : m_val{ val }, m_hasValue{ true } {}

		/**
		* Constructs the class with no value.
		*/
		ISTL_CONSTEXPR20 Nullable(const Null_T& null) noexcept : m_hasValue{ false } {}

		/**
		* @returns true if the class contains a valid reference, false otherwise.
		*/
		ISTL_NODISCARD const bool IsNull() const noexcept;

		/**
		* @returns a reference to the value. Fails if no value is available.
		*/
		ISTL_NODISCARD T& GetValue() noexcept;

		/**
		* @returns a pointer to the value. Fails if no value is available.
		*/
		ISTL_NODISCARD T* operator->() noexcept;

		/**
		* @returns a reference to the value. Fails if no value is available.
		*/
		ISTL_NODISCARD T& operator*() noexcept;
		
		ISTL_CONSTEXPR20 void operator=(const Null_T& ref) noexcept;
		ISTL_CONSTEXPR20 void operator=(T ref) noexcept;


		/// Deleted. Use IStl::NullableReference.
		Nullable(T&) = delete;
		/// Deleted. Use IStl::NullableReference.
		ISTL_CONSTEXPR20 void operator=(T&) = delete;
	private:
		T m_val;
		bool m_hasValue;

		void Reset();
		void Set(T val);
	};
}

#include "inlineDefinition/IStlNullableType.inl"