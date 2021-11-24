#pragma once
#include <nana/gui/widgets/listbox.hpp>
#include <nana/deploy.hpp>
#include <map>

template<typename K, typename V>
struct ListviewItemKVPair
{
private:
	std::pair<K, V> m_NativePair;
	nana::listbox::item_proxy m_NativeItemProxy;

	const K* KeyPtr(const K& key) const
	{
		return &key;
	}

	const K* KeyPtr(const K* key) const
	{
		return key;
	}

	const V* ValuePtr(const V& value) const
	{
		return &value;
	}

	const V* ValuePtr(const V* value) const
	{
		return value;
	}

public:
	nana::listbox::item_proxy* ItemProxy()
	{
		return &m_NativeItemProxy;
	}

	std::pair<K, V>* KeyValuePtr()
	{
		return &m_NativePair;
	}

	std::pair<K, V> KeyValue()
	{
		return m_NativePair;
	}

	const K* KeyPtr() const
	{
		return KeyPtr(m_NativePair.first);
	}

	const K Key() const
	{
		return *KeyPtr(m_NativePair.first);
	}

	const V* ValuePtr() const
	{
		return ValuePtr(m_NativePair.second);
	}

	const V Value() const
	{
		return *ValuePtr(m_NativePair.second);
	}

	ListviewItemKVPair& AppendToListbox(nana::listbox& listbox)
	{
		*ItemProxy() = listbox.at(0).append(*this);

		return *this;
	}

	ListviewItemKVPair& Update()
	{
		*ItemProxy() = ItemProxy()->resolve_from(*this);

		return *this;
	}

	ListviewItemKVPair& SetKey(const K key)
	{
		KeyValuePtr()->first = key;

		return *this;
	}

	ListviewItemKVPair& SetValue(const V value)
	{
		KeyValuePtr()->second = value;

		return *this;
	}

	ListviewItemKVPair() : m_NativePair(std::pair<K, V>(K(), V())), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key) : m_NativePair(std::pair<K, V>(key, V())), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), V())), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), V())), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key, const char* value) : m_NativePair(std::pair<K, nana::detail::native_string_type>(key, nana::to_nstring(value))), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key, const wchar_t* value) : m_NativePair(std::pair<K, nana::detail::native_string_type>(key, nana::to_nstring(value))), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key, V value) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), value)), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key, V value) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), value)), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key, const char* value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(nana::to_nstring(key), nana::to_nstring(value))), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key, const wchar_t* value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(nana::to_nstring(key), nana::to_nstring(value))), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(nana::detail::native_string_type key, nana::detail::native_string_type value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(key, value)), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}
};

template<typename K, typename V>
nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const ListviewItemKVPair<K, V>& ps)
{
	orr << ps.Key();
	orr << ps.Value();
	return orr;
}

template<typename K, typename V>
std::ostream& operator << (std::ostream& orr, const ListviewItemKVPair<K, V>& ps)
{
	orr << ps.Key();
	orr << ps.Value();
	return orr;
}

template<typename K, typename V>
nana::listbox::iresolver& operator >> (nana::listbox::iresolver& orr, ListviewItemKVPair<K, V>& ps)
{
	orr >> ps.KeyValuePtr()->first;
	orr >> ps.KeyValuePtr()->second;
	return orr;
}