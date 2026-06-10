# 1 "data/maps/VermilionCity_Mart/scripts.pory"

# 2 "data/maps/VermilionCity_Mart/scripts.pory"
VermilionCity_Mart_MapScripts::
# 3 "data/maps/VermilionCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/VermilionCity_Mart/scripts.pory"

# 5 "data/maps/VermilionCity_Mart/scripts.pory"
VermilionCity_Mart_EventScript_CooltrainerF::
# 6 "data/maps/VermilionCity_Mart/scripts.pory"
	msgbox VermilionCity_Mart_Text_MonsGoodOrBadDependingOnTrainer, MSGBOX_NPC
# 7 "data/maps/VermilionCity_Mart/scripts.pory"
	end
# 8 "data/maps/VermilionCity_Mart/scripts.pory"

# 9 "data/maps/VermilionCity_Mart/scripts.pory"
VermilionCity_Mart_EventScript_BaldingMan::
# 10 "data/maps/VermilionCity_Mart/scripts.pory"
	msgbox VermilionCity_Mart_Text_TeamRocketAreWickedPeople, MSGBOX_NPC
# 11 "data/maps/VermilionCity_Mart/scripts.pory"
	end
# 12 "data/maps/VermilionCity_Mart/scripts.pory"

# 13 "data/maps/VermilionCity_Mart/scripts.pory"
VermilionCity_Mart_EventScript_Clerk::
# 14 "data/maps/VermilionCity_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 15 "data/maps/VermilionCity_Mart/scripts.pory"
	lock
# 16 "data/maps/VermilionCity_Mart/scripts.pory"
	faceplayer
# 17 "data/maps/VermilionCity_Mart/scripts.pory"
	message Text_MayIHelpYou
# 18 "data/maps/VermilionCity_Mart/scripts.pory"
	waitmessage
# 19 "data/maps/VermilionCity_Mart/scripts.pory"
	pokemart SHOP_ID_VERMILION_CITY_MART
# 20 "data/maps/VermilionCity_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 21 "data/maps/VermilionCity_Mart/scripts.pory"
	release
# 22 "data/maps/VermilionCity_Mart/scripts.pory"
	end
