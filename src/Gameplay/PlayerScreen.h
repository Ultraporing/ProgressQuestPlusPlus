#ifndef PLAYER_SCREEN_H 
#define PLAYER_SCREEN_H
#include "../PlayerWidgets/PlayerWidgets.h"
#include "PlayerData.h"
#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>
#include <nana/gui/widgets/button.hpp>
#include <nana/gui/widgets/progress.hpp>
#include <nana/gui/timer.hpp>

class PlayerScreen
{
public:
	PlayerScreen(nana::window wnd, PlayerData plrData = PlayerData());
	void SetPlayer(PlayerData plrData);
	void UpdateUI();
	PlayerData& GetPlayer()
	{
		return m_PlayerData;
	}

protected:
	nana::place m_PlayerFrame;
	nana::window m_Window;
	
	nana::label m_CharSheetLbl;
	nana::label m_SpellBookLbl;
	nana::label m_EquipmentLbl;
	nana::label m_InventoryLbl;
	nana::label m_EncumbranceLbl;
	nana::label m_ActionLbl;
	nana::label m_PlotLbl;
	nana::label m_QuestLbl;
	nana::label m_ExperienceLbl;

	nana::progress m_EncumbrancePb;
	nana::progress m_ActionPb;
	nana::progress m_ExperiencePb;
	nana::progress m_PlotPb;
	nana::progress m_QuestPb;

	StatsWidget m_Stats;
	TraitsWidget m_Traits;
	SpellsWidget m_Spells;
	EquipmentWidget m_Equipment;
	InventoryWidget m_Inventory;
	PlotsWidget m_Plots;
	QuestsWidget m_Quests;

	PlayerData m_PlayerData;

	void SetLayout();
};
#endif // !PLAYER_SCREEN_H
