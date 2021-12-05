#ifndef STATS_WIDGET_H 
#define STATS_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

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

	StatsWidget(nana::window wnd = nullptr) :
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
		
		listboxWidget.column_at(0).fit_content();
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(false);
		listboxWidget.enable_single(true, false);
		listboxWidget.auto_draw(true);
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

#endif // !STATS_WIDGET_H