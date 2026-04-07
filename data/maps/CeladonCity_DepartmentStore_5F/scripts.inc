# 1 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 2 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_MapScripts::
# 3 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.byte 0
# 4 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 5 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_Gentleman::
# 6 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_ExplainStatEnhancers, MSGBOX_NPC
# 7 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 8 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 9 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_Sailor::
# 10 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_HereForStatEnhancers, MSGBOX_NPC
# 11 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 12 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 13 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_FloorSign::
# 14 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox CeladonCity_DepartmentStore_5F_Text_Drugstore, MSGBOX_SIGN
# 15 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 16 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 17 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_ClerkXItems::
# 18 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 19 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	lock
# 20 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 21 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	message Text_MayIHelpYou
# 22 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 23 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	pokemart CeladonCity_DepartmentStore_5F_XItems
# 24 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 25 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 26 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 27 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 28 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 29 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_XItems::
# 30 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 31 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_DEFEND
# 32 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_SPEED
# 33 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 34 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_SP_DEF
# 35 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 36 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 37 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 38 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_NONE
# 39 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 40 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 41 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 42 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
# 43 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 44 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	lock
# 45 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 46 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	message Text_MayIHelpYou
# 47 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 48 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	pokemart CeladonCity_DepartmentStore_5F_Vitamins
# 49 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 50 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 51 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 52 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 53 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.align 2
# 54 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_Vitamins::
# 55 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_HP_UP
# 56 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_PROTEIN
# 57 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_IRON
# 58 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_CALCIUM
# 59 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_ZINC
# 60 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_CARBOS
# 61 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	.2byte ITEM_NONE
# 62 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 63 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
