#include "StatsWidget.h"

void StatsWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    tSTR = tSTR.resolve_from(STR);
    tCON = tCON.resolve_from(CON);
    tDEX = tDEX.resolve_from(DEX);
    tINT = tINT.resolve_from(INT);
    tWIS = tWIS.resolve_from(WIS);
    tCHA = tCHA.resolve_from(CHA);
    tHPMax = tHPMax.resolve_from(HPMax);
    tMPMax = tMPMax.resolve_from(MPMax);

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}

void StatsWidget::ResizeHeaders()
{
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).fit_content();
    auto width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(0).width((unsigned int)(width0 * 1.10));
    width0 = listboxWidget.column_at(0).width();
    listboxWidget.column_at(1).width(f - width0);
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