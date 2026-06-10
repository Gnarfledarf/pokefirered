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
	pokemart SHOP_ID_CELADON_CITY_DEPARTMENT_STORE_5F_XITEMS
# 24 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 25 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 26 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
# 27 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"

# 28 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
CeladonCity_DepartmentStore_5F_EventScript_ClerkVitamins::
# 29 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 30 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	lock
# 31 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	faceplayer
# 32 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	message Text_MayIHelpYou
# 33 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	waitmessage
# 34 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	pokemart SHOP_ID_CELADON_CITY_DEPARTMENT_STORE_5F_VITAMINS
# 35 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	msgbox Text_PleaseComeAgain
# 36 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	release
# 37 "data/maps/CeladonCity_DepartmentStore_5F/scripts.pory"
	end
