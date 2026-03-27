#include "BrainTree.h" 
#include <iostream>

class AttackPlayer : public BrainTree::Node {
public:
    Status update() override {
        std::cout << "Enemy Attacking Player!" << std::endl;
        // Attack logics.
        return Node::Status::Success; // Failiure could happen
    }
};

class CheckPlayerInRange : public BrainTree::Node {
public:
    Status update() override {
        // Player range logic
        bool inRange = true; // Placeholder
        return inRange ? Node::Status::Success : Node::Status::Failure;
    }
};

void CreateEnemyBehavior() {
    BrainTree::BehaviorTree tree;

    // Create nodesss
    auto dash attack = std::make_shared<AttackPlayer>();
    auto Rangecheck = std::make_shared<CheckPlayerInRange>();

    // Sequence; if in range attack.
    auto dashattackSequence = std::make_shared<BrainTree::Sequence>();
    dashattackSequence->addChild(checkRange);
    dashattackSequence->addChild(attack);

    // root of tree
    tree.setRoot(dashattackSequence);
};
