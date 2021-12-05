#include "InventoryWidget.h"

ListviewItemKVPair<nana::detail::native_string_type, unsigned int> InventoryWidget::GetItem(const nana::detail::native_string_type& name)
{
    auto it = tInventoryList.find(name);
    if (it != tInventoryList.end())
    {
        ListviewItemKVPair<nana::detail::native_string_type, unsigned int> oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

void InventoryWidget::SetItem(ListviewItemKVPair<nana::detail::native_string_type, unsigned int> item)
{
    auto it = InventoryList.find(item.Key());

    if (it != InventoryList.end())
    {
        auto it2 = tInventoryList.find(nana::to_nstring(item.Key()));
        if (item.Value() == 0)
        {
            InventoryList.erase(it);
            tInventoryList.erase(it2);
        }
        else
        {
            it->second = item;
            it2->second = it2->second.resolve_from(item);
        }
    }
    else
    {
        InventoryList.emplace(item.Key(), item);
        tInventoryList.emplace(item.Key(), listboxWidget.at(0).append(item));
    }
}

void InventoryWidget::ResizeHeaders()
{
    auto f = listboxWidget.content_area().width;
    auto width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(1).width((unsigned int)(50));
    width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(0).width(f - width1);
}

void InventoryWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    for (auto& it : InventoryList)
    {
        auto it2 = tInventoryList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}
