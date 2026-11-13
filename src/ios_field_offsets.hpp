#pragma once
#include <cstddef>
// Generated from both 2.33.1 dumps. Values are equal for these fields in both clients.
namespace vt::ios::layout {
// .FrameWork::AntiCheatListener (AntiCheatListener)
inline constexpr std::size_t FrameWork_AntiCheatListener = 0x158;
// .AntiCheatListener::_dectectHashSet (HashSet<int>)
inline constexpr std::size_t AntiCheatListener__dectectHashSet = 0x50;
// .FrameWork::sysModule (ModuleSystem)
inline constexpr std::size_t FrameWork_sysModule = 0xe8;
// .ModuleSystem::_cheatDetectDic (Dictionary<ObscuredInt, ObscuredString>)
inline constexpr std::size_t ModuleSystem__cheatDetectDic = 0x40;
// .ActorSystem::myActorCharacter (ActorCharacter)
inline constexpr std::size_t ActorSystem_myActorCharacter = 0x58;
// .ActorBase::actorControl (IActorControl)
inline constexpr std::size_t ActorBase_actorControl = 0x68;
// .ActorControl::actorBase (ActorBase)
inline constexpr std::size_t ActorControl_actorBase = 0x40;
// .ActorControl::_terminate (bool)
inline constexpr std::size_t ActorControl__terminate = 0xa8;
// .ActorMiniGameControl::<IsGoalIn>k__BackingField (bool)
inline constexpr std::size_t ActorMiniGameControl__IsGoalIn_k__BackingField = 0x2b2;
// .ActorMiniGameControl::<IsDeathInGame>k__BackingField (bool)
inline constexpr std::size_t ActorMiniGameControl__IsDeathInGame_k__BackingField = 0x2b0;
// .ActorKMGPlayer::isDie (bool)
inline constexpr std::size_t ActorKMGPlayer_isDie = 0x402;
// .ActorMiniGameControl::<IsUserWatchMode>k__BackingField (bool)
inline constexpr std::size_t ActorMiniGameControl__IsUserWatchMode_k__BackingField = 0x380;
// .ActorKMGPlayer::<CurrentCharacterState>k__BackingField (ActorKMGPlayer.eCharacterState)
inline constexpr std::size_t ActorKMGPlayer__CurrentCharacterState_k__BackingField = 0x400;
// PlayTogether.MiniGame.MiniGameKMGUnit::isCurrentSuccess (bool)
inline constexpr std::size_t MiniGameKMGUnit_isCurrentSuccess = 0x19a;
// PlayTogether.MiniGame.MiniGameKMGUnit::_targetResultStep (MiniGameKMGUnit.eResultStep)
inline constexpr std::size_t MiniGameKMGUnit__targetResultStep = 0x1c8;
// .DialogJoyStick::targetActor (ActorBase)
inline constexpr std::size_t DialogJoyStick_targetActor = 0x1f0;
// .DialogJoyStick::vehicleEnterMode (bool)
inline constexpr std::size_t DialogJoyStick_vehicleEnterMode = 0x1f8;
// .DialogJoyStick::_isSheetMusicMode (bool)
inline constexpr std::size_t DialogJoyStick__isSheetMusicMode = 0x209;
// .DialogJoyStick::onCallBackLinkAction (DialogJoyStick.CallBackLinkAction)
inline constexpr std::size_t DialogJoyStick_onCallBackLinkAction = 0x218;
// .DialogJoyStick::jumpButton (JoyStickButton)
inline constexpr std::size_t DialogJoyStick_jumpButton = 0x140;
// .MyHomeObjectManager::loadState (MyHomeObjectManager.eLoadState)
inline constexpr std::size_t MyHomeObjectManager_loadState = 0x38;
// .MyHomeObjectManager::isCloseFlow (bool)
inline constexpr std::size_t MyHomeObjectManager_isCloseFlow = 0x3c;
// .FrameWork::sysDialog (DialogSystem)
inline constexpr std::size_t FrameWork_sysDialog = 0x20;
// .MyHomeGameManager::_isReadyGame (bool)
inline constexpr std::size_t MyHomeGameManager__isReadyGame = 0x3d;
// .MyHomeGameManager::_isLoadDialogMinigameInfo (bool)
inline constexpr std::size_t MyHomeGameManager__isLoadDialogMinigameInfo = 0x48;
// .DialogMinigameSimpleInfo::buttonGameReady (UIButton)
inline constexpr std::size_t DialogMinigameSimpleInfo_buttonGameReady = 0x138;
// .DialogMinigameSimpleInfo::_isReadyState (bool)
inline constexpr std::size_t DialogMinigameSimpleInfo__isReadyState = 0x163;
// .DialogMinigameSimpleInfo::_isLock (bool)
inline constexpr std::size_t DialogMinigameSimpleInfo__isLock = 0x162;
// .DialogMinigameSimpleInfo::_useTicektGame (bool)
inline constexpr std::size_t DialogMinigameSimpleInfo__useTicektGame = 0x16c;
// .DialogMinigameSimpleInfo::_onClickGameReady (PTCallback)
inline constexpr std::size_t DialogMinigameSimpleInfo__onClickGameReady = 0x170;
// .DialogGroupPlay::button_GameReady_Member (UIButton)
inline constexpr std::size_t DialogGroupPlay_button_GameReady_Member = 0x188;
// .DialogGroupPlay::groupType (DialogGroupPlay.eGroupType)
inline constexpr std::size_t DialogGroupPlay_groupType = 0x1d4;
// .DialogGroupPlay::_useTicketGame (bool)
inline constexpr std::size_t DialogGroupPlay__useTicketGame = 0x1d8;
// PlayTogether.MiniGame.MiniGameKMGDuel::<IsStateAttack>k__BackingField (bool)
inline constexpr std::size_t MiniGameKMGDuel__IsStateAttack_k__BackingField = 0x1d8;
// PlayTogether.MiniGame.MiniGameKMGDuel::<IsCanAttack>k__BackingField (bool)
inline constexpr std::size_t MiniGameKMGDuel__IsCanAttack_k__BackingField = 0x1d9;
// PlayTogether.MiniGame.MiniGameKMGDuel::<CurRound>k__BackingField (uint)
inline constexpr std::size_t MiniGameKMGDuel__CurRound_k__BackingField = 0x1dc;
// PlayTogether.MiniGame.MiniGameKMGDuel::isEndGame (bool)
inline constexpr std::size_t MiniGameKMGDuel_isEndGame = 0x214;
// PlayTogether.MiniGame.MiniGameKMGDuel::myScore (int)
inline constexpr std::size_t MiniGameKMGDuel_myScore = 0x218;
// PlayTogether.MiniGame.MiniGameKMGDuel::_actorDuelPlayer (ActorDuelPlayer)
inline constexpr std::size_t MiniGameKMGDuel__actorDuelPlayer = 0x238;
// .ActorDuelPlayer::isStun (bool)
inline constexpr std::size_t ActorDuelPlayer_isStun = 0x3c0;
// PlayTogether.MiniGame.MiniGameKMGUnit::<KMGTableID>k__BackingField (uint)
inline constexpr std::size_t MiniGameKMGUnit__KMGTableID_k__BackingField = 0x110;
// PlayTogether.MiniGame.MiniGameUnit::currentBattleState (GameBattleState)
inline constexpr std::size_t MiniGameUnit_currentBattleState = 0x6c;
// PlayTogether.MiniGame.MiniGameKMGUnit::hideObjectManager (HideObjectManager)
inline constexpr std::size_t MiniGameKMGUnit_hideObjectManager = 0x140;
// PlayTogether.MiniGame.HideStampObjectData::<ObjectCollider>k__BackingField (Collider)
inline constexpr std::size_t HideStampObjectData__ObjectCollider_k__BackingField = 0x40;
// PlayTogether.MiniGame.HideStampObjectData::_curHideState (HideObjectState)
inline constexpr std::size_t HideStampObjectData__curHideState = 0x58;
// PlayTogether.MiniGame.HideStampObjectData::ObjectRenderer (MeshRenderer)
inline constexpr std::size_t HideStampObjectData_ObjectRenderer = 0x30;
// PlayTogether.MiniGame.HideObjectManager::BoardRootTransform (Transform)
inline constexpr std::size_t HideObjectManager_BoardRootTransform = 0xa8;
// PlayTogether.MiniGame.HideObjectManager::hideStampGameObjectList (List<HideStampObjectData>)
inline constexpr std::size_t HideObjectManager_hideStampGameObjectList = 0x40;
// PlayTogether.MiniGame.HideStampObjectData::StableStateObject (GameObject)
inline constexpr std::size_t HideStampObjectData_StableStateObject = 0x48;
// PlayTogether.MiniGame.HideObjectManager::hideGameObjectList (List<GameObject>)
inline constexpr std::size_t HideObjectManager_hideGameObjectList = 0x38;
// PlayTogether.MiniGame.HideStampObjectData::_maxStep (int)
inline constexpr std::size_t HideStampObjectData__maxStep = 0xe0;
// PlayTogether.MiniGame.MiniGameKMGTwistRoad::endPointGo (GameObject)
inline constexpr std::size_t MiniGameKMGTwistRoad_endPointGo = 0x1d8;
// PlayTogether.MiniGame.HideObjectManager::EndPoint (GameObject)
inline constexpr std::size_t HideObjectManager_EndPoint = 0xb8;
// .ActorControl::kunit (KinematicControllerUnit)
inline constexpr std::size_t ActorControl_kunit = 0xa0;
// PlayTogether.Kinematic.KinematicControllerUnit::Motor (KinematicCharacterMotor)
inline constexpr std::size_t KinematicControllerUnit_Motor = 0x20;
// KinematicCharacterController.KinematicCharacterMotor::CapsuleRadius (float)
inline constexpr std::size_t KinematicCharacterMotor_CapsuleRadius = 0x28;
// KinematicCharacterController.KinematicCharacterMotor::CapsuleHeight (float)
inline constexpr std::size_t KinematicCharacterMotor_CapsuleHeight = 0x2c;
// KinematicCharacterController.KinematicCharacterMotor::CollidableLayers (LayerMask)
inline constexpr std::size_t KinematicCharacterMotor_CollidableLayers = 0xf0;
// PlayTogether.MiniGame.MiniGameKMGFogMaze::FogManager (FowManager)
inline constexpr std::size_t MiniGameKMGFogMaze_FogManager = 0x1d8;
// PlayTogether.MiniGame.MiniGameKMGFogMaze::EndPointGo (GameObject)
inline constexpr std::size_t MiniGameKMGFogMaze_EndPointGo = 0x1e0;
// PlayTogether.MiniGame.FowManager::EndingPoint (Transform)
inline constexpr std::size_t FowManager_EndingPoint = 0x80;
// PlayTogether.MiniGame.FowManager::StartingPoint (Transform)
inline constexpr std::size_t FowManager_StartingPoint = 0x78;
// PlayTogether.MiniGame.MiniGameKMGUnit::endKeppRoot (GameObject)
inline constexpr std::size_t MiniGameKMGUnit_endKeppRoot = 0x138;
// PlayTogether.MiniGame.MiniGameKMGCrossyRoad::StageManager (CrossyRoadStageManager)
inline constexpr std::size_t MiniGameKMGCrossyRoad_StageManager = 0x1d8;
// PlayTogether.MiniGame.CrossyRoadStageManager::GoalStageRoot (Transform)
inline constexpr std::size_t CrossyRoadStageManager_GoalStageRoot = 0x20;
// PlayTogether.MiniGame.MiniGameKMGFogMaze::headUpLandMark (HeadUpLandMark)
inline constexpr std::size_t MiniGameKMGFogMaze_headUpLandMark = 0x1e8;
// PlayTogether.MiniGame.MiniGameKMGCrossyRoad::headUpLandMark (HeadUpLandMark)
inline constexpr std::size_t MiniGameKMGCrossyRoad_headUpLandMark = 0x1e0;
// PlayTogether.MiniGame.MiniGameKMGTwistRoad::headUpLandMark (HeadUpLandMark)
inline constexpr std::size_t MiniGameKMGTwistRoad_headUpLandMark = 0x1f8;
// .HeadUp::mainCamera (Camera)
inline constexpr std::size_t HeadUp_mainCamera = 0x90;
// Cinemachine.CinemachineBrain::m_OutputCamera (Camera)
inline constexpr std::size_t CinemachineBrain_m_OutputCamera = 0x50;
// .IMap::cinemachineBrain (CinemachineBrain)
inline constexpr std::size_t IMap_cinemachineBrain = 0x48;
// .ActorBase::<SUID>k__BackingField (long)
inline constexpr std::size_t ActorBase__SUID_k__BackingField = 0x28;
// .ActorMiniGameControl::<IsCanJump>k__BackingField (bool)
inline constexpr std::size_t ActorMiniGameControl__IsCanJump_k__BackingField = 0x2a9;
// .ActorDefaultControlPlayer::_isCamJump (bool)
inline constexpr std::size_t ActorDefaultControlPlayer__isCamJump = 0x4e3;
}
