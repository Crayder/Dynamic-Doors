/*------------------------------*\_______________________________
Dynamic Door Include, By: Crayder_______________________________|
\*------------------------------*/

/*
	CreateDynamicDoor
	_______________________________________________________________________________________________
	
	model				Object ID, like CreateObject.
	type				Door's type, Teleporting, Rotating, and Sliding.
	Float:X				The X coord in which the door is built.
	Float:Y				The Y coord in which the door is built.
	Float:Z				The Z coord in which the door is built.
	Float:rX			The rotation of X-axis in which the door is built.
	Float:rY			The rotation of Y-axis in which the door is built.
	Float:rZ			The rotation of Z-axis in which the door is built.
							Also: If the door's type is rotating, this is it's first rotation.
	Float:eX			The second X coord of the door.
							Also: When sliding, this is the X coord it will "slide" to.
							Also: When teleporting, this is the X coord the player will teleport to.
	Float:eY			The second Y coord of the door.
							Also: When sliding, this is the Y coord it will "slide" to.
							Also: When teleporting, this is the Y coord the player will teleport to.
	Float:eZ			The second Z coord of the door.
							Also: When sliding, this is the X coord it will "slide" to.
							Also: When teleporting, this is the Z coord the player will teleport to.
	Float:erX			If the door's type is rotating, this is it's second rotation.
	Float:erY			If the door's type is rotating, this is it's second rotation.
	Float:erZ			If the door's type is rotating, this is it's second rotation.
							Also: When teleporting, this is the rotation the player will teleport to.
	world				The door's world.
	interior			The door's interior.
	_______________________________________________________________________________________________
*/

#if !defined STREAMER_TYPE_OBJECT
	#error c_doors requires streamer to be included.
#endif

#if !defined _Y_ITERATE_LOCAL_VERSION
	#error c_doors requires y_iterate to be included.
#endif

#define INVALID_DOOR_ID (Door:INVALID_OBJECT_ID)

#if !defined MAX_DOORS
	#define MAX_DOORS 200
#endif

enum DoorType
{
	DOOR_TYPE_ROTATING,
	DOOR_TYPE_TELEPORT,
	DOOR_TYPE_SLIDING
}

enum DoorState
{
	DOOR_STATE_OPEN,
	DOOR_STATE_CLOSED
}

enum __E_DoorInfo
{
	cd_ObjectID,
	DoorType:cd_Type,
	
	Float:cd_StartX,
	Float:cd_StartY,
	Float:cd_StartZ,
	Float:cd_EndX,
	Float:cd_EndY,
	Float:cd_EndZ,
	
	Float:cd_StartRX,
	Float:cd_StartRY,
	Float:cd_StartRZ,
	Float:cd_EndRX,
	Float:cd_EndRY,
	Float:cd_EndRZ,
	
	cd_World,
	cd_Interior,
	
	DoorState:cd_State
}

new	__C_DoorInfo[MAX_DOORS][__E_DoorInfo],
	Iterator:__Door<MAX_DOORS>;

/*	Functions
	native Door:CreateDynamicDoor(model, Float:range, type, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX = 0.0, Float:eY = 0.0, Float:eZ = 0.0, Float:erX = 0.0, Float:erY = 0.0, Float:erZ = 0.0, world = -1, interior = -1)
	native Door:CreateRotatingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:erX, Float:erY, Float:erZ, world = -1, interior = -1)
	native Door:CreateSlidingDoor(model, Float:X, Float:Y, Float:Z, Float:eX, Float:eY, Float:eZ, Float:rX, Float:rY, Float:rZ, world = -1, interior = -1)
	native Door:CreateTeleportingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX, Float:eY, Float:eZ, Float:erZ, world = -1, interior = -1)

	native DestroyDynamicDoor(Door:doorid);
	
	native ActivateDynamicDoor(Door:doorid, Float:Speed = 1.0);
	
	native IsValidDynamicDoor(Door:doorid);
	native Door:IsPlayerInRangeOfAnyDynamicDoor(playerid, Float:range = 3.0);
	native IsPlayerInRangeOfDynamicDoor(playerid, Door:doorid, Float:range = 3.0);
	native GetDynamicDoorPos(Door:doorid, &Float:X, &Float:Y, &Float:Z);
	native GetDynamicDoorRot(Door:doorid, &Float:rX, &Float:rY, &Float:rZ);
*/

/**--------------------------------------------------------------------------**\
<summary>
	Door:CreateDynamicDoor
</summary>
	<param name="model">Object Model</param>
	<param name="DoorType:type">Type: DOOR_TYPE_ROTATING, DOOR_TYPE_SLIDING, or DOOR_TYPE_TELEPORT</param>
	<param name="Float:X">Object Initial X Position</param>
	<param name="Float:Y">Object Initial Y Position</param>
	<param name="Float:Z">Object Initial Z Position</param>
	<param name="Float:rX">Object Initial X Rotation</param>
	<param name="Float:rY">Object Initial Y Rotation</param>
	<param name="Float:rZ">Object Initial Z Rotation</param>
	<param name="Float:eX">Object End X Position</param>
	<param name="Float:eY">Object End Y Position</param>
	<param name="Float:eZ">Object End Z Position</param>
	<param name="Float:erX">Object End X Rotation</param>
	<param name="Float:erY">Object End Y Rotation</param>
	<param name="Float:erZ">Object End Z Rotation</param>
	<param name="world">Object World</param>
	<param name="interior">Object Interior</param>
<returns>
	The door's ID with the 'Door' tag.
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock Door:CreateDynamicDoor(model, DoorType:type, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX = 0.0, Float:eY = 0.0, Float:eZ = 0.0, Float:erX = 0.0, Float:erY = 0.0, Float:erZ = 0.0, world = -1, interior = -1)
{
	new i = Iter_Free(__Door);
	if(i == cellmin)
		return INVALID_DOOR_ID;
	
	__C_DoorInfo[i][cd_ObjectID] = CreateDynamicObject(model, X, Y, Z, rX, rY, rZ, world, interior);
	__C_DoorInfo[i][cd_Type] = type;
	
	__C_DoorInfo[i][cd_StartX] = X;
	__C_DoorInfo[i][cd_StartY] = Y;
	__C_DoorInfo[i][cd_StartZ] = Z;
	__C_DoorInfo[i][cd_EndX] = eX;
	__C_DoorInfo[i][cd_EndY] = eY;
	__C_DoorInfo[i][cd_EndZ] = eZ;
	
	__C_DoorInfo[i][cd_StartRX] = rX;
	__C_DoorInfo[i][cd_StartRY] = rY;
	__C_DoorInfo[i][cd_StartRZ] = rZ;
	__C_DoorInfo[i][cd_EndRX] = erX;
	__C_DoorInfo[i][cd_EndRY] = erY;
	__C_DoorInfo[i][cd_EndRZ] = erZ;
	
	__C_DoorInfo[i][cd_World] = world;
	__C_DoorInfo[i][cd_Interior] = interior;
	
	Iter_Add(__Door, i);
	
	return Door:i;
}

/**--------------------------------------------------------------------------**\
<summary>
	Door:CreateRotatingDoor
</summary>
	<param name="model">Object Model</param>
	<param name="Float:X">Object Initial X Position</param>
	<param name="Float:Y">Object Initial Y Position</param>
	<param name="Float:Z">Object Initial Z Position</param>
	<param name="Float:rX">Object Closed X Rotation</param>
	<param name="Float:rY">Object Closed Y Rotation</param>
	<param name="Float:rZ">Object Closed Z Rotation</param>
	<param name="Float:erX">Object Open X Rotation</param>
	<param name="Float:erY">Object Open Y Rotation</param>
	<param name="Float:erZ">Object Open Z Rotation</param>
	<param name="world">Object World</param>
	<param name="interior">Object Interior</param>
<returns>
	The door's ID with the 'Door' tag.
</returns>
<remarks>
	Only accepts starting position.
</remarks>
\**--------------------------------------------------------------------------**/

stock Door:CreateRotatingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:erX, Float:erY, Float:erZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_ROTATING, X, Y, Z, rX, rY, rZ, X, Y, Z, erX, erY, erZ, world, interior);

/**--------------------------------------------------------------------------**\
<summary>
	Door:CreateSlidingDoor
</summary>
	<param name="model">Object Model</param>
	<param name="Float:X">Object Closed X Position</param>
	<param name="Float:Y">Object Closed Y Position</param>
	<param name="Float:Z">Object Closed Z Position</param>
	<param name="Float:eX">Object Open X Position</param>
	<param name="Float:eY">Object Open Y Position</param>
	<param name="Float:eZ">Object Open Z Position</param>
	<param name="Float:rX">Object X Rotation</param>
	<param name="Float:rY">Object Y Rotation</param>
	<param name="Float:rZ">Object Z Rotation</param>
	<param name="world">Object World</param>
	<param name="interior">Object Interior</param>
<returns>
	The door's ID with the 'Door' tag.
</returns>
<remarks>
	Only accepts starting rotation.
</remarks>
\**--------------------------------------------------------------------------**/

stock Door:CreateSlidingDoor(model, Float:X, Float:Y, Float:Z, Float:eX, Float:eY, Float:eZ, Float:rX, Float:rY, Float:rZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_SLIDING, X, Y, Z, rX, rY, rZ, eX, eY, eZ, rX, rY, rZ, world, interior);

/**--------------------------------------------------------------------------**\
<summary>
	Door:CreateTeleportingDoor
</summary>
	<param name="model">Object Model</param>
	<param name="Float:X">Object X Position</param>
	<param name="Float:Y">Object Y Position</param>
	<param name="Float:Z">Object Z Position</param>
	<param name="Float:rX">Object X Rotation</param>
	<param name="Float:rY">Object Y Rotation</param>
	<param name="Float:rZ">Object Z Rotation</param>
	<param name="Float:eX">Player End X Position</param>
	<param name="Float:eY">Player End Y Position</param>
	<param name="Float:eZ">Player End Z Position</param>
	<param name="Float:erZ">Player End Facing Angle</param>
	<param name="world">Object World</param>
	<param name="interior">Object Interior</param>
<returns>
	The door's ID with the 'Door' tag.
</returns>
<remarks>
	If your door is dual entranced, create two doors with opposite positions.
</remarks>
\**--------------------------------------------------------------------------**/

stock Door:CreateTeleportingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX, Float:eY, Float:eZ, Float:erZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_TELEPORT, X, Y, Z, rX, rY, rZ, eX, eY, eZ, rX, rY, erZ, world, interior);

/**--------------------------------------------------------------------------**\
<summary>
	ActivateDynamicDoor
</summary>
	<param name="Door:doorid">Door ID</param>
	<param name="Float:speed">Speed of movement or range from teleporting door</param>
	<param name="playerid">Player to teleport</param>
<returns>
	0 on failure, causes: Non-existent door, player not connected, player not in range
	1 on success
</returns>
<remarks>
	The param named 'speed' could be misinterpreted when using a teleporting door.
	In that case it is actually the range the player needs to be in for it to work.
</remarks>
\**--------------------------------------------------------------------------**/

stock ActivateDynamicDoor(Door:doorid, Float:speed = 1.0, playerid = INVALID_PLAYER_ID)
{
	if(!Iter_Contains(__Door, _:doorid))
		return 0;
	
	new i = _:doorid;
	
	switch(__C_DoorInfo[i][cd_Type]) {
		case DOOR_TYPE_ROTATING: {
			if(__C_DoorInfo[i][cd_State] == DOOR_STATE_CLOSED) {
				MoveDynamicObject(__C_DoorInfo[i][cd_ObjectID], __C_DoorInfo[i][cd_StartX], __C_DoorInfo[i][cd_StartY], __C_DoorInfo[i][cd_StartZ] + 0.00001, speed, __C_DoorInfo[i][cd_EndRY], __C_DoorInfo[i][cd_EndRY], __C_DoorInfo[i][cd_EndRZ]);
				__C_DoorInfo[i][cd_State] = DOOR_STATE_OPEN;
			}
			else if(__C_DoorInfo[i][cd_State] == DOOR_STATE_OPEN) {
				MoveDynamicObject(__C_DoorInfo[i][cd_ObjectID], __C_DoorInfo[i][cd_StartX], __C_DoorInfo[i][cd_StartY], __C_DoorInfo[i][cd_StartZ] - 0.00001, speed, __C_DoorInfo[i][cd_StartRY], __C_DoorInfo[i][cd_StartRY], __C_DoorInfo[i][cd_StartRZ]);
				__C_DoorInfo[i][cd_State] = DOOR_STATE_CLOSED;
			}
		}
		case DOOR_TYPE_SLIDING: {
			if(__C_DoorInfo[i][cd_State] == DOOR_STATE_CLOSED) {
				MoveDynamicObject(__C_DoorInfo[i][cd_ObjectID], __C_DoorInfo[i][cd_EndX], __C_DoorInfo[i][cd_EndY], __C_DoorInfo[i][cd_EndZ], speed);
				__C_DoorInfo[i][cd_State] = DOOR_STATE_OPEN;
			}
			else if(__C_DoorInfo[i][cd_State] == DOOR_STATE_OPEN) {
				MoveDynamicObject(__C_DoorInfo[i][cd_ObjectID], __C_DoorInfo[i][cd_StartX], __C_DoorInfo[i][cd_StartY], __C_DoorInfo[i][cd_StartZ], speed);
				__C_DoorInfo[i][cd_State] = DOOR_STATE_CLOSED;
			}
		}
		case DOOR_TYPE_TELEPORT: {
			if(!IsPlayerConnected(playerid) || IsPlayerInRangeOfDynamicDoor(playerid, doorid, speed))
				return 0;
				
			SetPlayerPos(playerid, __C_DoorInfo[i][cd_EndX], __C_DoorInfo[i][cd_EndY], __C_DoorInfo[i][cd_EndZ]);
			SetPlayerFacingAngle(playerid, __C_DoorInfo[i][cd_EndRZ]);
		}
	}
	
	return 1;
}

/**--------------------------------------------------------------------------**\
<summary>
	DestroyDynamicDoor
</summary>
	<param name="Door:doorid">Door ID</param>
<returns>
	0 on failure, causes: Non-existent door
	1 on success
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock DestroyDynamicDoor(Door:doorid)
{
	if(!Iter_Contains(__Door, _:doorid))
		return 0;
	
	new i = _:doorid;
    
	__C_DoorInfo[i][cd_State] = DOOR_STATE_CLOSED;
	DestroyDynamicObject(__C_DoorInfo[i][cd_ObjectID]);
    Iter_Remove(__Door, i);
    
    return 1;
}

/**--------------------------------------------------------------------------**\
<summary>
	bool:IsValidDynamicDoor
</summary>
	<param name="Door:doorid">Door ID</param>
<returns>
	0 if door is not valid
	1 if door is valid
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

#define IsValidDynamicDoor(%0) \
	(Iter_Contains(__Door, _:%0))

/**--------------------------------------------------------------------------**\
<summary>
	GetDynamicDoorObjectID
</summary>
	<param name="Door:doorid">Door ID</param>
<returns>
	Streamer ID if door is valid
	INVALID_OBJECT_ID if door is not valid
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

#define GetDynamicDoorObjectID(%0) \
	(!IsValidDynamicDoor(%0) ? INVALID_OBJECT_ID : __C_DoorInfo[_:%0][cd_ObjectID])

/**--------------------------------------------------------------------------**\
<summary>
	Door:IsPlayerInRangeOfAnyDynamicDoor
</summary>
	<param name="playerid">Player ID</param>
	<param name="Float:range">Range to test</param>
<returns>
	Door ID of first door found
	INVALID_DOOR_ID if not
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock Door:IsPlayerInRangeOfAnyDynamicDoor(playerid, Float:range = 3.0)
{
	foreach(new i: __Door)
		if(IsPlayerInRangeOfPoint(playerid, range, __C_DoorInfo[i][cd_StartX], __C_DoorInfo[i][cd_StartY], __C_DoorInfo[i][cd_StartZ]))
			return Door:i;

	return INVALID_DOOR_ID;
}

/**--------------------------------------------------------------------------**\
<summary>
	IsPlayerInRangeOfDynamicDoor
</summary>
	<param name="playerid">Player ID</param>
	<param name="Door:door">Door ID</param>
	<param name="Float:range">Range to test</param>
<returns>
	0 on failure
	1 on success
	
	Sliding:
		1 when near start
		2 when near end
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock IsPlayerInRangeOfDynamicDoor(playerid, Door:door, Float:range = 3.0)
{
	new i = _:door;
	
	return (
		IsPlayerInRangeOfPoint(playerid, range, __C_DoorInfo[i][cd_StartX], __C_DoorInfo[i][cd_StartY], __C_DoorInfo[i][cd_StartZ]) ? 1 :
		__C_DoorInfo[i][cd_Type] == DOOR_TYPE_SLIDING && IsPlayerInRangeOfPoint(playerid, range, __C_DoorInfo[i][cd_EndX], __C_DoorInfo[i][cd_EndY], __C_DoorInfo[i][cd_EndZ]) ? 2 :
		0
	);
}

/**--------------------------------------------------------------------------**\
<summary>
	GetDynamicDoorPos
</summary>
	<param name="Door:door">Door ID</param>
	<param name="&Float:X">Returned X Position</param>
	<param name="&Float:Y">Returned Y Position</param>
	<param name="&Float:Z">Returned Z Position</param>
<returns>
	0 on failure, causes: Non-existent Door
	1 on success
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock GetDynamicDoorPos(Door:doorid, &Float:X, &Float:Y, &Float:Z)
{
	return Iter_Contains(__Door, _:doorid) ? GetDynamicObjectPos((__C_DoorInfo[_:doorid][cd_ObjectID]), X, Y, Z) : 0;
}

/**--------------------------------------------------------------------------**\
<summary>
	GetDynamicDoorRot
</summary>
	<param name="Door:door">Door ID</param>
	<param name="&Float:rX">Returned X Rotation</param>
	<param name="&Float:rY">Returned Y Rotation</param>
	<param name="&Float:rZ">Returned Z Rotation</param>
<returns>
	0 on failure, causes: Non-existent Door
	1 on success
</returns>
<remarks>
</remarks>
\**--------------------------------------------------------------------------**/

stock GetDynamicDoorRot(Door:doorid, &Float:rX, &Float:rY, &Float:rZ)
{
	return Iter_Contains(__Door, _:doorid) ? GetDynamicObjectRot((__C_DoorInfo[_:doorid][cd_ObjectID]), rX, rY, rZ) : 0;
}
