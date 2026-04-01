#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "party_menu.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
// #include "trainer_hill.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/flags.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
// #include "constants/trainer_hill.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "trainer_slide.h"
#include "battle_message.h"

static u32 BattlerHPPercentage(enum BattlerId battler, u32 operation, u32 threshold);
static u32 GetPartyMonCount(u32 firstId, u32 lastId, enum BattleSide side, bool32 onlyAlive);
static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum BattlerId battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum BattlerId battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(enum BattlerId battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId, enum BattleSide side);
static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler, enum TrainerSlideType slideId);
static bool32 ShouldRunTrainerSlideLastSwitchIn(enum BattlerId battler);
static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler);
static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler);
static void SetTrainerSlideParameters(enum BattlerId battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue);
static bool32 IsSlideInitalizedOrPlayed(enum BattlerId battler, enum TrainerSlideType slideId);

// Partner trainers must be added as TRAINER_PARTNER(PARTNER_XXXX)
static const u8* const sTrainerSlides[DIFFICULTY_COUNT][TRAINER_PARTNER(PARTNER_COUNT)][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
        [TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Not fair!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha, ha, ha! Take that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Oh, so you know about Types.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Argh! Useless!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha ha! No chance!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: This one's stronger anyway!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Not fair!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha, ha, ha! Take that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Oh, so you know about Types.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Argh! Useless!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha ha! No chance!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: This one's stronger anyway!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Not fair!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha, ha, ha! Take that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Oh, so you know about Types.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Argh! Useless!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha ha! No chance!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: This one's stronger anyway!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_CERULEAN_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Take that! Ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Drat!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: That one's too weak!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Nice try.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Now you're done for!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_CERULEAN_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Take that! Ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Drat!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: That one's too weak!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Nice try.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Now you're done for!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_CERULEAN_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Take that! Ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Drat!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: That one's too weak!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Nice try.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Now you're done for!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SS_ANNE_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, yeah!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Hey! Stop that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: So {B_OPPONENT_MON1_NAME} couldn't cut it…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: You really think that would work?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, that's it!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SS_ANNE_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, yeah!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Hey! Stop that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: So {B_OPPONENT_MON1_NAME} couldn't cut it…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: You really think that would work?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, that's it!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SS_ANNE_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: No way!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, yeah!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Hey! Stop that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: So {B_OPPONENT_MON1_NAME} couldn't cut it…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: You really think that would work?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, that's it!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_POKEMON_TOWER_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Darn it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Haha! Serves you right!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Cut that out!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: {B_OPPONENT_MON1_NAME} is no good!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Huh? What was that?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Let's go, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_POKEMON_TOWER_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Darn it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Haha! Serves you right!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Cut that out!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: {B_OPPONENT_MON1_NAME} is no good!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Huh? What was that?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Let's go, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_POKEMON_TOWER_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Darn it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Haha! Serves you right!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Cut that out!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: {B_OPPONENT_MON1_NAME} is no good!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Huh? What was that?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Let's go, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SILPH_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: You just got lucky!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha! Critical hit!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Argh!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: I'm just getting started!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Seriously?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, you got stronger…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SILPH_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: You just got lucky!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha! Critical hit!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Argh!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: I'm just getting started!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Seriously?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, you got stronger…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_SILPH_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: You just got lucky!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Ha! Critical hit!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Argh!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: I'm just getting started!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Seriously?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Okay, you got stronger…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Rotten luck!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yeah! Now we're talking!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Ow!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Take this seriously!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: I'm not finished!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Why, I oughta…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Rotten luck!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yeah! Now we're talking!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Ow!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Take this seriously!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: I'm not finished!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Why, I oughta…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Rotten luck!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yeah! Now we're talking!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Ow!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Take this seriously!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: I'm not finished!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Why, I oughta…{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_BOSS_GIOVANNI] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: That was cunning.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: Let this be a lesson!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Giovanni: What a nuisance…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Giovanni: You have no idea who you are challenging, child.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Giovanni: You failed as soon as you challenged me.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Giovanni: What in the world was that? Don't tell me some inexperienced kid can possibly be that strong!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Giovanni: You surprise me.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Giovanni: How did you do that?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Giovanni: You cannot stop my master plan.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Giovanni: Now I'll show you a world of pain!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_BOSS_GIOVANNI_2] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: Unbelievable.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: Nothing can stop me now!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Giovanni: How dare you!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Giovanni: That's enough!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Giovanni: You still have much to learn.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Giovanni: This is as far as you go.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Giovanni: What in the world?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Giovanni: You will pay for your insolence!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Giovanni: I'll show you true power.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Giovanni: Now I'll show you a world of pain!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_BROCK] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Brock: Argh! Bad news! That bypassed our defenses!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Brock: Good job, {B_OPPONENT_MON1_NAME}! You rocked its weak spot!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Brock: Ow ow ow ow ow…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Brock: We won't let this shatter us.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Brock: You can't touch us!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Brock: Let me show you my rock-hard willpower!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Brock: You can't break us!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Brock: Our resolve is unshakable!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Brock: Let's show them your ultimate rock-solid form, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Brock: {B_OPPONENT_MON1_NAME}! Let's hit them with the full power of our rock-hard determination!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_MISTY] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Misty: Hey! What was that for?!?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Misty: There! That hit its weak spot! Surprised?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Misty: Oh, come on!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Misty: That's not going to work on us!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Misty: Hmm… You're pretty good…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Misty: We're not done yet!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Misty: Hang in there, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Misty: It's time to go all out. Let's go, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Misty: {B_OPPONENT_MON1_NAME}! It's time for our all-out offense!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_LT_SURGE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lt. Surge: No! That's an emphatic “No!” Not the weak spot!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lt. Surge: Pinpoint strike on the weak spot! Wonderful!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Lt. Surge: Arrrgh! You are strong!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Lt. Surge: Oh, no! That's no good.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Lt. Surge: What are you doing, kid?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Lt. Surge: It's not over yet. It's just beginning!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Lt. Surge: Oh, last one! Never give up!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Lt. Surge: Surrender? I don't know the meaning of the word!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Lt. Surge: This'll turn the tide of this war!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Lt. Surge: We'll zap you 'til nothing remains!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_ERIKA] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Erika: Oh, my goodness.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Erika: A critical hit! How delightful!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Erika: Oh dear, that hurt!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Erika: Oh, you are strong.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Erika: Oh, dear. That's unfortunate.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Erika: Don't go easy on me. Give me everything you've got!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Erika: One must endure.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Erika: Wow, that's a bit harsh!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Erika: I'll show you the beauty of my lovely {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Erika: We're in full bloom! Let's go, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_KOGA] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Koga: Landing a critical hit is merely a fluke, that's all!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Koga: That critical hit was by mere chance! It was nothing!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Koga: This cannot be!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Koga: Ah… You've done well, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Koga: You let your guard down!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Koga: One Pokémon left? Fwahahaha! I've been counting on this one from the very beginning!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Koga: You're powerful, but this is not over yet!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Koga: Ooooof…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Koga: Fwahahaha! You shall feel the despair of poison!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Koga: Fwahahaha! Prepare to be the victim of our sinister technique!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_SABRINA] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Sabrina: I've accounted for this in my predictions.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Sabrina: Exactly as I had predicted!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Sabrina: So you've discovered our weak spot…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Sabrina: …{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Sabrina: Just as I foresaw…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Sabrina: What will happen after this? I already know.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Sabrina: That's no good!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Sabrina: Was the future I saw…wrong?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Sabrina: Focus your mind and bend them to your will, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Sabrina: Since you wish it, I will show you my psychic powers!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_BLAINE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Blaine: Critical hit? Arrrgh… Tarnation…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Blaine: Yes! Scorched the weak spot! That's what I want!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Blaine: Guh, blast it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Blaine: Hah! I'm all fired up!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Blaine: Sorry! Bad call!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Blaine: I'll show you my blazing spirit!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Blaine: Hmm. You impress me.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Blaine: We can still do it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Blaine: Let's show them our burning ambition, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Blaine: Hyaaah! Are you ready to get burned? Let's incinerate them with our ultimate technique, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_LEADER_GIOVANNI] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: For that, I will make you feel a world of pain!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Giovanni: My power knows no bounds!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Giovanni: How dare you?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Giovanni: That's enough!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Giovanni: You cannot stop me… but I'm amused by your attempt.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Giovanni: You are pushing me to this point again?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Giovanni: What was that?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Giovanni: What in the world are you?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Giovanni: Team Rocket will be born again, and I will rule the world!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Giovanni: Now I'll show you a world of pain!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_LORELEI] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lorelei: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lorelei: Well done, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Lorelei: A powerful attack!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Lorelei: Tch! What a tough opponent.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Lorelei: You should know better than that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Lorelei: You're doing better than I expected!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Lorelei: How could this be?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Lorelei: Argh! How?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Lorelei: This is the power of my Ice-type Pokémon!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Lorelei: There's nothing you can do once you're frozen!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_BRUNO] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Bruno: Blast it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Bruno: Critical hit! That's how you do it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Bruno: Urk!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Bruno: We need to recover.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Bruno: What do you think you're doing?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Bruno: Fight as hard as you can 'til you faint!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Bruno: No! This is not over!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Bruno: We're standing firm!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Bruno: We will surpass the limits of our own strength together, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Bruno: Time to flex our muscles, {B_OPPONENT_MON1_NAME}! Hoo… Hah!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_AGATHA] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Agatha: Why, you…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Agatha: That's how it's done!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Agatha: Now that's unpleasant.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Agatha: Hmph. You're good.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Agatha: Not a good idea.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Agatha: This makes me feel young again!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Agatha: If you give up, you'll never grow as a Trainer!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Agatha: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Agatha: I'll show you how a real Trainer battles!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Agatha: Let's see how you'll handle this!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_LANCE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lance: A lucky hit, but no matter.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lance: That's how it's done!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Lance: Impressive!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Lance: I can't believe it.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Lance: My dragons are invincible!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Lance: All right! I thought this would never happen!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Lance: How could I be pushed to such a point?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Lance: I never give up, no matter what. You must be the same?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Lance: We will surpass the legends! {B_OPPONENT_MON1_NAME}, Mega Evolution!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Lance: You haven't seen our true strength yet. Let's end it with one strike, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_LORELEI_2] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lorelei: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lorelei: Well done, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Lorelei: A powerful attack!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Lorelei: Tch! What a tough opponent.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Lorelei: You should know better than that!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Lorelei: You're doing better than I expected!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Lorelei: How could this be?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Lorelei: Argh! How?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Lorelei: This is the power of my Ice-type Pokémon!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Lorelei: There's nothing you can do once you're frozen!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_BRUNO_2] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Bruno: Blast it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Bruno: Critical hit! That's how you do it!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Bruno: Urk!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Bruno: We need to recover.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Bruno: What do you think you're doing?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Bruno: Fight as hard as you can 'til you faint!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Bruno: No! This is not over!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Bruno: We're standing firm!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Bruno: We will surpass the limits of our own strength together, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Bruno: Time to flex our muscles, {B_OPPONENT_MON1_NAME}! Hoo… Hah!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_AGATHA_2] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Agatha: Why, you…{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Agatha: That's how it's done!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Agatha: Now that's unpleasant.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Agatha: Hmph. You're good.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Agatha: Not a good idea.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Agatha: This makes me feel young again!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Agatha: If you give up, you'll never grow as a Trainer!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Agatha: Not bad!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Agatha: I'll show you how a real Trainer battles!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Agatha: Let's see how you'll handle this!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_ELITE_FOUR_LANCE_2] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lance: A lucky hit, but no matter.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("Lance: That's how it's done!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("Lance: Impressive!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("Lance: I can't believe it.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("Lance: My dragons are invincible!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("Lance: All right! I see you've gotten stronger!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("Lance: How could I be pushed to such a point?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("Lance: I never give up, no matter what. You must be the same?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("Lance: We will surpass the legends! {B_OPPONENT_MON1_NAME}, Mega Evolution!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("Lance: You haven't seen our true strength yet. Let's end it with one strike, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_FIRST_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, come on{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yes! Critical hit! Ha, ha, ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Arrrgh! You jerk!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Wh-what! Wait a sec!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha! That's not working!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: What? How am I down to my last Pokémon?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: What the what?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Betcha didn't expect what's coming!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll show you why I'm the strongest Trainer in the world!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_FIRST_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, come on{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yes! Critical hit! Ha, ha, ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Arrrgh! You jerk!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Wh-what! Wait a sec!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha! That's not working!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: What? How am I down to my last Pokémon?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: What the what?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Betcha didn't expect what's coming!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll show you why I'm the strongest Trainer in the world!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_FIRST_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Oh, come on{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Yes! Critical hit! Ha, ha, ha!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: Arrrgh! You jerk!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Wh-what! Wait a sec!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Ha! That's not working!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: What? How am I down to my last Pokémon?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: What the what?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Betcha didn't expect what's coming!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll show you why I'm the strongest Trainer in the world!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_REMATCH_SQUIRTLE] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Man, that's frustrating.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: There! Yes!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Gimme a break!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Wouldn't do that if I were you.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Heh heh heh… You're unprepared for this. We'll knock you down!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Am I the one who was unprepared?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Let's show 'em how strong we are… I'm countin' on you, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll teach you just how strong I am! Here I come!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_REMATCH_BULBASAUR] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Man, that's frustrating.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: There! Yes!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Gimme a break!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Wouldn't do that if I were you.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Heh heh heh… You're unprepared for this. We'll knock you down!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Am I the one who was unprepared?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Let's show 'em how strong we are… I'm countin' on you, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll teach you just how strong I am! Here I come!{PAUSE_UNTIL_PRESS}"),
        },
        [TRAINER_CHAMPION_REMATCH_CHARMANDER] =
        {
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: Man, that's frustrating.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT] = COMPOUND_STRING("{RIVAL}: There! Yes!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT] = COMPOUND_STRING("{RIVAL}: You're kidding me!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN] = COMPOUND_STRING("{RIVAL}: Gimme a break!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_ENEMY_MON_UNAFFECTED] = COMPOUND_STRING("{RIVAL}: Wouldn't do that if I were you.{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_SWITCHIN] = COMPOUND_STRING("{RIVAL}: Heh heh heh… You're unprepared for this. We'll knock you down!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_HALF_HP] = COMPOUND_STRING("{RIVAL}: Whoa, seriously?!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_LAST_LOW_HP] = COMPOUND_STRING("{RIVAL}: Am I the one who was unprepared?{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_MEGA_EVOLUTION] = COMPOUND_STRING("{RIVAL}: Let's show 'em how strong we are… I'm countin' on you, {B_OPPONENT_MON1_NAME}!{PAUSE_UNTIL_PRESS}"),
            [TRAINER_SLIDE_Z_MOVE] = COMPOUND_STRING("{RIVAL}: I'll teach you just how strong I am! Here I come!{PAUSE_UNTIL_PRESS}"),
        },
    },
};

static const u8* const sFrontierTrainerSlides[DIFFICULTY_COUNT][FRONTIER_TRAINERS_COUNT][TRAINER_SLIDE_COUNT] =
{
    [DIFFICULTY_NORMAL] =
    {
    },
};

static const u8* const sTestTrainerSlides[DIFFICULTY_COUNT][MAX_TRAINERS_COUNT + PARTNER_COUNT][TRAINER_SLIDE_COUNT] =
{
#include "../test/battle/trainer_slides.h"
};

static u32 BattlerHPPercentage(enum BattlerId battler, u32 operation, u32 threshold)
{
    switch (operation)
    {
        case LESS_THAN:
            return gBattleMons[battler].hp < (gBattleMons[battler].maxHP / threshold);
        case EQUAL:
            return gBattleMons[battler].hp == (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN:
            return gBattleMons[battler].hp > (gBattleMons[battler].maxHP / threshold);
        case LESS_THAN_OR_EQUAL:
            return gBattleMons[battler].hp <= (gBattleMons[battler].maxHP / threshold);
        case GREATER_THAN_OR_EQUAL:
            return gBattleMons[battler].hp >= (gBattleMons[battler].maxHP / threshold);
        case NOT_EQUAL:
        default:
            return gBattleMons[battler].hp != (gBattleMons[battler].maxHP / threshold);
    }
}

static const s8 sMultiBattleOrder[] = {0, 2, 3, 1, 4, 5};

static u32 GetPartyMonCount(u32 firstId, u32 lastId, enum BattleSide side, bool32 onlyAlive)
{
    u32 count = 0;
    struct Pokemon* party = (side == B_SIDE_OPPONENT ? gEnemyParty : gPlayerParty);

    if (IsMultiBattle() && side == B_SIDE_PLAYER)
    {
        for (u32 i = firstId; i < lastId; i++)
        {
            u32 species = GetMonData(&party[sMultiBattleOrder[i]], MON_DATA_SPECIES_OR_EGG);
            if (species != SPECIES_NONE
                    && species != SPECIES_EGG
                    && (!onlyAlive || GetMonData(&party[sMultiBattleOrder[i]], MON_DATA_HP)))
            {
                count++;
            }
        }
    }
    else
    {
        for (u32 i = firstId; i < lastId; i++)
        {
            u32 species = GetMonData(&party[i], MON_DATA_SPECIES_OR_EGG);
            if (species != SPECIES_NONE
                    && species != SPECIES_EGG
                    && (!onlyAlive || GetMonData(&party[i], MON_DATA_HP)))
            {
                count++;
            }
        }
    }

    return count;
}

static const u8* const *GetTrainerSlideArray(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
#if TESTING
    return (FlagGet(TESTING_FLAG_TRAINER_SLIDES) ? sTestTrainerSlides[difficulty][trainerId] : NULL);
#else
    if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        return sFrontierTrainerSlides[difficulty][trainerId];
    else
        return sTrainerSlides[difficulty][trainerId];
#endif // TESTING
}

static bool32 DoesTrainerHaveSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    const u8* const *trainerSlides = GetTrainerSlideArray(difficulty, trainerId, slideId);
    const u8* const *trainerSlidesNormal = GetTrainerSlideArray(DIFFICULTY_NORMAL, trainerId, slideId);

#if TESTING
    if (VarGet(TESTING_VAR_TRAINER_SLIDES) == slideId)
    {
        if (trainerSlides[slideId] == NULL)
            return (trainerSlidesNormal[slideId] != NULL);
        else
            return TRUE;
    }
    else
    {
        return FALSE;
    }
#else
    if (trainerSlides[slideId] == NULL)
        return (trainerSlidesNormal[slideId] != NULL);
    else
        return TRUE;
#endif // TESTING
}

void SetTrainerSlideMessage(enum DifficultyLevel difficulty, u32 trainerId, u32 slideId)
{
    const u8* const *trainerSlides = GetTrainerSlideArray(difficulty, trainerId, slideId);
    const u8* const *trainerSlidesNormal = GetTrainerSlideArray(DIFFICULTY_NORMAL, trainerId, slideId);

    if (trainerSlides[slideId] != NULL)
        gBattleStruct->trainerSlideMsg = trainerSlides[slideId];
    else
        gBattleStruct->trainerSlideMsg = trainerSlidesNormal[slideId];
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(enum BattlerId battler, enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(battler, slideId);
}

static bool32 ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(enum BattlerId battler, enum TrainerSlideType slideId)
{
    return IsTrainerSlideInitialized(battler, slideId);
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(enum BattlerId battler, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(battler, slideId))
        return FALSE;

    if (!IsBattlerAlive(battler))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstSTABMove(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(battler, slideId))
        return FALSE;

    if (GetPartyMonCount(firstId, lastId, side, TRUE) != GetPartyMonCount(firstId, lastId, side, FALSE))
        return FALSE;

    return TRUE;
}

static bool32 ShouldRunTrainerSlidePlayerLandsFirstDown(u32 firstId, u32 lastId, enum BattleSide side)
{
    return ((GetPartyMonCount(firstId, lastId, side, TRUE) == (GetPartyMonCount(firstId, lastId, side, FALSE) - 1)));
}

static bool32 ShouldRunTrainerSlideEnemyMonUnaffected(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler, enum TrainerSlideType slideId)
{
    if (!IsTrainerSlideInitialized(battler, slideId))
        return FALSE;

    return (GetPartyMonCount(firstId, lastId, side, TRUE) == GetPartyMonCount(firstId, lastId, side, FALSE));
}

static bool32 ShouldRunTrainerSlideLastSwitchIn(enum BattlerId battler)
{
    return !CanBattlerSwitch(battler);
}

static bool32 ShouldRunTrainerSlideLastHalfHP(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler)
{
    if (GetPartyMonCount(firstId, lastId, side, TRUE) != 1)
        return FALSE;

    if (BattlerHPPercentage(battler, GREATER_THAN, 2))
        return FALSE;

    return (BattlerHPPercentage(battler, GREATER_THAN, 4));
}

static bool32 ShouldRunTrainerSlideLastLowHp(u32 firstId, u32 lastId, enum BattleSide side, enum BattlerId battler)
{
    if (GetPartyMonCount(firstId, lastId, side, TRUE) != 1)
        return FALSE;

    if (!IsBattlerAlive(battler))
        return FALSE;

    return (BattlerHPPercentage(battler, LESS_THAN_OR_EQUAL, 4));
}

static void SetTrainerSlideParameters(enum BattlerId battler, u32* firstId, u32* lastId, u32* trainerId, u32* retValue)
{
    if ((battler & BIT_SIDE) == B_SIDE_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
        {
            if (gBattlerPartyIndexes[battler] >= MULTI_PARTY_SIZE)
            {
                *firstId = MULTI_PARTY_SIZE;
                *lastId = PARTY_SIZE;
                *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                *retValue = TRAINER_SLIDE_TARGET_TRAINER_B;
            }
            else
            {
                *firstId = 0;
                *lastId = MULTI_PARTY_SIZE;
                *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
            }
        }
        else
        {
            *firstId = 0;
            *lastId = PARTY_SIZE;
            *trainerId = SanitizeTrainerId(TRAINER_BATTLE_PARAM.opponentA);
        }
    }
    else if (GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT && gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        *firstId = MULTI_PARTY_SIZE;
        *lastId = PARTY_SIZE;
        *trainerId = SanitizeTrainerId(gPartnerTrainerId);
        *retValue = TRAINER_SLIDE_TARGET_TRAINER_PARTNER;
    }
}

enum TrainerSlideTargets ShouldDoTrainerSlide(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 firstId = 0, lastId = PARTY_SIZE, trainerId = 0;
    enum BattleSide side = GetBattlerSide(battler);
    u32 retValue = TRAINER_SLIDE_TARGET_TRAINER_A;
    bool32 shouldRun = FALSE;

    if (!(gBattleTypeFlags & BATTLE_TYPE_TRAINER))
        return TRAINER_SLIDE_TARGET_NONE;

    if (!IsDoubleBattle() && (battler > B_BATTLER_1))
        return TRAINER_SLIDE_TARGET_NONE;

    SetTrainerSlideParameters(battler, &firstId, &lastId, &trainerId, &retValue);
    enum DifficultyLevel difficulty = GetCurrentDifficultyLevel();

    gBattleScripting.battler = battler;

    if (IsTrainerSlidePlayed(battler, slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    if (!DoesTrainerHaveSlideMessage(difficulty,trainerId,slideId))
        return TRAINER_SLIDE_TARGET_NONE;

    switch (slideId)
    {
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstCriticalHit(battler, slideId);
            break;
        case TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT:
            shouldRun = ShouldRunTrainerSlideEnemyLandsFirstCriticalHit(battler, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSuperEffectiveHit(battler, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstSTABMove(firstId, lastId, side, battler, slideId);
            break;
        case TRAINER_SLIDE_PLAYER_LANDS_FIRST_DOWN:
            shouldRun = ShouldRunTrainerSlidePlayerLandsFirstDown(firstId, lastId, side);
            break;
        case TRAINER_SLIDE_ENEMY_MON_UNAFFECTED:
            shouldRun = ShouldRunTrainerSlideEnemyMonUnaffected(firstId, lastId, side, battler, slideId);
            break;
        case TRAINER_SLIDE_LAST_SWITCHIN:
            shouldRun = ShouldRunTrainerSlideLastSwitchIn(battler);
            break;
        case TRAINER_SLIDE_LAST_HALF_HP:
            shouldRun = ShouldRunTrainerSlideLastHalfHP(firstId, lastId, side, battler);
            break;
        case TRAINER_SLIDE_LAST_LOW_HP:
            shouldRun = ShouldRunTrainerSlideLastLowHp(firstId, lastId, side, battler);
            break;
        case TRAINER_SLIDE_BEFORE_FIRST_TURN:
        case TRAINER_SLIDE_MEGA_EVOLUTION:
        case TRAINER_SLIDE_Z_MOVE:
        case TRAINER_SLIDE_DYNAMAX:
            shouldRun = TRUE;
            break;
        default:
            return TRAINER_SLIDE_TARGET_NONE;
    }

    if (shouldRun == FALSE)
        return TRAINER_SLIDE_TARGET_NONE;

    // Prevents slides triggering twice in single-trainer doubles (B == A / B == TRAINER_NONE) and 2v1 multibattles (B == 0xFFFF)
    if (((TRAINER_BATTLE_PARAM.opponentB == TRAINER_BATTLE_PARAM.opponentA)
     || (TRAINER_BATTLE_PARAM.opponentB == TRAINER_NONE)
     || (TRAINER_BATTLE_PARAM.opponentB == 0xFFFF)))
    {
        MarkTrainerSlideAsPlayed(BATTLE_PARTNER(battler), slideId);
    }

    MarkTrainerSlideAsPlayed(battler, slideId);
    SetTrainerSlideMessage(difficulty,trainerId,slideId);
    return retValue;
}

static bool32 IsSlideInitalizedOrPlayed(enum BattlerId battler, enum TrainerSlideType slideId)
{
    if (IsTrainerSlideInitialized(battler, slideId))
        return TRUE;

    if (IsTrainerSlidePlayed(battler, slideId))
        return TRUE;

    return FALSE;
}

void TryInitializeFirstSTABMoveTrainerSlide(enum BattlerId battlerDef, enum BattlerId battlerAtk, enum Type moveType)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_STAB_MOVE;

    if (IsSlideInitalizedOrPlayed(battlerDef, slideId))
        return;

    if ((IsOnPlayerSide(battlerDef)))
        return;

    if (IS_BATTLER_OF_TYPE(battlerAtk, moveType) == FALSE)
        return;

    InitalizeTrainerSlide(battlerDef, slideId);
}

void TryInitializeTrainerSlidePlayerLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(target, slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(target, slideId);
}

void TryInitializeTrainerSlideEnemyLandsFirstCriticalHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_LANDS_FIRST_CRITICAL_HIT;

    if (IsSlideInitalizedOrPlayed(gBattlerAttacker, slideId))
        return;

    if (!IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(gBattlerAttacker, slideId);
}

void TryInitializeTrainerSlidePlayerLandsFirstSuperEffectiveHit(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_PLAYER_LANDS_FIRST_SUPER_EFFECTIVE_HIT;

    if (IsSlideInitalizedOrPlayed(target, slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(target, slideId);
}

void TryInitializeTrainerSlideEnemyMonUnaffected(u32 target)
{
    enum TrainerSlideType slideId = TRAINER_SLIDE_ENEMY_MON_UNAFFECTED;

    if (IsSlideInitalizedOrPlayed(target, slideId))
        return;

    if (IsOnPlayerSide(target))
        return;

    InitalizeTrainerSlide(target, slideId);
}

bool32 IsTrainerSlideInitialized(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messageInitalized[battler][arrayIndex] & (1 << bitPosition)) != 0;
}

bool32 IsTrainerSlidePlayed(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    return (gBattleStruct->slideMessageStatus.messagePlayed[battler][arrayIndex] & (1 << bitPosition)) != 0;
}

void InitalizeTrainerSlide(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messageInitalized[battler][arrayIndex] |= (1 << bitPosition);
}

void MarkInitializedTrainerSlidesAsPlayed(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    if (IsTrainerSlideInitialized(battler, slideId) && !IsTrainerSlidePlayed(battler, slideId))
        gBattleStruct->slideMessageStatus.messagePlayed[battler][arrayIndex] |= (1 << bitPosition);
}

void MarkTrainerSlideAsPlayed(enum BattlerId battler, enum TrainerSlideType slideId)
{
    u32 arrayIndex = slideId / TRAINER_SLIDES_PER_ARRAY;
    u32 bitPosition = slideId % TRAINER_SLIDES_PER_ARRAY;

    gBattleStruct->slideMessageStatus.messagePlayed[battler][arrayIndex] |= (1 << bitPosition);
}
