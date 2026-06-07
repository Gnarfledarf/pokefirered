EventScript_PkmnCenterNurse::
	goto_if_questlog EventScript_ReleaseEnd
	goto_if_set FLAG_SYS_GAME_CLEAR, EventScript_PkmnCenterNurse_Champ
	gettime
	switch VAR_0x8003
	case 0, EventScript_PkmnCenterNurse_NurseIntro_Morning
	case 1, EventScript_PkmnCenterNurse_NurseIntro_Day
	case 2, EventScript_PkmnCenterNurse_NurseIntro_Evening
	case 3, EventScript_PkmnCenterNurse_NurseIntro_Night
	end

EventScript_PkmnCenterNurse_Champ::
	gettime
	switch VAR_0x8003
	case 0, EventScript_PkmnCenterNurse_NurseIntro_Champ_Morning
	case 1, EventScript_PkmnCenterNurse_NurseIntro_Champ_Day
	case 2, EventScript_PkmnCenterNurse_NurseIntro_Champ_Evening
	case 3, EventScript_PkmnCenterNurse_NurseIntro_Champ_Night
	end

EventScript_PkmnCenterNurse_NurseIntro_Morning::
	message Text_WelcomeWantToHealPkmn_Morning
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Day::
	message Text_WelcomeWantToHealPkmn_Day
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Evening::
	message Text_WelcomeWantToHealPkmn_Evening
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Night::
	message Text_WelcomeWantToHealPkmn_Night
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Champ_Morning::
	message Text_WelcomeWantToHealPkmn_Champ_Morning
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Champ_Day::
	message Text_WelcomeWantToHealPkmn_Champ_Day
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Champ_Evening::
	message Text_WelcomeWantToHealPkmn_Champ_Evening
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_NurseIntro_Champ_Night::
	message Text_WelcomeWantToHealPkmn_Champ_Night
	waitmessage
	multichoice 19, 8, MULTI_YESNO, FALSE | (TRUE << 1)
	switch VAR_RESULT
	case 0, EventScript_PkmnCenterNurse_HealPkmn
	case 1 EventScript_PkmnCenterNurse_Goodbye
	case MULTI_B_PRESSED, EventScript_PkmnCenterNurse_Goodbye
	end

EventScript_PkmnCenterNurse_HealPkmn::
	incrementgamestat GAME_STAT_USED_POKECENTER
	message Text_TakeYourPkmnForFewSeconds
	waitmessage
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	special SetUsedPkmnCenterQuestLogEvent
	goto EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom
	end

EventScript_PkmnCenterNurse_TakeAndHealPkmn::
	hidefollower 0
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Turn
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	return

EventScript_PkmnCenterNurse_CheckTrainerTowerAndUnionRoom::
	specialvar VAR_RESULT, IsPlayerNotInTrainerTowerLobby
	goto_if_eq VAR_RESULT, FALSE, EventScript_PkmnCenterNurse_ReturnPkmn
	specialvar VAR_RESULT, BufferUnionRoomPlayerName
	copyvar VAR_0x8008, VAR_RESULT
	goto_if_eq VAR_0x8008, 0, EventScript_PkmnCenterNurse_ReturnPkmn
	goto_if_eq VAR_0x8008, 1, EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom
	end

EventScript_PkmnCenterNurse_ReturnPkmn::
	message Text_RestoredPkmnToFullHealth
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_PlayerWaitingInUnionRoom::
	goto_if_set FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER, EventScript_PkmnCenterNurse_ReturnPkmn
	msgbox Text_RestoredPkmnToFullHealth
	setflag FLAG_SYS_INFORMED_OF_LOCAL_WIRELESS_PLAYER
	message Text_PlayerIsPlayingRightNowGoForIt
	waitmessage
	applymovement VAR_LAST_TALKED, Movement_Bow
	waitmovement 0
	msgbox Text_WeHopeToSeeYouAgain
	return

EventScript_PkmnCenterNurse_Goodbye::
	msgbox Text_WeHopeToSeeYouAgain
	return

Movement_Bow::
	nurse_joy_bow
	delay_4
	step_end

Movement_PkmnCenterNurse_Turn:
	walk_in_place_faster_left
	step_end
