#ifndef PLOTS_WIDGET_H 
#define PLOTS_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class PlotsWidget
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, int>> PlotList;

	PlotsWidget(nana::window wnd) : PlotList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, int>>()),
		tPlotList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()),
		listboxWidget(wnd, true)
	{
		listboxWidget.clear_headers();
		listboxWidget.auto_draw(false);
		listboxWidget.sortable(false);
		listboxWidget.append_header("Plot");
		listboxWidget.column_at(0).fit_content();
		listboxWidget.checkable(true);
		listboxWidget.auto_draw(true);
		listboxWidget.column_movable(false);
		listboxWidget.column_resizable(true);
		listboxWidget.enable_single(true, false);
		listboxWidget.show_header(false);
		listboxWidget.enabled(false);

		listboxWidget.events().resized([&] {
			ResizeHeaders();
			});
	}

	ListviewItemKVPair<nana::detail::native_string_type, int> GetPlot(const nana::detail::native_string_type& name);
	void SetPlot(ListviewItemKVPair<nana::detail::native_string_type, int> plot);
	void ResizeHeaders();
	void UpdateData();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tPlotList;
	nana::listbox listboxWidget;
};

#endif // !PLOTS_WIDGET_H