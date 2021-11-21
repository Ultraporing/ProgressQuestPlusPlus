#pragma once
#include <nana/gui/widgets/listbox.hpp>
#include <nana/deploy.hpp>
#include <map>

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
	NativeStringPair HPMax;
	NativeStringPair MPMax;

	Stats() : 
		STR("STR", ""), CON("CON", ""), DEX("DEX", ""), INT("INT", ""), WIS("WIS", ""), CHA("CHA", ""), HPMax("HP Max", ""), MPMax("MP Max", ""),
		tSTR(nana::listbox::item_proxy(nullptr)), tCON(nana::listbox::item_proxy(nullptr)),	tDEX(nana::listbox::item_proxy(nullptr)), 
		tINT(nana::listbox::item_proxy(nullptr)), tWIS(nana::listbox::item_proxy(nullptr)), tCHA(nana::listbox::item_proxy(nullptr)),
		tHPMax(nana::listbox::item_proxy(nullptr)), tMPMax(nana::listbox::item_proxy(nullptr))
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
	nana::listbox::item_proxy tHPMax;
	nana::listbox::item_proxy tMPMax;
};

struct Spells
{
	std::map<nana::detail::native_string_type, NativeStringPair> SpellList;

	Spells() : SpellList(std::map<nana::detail::native_string_type, NativeStringPair>()), tSpellList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>())
	{}

	NativeStringPair GetSpell(const std::wstring& name);
	NativeStringPair GetSpell(const std::string& name);
	void SetSpell(const NativeStringPair& spell, nana::listbox& listbox);

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tSpellList;
};