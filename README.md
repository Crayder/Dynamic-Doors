# Crayzie Dynamic Doors

-------------

## Functions:

```
Door:CreateDynamicDoor(model, Float:range, type, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX = 0.0, Float:eY = 0.0, Float:eZ = 0.0, Float:erX = 0.0, Float:erY = 0.0, Float:erZ = 0.0, world = -1, interior = -1)
Door:CreateRotatingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:erX, Float:erY, Float:erZ, world = -1, interior = -1)
Door:CreateSlidingDoor(model, Float:X, Float:Y, Float:Z, Float:eX, Float:eY, Float:eZ, Float:rX, Float:rY, Float:rZ, world = -1, interior = -1)
Door:CreateTeleportingDoor(model, Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ, Float:eX, Float:eY, Float:eZ, Float:erZ, world = -1, interior = -1)

DestroyDynamicDoor(Door:doorid);
DestroyAllDynamicDoors();

ActivateDynamicDoor(Door:doorid, Float:Speed = 1.0);

IsValidDynamicDoor(Door:doorid);
Door:IsPlayerInRangeOfAnyDynamicDoor(playerid, Float:range = 3.0);
IsPlayerInRangeOfDynamicDoor(playerid, Door:doorid, Float:range = 3.0);
GetDynamicDoorPos(Door:doorid, &Float:X, &Float:Y, &Float:Z);
GetDynamicDoorRot(Door:doorid, &Float:rX, &Float:rY, &Float:rZ);

DoorType:GetDynamicDoorPos(Door:doorid);
DoorState:GetDynamicDoorRot(Door:doorid);
```


