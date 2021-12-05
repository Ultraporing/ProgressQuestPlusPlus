#ifndef TRAITS_WIDGET_H 
#define TRAITS_WIDGET_H

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
		tName(nana::listbox::item_proxy(nullptr)), tRace(nana::listbox::item_proxy(nullptr)), tClass(nana::listbox::item_proxy(nullptr)), tLevel(nana::listbox::item_proxy(nullptr)), 
		listboxWidget(wnd, true)
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
	nana::listbox::item_proxy tName;
	nana::listbox::item_proxy tRace;
	nana::listbox::item_proxy tClass;
	nana::listbox::item_proxy tLevel;
	nana::listbox listboxWidget;

	void AppendToListbox();
};

#endif // !TRAITS_WIDGET_H