// Copyright (C) 2009 - 2026 Settlers Freaks <sf-team at siedler25.org>
//
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#include "defines.h"
#include <array>

// Landscape objects stored with objectInfo 0xC8 (see WLD_reference.md, block 5 and 6).
// The list follows the objects s25client knows (MapLoader::PlaceObjects).
struct LandscapeObject
{
    Uint8 objectType;
    const char* name;
    int picture;
    // true if the object blocks building at its vertex (noStaticObject in s25client)
    bool blocking;
};

constexpr Uint8 LANDSCAPE_OBJECT_INFO = 0xC8;
// big object that also occupies the vertices west, north west and north east of it
constexpr Uint8 LANDSCAPE_OBJECT_RUINED_FORTRESS = 0x2F;

constexpr std::array<LandscapeObject, 54> landscapeObjects{{
  {0x00, "Mushroom 1", MAPPIC_MUSHROOM1, false},
  {0x01, "Mushroom 2", MAPPIC_MUSHROOM2, false},
  {0x02, "Stone 1", MAPPIC_STONE1, false},
  {0x03, "Stone 2", MAPPIC_STONE2, false},
  {0x04, "Stone 3", MAPPIC_STONE3, false},
  {0x05, "Dead tree trunk", MAPPIC_TREE_TRUNK_DEAD, false},
  {0x06, "Dead tree", MAPPIC_TREE_DEAD, false},
  {0x07, "Bone 1", MAPPIC_BONE1, false},
  {0x08, "Bone 2", MAPPIC_BONE2, false},
  {0x09, "Flowers", MAPPIC_FLOWERS, false},
  {0x0A, "Bush 1", MAPPIC_BUSH1, false},
  {0x0B, "Wasserstein", MAPPIC_ROCK4, true},
  {0x0C, "Cactus 1", MAPPIC_CACTUS1, false},
  {0x0D, "Cactus 2", MAPPIC_CACTUS2, false},
  {0x0E, "Shrub 1", MAPPIC_SHRUB1, false},
  {0x0F, "Shrub 2", MAPPIC_SHRUB2, false},
  {0x10, "Bush 2", MAPPIC_BUSH2, false},
  {0x11, "Bush 3", MAPPIC_BUSH3, false},
  {0x12, "Bush 4", MAPPIC_BUSH4, false},
  {0x13, "Shrub 3", MAPPIC_SHRUB3, false},
  {0x14, "Shrub 4", MAPPIC_SHRUB4, false},
  {0x15, "Stranded ship", MIS0BOBS_SHIP, true},
  {0x16, "Gate", MAPPIC_DOOR, true},
  {0x17, "Open gate", MAPPIC_DOOR_OPEN, true},
  {0x18, "Stalagmite 1", MIS1BOBS_STONE1, true},
  {0x19, "Stalagmite 2", MIS1BOBS_STONE2, true},
  {0x1A, "Stalagmite 3", MIS1BOBS_STONE3, true},
  {0x1B, "Stalagmite 4", MIS1BOBS_STONE4, true},
  {0x1C, "Stalagmite 5", MIS1BOBS_STONE5, true},
  {0x1D, "Stalagmite 6", MIS1BOBS_STONE6, true},
  {0x1E, "Stalagmite 7", MIS1BOBS_STONE7, true},
  {0x1F, "Big dead tree 1", MIS1BOBS_TREE1, true},
  {0x20, "Big dead tree 2", MIS1BOBS_TREE2, true},
  {0x21, "Skeleton", MIS1BOBS_SKELETON, true},
  {0x22, "Mushroom 3", MAPPIC_MUSHROOM3, false},
  {0x23, "Stone 4", MAPPIC_STONE4, false},
  {0x24, "Stone 5", MAPPIC_STONE5, false},
  {0x25, "Pebble 1", MAPPIC_PEBBLE1, false},
  {0x26, "Pebble 2", MAPPIC_PEBBLE2, false},
  {0x27, "Pebble 3", MAPPIC_PEBBLE3, false},
  {0x28, "Shrub 5", MAPPIC_SHRUB5, false},
  {0x29, "Shrub 6", MAPPIC_SHRUB6, false},
  {0x2A, "Shrub 7", MAPPIC_SHRUB7, false},
  {0x2B, "Snowman", MAPPIC_SNOWMAN, false},
  {0x2C, "Tent", MIS2BOBS_TENT, true},
  {0x2D, "Ruined guardhouse", MIS2BOBS_GUARDHOUSE, true},
  {0x2E, "Ruined watchtower", MIS2BOBS_GUARDTOWER, true},
  {0x2F, "Ruined fortress", MIS2BOBS_FORTRESS, true},
  {0x30, "Scarecrow with spears", MIS2BOBS_PUPPY, true},
  {0x31, "Viking with boat", MIS3BOBS_VIKING, true},
  {0x32, "Pile of scrolls", MIS4BOBS_SCROLLS, true},
  {0x33, "Whale skeleton", MIS5BOBS_SKELETON1, true},
  // The next 2 objects are not available in the original game, only in s25client
  {0x34, "Whale skeleton 2 (RTTR)", MIS5BOBS_SKELETON2, true},
  {0x35, "Cave (RTTR)", MIS5BOBS_CAVE, true},
}};

constexpr bool isIndexedByObjectType()
{
    for(unsigned i = 0; i < landscapeObjects.size(); i++)
    {
        if(landscapeObjects[i].objectType != i)
            return false;
    }
    return true;
}
static_assert(isIndexedByObjectType(), "landscapeObjects must be sorted by objectType without gaps");

inline const LandscapeObject* findLandscapeObject(Uint8 objectType)
{
    return objectType < landscapeObjects.size() ? &landscapeObjects[objectType] : nullptr;
}
