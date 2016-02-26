/*------------------------------*\_______________________________
Dynamic __Door Include, By: Crayder_______________________________|
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

#define DOOR_TYPE_ROTATING		1
#define DOOR_TYPE_TELEPORT 		2
#define DOOR_TYPE_SLIDING 		3

#define DOOR_OPEN 				1
#define DOOR_CLOSED				0

enum __E_DoorInfo
{
	cd_ObjectID,
	cd_Type,
	
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
	
	cd_State
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

stock Door:CreateDynamicDoor(model, type, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX = 0.0, Float:eY = 0.0, Float:eZ = 0.0, Float:erX = 0.0, Float:erY = 0.0, Float:erZ = 0.0, world = -1, interior = -1)
{
	new i = Iter_Free(__Door);
	if(i == cellmin)
		return INVALID_DOOR_ID;
	
	__DD[i][cd_ObjectID] = CreateDynamicObject(model, X, Y, Z, rX, rY, rZ, world, interior);
	__DD[i][cd_Type] = type;
	
	__DD[i][cd_StartX] = X;
	__DD[i][cd_StartY] = Y;
	__DD[i][cd_StartZ] = Z;
	__DD[i][cd_EndX] = eX;
	__DD[i][cd_EndY] = eY;
	__DD[i][cd_EndZ] = eZ;
	
	__DD[i][cd_StartRX] = rX;
	__DD[i][cd_StartRY] = rY;
	__DD[i][cd_StartRZ] = rZ;
	__DD[i][cd_EndRX] = erX;
	__DD[i][cd_EndRY] = erY;
	__DD[i][cd_EndRZ] = erZ;
	
	__DD[i][cd_World] = world;
	__DD[i][cd_Interior] = interior;
	
	Iter_Add(__Door, i);
	
	return Door:i;
}

stock Door:CreateRotatingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:erX, Float:erY, Float:erZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_ROTATING, X, Y, Z, rX, rY, rZ, X, Y, Z, erX, erY, erZ, world, interior);

stock Door:CreateSlidingDoor(model, Float:X, Float:Y, Float:Z, Float:eX, Float:eY, Float:eZ, Float:rX, Float:rY, Float:rZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_SLIDING, X, Y, Z, rX, rY, rZ, eX, eY, eZ, rX, rY, rZ, world, interior);

stock Door:CreateTeleportingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX, Float:eY, Float:eZ, Float:erZ, world = -1, interior = -1)
	return CreateDynamicDoor(model, DOOR_TYPE_TELEPORT, X, Y, Z, rX, rY, rZ, eX, eY, eZ, rX, rY, erZ, world, interior);

stock ActivateDynamicDoor(Door:doorid, Float:speed = 1.0, playerid = INVALID_PLAYER_ID)
{
	if(!Iter_Contains(__Door, _:doorid))
		return 0;
	
	new i = _:doorid;
	
	switch(__DD[i][cd_Type]) {
		case DOOR_TYPE_ROTATING: {
			if(__DD[i][cd_State] == DOOR_CLOSED) {
				MoveDynamicObject(__DD[i][cd_ObjectID], __DD[i][cd_StartX], __DD[i][cd_StartY], __DD[i][cd_StartZ] + 0.0001, speed, __DD[i][cd_EndRY], __DD[i][cd_EndRY], __DD[i][cd_EndRZ]);
				__DD[i][cd_State] = DOOR_OPEN;
			}
			else if(__DD[i][cd_State] == DOOR_OPEN) {
				MoveDynamicObject(__DD[i][cd_ObjectID], __DD[i][cd_StartX], __DD[i][cd_StartY], __DD[i][cd_StartZ] - 0.0001, speed, __DD[i][cd_StartRY], __DD[i][cd_StartRY], __DD[i][cd_StartRZ]);
				__DD[i][cd_State] = DOOR_CLOSED;
			}
		}
		case DOOR_TYPE_SLIDING: {
			if(__DD[i][cd_State] == DOOR_CLOSED) {
				MoveDynamicObject(__DD[i][cd_ObjectID], __DD[i][cd_EndX], __DD[i][cd_EndY], __DD[i][cd_EndZ], Speed);
				__DD[i][cd_State] = DOOR_OPEN;
			}
			else if(__DD[i][cd_State] == DOOR_OPEN) {
				MoveDynamicObject(__DD[i][cd_ObjectID], __DD[i][cd_StartX], __DD[i][cd_StartY], __DD[i][cd_StartZ], Speed);
				__DD[i][cd_State] = DOOR_CLOSED;
			}
		}
		case DOOR_TYPE_TELEPORT: {
			if(!IsPlayerConnected(playerid) || IsPlayerInRangeOfDynamicDoor(playerid, door, speed))
				return 0;
				
			SetPlayerPos(playerid, __DD[i][cd_EndX], __DD[i][cd_EndY], __DD[i][cd_EndZ]);
			SetPlayerPos(playerid, __DD[i][cd_EndRZ]);
		}
	}
	
	return 1;
}

#define DestroyDynamicDoor(%0) \
	(DestroyDynamicObject(__DD[_:%0][cd_ObjectID]))

#define IsValidDynamicDoor(%0) \
	(Iter_Contains(__Door, _:%0))

#define GetDynamicDoorObjectID(%0) \
	(__DD[_:%0][cd_ObjectID])

stock Door:IsPlayerInRangeOfAnyDynamicDoor(playerid, Float:range = 3.0)
{
	foreach(new i: Door)
		if(IsPlayerInRangeOfPoint(playerid, range, __DD[i][cd_StartX], __DD[i][cd_StartY], __DD[i][cd_StartZ]))
			return i;

	return INVALID_DOOR_ID;
}

stock IsPlayerInRangeOfDynamicDoor(playerid, Door:door, Float:range = 3.0)
{
	new i = _:door;
	
	return (
		IsPlayerInRangeOfPoint(playerid, range, __DD[i][cd_StartX], __DD[i][cd_StartY], __DD[i][cd_StartZ]) ? 1 :
		__DD[i][cd_Type] == DOOR_TYPE_SLIDING && IsPlayerInRangeOfPoint(playerid, range, __DD[i][cd_EndX], __DD[i][cd_EndY], __DD[i][cd_EndZ]) ? 2 :
		0
	);
}

stock GetDynamicDoorPos(Door:doorid, &Float:X, &Float:Y, &Float:Z)
{
	return Iter_Contains(__Door, _:doorid) ? GetDynamicObjectPos(__DD[_:doorid][cd_ObjectID], X, Y, Z) : 0;
}

stock GetDynamicDoorRot(Door:doorid, &Float:rX, &Float:rY, &Float:rZ)
{
	return Iter_Contains(__Door, _:doorid) ? GetDynamicObjectRot(__DD[_:doorid][cd_ObjectID], rX, rY, rZ) : 0;
}
