#pragma once

/// Include in IStlNullableReference.hpp

namespace IStl {
	template<typename T>
	ISTL_NODISCARD const bool NullableReference<T>::IsNull() const noexcept { return m_ptr == nullptr; }

	template<typename T>
	ISTL_NODISCARD T& NullableReference<T>::GetValue() noexcept {
		ISTL_ASSERT(m_ptr != nullptr, "IRun::NullableReference must have value to get value!");
		return *m_ptr;
	}

	template<typename T>
	ISTL_NODISCARD T* NullableReference<T>::operator->() noexcept {
		ISTL_ASSERT(m_ptr != nullptr, "IRun::NullableReference must have value to get value!");
		return m_ptr;
	}

	template<typename T>
	ISTL_NODISCARD T& NullableReference<T>::operator*() noexcept {
		ISTL_ASSERT(m_ptr != nullptr, "IRun::NullableReference must have value to get value!");
		return *m_ptr;
	}

	template<typename T>
	inline ISTL_CONSTEXPR20 void NullableReference<T>::operator=(const Null_T& ref) noexcept { Reset(); }

	template<typename T>
	inline ISTL_CONSTEXPR20 void NullableReference<T>::operator=(T& ref) noexcept { Set(ref); }

	template<typename T>
	void NullableReference<T>::Reset() {
		m_ptr = nullptr;
	}

	template<typename T>
	void NullableReference<T>::Set(T& ptr) {
		m_ptr = &ptr;
	}
}