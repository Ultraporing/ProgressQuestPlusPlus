#include "SpellsWidget.h"

ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> SpellsWidget::GetSpell(const nana::detail::native_string_type& name)
{
    auto it = tSpellList.find(name);
    if (it != tSpellList.end())
    {
        ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

void SpellsWidget::SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell)
{
    auto it = SpellList.find(spell.Key());
    
    if (it != SpellList.end())
    {
        auto it2 = tSpellList.find(nana::to_nstring(spell.Key()));
        if (spell.Value().empty())
        {
            SpellList.erase(it);
            tSpellList.erase(it2);
        }
        else
        {
            it->second = spell;
            it2->second = it2->second.resolve_from(spell);
        }     
    }
    else
    {
        SpellList.emplace(spell.Key(), spell);
        tSpellList.emplace(spell.Key(), listboxWidget.at(0).append(spell));
    }
}

void SpellsWidget::ResizeHeaders()
{
    auto f = listboxWidget.content_area().width;
    auto width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(1).width((unsigned int)(80));
    width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(0).width(f - width1);
}

void SpellsWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    for (auto& it : SpellList)
    {
        auto it2 = tSpellList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}