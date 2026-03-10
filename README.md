<img width="960" height="300" alt="image" src="https://github.com/user-attachments/assets/940c3041-92f4-4125-afad-2a93efc39426" />

# The-Sealed-King---Third-semester-project
The Sealed King is a 3D third person action game focused on melee combat, where you fight through a snow covered castle by using tactics like parry, finish, block, stun and special abilities. Set in a dark/low fantasy world. The goal? Kill the unworthy king!

The Sealed King was developed in 10 weeks as a student project at the [S4G School for Games](https://www.school4games.net/).

Play it on [Itch.io!](https://s4g.itch.io/the-sealed-king)

## Responsibilities
My main focus in this project was the implementation of the enemy AI and everything related to that, such as the 
[enemy base class](https://blueprintue.com/blueprint/cy7gb_sy/), 
[behavior trees](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Behavior%20Tree%20Pictures/BT_Knight.png) and [custom EQS tests](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Source/Slasher/Private/EnvQueryTest_OnScreen.cpp). I worked closely with our designers on the combat and its design, notably on the stamina bar and the [knockback](https://blueprintue.com/blueprint/ndy-lkfc/) ability. I was also responsible for the implementation of the [king](https://blueprintue.com/blueprint/ax0yrqdb/) enemy for the final boss fight.

## About the project
The game was developed using the Unreal game engine 5.7. We used primiraly Blueprints and some C++ for specific tasks.

## Code Snippets - Enemy types 
(Links lead to [BlueprintUE.com](https://blueprintue.com/))

[Enemy Base Class](https://blueprintue.com/blueprint/cy7gb_sy/) - Base class that defines the behavior and abilities that all enemies inherit from

[Melee Enemy Base Class](https://blueprintue.com/blueprint/_e8cozgg/) - Basic knight that keeps a certain distance to the player and then suddenly attacks

[Spearman Enemy Base Calss](https://blueprintue.com/blueprint/bh4axh-y/) - Tries to protect archers if there are any in range

[King Enemy Base class (Boss)](https://blueprintue.com/blueprint/ax0yrqdb/) - Boss that teleports instead of walking

[Ranged Enemy Base Class](https://blueprintue.com/blueprint/jk738hd8/) - Archer that tries to stay in the background while attacking the player

## Workflow

### The Problem
From early on in the project we had the problem that groups of enemies that are attacking the player at the same time are very hard to keep track of. 
If you have 4 enemies that are attacking you from all directions and you can only see those whoe are on screen. That means you're constantly being attacked from behind without being able to react. to solve this problem, 
we took inspiration from God of War which uses a system to make the enemies stay on screen.

I re created this in a simple form using the Unreal Envriomental Query System. (EQS) 
To create a custom EQS Test in C++.
This test uses the dot product to compare the normal direction of the screen center with the 
direction from the screen center to the possible position and increases the scoring the more similar these directions are.

[Video](https://drive.google.com/file/d/1MKVIdf-pXj9ygoxigJHQeEbphxgQAQnT/view?usp=sharing);
By doing this, we're creating a simple but effective system that makes enemies prefer positions that are within the viewport.
