#include "PlayerData.h"

void Traits::UpdateUI()
{
    tName = tName.resolve_from(Name);
    tRace = tRace.resolve_from(Race);
    tClass = tClass.resolve_from(Class);
    tLevel = tLevel.resolve_from(Level);

    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(listboxWidget.column_at(0).width() * 1.10));
    listboxWidget.column_at(1).width(f - listboxWidget.column_at(0).width());
}

void Traits::AppendToListbox()
{
    tName = *Name.AppendToListbox(listboxWidget).ItemProxy();
    tRace = *Race.AppendToListbox(listboxWidget).ItemProxy();
    tClass = *Class.AppendToListbox(listboxWidget).ItemProxy();
    tLevel = *Level.AppendToListbox(listboxWidget).ItemProxy();
}

void Stats::UpdateUI()
{
    tSTR = tSTR.resolve_from(STR);
    tCON = tCON.resolve_from(CON);
    tDEX = tDEX.resolve_from(DEX);
    tINT = tINT.resolve_from(INT);
    tWIS = tWIS.resolve_from(WIS);
    tCHA = tCHA.resolve_from(CHA);
    tHPMax = tHPMax.resolve_from(HPMax);
    tMPMax = tMPMax.resolve_from(MPMax);

    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(listboxWidget.column_at(0).width() * 1.10));
    listboxWidget.column_at(1).width(f - listboxWidget.column_at(0).width());
}

void Stats::AppendToListbox()
{
    tSTR = listboxWidget.at(0).append(STR);
    tCON = listboxWidget.at(0).append(CON);
    tDEX = listboxWidget.at(0).append(DEX);
    tINT = listboxWidget.at(0).append(INT);
    tWIS = listboxWidget.at(0).append(WIS);
    tCHA = listboxWidget.at(0).append(CHA);
    tHPMax = listboxWidget.at(0).append(HPMax);
    tMPMax = listboxWidget.at(0).append(MPMax);
}

ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> Spells::GetSpell(const nana::detail::native_string_type& name)
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

void Spells::SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell)
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

void Spells::UpdateUI()
{
    for (auto& it : SpellList)
    {
        auto it2 = tSpellList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    listboxWidget.column_at(1).fit_content();
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(1).width(50, f - listboxWidget.column_at(0).width());
    listboxWidget.column_at(0).width(f - listboxWidget.column_at(1).width());
}
