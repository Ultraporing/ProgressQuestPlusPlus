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
}

void Stats::AppendToListbox(nana::listbox& listbox)
{
    tSTR = listbox.at(0).append(STR);
    tCON = listbox.at(0).append(CON);
    tDEX = listbox.at(0).append(DEX);
    tINT = listbox.at(0).append(INT);
    tWIS = listbox.at(0).append(WIS);
    tCHA = listbox.at(0).append(CHA);
}
