#ifndef INVENTORY_WIDGET_H 
#define INVENTORY_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class InventoryWidget
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, unsigned int>> InventoryList;

	InventoryWidget(nana::window wnd = nullptr) : InventoryList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, unsigned int>>()),
		tInventoryList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()), 
		listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Item");
		listboxWidget.append_header("Qty");
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

	ListviewItemKVPair<nana::detail::native_string_type, unsigned int> GetItem(const nana::detail::native_string_type& name);
	void SetItem(ListviewItemKVPair<nana::detail::native_string_type, unsigned int> item);
	void ResizeHeaders();
	void UpdateData();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tInventoryList;
	nana::listbox listboxWidget;
};

#endif // !INVENTORY_WIDGET_H