<img width="960" height="300" alt="image" src="https://github.com/user-attachments/assets/940c3041-92f4-4125-afad-2a93efc39426" />

# The-Sealed-King---Third-semester-project
The Sealed King is a 3D third person action game focused on melee combat, where you fight through a snow covered castle by using tactics like parry, finish, block, stun and special abilities. Set in a dark/low fantasy world. The goal? Kill the unworthy king!

The Sealed King was developed in 10 weeks as a student project at the [S4G School for Games](https://www.school4games.net/).

Play it on [Itch.io!](https://s4g.itch.io/the-sealed-king)

## Responsibilities
My main focus in this project was the implementation of the enemy AI and everything related to that, such as the 
[enemy base class](https://blueprintue.com/blueprint/cy7gb_sy/), 
[behavior trees](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Behavior%20Tree%20Pictures/BT_Knight.png) and [custom EQS tests](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Source/Slasher/Private/EnvQueryTest_OnScreen.cpp). I worked closely with our designers on the combat and its design, notably on the stamina bar and the [knockback](https://blueprintue.com/blueprint/ndy-lkfc/) ability. I was also responsible for the implementation of the [king](https://blueprintue.com/blueprint/ax0yrqdb/) enemy for the final boss fight.

## About The Project
The game was developed using the Unreal game engine 5.7. We used primiraly Blueprints and some C++ for specific tasks.



## My Workflow



### The Problem
From early on in the project we had the problem that groups of enemies that were attacking the player at the same time were very hard to keep track of. 

<img width="2543" height="1129" alt="image" src="https://github.com/user-attachments/assets/e4c1b027-ddd3-4c75-9037-c6cfc3f8a3ab" />

 For example if you have 6 enemies that are attacking you from all directions, you can only see those whoe are on screen.
 That means you're constantly being attacked from behind without being able to react.

### The Solution
To solve this problem, we took inspiration from God of War which uses a system to make the enemies stay on screen.
First I created a simple conceptual prototype in Blueprints to test my idea which was based on the dod product. Then I recreated this using the Unreal Environmental Query System, or for short EQS, to create a [custom EQS Test in C++.](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Source/Slasher/Private/EnvQueryTest_OnScreen.cpp)


<img width="2545" height="1219" alt="image" src="https://github.com/user-attachments/assets/880fdfc2-3539-4836-86de-3b73b720242f" />

This test uses the dot product to compare the normal direction of the screen center with the 
direction from the screen center to the possible position and increases the scoring the more similar these directions are.
By doing this, I creating a simple but effective system that makes enemies prefer positions that are within the viewport, 
as you can see on the picture.

<img width="2536" height="1233" alt="image" src="https://github.com/user-attachments/assets/45358fa2-03f5-4f40-a6ea-50c5d98f43ac" />

On this picture you can clearly see how the scoring is increaesing, the closer the positions are to the center.

Resource: [God of War GDC Talk](https://www.youtube.com/watch?v=hE5tWF-Ou2k&t=2663s)

## Code Snippets - Enemy types 
(Links lead to [BlueprintUE.com](https://blueprintue.com/))

[Enemy Base Class](https://blueprintue.com/blueprint/cy7gb_sy/) - Base class that defines the behavior and abilities that all enemies inherit from

[Melee Enemy Base Class](https://blueprintue.com/blueprint/_e8cozgg/) - Basic knight that keeps a certain distance to the player and then suddenly attacks

[Spearman Enemy Base Calss](https://blueprintue.com/blueprint/bh4axh-y/) - Tries to protect archers if there are any in range

[King Enemy Base class (Boss)](https://blueprintue.com/blueprint/ax0yrqdb/) - Boss that teleports instead of walking

[Ranged Enemy Base Class](https://blueprintue.com/blueprint/jk738hd8/) - Archer that tries to stay in the background while attacking the player
