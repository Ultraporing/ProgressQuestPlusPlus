// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/timer.hpp>
#include "PlayerData.h"
//#include <nana/gui/widgets/listbox.hpp>



using namespace std;

struct PairStr
{
public:
    std::string P1;
    std::string P2;
};

nana::listbox::oresolver& operator << (nana::listbox::oresolver& orr, const PairStr& ps)
{
    orr << ps.P1;
    orr << ps.P2;
    return orr;
}

std::ostream& operator << (std::ostream& orr, const PairStr& ps)
{
    orr << ps.P1;
    orr << ps.P2;
    return orr;
}

nana::listbox::iresolver& operator >> (nana::listbox::iresolver& orr, PairStr& ps)
{
    orr >> ps.P1;
    orr >> ps.P2;
    return orr;
}

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;

    //Define a form.
    form fm(API::make_center(640,480));

    //Define a label and display a text.
    label charSheetLbl{ fm, "<bold=true>Character Sheet</>" };
    charSheetLbl.text_align(nana::align::left);
    charSheetLbl.typeface(nana::paint::font("", 10, true));
    charSheetLbl.format(true);

    progress expPro{ fm, true };
    label labExp{ fm, "Experience" };
    labExp.text_align(nana::align::left);
    labExp.typeface(nana::paint::font("", 10, true));
    labExp.format(true);
    expPro.unknown(false);

    timer timer_;
    timer_.elapse([&expPro](const nana::arg_elapse& a)
    {
            //Resets the known mode progress if its value reaches the amount value.
            if (expPro.value() == expPro.amount())
                expPro.value(0);
            expPro.inc();
    });
    timer_.interval(std::chrono::milliseconds{ 80 });
    timer_.start();

    listbox statsLb{ fm, true };
    statsLb.clear_headers();
    statsLb.auto_draw(false);
    statsLb.sortable(false);
    statsLb.append_header("Stat");
    statsLb.append_header("Value");


    listbox traitsLb{ fm, true };
    traitsLb.clear_headers();
    traitsLb.auto_draw(false);
    traitsLb.sortable(false);
    traitsLb.append_header("Trait");
    traitsLb.append_header("Value");

    Stats stats;
    stats.STR.Value = to_nstring("5");
    stats.CON.Value = to_nstring("8");
    stats.DEX.Value = to_nstring("7");
    stats.INT.Value = to_nstring("3");
    stats.WIS.Value = to_nstring("0");
    stats.CHA.Value = to_nstring("15");
    stats.HPMax.Value = to_nstring("10");
    stats.MPMax.Value = to_nstring("17");
    stats.AppendToListbox(statsLb);
    statsLb.auto_draw(true);

    Traits traits;
    traits.Name.Value = to_nstring("Derp");
    traits.Class.Value = to_nstring("Treehugger");
    traits.Race.Value = to_nstring("Frisbee");
    traits.Level.Value = to_nstring(69);
    traits.AppendToListbox(traitsLb);
    traitsLb.auto_draw(true);

    label l1{ fm, "l1"};
    label l2{ fm, "l2" };
    label l3{ fm, "l3" };
    label l4{ fm, "l4" };
    label l5{ fm, "l5" };
    label l6{ fm, "l6" };
    label l7{ fm, "l7" };
    label l8{ fm, "l8" };
    statsLb.column_at(0).fit_content();
    statsLb.column_at(0).width((unsigned int)(statsLb.column_at(0).width() * 1.10));
    statsLb.column_at(1).width(200 - statsLb.column_at(0).width()-10);
    traitsLb.column_at(0).fit_content();
    traitsLb.column_at(0).width(statsLb.column_at(0).width());
    traitsLb.column_at(1).width(200 - traitsLb.column_at(0).width()-10);
    //Layout management
    place plc(fm);
    plc.div("horizontal <leftFld><centerFld><rightFld>");
    plc.modify("leftFld", "weight = 200<vertical <charSheetLbl weight = 20><traitsLb weight = 110><statsLb weight = 195><labExp weight = 20><expPro weight = 20>");
    plc.modify("centerFld", "<vertical <l1 weight = 20><l2 weight = 108><l3 weight = 150><l4 weight = 20><l5 weight = 20>");
    plc.modify("rightFld", "<vertical <l6 weight = 20><l7 weight = 108><l8 weight = 150>");
    
    plc["charSheetLbl"] << charSheetLbl;
    plc["traitsLb"] << traitsLb;
    plc["statsLb"] << statsLb;
    plc["labExp"] << labExp;
    plc["expPro"] << expPro;
    plc["l1"] << l1;
    plc["l2"] << l2;
    plc["l3"] << l3;
    plc["l4"] << l4;
    plc["l5"] << l5;
    plc["l6"] << l6;
    plc["l7"] << l7;
    plc["l8"] << l8;

    plc.collocate();
 
    // pd.P2 = "63";
        
    //Show the form
    fm.show();



    //Start to event loop process, it blocks until the form is closed.
    exec();

	return 0;
}
