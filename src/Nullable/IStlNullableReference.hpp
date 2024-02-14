#pragma once

#include "IStlNullable.hpp"
#include "../_IStlCore.hpp"

#include <type_traits>


namespace IStl {
	/**
	* A non-owning class that allows any reference to be set to IStl::null.
	* 
	* @tparam T the type of data this class holds.
	*/
	template<typename T>
	class NullableReference {
	public:
		ISTL_CONSTEXPR20 NullableReference(T& ref) : m_ptr{ &ref } {}
		ISTL_CONSTEXPR20 NullableReference(const Null_T& nullref) : m_ptr{ nullptr } {}

		/**
		* @exceptsafe no-throw
		* @returns true if the class contains a valid reference, false otherwise.
		*/
		inline ISTL_NODISCARD const bool IsNull() const noexcept { return m_ptr == nullptr; }

		/**
		* @exceptsafe no-throw
		* @returns a reference to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T& GetValue() noexcept {
			ISTL_ASSERT(m_ptr != nullptr, "IRun::NullableReference must have value to get value!");
			return *m_ptr;
		}

		/**
		* @exceptsafe no-throw
		* @returns a pointer to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T* operator->() noexcept {
			ISTL_ASSERT(m_ptr != nullptr , "IRun::NullableReference must have value to get value!");
			return m_ptr;
		}

		/**
		* @exceptsafe no-throw
		* @returns a reference to the value. Fails if no value is available.
		*/
		inline ISTL_NODISCARD T& operator*() noexcept {
			ISTL_ASSERT(m_ptr != nullptr, "IRun::NullableReference must have value to get value!");
			return *m_ptr;
		}

		inline ISTL_CONSTEXPR20 void operator=(const Null_T& ref) { Reset(); }
		inline ISTL_CONSTEXPR20 void operator=(T& ref) { Set(ref); }

		inline ISTL_CONSTEXPR20 void operator=(T&& ref) = delete;
		NullableReference(T&&) = delete;
	private:
		T* m_ptr;

		inline void Reset() {
			m_ptr = nullptr;
		}

		inline void Set(T& ptr) {
			m_ptr = &ptr;
		}
	};
}