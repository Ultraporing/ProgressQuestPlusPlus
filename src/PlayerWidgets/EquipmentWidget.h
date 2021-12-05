#ifndef EQUIPMENT_WIDGET_H 
#define EQUIPMENT_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

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

	EquipmentWidget(nana::window wnd = nullptr) :
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
		listboxWidget.column_resizable(true);
		listboxWidget.enable_single(true, false);
		listboxWidget.enabled(false);

		listboxWidget.events().resized([&] {
			ResizeHeaders();
			});
	}

	void ResizeHeaders();
	void UpdateData();
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

#endif // !EQUIPMENT_WIDGET_H