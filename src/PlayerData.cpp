#include "PlayerData.h"

void Traits::UpdateUI()
{
    tName = tName.resolve_from(Name);
    tRace = tRace.resolve_from(Race);
    tClass = tClass.resolve_from(Class);
    tLevel = tLevel.resolve_from(Level);
}

void Traits::AppendToListbox(nana::listbox& listbox)
{
    tName = *Name.AppendToListbox(listbox).ItemProxy();
    tRace = *Race.AppendToListbox(listbox).ItemProxy();
    tClass = *Class.AppendToListbox(listbox).ItemProxy();
    tLevel = *Level.AppendToListbox(listbox).ItemProxy();
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
}

void Stats::AppendToListbox(nana::listbox& listbox)
{
    tSTR = listbox.at(0).append(STR);
    tCON = listbox.at(0).append(CON);
    tDEX = listbox.at(0).append(DEX);
    tINT = listbox.at(0).append(INT);
    tWIS = listbox.at(0).append(WIS);
    tCHA = listbox.at(0).append(CHA);
    tHPMax = listbox.at(0).append(HPMax);
    tMPMax = listbox.at(0).append(MPMax);
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

void Spells::SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type> spell, nana::listbox& listbox)
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
        tSpellList.emplace(spell.Key(), listbox.at(0).append(spell));
    }
}