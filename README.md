# The-Sealed-King---Third-semester-project
The Sealed King is a 3D third person action game focused on melee combat, where you fight through a snow covered castle by using tactics like parry, finish, block, stun and special abilities. Set in a dark/low fantasy world. The goal? Kill the unworthy king!

## Behavior Tree
This snappshot shows a typical behavior tree that all enemy types are using with minor and major adjustments depending on the enemy's type.

<img width="2546" height="1203" alt="Kopie von BT_Knight" src="https://github.com/user-attachments/assets/9872448c-0afe-4581-8b0d-714ca9dffa31" />


### Physical condition check
On the left side is the physical condition check, which always has the highest priority to ensure, for instance, that an enemy immediately reacts when being hit.
### Attack behavior
In the middle is the attack behavior, which varies heavely depending on the enemy's type. 
### Strafe / not attacking behavior
On the right side is the strafe behavior, which is active, when enemy is not attacking but still in combat. 
In this case, the enemy usually tries to look for positions that are not too close to  the player, but still on screen.
To ensure this behavior, I created a custom EQS test, which increases the location's score, the closer it is to the screen center.

## EQS
[Custom EQS Test](https://github.com/AnubisDev161/The-Sealed-King---Third-semester-project/blob/main/Source/Slasher/Private/EnvQueryTest_OnScreen.cpp) to make enemies prefer positions on screen 

[Enemy Base Class](https://blueprintue.com/blueprint/cy7gb_sy/)

[Melee Enemy Base Class](https://blueprintue.com/blueprint/_e8cozgg/)

[Spearman Enemy Base Calss](https://blueprintue.com/blueprint/bh4axh-y/)

[King Enemy Base class (Boss)](https://blueprintue.com/blueprint/ax0yrqdb/)

[Ranged Enemy Base Class](https://blueprintue.com/blueprint/jk738hd8/)



