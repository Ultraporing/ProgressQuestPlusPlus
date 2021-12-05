#include "QuestsWidget.h"

ListviewItemKVPair<nana::detail::native_string_type, int> QuestsWidget::GetQuest(const nana::detail::native_string_type& name)
{
    auto it = tQuestList.find(name);
    if (it != tQuestList.end())
    {
        ListviewItemKVPair<nana::detail::native_string_type, int> oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

void QuestsWidget::SetQuest(ListviewItemKVPair<nana::detail::native_string_type, int> quest)
{
    auto it = QuestList.find(quest.Key());

    if (it != QuestList.end())
    {
        auto it2 = tQuestList.find(nana::to_nstring(quest.Key()));
        if (quest.Value() == -1)
        {
            QuestList.erase(it);
            tQuestList.erase(it2);
        }
        else
        {
            it->second = quest;
            it2->second = it2->second.resolve_from(quest);
            it2->second.check((quest.Value() == 0 ? false : true), true);
        }
    }
    else
    {
        QuestList.emplace(quest.Key(), quest);
        tQuestList.emplace(quest.Key(), listboxWidget.at(0).append(quest));
        auto ita = tQuestList.find(nana::to_nstring(quest.Key()));
        if (ita != tQuestList.end())
        {
            ita->second.check((quest.Value() == 0 ? false : true), true);
        }      
    }
}

void QuestsWidget::ResizeHeaders()
{
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width(f);
}

void QuestsWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    for (auto& it : QuestList)
    {
        auto it2 = tQuestList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}