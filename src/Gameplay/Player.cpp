#include "Player.h"
#include "Player.h"
#include "Player.h"
#include "../../lib/nana/source/gui/detail/basic_window.hpp"

Player::Player(nana::window wnd) :
	m_Window(wnd), m_PlayerFrame(wnd),
	m_CharSheetLbl(wnd, "<bold=true>Character Sheet</>"), m_SpellBookLbl(wnd, "<bold=true>Spell Book</>"),
	m_EquipmentLbl(wnd, "<bold=true>Equipment</>"), m_InventoryLbl(wnd, "<bold=true>Inventory</>"),
	m_EncumbranceLbl(wnd, "Encumbrance"), m_ActionLbl(wnd, ""), m_PlotLbl(wnd, "<bold=true>Plot Development</>"),
	m_QuestLbl(wnd, "<bold=true>Quests</>"), m_ExperienceLbl(wnd, "Experience"),
	m_EncumbrancePb(wnd, true), m_ActionPb(wnd, true), m_ExperiencePb(wnd, true), m_PlotPb(wnd, true), m_QuestPb(wnd, true),
	m_Stats(wnd), m_Traits(wnd), m_Spells(wnd), m_Equipment(wnd), m_Inventory(wnd), m_Plots(wnd), m_Quests(wnd)
{
	m_CharSheetLbl.text_align(nana::align::left);
	m_CharSheetLbl.typeface(nana::paint::font("", 10, true));
	m_CharSheetLbl.size(nana::size(m_CharSheetLbl.size().width, 25));
	m_CharSheetLbl.format(true);

	m_SpellBookLbl.text_align(nana::align::left);
	m_SpellBookLbl.typeface(nana::paint::font("", 10, true));
	m_SpellBookLbl.size(nana::size(m_SpellBookLbl.size().width, 25));
	m_SpellBookLbl.format(true);

	m_EquipmentLbl.text_align(nana::align::left);
	m_EquipmentLbl.typeface(nana::paint::font("", 10, true));
	m_EquipmentLbl.size(nana::size(m_EquipmentLbl.size().width, 25));
	m_EquipmentLbl.format(true);

	m_InventoryLbl.text_align(nana::align::left);
	m_InventoryLbl.typeface(nana::paint::font("", 10, true));
	m_InventoryLbl.size(nana::size(m_InventoryLbl.size().width, 25));
	m_InventoryLbl.format(true);

	m_EncumbranceLbl.text_align(nana::align::left);
	m_EncumbranceLbl.typeface(nana::paint::font("", 10, true));
	m_EncumbranceLbl.size(nana::size(m_EncumbranceLbl.size().width, 25));
	m_EncumbranceLbl.format(true);

	m_ActionLbl.text_align(nana::align::left);
	m_ActionLbl.typeface(nana::paint::font("", 10, true));
	m_ActionLbl.size(nana::size(m_ActionLbl.size().width, 25));
	m_ActionLbl.format(true);

	m_PlotLbl.text_align(nana::align::left);
	m_PlotLbl.typeface(nana::paint::font("", 10, true));
	m_PlotLbl.size(nana::size(m_PlotLbl.size().width, 25));
	m_PlotLbl.format(true);

	m_QuestLbl.text_align(nana::align::left);
	m_QuestLbl.typeface(nana::paint::font("", 10, true));
	m_QuestLbl.size(nana::size(m_QuestLbl.size().width, 25));
	m_QuestLbl.format(true);

	m_ExperienceLbl.text_align(nana::align::left);
	m_ExperienceLbl.typeface(nana::paint::font("", 10, true));
	m_ExperienceLbl.format(true);

	m_EncumbrancePb.unknown(false);
	m_ActionPb.unknown(false);
	m_ExperiencePb.unknown(false);
	m_PlotPb.unknown(false);
	m_QuestPb.unknown(false);

	SetLayout();
}

void Player::SetLayout()
{
    m_PlayerFrame.div("<vertical <hoizontal <vertical leftFld arrange=[20,110,195,20,20,20,variable]><vertical centerFld arrange=[20,235,20,variable,20,20]><vertical rightFld arrange=[20,215,20,20,variable,20]>><vert statFld weight=40>>");
    m_PlayerFrame["leftFld"] << m_CharSheetLbl << m_Traits.GetListboxWidget() << m_Stats.GetListboxWidget() << m_ExperienceLbl << m_ExperiencePb << m_SpellBookLbl << m_Spells.GetListboxWidget();
    m_PlayerFrame["centerFld"] << m_EquipmentLbl << m_Equipment.GetListboxWidget() << m_InventoryLbl << m_Inventory.GetListboxWidget() << m_EncumbranceLbl << m_EncumbrancePb;
    m_PlayerFrame["statFld"] << m_ActionLbl << m_ActionPb;
    m_PlayerFrame["rightFld"] << m_PlotLbl << m_Plots.GetListboxWidget() << m_PlotPb << m_QuestLbl << m_Quests.GetListboxWidget() << m_QuestPb;

	m_Stats.UpdateData();
	m_Traits.UpdateData();
	m_Spells.UpdateData();
	m_Equipment.UpdateData();
	m_Inventory.UpdateData();
	m_Plots.UpdateData();
	m_Quests.UpdateData();

	m_PlayerFrame.collocate();
}
