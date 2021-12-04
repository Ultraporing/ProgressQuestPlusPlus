#ifndef PLAYER_DATA_H 
#define PLAYER_DATA_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class Traits
{
public:
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Name;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Race;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Class;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Level;
	
	Traits(nana::window wnd) : 
		Name("Name", ""), Race("Race", ""), Class("Class", ""), Level("Level", ""),
		tName(nana::listbox::item_proxy(nullptr)), tRace(nana::listbox::item_proxy(nullptr)), tClass(nana::listbox::item_proxy(nullptr)), tLevel(nana::listbox::item_proxy(nullptr)), listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Trait");
		listboxWidget.append_header("Value");
		AppendToListbox();
		listboxWidget.auto_draw(true);
		listboxWidget.column_at(0).fit_content();
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(false);
		listboxWidget.enable_single(true, false);
	}

	void UpdateUI();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	nana::listbox::item_proxy tName;
	nana::listbox::item_proxy tRace;
	nana::listbox::item_proxy tClass;
	nana::listbox::item_proxy tLevel;
	nana::listbox listboxWidget;

	void AppendToListbox();
};

class Stats
{
public:
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> STR;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> CON;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> DEX;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> INT;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> WIS;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> CHA;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> HPMax;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> MPMax;

	Stats(nana::window wnd) : 
		STR("STR", ""), CON("CON", ""), DEX("DEX", ""), INT("INT", ""), WIS("WIS", ""), CHA("CHA", ""), HPMax("HP Max", ""), MPMax("MP Max", ""),
		tSTR(nana::listbox::item_proxy(nullptr)), tCON(nana::listbox::item_proxy(nullptr)),	tDEX(nana::listbox::item_proxy(nullptr)), 
		tINT(nana::listbox::item_proxy(nullptr)), tWIS(nana::listbox::item_proxy(nullptr)), tCHA(nana::listbox::item_proxy(nullptr)),
		tHPMax(nana::listbox::item_proxy(nullptr)), tMPMax(nana::listbox::item_proxy(nullptr)), listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Stat");
		listboxWidget.append_header("Value");
		AppendToListbox();
		listboxWidget.auto_draw(true);
		listboxWidget.column_at(0).fit_content();
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(false);
		listboxWidget.enable_single(true, false);
	}

	void UpdateUI();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	nana::listbox::item_proxy tSTR;
	nana::listbox::item_proxy tCON;
	nana::listbox::item_proxy tDEX;
	nana::listbox::item_proxy tINT;
	nana::listbox::item_proxy tWIS;
	nana::listbox::item_proxy tCHA;
	nana::listbox::item_proxy tHPMax;
	nana::listbox::item_proxy tMPMax;
	nana::listbox listboxWidget;

	void AppendToListbox();
};

class Spells
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>> SpellList;

	Spells(nana::window wnd) : SpellList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>>()), tSpellList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()), listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Spell");
		listboxWidget.append_header("Level");
		listboxWidget.column_at(0).fit_content();
		listboxWidget.auto_draw(true);
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(false);
		listboxWidget.enable_single(true, false);
	}

	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> GetSpell(const nana::detail::native_string_type& name);
	void SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell);
	void UpdateUI();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tSpellList;
	nana::listbox listboxWidget;
};

#endif // !PLAYER_DATA_H