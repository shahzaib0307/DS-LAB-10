// Question#2: Reuse the methods from above question 1 and complete below question:
// You are required to implement a game titled “BattleQuest: BST Arena” using a Binary
// Search Tree (BST) where each node in the tree stores a Combatant object. This
// game simulates a classic RPG-style battle between a player’s team of heroes and a
// team of enemies. The core challenge involves managing two separate BSTs — one for
// the player’s team and another for the enemy team — where each node contains a
// Combatant object with attributes such as name, health points (HP), and attack power.
// The game follows a strict turn-based combat system, where the player’s team and the
// enemy team alternate turns. Only the frontline combatant — defined as the node with
// the smallest key value (i.e., the leftmost node in the BST) participates in combat during
// each turn.
// When a combatant’s health drops to zero or below, that combatant is removed from
// their respective BST. The next available combatant in the tree (the new leftmost node)
// becomes the frontline fighter for the following turn.
// The battle continues until one team’s BST becomes empty, determining the winner.
// The player’s team should be initialized with five heroes. The enemy team should be
// initialized with five enemies.
// Both trees should be constructed using insertions according to the BST property based
// on the combatant’s name or unique ID.
// The player always attacks first in each round, followed by the enemy counterattack.
// During an attack: The attacker’s damage = base attack power + random value (0 to 4)
// The damage will affect the defender’s health. If the defender’s health ≤ 0, they are
// removed from their BST immediately. The next combatant automatically takes their
// place as the new frontline fighter.

// During each turn, the game must display the following information clearly:

//  Round number
//  Names and current HP of all heroes and enemies (in BST order)
//  Active attackers and defenders
//  Damage dealt in the attack
//  Updated HP values after each hit
//  Elimination messages when a combatant is defeated
//  Victory message when one BST becomes empty

