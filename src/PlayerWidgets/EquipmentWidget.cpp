#include "EquipmentWidget.h"

void EquipmentWidget::ResizeHeaders()
{
    listboxWidget.column_at(0).fit_content();
    auto width0 = listboxWidget.column_at(0).width();
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(width0 * 1.10));
    width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(1).width(f - width0);
}

void EquipmentWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
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

    ResizeHeaders();
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