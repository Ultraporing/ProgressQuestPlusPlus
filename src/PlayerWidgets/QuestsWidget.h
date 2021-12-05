#ifndef QUESTS_WIDGET_H 
#define QUESTS_WIDGET_H

#include "../Generic/ListviewItemKVPair.h"
#include "../Generic/RomanDecimal.h"

class QuestsWidget
{
public:
	std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, int>> QuestList;

	QuestsWidget(nana::window wnd) : QuestList(std::map<nana::detail::native_string_type, ListviewItemKVPair<nana::detail::native_string_type, int>>()),
		tQuestList(std::map<nana::detail::native_string_type, nana::listbox::item_proxy>()),
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

	ListviewItemKVPair<nana::detail::native_string_type, int> GetQuest(const nana::detail::native_string_type& name);
	void SetQuest(ListviewItemKVPair<nana::detail::native_string_type, int> quest);
	void ResizeHeaders();
	void UpdateData();
	nana::listbox& GetListboxWidget()
	{
		return listboxWidget;
	}

private:
	std::map<nana::detail::native_string_type, nana::listbox::item_proxy> tQuestList;
	nana::listbox listboxWidget;
};

#endif // !QUESTS_WIDGET_H