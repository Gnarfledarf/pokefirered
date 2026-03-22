#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "follower_npc.h"
#include "overworld.h"
#include "party_menu.h"
#include "script.h"
#include "sound.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/maps.h"
#include "constants/metatile_behaviors.h"
#include "constants/songs.h"

static void FieldCallback_UseHeadbutt(void);
static void StartHeadbuttFieldEffect(void);
static void FieldCallback_HeadbuttSudowoodo(void);

bool8 CheckObjectGraphicsInFrontOfPlayer(u16 graphicsId)
{
    u8 mapObjId;

    GetXYCoordsOneStepInFrontOfPlayer(&gPlayerFacingPosition.x, &gPlayerFacingPosition.y);
    gPlayerFacingPosition.elevation = PlayerGetElevation();
    mapObjId = GetObjectEventIdByPosition(gPlayerFacingPosition.x, gPlayerFacingPosition.y, gPlayerFacingPosition.elevation);
    if (gObjectEvents[mapObjId].graphicsId != graphicsId)
        return FALSE;
    gSpecialVar_LastTalked = gObjectEvents[mapObjId].localId;
    return TRUE;
}

// Called when Headbutt is used from the party menu
// For interacting with a headbuttable tree in the field, see EventScript_Headbutt
bool32 FieldMove_SetUpHeadbutt(void)
{
    s16 x, y;
    u8 elevation;
    u8 objId;
    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);
    elevation = PlayerGetElevation();
    objId = GetObjectEventIdByPosition(x, y, elevation);
    if (MapGridGetMetatileBehaviorAt(x, y) == MB_HEADBUTT)
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_UseHeadbutt;
        return TRUE;
    }
    else if (gObjectEvents[objId].graphicsId == OBJ_EVENT_GFX_SUDOWOODO
     && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAP_FIVE_ISLAND_MEADOW)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAP_FIVE_ISLAND_MEADOW))
    {
        gFieldCallback2 = FieldCallback_PrepareFadeInFromMenu;
        gPostMenuFieldCallback = FieldCallback_HeadbuttSudowoodo;
        return TRUE;
    }
    return FALSE;
}

static void FieldCallback_UseHeadbutt(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(EventScript_UseHeadbutt);
}

u32 FldEff_UseHeadbutt(void)
{
    u8 taskId = CreateFieldEffectShowMon();

    FLDEFF_SET_FUNC_TO_DATA(StartHeadbuttFieldEffect);
    IncrementGameStat(GAME_STAT_USED_HEADBUTT);
    return FALSE;
}

// The important part is handled by EventScript_Headbutt
static void StartHeadbuttFieldEffect(void)
{
    PlaySE(SE_NOT_EFFECTIVE);
    FieldEffectActiveListRemove(FLDEFF_USE_HEADBUTT);
    ScriptContext_Enable();
}

static void FieldCallback_HeadbuttSudowoodo(void)
{
    gFieldEffectArguments[0] = GetCursorSelectionMonId();
    ScriptContext_SetupScript(FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo);
}
