#include "TraitsWidget.h"

void TraitsWidget::ResizeHeaders()
{
    listboxWidget.column_at(0).fit_content();
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width((unsigned int)(listboxWidget.column_at(0).width() * 1.10));
    listboxWidget.column_at(1).width(f - listboxWidget.column_at(0).width());
}

void TraitsWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    tName = tName.resolve_from(Name);
    tRace = tRace.resolve_from(Race);
    tClass = tClass.resolve_from(Class);
    tLevel = tLevel.resolve_from(Level);

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}

void TraitsWidget::AppendToListbox()
{
    tName = *Name.AppendToListbox(listboxWidget).ItemProxy();
    tRace = *Race.AppendToListbox(listboxWidget).ItemProxy();
    tClass = *Class.AppendToListbox(listboxWidget).ItemProxy();
    tLevel = *Level.AppendToListbox(listboxWidget).ItemProxy();
}