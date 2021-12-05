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
#include "PlayerWidgets/PlayerWidgets.h"

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

    label eqLbl{ fm, "<bold=true>Equipment</>" };
    eqLbl.text_align(nana::align::left);
    eqLbl.typeface(nana::paint::font("", 10, true));
    eqLbl.size(nana::size(eqLbl.size().width, 25));
    eqLbl.format(true);

    label invLbl{ fm, "<bold=true>Inventory</>" };
    invLbl.text_align(nana::align::left);
    invLbl.typeface(nana::paint::font("", 10, true));
    invLbl.size(nana::size(eqLbl.size().width, 25));
    invLbl.format(true);

    label encumbranceLbl{ fm, "Encumbrance" };
    encumbranceLbl.text_align(nana::align::left);
    encumbranceLbl.typeface(nana::paint::font("", 10, true));
    encumbranceLbl.size(nana::size(eqLbl.size().width, 25));
    encumbranceLbl.format(true);

    progress encumbrancePro{ fm, true };
    encumbrancePro.value(20);
    encumbrancePro.unknown(false);

    label statLbl{ fm, "Executing a Killert Toast" };
    statLbl.text_align(nana::align::left);
    statLbl.typeface(nana::paint::font("", 10, true));
    statLbl.size(nana::size(eqLbl.size().width, 25));
    statLbl.format(true);

    progress statPro{ fm, true };
    statPro.unknown(false);

    progress expPro{ fm, true };
    expPro.unknown(false);

    progress plotPro{ fm, true };
    plotPro.value(30);
    plotPro.unknown(false);

    label plotLbl{ fm, "<bold=true>Plot Development</>" };
    plotLbl.text_align(nana::align::left);
    plotLbl.typeface(nana::paint::font("", 10, true));
    plotLbl.size(nana::size(eqLbl.size().width, 25));
    plotLbl.format(true);

    progress questPro{ fm, true };
    questPro.value(70);
    questPro.unknown(false);

    label questLbl{ fm, "<bold=true>Quests</>" };
    questLbl.text_align(nana::align::left);
    questLbl.typeface(nana::paint::font("", 10, true));
    questLbl.size(nana::size(eqLbl.size().width, 25));
    questLbl.format(true);

    label labExp{ fm, "Experience" };
    labExp.text_align(nana::align::left);
    labExp.typeface(nana::paint::font("", 10, true));
    labExp.format(true);
 
    timer timer_;
    timer_.elapse([&]()
    {
            //Resets the known mode progress if its value reaches the amount value.
            if (expPro.value() == expPro.amount())
                expPro.value(0);
            expPro.inc();

            //Resets the known mode progress if its value reaches the amount value.
            if (statPro.value() == statPro.amount())
                statPro.value(0);
            statPro.inc();
    });
    timer_.interval(std::chrono::milliseconds{ 80 });
    timer_.start();

    StatsWidget stats(fm);
    stats.STR.SetValue(to_nstring("5"));
    stats.CON.SetValue(to_nstring("8"));
    stats.DEX.SetValue(to_nstring("7"));
    stats.INT.SetValue(to_nstring("3"));
    stats.WIS.SetValue(to_nstring("0"));
    stats.CHA.SetValue(to_nstring("15"));
    stats.HPMax.SetValue(to_nstring("10"));
    stats.MPMax.SetValue(to_nstring("17"));

    TraitsWidget traits(fm);
    traits.Name.SetValue(to_nstring("Derp"));
    traits.Class.SetValue(to_nstring("Treehugger"));
    traits.Race.SetValue(to_nstring("Frisbee"));
    traits.Level.SetValue(to_nstring(69));
 
    SpellsWidget spells(fm);
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>("derp pew", IntToRoman(512)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( "depew", IntToRoman(52)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( nana::to_nstring("deew"), IntToRoman(1)));
    spells.SetSpell(ListviewItemKVPair<nana::detail::native_string_type, nana::detail::native_string_type>( nana::to_nstring("kmkw"), IntToRoman(12)));

    EquipmentWidget equipment(fm);
    equipment.Weapon.SetValue(to_nstring("+1 Toaster"));

    InventoryWidget inventory(fm);
    inventory.SetItem(ListviewItemKVPair<nana::detail::native_string_type, unsigned int>("alcoholic liver", 5));
    inventory.SetItem(ListviewItemKVPair<nana::detail::native_string_type, unsigned int>("pikachu tail", 2));

    PlotsWidget plots(fm);
    plots.SetPlot(ListviewItemKVPair<nana::detail::native_string_type, int>("Prologue", 1));
    plots.SetPlot(ListviewItemKVPair<nana::detail::native_string_type, int>("Act I", 0));

    QuestsWidget quests(fm);
    quests.SetQuest(ListviewItemKVPair<nana::detail::native_string_type, int>("Shit the bed", 1));
    quests.SetQuest(ListviewItemKVPair<nana::detail::native_string_type, int>("Watch paint dry", 0));
   
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
    plc.div("<vertical <hoizontal <vertical leftFld arrange=[20,110,195,20,20,20,variable]><vertical centerFld arrange=[20,235,20,variable,20,20]><vertical rightFld arrange=[20,215,20,20,variable,20]>><vert statFld weight=40>>");
    plc["leftFld"] << charSheetLbl << traits.GetListboxWidget() << stats.GetListboxWidget() << labExp << expPro << spellBookLbl << spells.GetListboxWidget();
    plc["centerFld"] << eqLbl << equipment.GetListboxWidget() << invLbl << inventory.GetListboxWidget() << encumbranceLbl << encumbrancePro;
    plc["statFld"] << statLbl << statPro;
    plc["rightFld"] << plotLbl << plots.GetListboxWidget() << plotPro << questLbl << quests.GetListboxWidget() << questPro;

    plc.collocate();
    
    stats.UpdateData();
    traits.UpdateData();
    spells.UpdateData();
    equipment.UpdateData();
    inventory.UpdateData();
    plots.UpdateData();

    //Show the form
    fm.show();

    //Start to event loop process, it blocks until the form is closed.
    exec();

	return 0;
}
