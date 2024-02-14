#pragma once

#include "IStlNullable.hpp"
#include "../_IStlCore.hpp"

namespace IStl {
	/**
	* A non-owning class that allows any reference to be set to IStl::null.
	* 
	* @tparam T the type of data this class holds.
	*/
	template<typename T>
	class NullableReference {
	public:
		/**
		* Constructs the class with value.
		*/
		ISTL_CONSTEXPR20 NullableReference(T& ref) noexcept : m_ptr{ &ref } {}

		/**
		* Constructs the class with no value.
		*/
		ISTL_CONSTEXPR20 NullableReference(const Null_T& nullref) noexcept : m_ptr{ nullptr } {}

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
		ISTL_CONSTEXPR20 void operator=(T& ref) noexcept;

		/// Deleted. Use IStl::Nullable.
		ISTL_CONSTEXPR20 void operator=(T&& ref) = delete;
		/// Deleted. Use IStl::Nullable.
		NullableReference(T&&) = delete;
	private:
		T* m_ptr;

		inline void Reset();
		inline void Set(T& ptr);
	};
}

#include "inlineDefinition/IStlNullableReference.inl"