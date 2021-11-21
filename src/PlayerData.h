#pragma once
#include <nana/gui/widgets/listbox.hpp>
#include <nana/deploy.hpp>

struct NativeStringPair
{
	nana::detail::native_string_type Name;
	nana::detail::native_string_type Value;

	NativeStringPair() : Name(nana::to_nstring("")), Value(nana::to_nstring(""))
	{
	}

	NativeStringPair(const std::wstring& name) : Name(nana::to_nstring(name)), Value(nana::to_nstring(""))
	{
	}

	NativeStringPair(const std::wstring& name, const std::wstring& value) : Name(nana::to_nstring(name)), Value(nana::to_nstring(value))
	{
	}

	NativeStringPair(const std::string& name) : Name(nana::to_nstring(name)), Value(nana::to_nstring(""))
	{
	}

	NativeStringPair(const std::string& name, const std::string& value) : Name(nana::to_nstring(name)), Value(nana::to_nstring(value))
	{
	}
};

struct Traits
{
	NativeStringPair Name;
	NativeStringPair Race;
	NativeStringPair Class;
	NativeStringPair Level;
	
	Traits() : 
		Name("Name", ""), Race("Race", ""), Class("Class", ""), Level("Level", ""), 
		tName(nana::listbox::item_proxy(nullptr)), tRace(nana::listbox::item_proxy(nullptr)), tClass(nana::listbox::item_proxy(nullptr)), tLevel(nana::listbox::item_proxy(nullptr))
	{
	}

	void UpdateUI();
	void AppendToListbox(nana::listbox& listbox);

private:
	nana::listbox::item_proxy tName;
	nana::listbox::item_proxy tRace;
	nana::listbox::item_proxy tClass;
	nana::listbox::item_proxy tLevel;
};

struct Stats
{
	NativeStringPair STR;
	NativeStringPair CON;
	NativeStringPair DEX;
	NativeStringPair INT;
	NativeStringPair WIS;
	NativeStringPair CHA;

	Stats() : 
		STR("STR", ""), CON("CON", ""), DEX("DEX", ""), INT("INT", ""), WIS("WIS", ""), CHA("CHA", ""),
		tSTR(nana::listbox::item_proxy(nullptr)), tCON(nana::listbox::item_proxy(nullptr)),	tDEX(nana::listbox::item_proxy(nullptr)), 
		tINT(nana::listbox::item_proxy(nullptr)), tWIS(nana::listbox::item_proxy(nullptr)), tCHA(nana::listbox::item_proxy(nullptr))
	{
	}

	void UpdateUI();
	void AppendToListbox(nana::listbox& listbox);

private:
	nana::listbox::item_proxy tSTR;
	nana::listbox::item_proxy tCON;
	nana::listbox::item_proxy tDEX;
	nana::listbox::item_proxy tINT;
	nana::listbox::item_proxy tWIS;
	nana::listbox::item_proxy tCHA;
};