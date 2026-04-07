# 1 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 2 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_MapScripts::
# 3 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
# 4 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.byte 0
# 5 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 6 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_OnTransition:
# 7 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
# 8 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
# 9 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 10 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 11 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FerryAttendant::
# 12 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 13 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 14 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
# 15 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	checkitem ITEM_SS_TICKET
# 16 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
# 17 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
# 18 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 19 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_NAVEL_ROCK
# 20 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	multichoice 20, 8, MULTI_SEAGALLOP_VERMILION, FALSE
# 21 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	switch VAR_RESULT
# 22 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 0, EventScript_SailToVermilionCity
# 23 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case 1, EventScript_CancelSail
# 24 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 25 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 26 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 27 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_NoSSTicket::
# 28 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
# 29 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 30 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 31 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 32 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
# 33 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
# 34 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 35 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 36 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
# 37 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
# 38 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 39 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 40 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
# 41 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
# 42 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 43 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 44 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused. Of note, Battle Tower is in the East section in the final release
# 45 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
# 46 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
# 47 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 48 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 49 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 50 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
# 51 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
# 52 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 53 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 54 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy1::
# 55 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
# 56 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 57 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 58 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman2::
# 59 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 60 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 61 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
# 62 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 63 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_FISHERMAN_2, Common_Movement_FaceAwayPlayer
# 64 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 65 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 66 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 67 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 68 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 69 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man1::
# 70 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
# 71 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 72 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 73 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac1::
# 74 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 75 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 76 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 77 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 78 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Maniac2::
# 79 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 80 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
# 81 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 82 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 83 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
# 84 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
# 85 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 86 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
# 87 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
# 88 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 89 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
# 90 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 91 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 25
# 92 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
# 93 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
# 94 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 95 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 96 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 97 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 98 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Camper::
# 99 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 100 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 101 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 20
# 102 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 103 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
# 104 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 105 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
# 106 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
# 107 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 108 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 109 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 110 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
# 111 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_CAMPER, Common_Movement_WalkInPlaceFasterUp
# 112 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 113 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 114 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 115 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
# 116 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 117 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 118 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Girl::
# 119 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 120 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 121 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
# 122 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmessage
# 123 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
# 124 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
# 125 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
# 126 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
# 127 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitbuttonpress
# 128 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 129 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 130 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 131 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
# 132 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
# 133 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 134 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 135 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 136 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
# 137 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
# 138 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 139 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 140 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 141 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
# 142 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
# 143 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 144 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 145 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 146 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
# 147 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
# 148 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 149 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 150 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 151 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
# 152 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 153 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 154 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 155 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 156 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
# 157 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 158 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_up
# 159 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 160 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 161 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderWest:
# 162 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 163 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_right
# 164 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 165 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 166 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Movement_GirlShudderEast:
# 167 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 168 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_left
# 169 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 170 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 171 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman2::
# 172 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 173 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 174 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
# 175 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	random 2
# 176 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
# 177 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
# 178 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 179 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 180 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
# 181 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
# 182 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 183 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 184 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 185 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
# 186 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
# 187 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 188 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 189 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 190 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Fisherman1::
# 191 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
# 192 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 193 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 194 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
@ Unused
# 195 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
# 196 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
# 197 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 198 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 199 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Gentleman::
# 200 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
# 201 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 202 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 203 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Lass::
# 204 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
# 205 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 206 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 207 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_ExpertM::
# 208 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
# 209 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 210 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 211 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man2::
# 212 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
# 213 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 214 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 215 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman1::
# 216 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
# 217 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 218 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 219 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan1::
# 220 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
# 221 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 222 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 223 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_FatMan2::
# 224 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
# 225 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 226 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 227 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Woman3::
# 228 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 229 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
# 230 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 231 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 232 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 233 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Boy2::
# 234 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 235 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
# 236 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 237 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 238 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 239 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_OldMan::
# 240 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
# 241 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 242 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 243 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man4::
# 244 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	lock
# 245 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	faceplayer
# 246 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
# 247 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	closemessage
# 248 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_FRONTIER_MAN_4, Common_Movement_FaceOriginalDirection
# 249 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 250 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	release
# 251 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 252 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 253 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_PokefanF::
# 254 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
# 255 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 256 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 257 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_EventScript_Man3::
# 258 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	msgbox BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier, MSGBOX_NPC
# 259 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	end
# 260 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 261 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Common_EventScript_FerryDepartIsland::
# 262 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
# 263 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
# 264 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 30
# 265 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	hideplayer
# 266 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	call Common_EventScript_FerryDepart
# 267 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 268 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 269 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Ferry_EventScript_DepartIslandSouth::
# 270 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardSouth
# 271 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 272 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 273 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 274 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Ferry_EventScript_DepartIslandWest::
# 275 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement LOCALID_PLAYER, Ferry_Movement_DepartIslandBoardWest
# 276 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 277 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 278 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 279 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Ferry_Movement_DepartIslandBoardSouth:
# 280 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_down
# 281 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 282 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 283 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Ferry_Movement_DepartIslandBoardWest:
# 284 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_left
# 285 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_in_place_faster_down
# 286 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 287 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 288 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Common_EventScript_FerryDepart::
# 289 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	delay 60
# 290 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	applymovement VAR_0x8004, Movement_FerryDepart
# 291 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	waitmovement 0
# 292 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	return
# 293 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 294 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
Movement_FerryDepart:
# 295 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_slow_right
# 296 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_slow_right
# 297 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_slow_right
# 298 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_right
# 299 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_right
# 300 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_right
# 301 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	walk_right
# 302 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	step_end
# 303 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 304 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleDomeSign:
# 305 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the Battle Dome!\n"
# 306 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Your path to the invincible superstar!$"
# 307 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 308 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattleFactorySign:
# 309 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the Battle Factory!\n"
# 310 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Seek out the toughest Pokémon!$"
# 311 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 312 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BattlePikeSign:
# 313 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the Battle Pike!\n"
# 314 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Choose one of three paths!$"
# 315 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 316 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
# 317 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This is the Battle Tower.\p"
# 318 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Trainers bring their best-raised\n"
# 319 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pokémon for elimination-style matches.$"
# 320 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 321 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
# 322 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hello, are you here for the ferry?\n"
# 323 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "May I see your Ticket?$"
# 324 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 325 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
# 326 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} doesn't have the Ticket…\p"
# 327 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm terribly sorry.\p"
# 328 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You must have a Ticket to board\n"
# 329 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the ferry.$"
# 330 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 331 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
# 332 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "{PLAYER} flashed the Ticket.\p"
# 333 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Perfect! That's all you need!\p"
# 334 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "And where would you like to go?$"
# 335 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 336 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SlateportItIs:
# 337 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Slateport City it is, then!$"
# 338 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 339 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LilycoveItIs:
# 340 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Lilycove City it is, then!$"
# 341 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 342 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
# 343 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please sail with us another time!$"
# 344 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 345 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
# 346 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Please board the ferry and wait for\n"
# 347 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "departure.$"
# 348 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 349 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
# 350 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Then, where would you like to go?$"
# 351 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 352 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
# 353 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm the best out of all my friends.\n"
# 354 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But here…\l"
# 355 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've been useless!$"
# 356 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 357 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_CantFindBattleTower:
# 358 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I want to go to the Battle Tower,\n"
# 359 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "but I can't find it even though I have\l"
# 360 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a map of the Battle Frontier.\p"
# 361 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "This place is just too big!$"
# 362 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 363 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
# 364 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I wanted to take a challenge as soon\n"
# 365 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "as I arrived here.\p"
# 366 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But on the way, I got seasick…\n"
# 367 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Urrrrp…$"
# 368 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 369 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
# 370 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's not as if just anyone can come\n"
# 371 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "here, you know?\p"
# 372 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Only those Trainers who've been\n"
# 373 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "recognized as tough are brought here.\p"
# 374 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's why many Trainers don't even\n"
# 375 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "know about the Battle Frontier.$"
# 376 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 377 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
# 378 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Hey, bro…\p"
# 379 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Are you sure we can make challenges\n"
# 380 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "even if we don't have any Pokémon?$"
# 381 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 382 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
# 383 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Uh…\n"
# 384 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure it'll be okay.\p"
# 385 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I think…\p"
# 386 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But remember that big scary guy?\n"
# 387 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "He said, “I'll lend you Pokémon!”$"
# 388 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 389 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
# 390 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's the Battle Factory.\n"
# 391 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You can rent strong Pokémon there.\p"
# 392 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But it makes me wonder.\n"
# 393 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Who's raising those rental Pokémon?$"
# 394 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 395 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
# 396 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm scared of going into the Battle\n"
# 397 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pike because of Seviper…\p"
# 398 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "B-but I came all the way here, so I will\n"
# 399 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "try to conquer everything!\l"
# 400 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "…Shudder…$"
# 401 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 402 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
# 403 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let's play rock, paper, scissors!\n"
# 404 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "One, two, three!\p"
# 405 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "… … … … … …$"
# 406 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 407 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
# 408 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Yay! I won!\n"
# 409 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I will take the Battle Pike challenge!$"
# 410 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 411 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
# 412 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, no…\n"
# 413 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I lost.\p"
# 414 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I guess I'm not very lucky today.\n"
# 415 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll put off my Battle Pike challenge\l"
# 416 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "until tomorrow.$"
# 417 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 418 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
# 419 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I believe I'm the only person here who,\n"
# 420 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "for some unknown reason, would choose\l"
# 421 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "fishing over battling.\p"
# 422 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? You can't catch anything here?\n"
# 423 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's disappointing…$"
# 424 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 425 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
# 426 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Today, I'm going to keep battling, no\n"
# 427 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "matter what, until I get a Symbol.$"
# 428 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 429 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
# 430 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh? You're off to challenge\n"
# 431 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "the Battle Dome?\p"
# 432 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll wish you the best of luck.\n"
# 433 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Let us both win our way up and meet\l"
# 434 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in challenges.$"
# 435 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 436 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
# 437 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Grandpa, over here!\n"
# 438 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The Battle Dome is here!\l"
# 439 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Go get 'em, Grandpa!$"
# 440 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 441 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
# 442 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Ah, so this here is the Battle Dome?\n"
# 443 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I won't let Gentlemen beat me!\p"
# 444 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But where is the entrance?$"
# 445 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 446 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
# 447 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "There used to be nothing here not all\n"
# 448 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "that long ago.\p"
# 449 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But, now look at this place! Amazing!\n"
# 450 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'll bring my mother out to see this.$"
# 451 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 452 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
# 453 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've finally arrived at the Battle\n"
# 454 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Frontier!\p"
# 455 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I'm sure to grab attention with\n"
# 456 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "my looks and ability!$"
# 457 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 458 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
# 459 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…\p"
# 460 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It looks like this square's filled with\n"
# 461 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "tough people.\p"
# 462 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Munch, munch…$"
# 463 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 464 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
# 465 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 466 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "A while back, I met this older girl\n"
# 467 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "at the Battle Pike.\p"
# 468 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She had these eyes that were scary\n"
# 469 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "in a real ornery way.\p"
# 470 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…\p"
# 471 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "She got all furious: “Will you quit\n"
# 472 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "eating!” Then she whaled on me.\p"
# 473 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It was a hair-raising kind of\n"
# 474 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "scary experience, sure enough.\p"
# 475 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Crunch, munch…$"
# 476 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 477 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
# 478 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Huh? Will you listen to yourself?\n"
# 479 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That's nothing!\p"
# 480 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Why, the last time I cheered for him,\n"
# 481 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "our eyes met and sparks flew!$"
# 482 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 483 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
# 484 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Whaaaaaat?!\n"
# 485 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Pfft!\p"
# 486 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "That only happened because\n"
# 487 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I happened to be sitting next to you!\p"
# 488 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The Dome Ace only looked our way\n"
# 489 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "because my cheering was so loud!$"
# 490 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 491 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_DomeAceIsMine:
# 492 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, shush!\n"
# 493 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Keep that racket down!\p"
# 494 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "You fair-weather fans should stick\n"
# 495 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to cheering for some Gym Leader!\p"
# 496 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The Dome Ace is mine!\n"
# 497 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The only idol for me!$"
# 498 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 499 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
# 500 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Those people squabbling over there…\p"
# 501 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It's hard to believe, but they once\n"
# 502 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "were Trainers, and good ones, too.\p"
# 503 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They used to be incredibly tough,\n"
# 504 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "and they were famous, too.\p"
# 505 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "But they were obliterated by this\n"
# 506 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "certain Trainer at a tournament.\p"
# 507 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They were so thoroughly whipped,\n"
# 508 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "they became smitten by the Trainer.\p"
# 509 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Now they're just fans of the Trainer.\n"
# 510 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "They go cheer for their idol at the\l"
# 511 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Battle Dome every day now.$"
# 512 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 513 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
# 514 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I heard a rumor that someone saw\n"
# 515 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "a Pokémon with an unusually long tail\l"
# 516 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "somewhere in the Battle Frontier.\p"
# 517 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "It must be adorable. I'm sure of it…\p"
# 518 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "Oh, challenges can wait. I feel driven\n"
# 519 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "to find the delightful creature!$"
# 520 "data/maps/BattleFrontier_OutsideWest/scripts.pory"

# 521 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
BattleFrontier_OutsideWest_Text_LongDreamedAboutBattleFrontier:
# 522 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "The Battle Frontier…\n"
# 523 "data/maps/BattleFrontier_OutsideWest/scripts.pory"
	.string "I've long dreamed about a place like it.$"
