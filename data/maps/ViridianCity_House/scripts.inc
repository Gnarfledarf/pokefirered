# 1 "data/maps/ViridianCity_House/scripts.pory"

# 2 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_MapScripts::
# 3 "data/maps/ViridianCity_House/scripts.pory"
	.byte 0
# 4 "data/maps/ViridianCity_House/scripts.pory"

# 5 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_BaldingMan::
# 6 "data/maps/ViridianCity_House/scripts.pory"
	lock
# 7 "data/maps/ViridianCity_House/scripts.pory"
	faceplayer
# 8 "data/maps/ViridianCity_House/scripts.pory"
	goto_if_unset FLAG_SYS_POKEDEX_GET, ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak
# 9 "data/maps/ViridianCity_House/scripts.pory"
	goto_if_set FLAG_GOT_SHARP_BEAK_IN_VIRIDIAN_CITY_HOUSE, ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak
# 10 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_DoYouHaveSpearow
# 11 "data/maps/ViridianCity_House/scripts.pory"
	check_if_species_caught SPECIES_SPEAROW
# 12 "data/maps/ViridianCity_House/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ViridianCity_House_EventScript_BaldingMan_CaughtSpearow
# 13 "data/maps/ViridianCity_House/scripts.pory"
	end
# 14 "data/maps/ViridianCity_House/scripts.pory"

# 15 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_BaldingMan_CaughtSpearow::
# 16 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_YouHaveCaughtSpearow, MSGBOX_NPC
# 17 "data/maps/ViridianCity_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 18 "data/maps/ViridianCity_House/scripts.pory"
	checkitemspace ITEM_SHARP_BEAK
# 19 "data/maps/ViridianCity_House/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 20 "data/maps/ViridianCity_House/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SHARP_BEAK
# 21 "data/maps/ViridianCity_House/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 22 "data/maps/ViridianCity_House/scripts.pory"
	message Text_ObtainedTheX
# 23 "data/maps/ViridianCity_House/scripts.pory"
	waitmessage
# 24 "data/maps/ViridianCity_House/scripts.pory"
	waitfanfare
# 25 "data/maps/ViridianCity_House/scripts.pory"
	additem ITEM_SHARP_BEAK
# 26 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_SharpBeakAway
# 27 "data/maps/ViridianCity_House/scripts.pory"
	call EventScript_RestorePrevTextColor
# 28 "data/maps/ViridianCity_House/scripts.pory"
	setflag FLAG_GOT_SHARP_BEAK_IN_VIRIDIAN_CITY_HOUSE
# 29 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_ItMakesFlyingTypeATtacksMorePowerful, MSGBOX_NPC
# 30 "data/maps/ViridianCity_House/scripts.pory"
	release
# 31 "data/maps/ViridianCity_House/scripts.pory"
	end
# 32 "data/maps/ViridianCity_House/scripts.pory"

# 33 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_BaldingMan_AlreadyGotSharpBeak::
# 34 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_NicknamingIsFun, MSGBOX_NPC
# 35 "data/maps/ViridianCity_House/scripts.pory"
	release
# 36 "data/maps/ViridianCity_House/scripts.pory"
	end
# 37 "data/maps/ViridianCity_House/scripts.pory"

# 38 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_LittleGirl::
# 39 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_MyDaddyLovesMonsToo, MSGBOX_NPC
# 40 "data/maps/ViridianCity_House/scripts.pory"
	end
# 41 "data/maps/ViridianCity_House/scripts.pory"

# 42 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_Speary::
# 43 "data/maps/ViridianCity_House/scripts.pory"
	lock
# 44 "data/maps/ViridianCity_House/scripts.pory"
	faceplayer
# 45 "data/maps/ViridianCity_House/scripts.pory"
	waitse
# 46 "data/maps/ViridianCity_House/scripts.pory"
	playmoncry SPECIES_SPEAROW, CRY_MODE_NORMAL
# 47 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_Speary
# 48 "data/maps/ViridianCity_House/scripts.pory"
	waitmoncry
# 49 "data/maps/ViridianCity_House/scripts.pory"
	release
# 50 "data/maps/ViridianCity_House/scripts.pory"
	end
# 51 "data/maps/ViridianCity_House/scripts.pory"

# 52 "data/maps/ViridianCity_House/scripts.pory"
ViridianCity_House_EventScript_NicknameSign::
# 53 "data/maps/ViridianCity_House/scripts.pory"
	msgbox ViridianCity_House_Text_SpearowNameSpeary, MSGBOX_SIGN
# 54 "data/maps/ViridianCity_House/scripts.pory"
	end
