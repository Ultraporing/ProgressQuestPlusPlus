#pragma once
#include <nana/gui/widgets/listbox.hpp>
#include <map>

template<typename K, typename V, typename Derived>
struct KVPair
{
protected:
	std::pair<K, V> m_NativePair;

	Derived* This() { return static_cast<Derived*>(this); }

	const K* KeyPtr(const K& key) const
	{
		return &key;
	}

	K* KeyPtr(K& key)
	{
		return &key;
	}

	const K* KeyPtr(const K* key) const
	{
		return key;
	}

	K* KeyPtr(K* key)
	{
		return key;
	}

	const V* ValuePtr(const V& value) const
	{
		return &value;
	}

	V* ValuePtr(V& value)
	{
		return &value;
	}

	const V* ValuePtr(const V* value) const
	{
		return value;
	}

	V* ValuePtr(V* value)
	{
		return value;
	}

public:
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

	K* KeyPtr()
	{
		return KeyPtr(m_NativePair.first);
	}

	const K Key() const
	{
		return *KeyPtr(m_NativePair.first);
	}

	K Key()
	{
		return *KeyPtr(m_NativePair.first);
	}

	const V* ValuePtr() const
	{
		return ValuePtr(m_NativePair.second);
	}

	V* ValuePtr()
	{
		return ValuePtr(m_NativePair.second);
	}

	const V Value() const
	{
		return *ValuePtr(m_NativePair.second);
	}

	V Value()
	{
		return *ValuePtr(m_NativePair.second);
	}

	Derived& SetKey(const K& key)
	{
		KeyValuePtr()->first = key;

		return *This();
	}

	Derived& SetKey(K& key)
	{
		KeyValuePtr()->first = key;

		return *This();
	}

	Derived& SetValue(const V& value)
	{
		KeyValuePtr()->second = value;

		return *This();
	}

	Derived& SetValue(V& value)
	{
		KeyValuePtr()->second = value;

		return *This();
	}

	KVPair() : m_NativePair(std::pair<K, V>(K(), V()))
	{
	}

	KVPair(K key) : m_NativePair(std::pair<K, V>(key, V()))
	{
	}

	KVPair(const char* key) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), V()))
	{
	}

	KVPair(const wchar_t* key) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), V()))
	{
	}

	KVPair(K key, const char* value) : m_NativePair(std::pair<K, nana::detail::native_string_type>(key, nana::to_nstring(value)))
	{
	}

	KVPair(K key, const wchar_t* value) : m_NativePair(std::pair<K, nana::detail::native_string_type>(key, nana::to_nstring(value)))
	{
	}

	KVPair(const char* key, V value) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), value))
	{
	}

	KVPair(const wchar_t* key, V value) : m_NativePair(std::pair<nana::detail::native_string_type, V>(nana::to_nstring(key), value))
	{
	}

	KVPair(const char* key, const char* value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(nana::to_nstring(key), nana::to_nstring(value)))
	{
	}

	KVPair(const wchar_t* key, const wchar_t* value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(nana::to_nstring(key), nana::to_nstring(value)))
	{
	}

	KVPair(nana::detail::native_string_type key, nana::detail::native_string_type value) : m_NativePair(std::pair<nana::detail::native_string_type, nana::detail::native_string_type>(key, value))
	{
	}
};

template<typename K, typename V>
struct ListviewItemKVPair : KVPair<K, V, ListviewItemKVPair<K,V>>
{
protected:
	nana::listbox::item_proxy m_NativeItemProxy;

public:
	nana::listbox::item_proxy* ItemProxy()
	{
		return &m_NativeItemProxy;
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

	ListviewItemKVPair() : KVPair<K, V, ListviewItemKVPair<K, V>>(), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key) : KVPair<K, V, ListviewItemKVPair<K, V>>(key), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key) : KVPair<K, V, ListviewItemKVPair<K, V>>(key), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key) : KVPair<K, V, ListviewItemKVPair<K, V>>(key), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key, const char* value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(K key, const wchar_t* value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key, V value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key, V value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const char* key, const char* value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(const wchar_t* key, const wchar_t* value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}

	ListviewItemKVPair(nana::detail::native_string_type key, nana::detail::native_string_type value) : KVPair<K, V, ListviewItemKVPair<K, V>>(key, value), m_NativeItemProxy(nana::listbox::item_proxy(nullptr))
	{
	}
};

template<typename K, typename V>
nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const ListviewItemKVPair<K*, V>& ps)
{
	orr << std::stringstream((*ps.KeyPtr())[0]).str();
	orr << *ps.ValuePtr();
	return orr;
}

template<typename K, typename V>
nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const ListviewItemKVPair<K, V>& ps)
{
	orr << *ps.KeyPtr();
	orr << *ps.ValuePtr();
	return orr;
}

template<typename K, typename V>
nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const ListviewItemKVPair<K*, V*>& ps)
{
	orr << std::stringstream((*ps.KeyPtr())[0]).str();
	orr << std::stringstream((*ps.ValuePtr())[0]).str();
	return orr;
}

template<typename K, typename V>
nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const ListviewItemKVPair<K, V*>& ps)
{
	orr << *ps.KeyPtr();
	orr << std::stringstream((*ps.ValuePtr())[0]).str();
	return orr;
}


template<typename K, typename V>
std::ostream& operator << (std::ostream& orr, const ListviewItemKVPair<K, V>& ps)
{
	orr << *ps.KeyPtr();
	orr << *ps.ValuePtr();
	return orr;
}

template<typename K, typename V>
std::ostream& operator << (std::ostream& orr, const ListviewItemKVPair<K*, V>& ps)
{
	orr << std::stringstream((*ps.KeyPtr())[0]).str();
	orr << *ps.ValuePtr();
	return orr;
}

template<typename K, typename V>
std::ostream& operator << (std::ostream& orr, const ListviewItemKVPair<K, V*>& ps)
{
	orr << *ps.KeyPtr();
	orr << std::stringstream((*ps.ValuePtr())[0]).str();
	return orr;
}

template<typename K, typename V>
std::ostream& operator << (std::ostream& orr, const ListviewItemKVPair<K*, V*>& ps)
{
	orr << std::stringstream((*ps.KeyPtr())[0]).str();
	orr << std::stringstream((*ps.ValuePtr())[0]).str();
	return orr;
}

template<typename K, typename V>
nana::listbox::iresolver& operator >> (nana::listbox::iresolver& orr, ListviewItemKVPair<K, V>& ps)
{
	orr >> ps.KeyValuePtr()->first;
	orr >> ps.KeyValuePtr()->second;
	return orr;
}