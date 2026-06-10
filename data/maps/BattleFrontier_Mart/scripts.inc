# 1 "data/maps/BattleFrontier_Mart/scripts.pory"

# 2 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_MapScripts::
# 3 "data/maps/BattleFrontier_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/BattleFrontier_Mart/scripts.pory"

# 5 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Clerk::
# 6 "data/maps/BattleFrontier_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 7 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 8 "data/maps/BattleFrontier_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/BattleFrontier_Mart/scripts.pory"
	message Text_MayIHelpYou
# 10 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/BattleFrontier_Mart/scripts.pory"
	pokemart SHOP_ID_BATTLE_FRONTIER_MART
# 12 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 13 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 14 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 15 "data/maps/BattleFrontier_Mart/scripts.pory"

# 16 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldMan::
# 17 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ChaperonGrandson, MSGBOX_NPC
# 18 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 19 "data/maps/BattleFrontier_Mart/scripts.pory"

# 20 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_OldWoman::
# 21 "data/maps/BattleFrontier_Mart/scripts.pory"
	lock
# 22 "data/maps/BattleFrontier_Mart/scripts.pory"
	applymovement LOCALID_FRONTIER_MART_OLD_WOMAN, Common_Movement_FaceDown
# 23 "data/maps/BattleFrontier_Mart/scripts.pory"
	waitmovement 0
# 24 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_ProteinMakeNiceGift, MSGBOX_DEFAULT
# 25 "data/maps/BattleFrontier_Mart/scripts.pory"
	release
# 26 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 27 "data/maps/BattleFrontier_Mart/scripts.pory"

# 28 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_EventScript_Boy::
# 29 "data/maps/BattleFrontier_Mart/scripts.pory"
	msgbox BattleFrontier_Mart_Text_FacilitiesDontAllowItems, MSGBOX_NPC
# 30 "data/maps/BattleFrontier_Mart/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_Mart/scripts.pory"

# 32 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ChaperonGrandson:
# 33 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "We came here to chaperon our\n"
# 34 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "grandson.\p"
# 35 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "But since we're here, we thought\n"
# 36 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "we should get some souvenirs.$"
# 37 "data/maps/BattleFrontier_Mart/scripts.pory"

# 38 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_ProteinMakeNiceGift:
# 39 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Dear, what do you think of this?\n"
# 40 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "Wouldn't this make a nice gift?\p"
# 41 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It's…Pro…te…in?\n"
# 42 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "It sounds delicious, doesn't it?$"
# 43 "data/maps/BattleFrontier_Mart/scripts.pory"

# 44 "data/maps/BattleFrontier_Mart/scripts.pory"
BattleFrontier_Mart_Text_FacilitiesDontAllowItems:
# 45 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "A lot of the Battle Frontier's\n"
# 46 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "facilities don't allow the use of items\l"
# 47 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "during battles.\p"
# 48 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "That rule makes things tougher than\n"
# 49 "data/maps/BattleFrontier_Mart/scripts.pory"
	.string "they already are!$"
