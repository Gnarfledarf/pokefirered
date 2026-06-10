# 1 "data/maps/FuchsiaCity_Mart/scripts.pory"

# 2 "data/maps/FuchsiaCity_Mart/scripts.pory"
FuchsiaCity_Mart_MapScripts::
# 3 "data/maps/FuchsiaCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FuchsiaCity_Mart/scripts.pory"

# 5 "data/maps/FuchsiaCity_Mart/scripts.pory"
FuchsiaCity_Mart_EventScript_CooltrainerF::
# 6 "data/maps/FuchsiaCity_Mart/scripts.pory"
	msgbox FuchsiaCity_Mart_Text_DidYouTryXSpeed, MSGBOX_NPC
# 7 "data/maps/FuchsiaCity_Mart/scripts.pory"
	end
# 8 "data/maps/FuchsiaCity_Mart/scripts.pory"

# 9 "data/maps/FuchsiaCity_Mart/scripts.pory"
FuchsiaCity_Mart_EventScript_Gentleman::
# 10 "data/maps/FuchsiaCity_Mart/scripts.pory"
	msgbox FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants, MSGBOX_NPC
# 11 "data/maps/FuchsiaCity_Mart/scripts.pory"
	end
# 12 "data/maps/FuchsiaCity_Mart/scripts.pory"

# 13 "data/maps/FuchsiaCity_Mart/scripts.pory"
FuchsiaCity_Mart_EventScript_Clerk::
# 14 "data/maps/FuchsiaCity_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 15 "data/maps/FuchsiaCity_Mart/scripts.pory"
	lock
# 16 "data/maps/FuchsiaCity_Mart/scripts.pory"
	faceplayer
# 17 "data/maps/FuchsiaCity_Mart/scripts.pory"
	message Text_MayIHelpYou
# 18 "data/maps/FuchsiaCity_Mart/scripts.pory"
	waitmessage
# 19 "data/maps/FuchsiaCity_Mart/scripts.pory"
	pokemart SHOP_ID_FUCHSIA_CITY_MART
# 20 "data/maps/FuchsiaCity_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 21 "data/maps/FuchsiaCity_Mart/scripts.pory"
	release
# 22 "data/maps/FuchsiaCity_Mart/scripts.pory"
	end
