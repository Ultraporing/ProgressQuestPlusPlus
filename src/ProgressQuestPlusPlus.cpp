// ProgressQuestPlusPlus.cpp : Defines the entry point for the application.
//

#include "ProgressQuestPlusPlus.h"
#include "config.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/timer.hpp>
#include <string>
#include "Player/PlayerData.h"

using namespace std;

int main()
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER << std::endl;

    using namespace nana;

    //Define a form.
    form fm(API::make_center(800,600));

    //Define a label and display a text.
    label charSheetLbl{ fm, "<bold=true>Character Sheet</>" };
    charSheetLbl.text_align(nana::align::left);
    charSheetLbl.typeface(nana::paint::font("", 10, true));
    charSheetLbl.size(nana::size(charSheetLbl.size().width, 25));
    charSheetLbl.format(true);

    label spellBookLbl{ fm, "<bold=true>Spell Book</>" };
    spellBookLbl.text_align(nana::align::left);
    spellBookLbl.typeface(nana::paint::font("", 10, true));
    spellBookLbl.size(nana::size(spellBookLbl.size().width, 25));
    spellBookLbl.format(true);

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


    Stats stats(fm);
    stats.STR.SetValue(to_nstring("5"));
    stats.CON.SetValue(to_nstring("8"));
    stats.DEX.SetValue(to_nstring("7"));
    stats.INT.SetValue(to_nstring("3"));
    stats.WIS.SetValue(to_nstring("0"));
    stats.CHA.SetValue(to_nstring("15"));
    stats.HPMax.SetValue(to_nstring("10"));
    stats.MPMax.SetValue(to_nstring("17"));

    Traits traits(fm);
    traits.Name.SetValue(to_nstring("Derp"));
    traits.Class.SetValue(to_nstring("Treehugger"));
    traits.Race.SetValue(to_nstring("Frisbee"));
    traits.Level.SetValue(to_nstring(69));
 
    Spells spells(fm);
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>("derp pew", IntToRoman(512)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( "depew", IntToRoman(52)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( nana::to_nstring("deew"), IntToRoman(1)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( nana::to_nstring("kmkw"), IntToRoman(12)));
     
    label l1{ fm, "l1"};
    label l2{ fm, "l2" };
    label l3{ fm, "l3" };
    label l4{ fm, "l4" };
    label l5{ fm, "l5" };
    label l6{ fm, "l6" };
    label l7{ fm, "l7" };
    label l8{ fm, "l8" };
    
    //Layout management
    place plc(fm);
    plc.div("<vertical leftFld arrange=[20,110,195,20,20,20,variable]><centerFld><rightFld>");
    plc.modify("centerFld", "<vertical <l1 weight = 20><l2 weight = 108><l3 weight = 150><l4 weight = 20><l5 weight = 20>");
    plc.modify("rightFld", "<vertical <l6 weight = 20><l7 weight = 108><l8 weight = 150>");
    plc["leftFld"] << charSheetLbl << traits.GetListboxWidget() << stats.GetListboxWidget() << labExp << expPro << spellBookLbl << spells.GetListboxWidget();
    plc["l1"] << l1;
    plc["l2"] << l2;
    plc["l3"] << l3;
    plc["l4"] << l4;
    plc["l5"] << l5;
    plc["l6"] << l6;
    plc["l7"] << l7;
    plc["l8"] << l8;

    plc.collocate();

    stats.UpdateUI();
    traits.UpdateUI();
    spells.UpdateUI();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();

	return 0;
}
