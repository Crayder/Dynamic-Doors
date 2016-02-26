#include <a_samp>
#include <streamer>
#include <YSI\y_iterate>
#include <YSI\y_commands>

#include <c_doors>

new Door:doors[4];
    
main()
{
    doors[0] = CreateRotatingDoor(
        1497,
        0.0, 0.0, 3.0,
        0.0, 0.0, 0.0,
        0.0, 0.0, 90.0
    );
    doors[1] = CreateSlidingDoor(
        3095,
        5.0, 0.0, 4.0,
        5.0, 9.0, 4.0,
        0.0, 0.0, 0.0
    );
    doors[2] = CreateTeleportingDoor(
        1497,
        10.0, 0.0, 3.0,
        0.0, 0.0, 0.0,
        3000.0, 3000.0, 0.0, 180.0
    );
    doors[3] = CreateTeleportingDoor(
        1497,
        3000.0, 3000.0, 0.0,
        0.0, 0.0, 0.0,
        10.0, 0.0, 3.0, 180.0
    );
    
    printf("Dynamic Door ID: %i", _:doors[0]);
    printf("Dynamic Door ID: %i", _:doors[1]);
    printf("Dynamic Door ID: %i", _:doors[2]);
    
    printf("Activate Dynamic Door: %i", ActivateDynamicDoor(doors[0], 0.1));
    printf("Activate Dynamic Door: %i", ActivateDynamicDoor(doors[1], 2.0));
    
    printf("Dynamic Door Object ID: %i", GetDynamicDoorObjectID(doors[0]));
    printf("Dynamic Door Object ID: %i", GetDynamicDoorObjectID(doors[1]));
    printf("Dynamic Door Object ID: %i", GetDynamicDoorObjectID(doors[2]));
    
    printf("Dynamic Door Type: %i", _:GetDynamicDoorType(doors[0]));
    printf("Dynamic Door Type: %i", _:GetDynamicDoorType(doors[1]));
    printf("Dynamic Door Type: %i", _:GetDynamicDoorType(doors[2]));
    
    printf("Dynamic Door State: %i", _:GetDynamicDoorState(doors[0]));
    printf("Dynamic Door State: %i", _:GetDynamicDoorState(doors[1]));
    printf("Dynamic Door State: %i", _:GetDynamicDoorState(doors[2]));
    
    printf("Player In Range Of Any Door: %i", _:IsPlayerInRangeOfAnyDynamicDoor(0));
    printf("Player In Range Of Any Door: %i", _:IsPlayerInRangeOfAnyDynamicDoor(0));
    printf("Player In Range Of Any Door: %i", _:IsPlayerInRangeOfAnyDynamicDoor(0));
    
    printf("Player In Range Of Door: %i", IsPlayerInRangeOfDynamicDoor(0, doors[0]));
    printf("Player In Range Of Door: %i", IsPlayerInRangeOfDynamicDoor(0, doors[1]));
    printf("Player In Range Of Door: %i", IsPlayerInRangeOfDynamicDoor(0, doors[2]));
    
    new Float:X, Float:Y, Float:Z, Float:rX, Float:rY, Float:rZ;
    GetDynamicDoorPos(doors[0], X, Y, Z); GetDynamicDoorRot(doors[0], rX, rY, rZ);
    printf("Dynamic Door Transform: %4.4f, %4.4f, %4.4f; %4.4f, %4.4f, %4.4f", X, Y, Z, rX, rY, rZ);
    GetDynamicDoorPos(doors[1], X, Y, Z); GetDynamicDoorRot(doors[1], rX, rY, rZ);
    printf("Dynamic Door Transform: %4.4f, %4.4f, %4.4f; %4.4f, %4.4f, %4.4f", X, Y, Z, rX, rY, rZ);
    GetDynamicDoorPos(doors[2], X, Y, Z); GetDynamicDoorRot(doors[2], rX, rY, rZ);
    printf("Dynamic Door Transform: %4.4f, %4.4f, %4.4f; %4.4f, %4.4f, %4.4f", X, Y, Z, rX, rY, rZ);
    
    //if(IsValidDynamicDoor(doors[0]))
    //    printf("Destroy Dynamic Door: %i", DestroyDynamicDoor(doors[0]));
    //printf("Destroy All Dynamic Doors: %i", DestroyAllDynamicDoors());
    //if(IsValidDynamicDoor(doors[1]))
    //    printf("Destroy Dynamic Door: %i", DestroyDynamicDoor(doors[1]));
    //if(IsValidDynamicDoor(doors[2]))
    //    printf("Destroy Dynamic Door: %i", DestroyDynamicDoor(doors[2]));
}

YCMD:activate(playerid, params[], help)
{
    new Door:door = doors[strval(params)];
    
    ActivateDynamicDoor(door, 2.0, playerid);
}
