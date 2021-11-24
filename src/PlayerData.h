#pragma once
#include "ListviewItemKVPair.hpp"

struct Traits
{
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Name;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Race;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Class;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Level;
	
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
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> STR;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> CON;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> DEX;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> INT;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> WIS;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> CHA;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> HPMax;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> MPMax;

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
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>> SpellList;

	Spells() : SpellList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>>()), tSpellList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>())
	{}

	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> GetSpell(const nana::detail::native_string_type& name);
	void SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell, nana::listbox& listbox);

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tSpellList;
};