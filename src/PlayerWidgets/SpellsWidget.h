#ifndef SPELLS_WIDGET_H 
#define SPELLS_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class SpellsWidget
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>> SpellList;

	SpellsWidget(nana::window wnd) : SpellList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>>()), 
		tSpellList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()), 
		listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Spell");
		listboxWidget.append_header("Level");
		listboxWidget.column_at(0).fit_content();
		listboxWidget.auto_draw(true);
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(true);
		listboxWidget.enable_single(true, false);
		listboxWidget.enabled(false);

		listboxWidget.events().resized([&] {
			ResizeHeaders();
			});
	}

	ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> GetSpell(const nana::detail::native_string_type& name);
	void SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell);
	void ResizeHeaders();
	void UpdateData();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tSpellList;
	nana::listbox listboxWidget;
};

#endif // !SPELLS_WIDGET_H