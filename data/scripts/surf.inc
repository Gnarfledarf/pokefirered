EventScript_UseSurf::
	goto_if_questlog EventScript_UseSurfEnd
	checkfieldmoveusable FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, FALSE, EventScript_UseSurfEnd
	checkitem ITEM_HM03, 1
	goto_if_eq VAR_RESULT, FALSE, EventScript_UseSurfEnd
	playse SE_SELECT
	lockall
	goto_if_set FLAG_SYS_USE_SURF, EventScript_UseSurfQuick
	msgbox Text_WantToSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_UseSurfRelease
	msgbox Text_UsedSurf
EventScript_UseSurfQuick:
	dofieldeffect FLDEFF_USE_SURF
EventScript_UseSurfRelease:
	releaseall
EventScript_UseSurfEnd:
	end

EventScript_CurrentTooFast::
	lockall
	checkfieldmoveusable FIELD_MOVE_SURF
	goto_if_eq VAR_RESULT, FALSE, EventScript_CurrentTooFastEndMsg
	playse SE_SELECT
	msgbox Text_CurrentTooFast
EventScript_CurrentTooFastEndMsg::
	releaseall
	end
