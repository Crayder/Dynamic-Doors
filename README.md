# Crayzie Dynamic Doors

-------------

## Functions:

* [CreateDynamicDoor](README#createdynamicdoor)
* [CreateRotatingDoor](README#createrotatingdoor)
* [CreateSlidingDoor](README#createslidingdoor)
* [CreateTeleportingDoor](README#createteleportingdoor)
* [ActivateDynamicDoor](README#activatedynamicdoor)
* [DestroyDynamicDoor](README#destroydynamicdoor)
* [DestroyAllDynamicDoors](README#destroyalldynamicdoors)
* [IsValidDynamicDoor](README#isvaliddynamicdoor)
* [GetDynamicDoorObjectID](README#getdynamicdoorobjectid)
* [IsPlayerInRangeOfAnyDynamicDoor](README#isplayerinrangeofanydynamicdoor)
* [IsPlayerInRangeOfDynamicDoor](README#isplayerinrangeofdynamicdoor)
* [GetDynamicDoorPos](README#getdynamicdoorpos)
* [GetDynamicDoorRot](README#getdynamicdoorrot)
* [GetDynamicDoorType](README#getdynamicdoortype)
* [GetDynamicDoorState](README#getdynamicdoorstate)

#### CreateDynamicDoor
>* **Parameters:**
>	* `model`: model_INFO
>	* `DoorType:type`: DoorType:type_INFO
>	* `Float:X`: Float:X_INFO
>	* `Float:Y`: Float:Y_INFO
>	* `Float:Z`: Float:Z_INFO
>	* `Float:rX`: Float:rX_INFO
>	* `Float:rY`: Float:rY_INFO
>	* `Float:rZ`: Float:rZ_INFO
>	* `Float:eX`: Float:eX_INFO
>	* `Float:eY`: Float:eY_INFO
>	* `Float:eZ`: Float:eZ_INFO
>	* `Float:erX`: Float:erX_INFO
>	* `Float:erY`: Float:erY_INFO
>	* `Float:erZ`: Float:erZ_INFO
>	* `world`: world_INFO
>	* `interior`: interior_INFO
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>
 
***

#### CreateRotatingDoor
>* **Parameters:**
>	* `model`: model_INFO
>	* `Float:X`: Float:X_INFO
>	* `Float:Y`: Float:Y_INFO
>	* `Float:Z`: Float:Z_INFO
>	* `Float:rX`: Float:rX_INFO
>	* `Float:rY`: Float:rY_INFO
>	* `Float:rZ`: Float:rZ_INFO
>	* `Float:erX`: Float:erX_INFO
>	* `Float:erY`: Float:erY_INFO
>	* `Float:erZ`: Float:erZ_INFO
>	* `world`: world_INFO
>	* `interior`: interior_INFO
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	Only accepts starting position.
 
***

#### CreateSlidingDoor
>* **Parameters:**
>	* `model`: model_INFO
>	* `Float:X`: Float:X_INFO
>	* `Float:Y`: Float:Y_INFO
>	* `Float:Z`: Float:Z_INFO
>	* `Float:eX`: Float:eX_INFO
>	* `Float:eY`: Float:eY_INFO
>	* `Float:eZ`: Float:eZ_INFO
>	* `Float:rX`: Float:rX_INFO
>	* `Float:rY`: Float:rY_INFO
>	* `Float:rZ`: Float:rZ_INFO
>	* `world`: world_INFO
>	* `interior`: interior_INFO
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	Only accepts starting rotation.
 
***

#### CreateTeleportingDoor
>* **Parameters:**
>	* `model`: model_INFO
>	* `Float:X`: Float:X_INFO
>	* `Float:Y`: Float:Y_INFO
>	* `Float:Z`: Float:Z_INFO
>	* `Float:rX`: Float:rX_INFO
>	* `Float:rY`: Float:rY_INFO
>	* `Float:rZ`: Float:rZ_INFO
>	* `Float:eX`: Float:eX_INFO
>	* `Float:eY`: Float:eY_INFO
>	* `Float:eZ`: Float:eZ_INFO
>	* `Float:erZ`: Float:erZ_INFO
>	* `world`: world_INFO
>	* `interior`: interior_INFO
>* **Returns:**
>	* The door's ID with the 'Door' tag.
>* **Remarks:**
>	If your door is dual entranced, create two doors with opposite positions.
 
***

#### ActivateDynamicDoor
>* **Parameters:**
>	* `Door:doorid`: Door:doorid_INFO
>	* `Float:speed`: Float:speed_INFO
>	* `playerid`: playerid_INFO
>* **Returns:**
>	* 0 on failure, causes: Non-existent door, player not connected, player not in range
>	* 1 on success
>* **Remarks:**
>	The param named 'speed' could be misinterpreted when using a teleporting door.
>	In that case it is actually the range the player needs to be in for it to work.
 
***

#### DestroyDynamicDoor
>* **Parameters:**
>	* `Door:doorid`: Door:doorid_INFO
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
>	* `Door:doorid`: Door:doorid_INFO
>* **Returns:**
>	* 0 if door is not valid
>	* 1 if door is valid
>* **Remarks:**
>
 
***

#### GetDynamicDoorObjectID
>* **Parameters:**
>	* `Door:doorid`: Door:doorid_INFO
>* **Returns:**
>	* Streamer ID if door is valid
>	* INVALID_OBJECT_ID if door is not valid
>* **Remarks:**
>
 
***

#### IsPlayerInRangeOfAnyDynamicDoor
>* **Parameters:**
>	* `playerid`: playerid_INFO
>	* `Float:range`: Float:range_INFO
>* **Returns:**
>	* Door ID of first door found
>	* INVALID_DOOR_ID if not
>* **Remarks:**
>
 
***

#### IsPlayerInRangeOfDynamicDoor
>* **Parameters:**
>	* `playerid`: playerid_INFO
>	* `Door:door`: Door:door_INFO
>	* `Float:range`: Float:range_INFO
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
>	* `Door:door`: Door:door_INFO
>	* `&Float:X`: &Float:X_INFO
>	* `&Float:Y`: &Float:Y_INFO
>	* `&Float:Z`: &Float:Z_INFO
>* **Returns:**
>	* 0 on failure, causes: Non-existent Door
>	* 1 on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorRot
>* **Parameters:**
>	* `Door:door`: Door:door_INFO
>	* `&Float:rX`: &Float:rX_INFO
>	* `&Float:rY`: &Float:rY_INFO
>	* `&Float:rZ`: &Float:rZ_INFO
>* **Returns:**
>	* 0 on failure, causes: Non-existent Door
>	* 1 on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorType
>* **Parameters:**
>	* `Door:door`: Door:door_INFO
>* **Returns:**
>	* INVALID_DOOR_TYPE on failure, causes: Non-existent Door
>	* DOOR_TYPE_ROTATING, DOOR_TYPE_SLIDING, or DOOR_TYPE_TELEPORTING on success
>* **Remarks:**
>
 
***

#### GetDynamicDoorState
>* **Parameters:**
>	* `Door:door`: Door:door_INFO
>* **Returns:**
>	* INVALID_DOOR_STATE on failure, causes: Non-existent Door
>	* DOOR_STATE_OPEN or DOOR_STATE_CLOSED on success
>* **Remarks:**
>
 
***


