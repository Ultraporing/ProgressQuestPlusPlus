#include "PlayerData.h"

nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const NativeStringPair& ps)
{
    orr << ps.Name;
    orr << ps.Value;
    return orr;
}

std::ostream& operator << (std::ostream& orr, const NativeStringPair& ps)
{
    orr << ps.Name;
    orr << ps.Value;
    return orr;
}

nana::listbox::iresolver& operator >> (nana::listbox::iresolver& orr, NativeStringPair& ps)
{
    orr >> ps.Name;
    orr >> ps.Value;
    return orr;
}

void Traits::UpdateUI()
{
    tName = tName.resolve_from(Name);
    tRace = tRace.resolve_from(Race);
    tClass = tClass.resolve_from(Class);
    tLevel = tLevel.resolve_from(Level);
}

void Traits::AppendToListbox(nana::listbox& listbox)
{
    tName = listbox.at(0).append(Name);
    tRace = listbox.at(0).append(Race);
    tClass = listbox.at(0).append(Class);
    tLevel = listbox.at(0).append(Level);
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

NativeStringPair Spells::GetSpell(const std::wstring& name)
{
    auto it = tSpellList.find(nana::to_nstring(name));
    if (it != tSpellList.end())
    {
        NativeStringPair oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

NativeStringPair Spells::GetSpell(const std::string& name)
{
    auto it = tSpellList.find(nana::to_nstring(name));
    if (it != tSpellList.end())
    {
        NativeStringPair oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

void Spells::SetSpell(const NativeStringPair& spell, nana::listbox& listbox)
{
    auto it = SpellList.find(nana::to_nstring(spell.Name));
    
    if (it != SpellList.end())
    {
        auto it2 = tSpellList.find(nana::to_nstring(spell.Name));
        if (spell.Value.empty())
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
        SpellList.emplace(spell.Name, spell);
        tSpellList.emplace(spell.Name, listbox.at(0).append(spell));
    }
}