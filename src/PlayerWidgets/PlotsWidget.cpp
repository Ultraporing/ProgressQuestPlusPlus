#include "PlotsWidget.h"

ListviewItemKVPair<nana::detail::native_string_type, int> PlotsWidget::GetPlot(const nana::detail::native_string_type& name)
{
    auto it = tPlotList.find(name);
    if (it != tPlotList.end())
    {
        ListviewItemKVPair<nana::detail::native_string_type, int> oPair;
        it->second.resolve_to(oPair);
        return oPair;
    }

    return {};
}

void PlotsWidget::SetPlot(ListviewItemKVPair<nana::detail::native_string_type, int> plot)
{
    auto it = PlotList.find(plot.Key());

    if (it != PlotList.end())
    {
        auto it2 = tPlotList.find(nana::to_nstring(plot.Key()));
        if (plot.Value() == -1)
        {
            PlotList.erase(it);
            tPlotList.erase(it2);
        }
        else
        {
            it->second = plot;
            it2->second = it2->second.resolve_from(plot);
            it2->second.check((plot.Value() == 0 ? false : true), true);
        }
    }
    else
    {
        PlotList.emplace(plot.Key(), plot);
        tPlotList.emplace(plot.Key(), listboxWidget.at(0).append(plot));
        auto ita = tPlotList.find(nana::to_nstring(plot.Key()));
        if (ita != tPlotList.end())
        {
            ita->second.check((plot.Value() == 0 ? false : true), true);
        }      
    }
}

void PlotsWidget::ResizeHeaders()
{
    auto f = listboxWidget.content_area().width;
    listboxWidget.column_at(0).width(f);
}

void PlotsWidget::UpdateData()
{
    listboxWidget.auto_draw(false);
    for (auto& it : PlotList)
    {
        auto it2 = tPlotList.find(nana::to_nstring(it.second.Key()));
        it2->second = it2->second.resolve_from(it.second);
    }

    ResizeHeaders();
    listboxWidget.auto_draw(true);
}