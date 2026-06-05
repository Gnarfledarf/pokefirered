EventScript_ChangeDeoxysForm::
	lockall
	checkspecies SPECIES_DEOXYS, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm_Check
	checkspecies SPECIES_DEOXYS_ATTACK, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm_Check
	checkspecies SPECIES_DEOXYS_DEFENSE, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm_Check
	checkspecies SPECIES_DEOXYS_SPEED, NO_PARTY_SCREEN
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm_Check
	goto ChangeDeoxysForm_MeteoriteFromTheStars

ChangeDeoxysForm_End:
	releaseall
	end

ChangeDeoxysForm_Check:
	msgbox ChangeDeoxysForm_Text_Beginning, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq ChangeDeoxysForm_Start
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Start:
	msgbox ChangeDeoxysForm_Text_Select, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq ChangeDeoxysForm_End
	special TryChangeDeoxysForm
	compare VAR_RESULT, TRUE
	goto_if_eq ChangeDeoxysForm_Success
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Success:
	playmoncry SPECIES_DEOXYS, 0
	msgbox ChangeDeoxysForm_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitbuttonpress
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_MeteoriteFromTheStars::
    msgbox ChangeDeoxysForm_Text_MeteoriteFromTheStars, MSGBOX_DEFAULT
    releaseall
    end

ChangeDeoxysForm_Text_Beginning:
    .string "Deoxys seems to have taken an\n"
    .string "interest in this meteorite.\p"
    .string "Let Deoxys touch the meteorite?$"

ChangeDeoxysForm_Text_Select:
	.string "Please select Deoxys.$"

ChangeDeoxysForm_Text_Success:
    .string "Touching the meteorite changed\n"
    .string "the form and attributes of Deoxys.$"

ChangeDeoxysForm_Text_MeteoriteFromTheStars::
    .string "It's a mysterious meteorite that\n"
    .string "fell from the stars…$"
