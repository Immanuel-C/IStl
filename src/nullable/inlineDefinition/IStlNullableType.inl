#pragma once

/// Include in IStlNullableType.hpp

namespace IStl {
	template<typename T>
	ISTL_NODISCARD const bool Nullable<T>::IsNull() const noexcept { return !m_hasValue; }

	template<typename T>
	ISTL_NODISCARD T& Nullable<T>::GetValue() noexcept {
		ISTL_ASSERT(m_hasValue, "IRun::Nullable must have value to get value!");
		return m_val;
	}

	template<typename T>
	ISTL_NODISCARD T* Nullable<T>::operator->() noexcept {
		ISTL_ASSERT(m_hasValue, "IRun::Nullable must have value to get value!");
		return &m_val;
	}

	template<typename T>
	ISTL_NODISCARD T& Nullable<T>::operator*() noexcept {
		ISTL_ASSERT(m_hasValue, "IRun::NullableReference must have value to get value!");
		return m_val;
	}

	template<typename T>
	ISTL_CONSTEXPR20 void Nullable<T>::operator=(const Null_T& ref) noexcept { Reset(); }

	template<typename T>
	ISTL_CONSTEXPR20 void Nullable<T>::operator=(T ref) { Set(ref); }


	template<typename T>
	void Nullable<T>::Reset() {
		m_hasValue = false;
	}

	template<typename T>
	void Nullable<T>::Set(T val) {
		m_val = val;
		m_hasValue = true;
	}

}