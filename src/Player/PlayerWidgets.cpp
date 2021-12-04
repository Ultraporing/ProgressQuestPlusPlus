#include "PlayerWidgets.h"

void TraitsWidget::UpdateUI()
{
    tName = tName.resolve_from(Name);
    tRace = tRace.resolve_from(Race);
    tClass = tClass.resolve_from(Class);
    tLevel = tLevel.resolve_from(Level);

    listboxWidget.auto_draw(false);
    listboxWidget.column_at(0).fit_content();
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(listboxWidget.column_at(0).width() * 1.10));
    listboxWidget.column_at(1).width(f - listboxWidget.column_at(0).width());
    listboxWidget.auto_draw(true);
}

void TraitsWidget::AppendToListbox()
{
    tName = *Name.AppendToListbox(listboxWidget).ItemProxy();
    tRace = *Race.AppendToListbox(listboxWidget).ItemProxy();
    tClass = *Class.AppendToListbox(listboxWidget).ItemProxy();
    tLevel = *Level.AppendToListbox(listboxWidget).ItemProxy();
}

void StatsWidget::UpdateUI()
{
    tSTR = tSTR.resolve_from(STR);
    tCON = tCON.resolve_from(CON);
    tDEX = tDEX.resolve_from(DEX);
    tINT = tINT.resolve_from(INT);
    tWIS = tWIS.resolve_from(WIS);
    tCHA = tCHA.resolve_from(CHA);
    tHPMax = tHPMax.resolve_from(HPMax);
    tMPMax = tMPMax.resolve_from(MPMax);

    listboxWidget.auto_draw(false);
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).fit_content();
    auto width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(0).width((unsigned int)(width0 * 1.10));
    width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(1).width(f - width0);
    listboxWidget.auto_draw(true);
}

void StatsWidget::AppendToListbox()
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

void SpellsWidget::UpdateUI()
{
    for (auto& it : SpellList)
    {
        auto it2 = tSpellList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    listboxWidget.auto_draw(false);
    auto f = listboxWidget.content_area().width;
    auto width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(1).width((unsigned int)(80));
    width1 = listboxWidget.column_at(1).width();
    listboxWidget.column_at(0).width(f - width1);

    listboxWidget.auto_draw(true);
}

void EquipmentWidget::UpdateUI()
{
    tWeapon = tWeapon.resolve_from(Weapon);
    tShield = tShield.resolve_from(Shield);
    tHelm = tHelm.resolve_from(Helm);
    tHauberk = tHauberk.resolve_from(Hauberk);
    tBrassairts = tBrassairts.resolve_from(Brassairts);
    tVambraces = tVambraces.resolve_from(Vambraces);
    tGauntlets = tGauntlets.resolve_from(Gauntlets);
    tGamberson = tGamberson.resolve_from(Gamberson);
    tCuisses = tCuisses.resolve_from(Cuisses);
    tGreaves = tGreaves.resolve_from(Greaves);
    tSollerets = tSollerets.resolve_from(Sollerets);

    listboxWidget.auto_draw(false);
    auto width0 = listboxWidget.column_at(0).width();
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(width0 * 1.10));
    width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(1).width(f - width0);
    listboxWidget.auto_draw(true);
}

void EquipmentWidget::AppendToListbox()
{
    tWeapon = listboxWidget.at(0).append(Weapon);
    tShield = listboxWidget.at(0).append(Shield);
    tHelm = listboxWidget.at(0).append(Helm);
    tHauberk = listboxWidget.at(0).append(Hauberk);
    tBrassairts = listboxWidget.at(0).append(Brassairts);
    tVambraces = listboxWidget.at(0).append(Vambraces);
    tGauntlets = listboxWidget.at(0).append(Gauntlets);
    tGamberson = listboxWidget.at(0).append(Gamberson);
    tCuisses = listboxWidget.at(0).append(Cuisses);
    tGreaves = listboxWidget.at(0).append(Greaves);
    tSollerets = listboxWidget.at(0).append(Sollerets);
}