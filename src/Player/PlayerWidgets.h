#ifndef PLAYER_WIDGETS_H 
#define PLAYER_WIDGETS_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class TraitsWidget
{
public:
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Name;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Race;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Class;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Level;
	
	TraitsWidget(nana::window wnd) :
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

		listboxWidget.events().resized([&] {
			UpdateUI();
			});
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

class StatsWidget
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

	StatsWidget(nana::window wnd) :
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

		listboxWidget.events().resized([&] {
			UpdateUI();
			});
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

class SpellsWidget
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>> SpellList;

	SpellsWidget(nana::window wnd) : SpellList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>>()), tSpellList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()), listboxWidget(wnd, true)
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

		listboxWidget.events().resized([&] {
			UpdateUI();
			});
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

class EquipmentWidget
{
public:
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Weapon;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Shield;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Helm;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Hauberk;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Brassairts;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Vambraces;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Gauntlets;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Gamberson;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Cuisses;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Greaves;
	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Sollerets;

	EquipmentWidget(nana::window wnd) :
		Weapon("Weapon", ""), Shield("Shield", ""), Helm("Helm", ""), Hauberk("Hauberk", ""), Brassairts("Brassairts", ""), 
		Vambraces("Vambraces", ""), Gauntlets("Gauntlets", ""), Gamberson("Gamberson", ""), Cuisses("Cuisses", ""), Greaves("Greaves", ""), Sollerets("Sollerets", ""),
		tWeapon(nana::listbox::item_proxy(nullptr)), tShield(nana::listbox::item_proxy(nullptr)), tHelm(nana::listbox::item_proxy(nullptr)),
		tHauberk(nana::listbox::item_proxy(nullptr)), tBrassairts(nana::listbox::item_proxy(nullptr)), tVambraces(nana::listbox::item_proxy(nullptr)),
		tGauntlets(nana::listbox::item_proxy(nullptr)), tGamberson(nana::listbox::item_proxy(nullptr)), tCuisses(nana::listbox::item_proxy(nullptr)),
		tGreaves(nana::listbox::item_proxy(nullptr)), tSollerets(nana::listbox::item_proxy(nullptr)),	listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Equip");
		listboxWidget.append_header("Name");
		listboxWidget.show_header(false);
		AppendToListbox();
		listboxWidget.auto_draw(true);
		listboxWidget.column_at(0).fit_content();
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(false);
		listboxWidget.enable_single(true, false);

		listboxWidget.events().resized([&] {
			UpdateUI();
			});
	}

	void UpdateUI();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	nana::listbox::item_proxy tWeapon;
	nana::listbox::item_proxy tShield;
	nana::listbox::item_proxy tHelm;
	nana::listbox::item_proxy tHauberk;
	nana::listbox::item_proxy tBrassairts;
	nana::listbox::item_proxy tVambraces;
	nana::listbox::item_proxy tGauntlets;
	nana::listbox::item_proxy tGamberson;
	nana::listbox::item_proxy tCuisses;
	nana::listbox::item_proxy tGreaves;
	nana::listbox::item_proxy tSollerets;
	nana::listbox listboxWidget;

	void AppendToListbox();
};

#endif // !PLAYER_WIDGETS_H