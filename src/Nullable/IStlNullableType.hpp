#pragma once

#include "../_IStlCore.hpp"
#include "IStlNullable.hpp"

#include <type_traits>

namespace IStl {
	/**
	* A class that owns that value T and allows any type to be set to IStl::null.
	*
	* @tparam T the type of data this class holds.
	*/
	template<typename T>
	class Nullable {
	public:
		ISTL_CONSTEXPR20 Nullable(T val) noexcept : m_val{ val }, m_hasValue{ true } { }
		ISTL_CONSTEXPR20 Nullable(const Null_T& null) noexcept : m_hasValue{ false } {}

		/**
		* @exceptsafe no-throw
		* @returns true if the class contains a valid reference, false otherwise.
		*/
		inline ISTL_NODISCARD const bool IsNull() const noexcept { return !m_hasValue; }

		/**
		* @exceptsafe no-throw
		* @returns a reference to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T& GetValue() noexcept {
			ISTL_ASSERT(m_hasValue, "IRun::Nullable must have value to get value!");
			return m_val;
		}

		/**
		* @exceptsafe no-throw
		* @returns a pointer to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T* operator->() noexcept {
			ISTL_ASSERT(m_hasValue, "IRun::Nullable must have value to get value!");
			return &m_val;
		}

		/**
		* @exceptsafe no-throw
		* @returns a reference to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T& operator*() noexcept {
			ISTL_ASSERT(m_hasValue, "IRun::NullableReference must have value to get value!");
			return m_val;
		}
		
		inline ISTL_CONSTEXPR20 void operator=(const Null_T& ref) noexcept { Reset(); }
		inline ISTL_CONSTEXPR20 void operator=(T ref) { Set(ref); }


		/// Use IStl::NullableReference
		Nullable(T&) = delete;
		/// Use IStl::NullableReference
		inline ISTL_CONSTEXPR20 void operator=(T&) = delete;
	private:
		T m_val;
		bool m_hasValue;

		inline void Reset() {
			m_hasValue = false;
		}

		inline void Set(T val) {
			m_val = val;
			m_hasValue = true;
		}
	};
}