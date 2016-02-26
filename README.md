# Crayzie Dynamic Doors

-------------

## Functions:

* [CreateDynamicDoor](README.md#createdynamicdoor)
* [CreateRotatingDoor](README.md#createrotatingdoor)
* [CreateSlidingDoor](README.md#createslidingdoor)
* [CreateTeleportingDoor](README.md#createteleportingdoor)
* [ActivateDynamicDoor](README.md#activatedynamicdoor)
* [DestroyDynamicDoor](README.md#destroydynamicdoor)
* [DestroyAllDynamicDoors](README.md#destroyalldynamicdoors)
* [IsValidDynamicDoor](README.md#isvaliddynamicdoor)
* [GetDynamicDoorObjectID](README.md#getdynamicdoorobjectid)
* [IsPlayerInRangeOfAnyDynamicDoor](README.md#isplayerinrangeofanydynamicdoor)
* [IsPlayerInRangeOfDynamicDoor](README.md#isplayerinrangeofdynamicdoor)
* [GetDynamicDoorPos](README.md#getdynamicdoorpos)
* [GetDynamicDoorRot](README.md#getdynamicdoorrot)
* [GetDynamicDoorType](README.md#getdynamicdoortype)
* [GetDynamicDoorState](README.md#getdynamicdoorstate)

#### CreateDynamicDoor
>* **Parameters:**
>	* `model`: model
>	* `DoorType:type`: DoorType:type
>	* `Float:X`: Float:X
>	* `Float:Y`: Float:Y
>	* `Float:Z`: Float:Z
>	* `Float:rX`: Float:rX
>	* `Float:rY`: Float:rY
>	* `Float:rZ`: Float:rZ
>	* `Float:eX`: Float:eX
>	* `Float:eY`: Float:eY
>	* `Float:eZ`: Float:eZ
>	* `Float:erX`: Float:erX
>	* `Float:erY`: Float:erY
>	* `Float:erZ`: Float:erZ
>	* `world`: world
>	* `interior`: interior
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>
 
***

#### CreateRotatingDoor
>* **Parameters:**
>	* `model`: model
>	* `Float:X`: Float:X
>	* `Float:Y`: Float:Y
>	* `Float:Z`: Float:Z
>	* `Float:rX`: Float:rX
>	* `Float:rY`: Float:rY
>	* `Float:rZ`: Float:rZ
>	* `Float:erX`: Float:erX
>	* `Float:erY`: Float:erY
>	* `Float:erZ`: Float:erZ
>	* `world`: world
>	* `interior`: interior
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	Only accepts starting position.
 
***

#### CreateSlidingDoor
>* **Parameters:**
>	* `model`: model
>	* `Float:X`: Float:X
>	* `Float:Y`: Float:Y
>	* `Float:Z`: Float:Z
>	* `Float:eX`: Float:eX
>	* `Float:eY`: Float:eY
>	* `Float:eZ`: Float:eZ
>	* `Float:rX`: Float:rX
>	* `Float:rY`: Float:rY
>	* `Float:rZ`: Float:rZ
>	* `world`: world
>	* `interior`: interior
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	Only accepts starting rotation.
 
***

#### CreateTeleportingDoor
>* **Parameters:**
>	* `model`: model
>	* `Float:X`: Float:X
>	* `Float:Y`: Float:Y
>	* `Float:Z`: Float:Z
>	* `Float:rX`: Float:rX
>	* `Float:rY`: Float:rY
>	* `Float:rZ`: Float:rZ
>	* `Float:eX`: Float:eX
>	* `Float:eY`: Float:eY
>	* `Float:eZ`: Float:eZ
>	* `Float:erZ`: Float:erZ
>	* `world`: world
>	* `interior`: interior
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	If your door is dual entranced, create two doors with opposite positions.
 
***

#### ActivateDynamicDoor
>* **Parameters:**
>	* `Door:doorid`: Door:doorid
>	* `Float:speed`: Float:speed
>	* `playerid`: playerid
>* **Returns:**
>	* 0 on failure, causes: Non-existent door, player not connected, player not in range
>	* 1 on success
>* **Remarks:**
>	The param named 'speed' could be misinterpreted when using a teleporting door.
>	In that case it is actually the range the player needs to be in for it to work.
 
***

#### DestroyDynamicDoor
>* **Parameters:**
>	* `Door:doorid`: Door:doorid
>* **Returns:**
>	* 0 on failure, causes: Non-existent door
>	* 1 on success
>* **Remarks:**
>
 
***

#### DestroyAllDynamicDoors
>* **Parameters:**

>* **Returns:**
>	* 1 on success
>* **Remarks:**
>	Safe way to destroy all doors.
 
***

#### IsValidDynamicDoor
>* **Parameters:**
>	* `Door:doorid`: Door:doorid
>* **Returns:**
>	* 0 if door is not valid
>	* 1 if door is valid
>* **Remarks:**
>
 
***

#### GetDynamicDoorObjectID
>* **Parameters:**
>	* `Door:doorid`: Door:doorid
>* **Returns:**
>	* Streamer ID if door is valid
>	* INVALID_OBJECT_ID if door is not valid
>* **Remarks:**
>
 
***

#### IsPlayerInRangeOfAnyDynamicDoor
>* **Parameters:**
>	* `playerid`: playerid
>	* `Float:range`: Float:range
>* **Returns:**
>	* Door ID of first door found
>	* INVALID_DOOR_ID if not
>* **Remarks:**
>
 
***

#### IsPlayerInRangeOfDynamicDoor
>* **Parameters:**
>	* `playerid`: playerid
>	* `Door:door`: Door:door
>	* `Float:range`: Float:range
>* **Returns:**
>	* 0 on failure
>	* 1 on success
>	* Sliding:
>	* 1 when near start
>	* 2 when near end
>* **Remarks:**
>
 
***

#### GetDynamicDoorPos
>* **Parameters:**
>	* `Door:door`: Door:door
>	* `&Float:X`: &Float:X
>	* `&Float:Y`: &Float:Y
>	* `&Float:Z`: &Float:Z
>* **Returns:**
>	* 0 on failure, causes: Non-existent Door
>	* 1 on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorRot
>* **Parameters:**
>	* `Door:door`: Door:door
>	* `&Float:rX`: &Float:rX
>	* `&Float:rY`: &Float:rY
>	* `&Float:rZ`: &Float:rZ
>* **Returns:**
>	* 0 on failure, causes: Non-existent Door
>	* 1 on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorType
>* **Parameters:**
>	* `Door:door`: Door:door
>* **Returns:**
>	* INVALID_DOOR_TYPE on failure, causes: Non-existent Door
>	* DOOR_TYPE_ROTATING, DOOR_TYPE_SLIDING, or DOOR_TYPE_TELEPORTING on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorState
>* **Parameters:**
>	* `Door:door`: Door:door
>* **Returns:**
>	* INVALID_DOOR_STATE on failure, causes: Non-existent Door
>	* DOOR_STATE_OPEN or DOOR_STATE_CLOSED on success
>* **Remarks:**
>
 
***

